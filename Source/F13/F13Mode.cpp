#include "F13Mode.h"
#include "GameFramework/HUD.h" 
#include "F13PlayerController.h" 
#include "F13BotController.h"
#include "AIController.h"    
#include "GameFramework/PlayerController.h"
#include "F13PlayerState.h"    
#include "F13GameState.h"        
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"        
#include "UObject/ConstructorHelpers.h" 


DEFINE_LOG_CATEGORY_STATIC(LogF13Mode, Log, All);

AF13Mode::AF13Mode()
{
    //DefaultPawnClass = nullptr;
    PlayerControllerClass = AF13PlayerController::StaticClass();
    PlayerStateClass = AF13PlayerState::StaticClass();
    GameStateClass = AF13GameState::StaticClass();
    //PawnToSpawn = nullptr;
    BotControllerClass = AF13BotController::StaticClass();

}


void AF13Mode::BeginPlay()
{
    Super::BeginPlay();
}

void AF13Mode::InitGame(const FString& MapName, const FString& Options, FString& Error)
{
    Super::InitGame(MapName, Options, Error);

    // pull "?humans=xx" from the travel URL
    FParse::Value(*Options, TEXT("humans="), ExpectedHumans);
    UE_LOG(LogF13Mode, Log, TEXT("InitGame → Expecting %d human players"), ExpectedHumans);
}

void AF13Mode::HandleCharacterSelected(APlayerController* SelectingPC)
{
    if (!SelectingPC)
    {
        return;
    }

    // Sanity check: only run this on the server
    if (!HasAuthority())
    {
        return;
    }



    // Spawn logic (same as SpawnChosenPawnForController):
    AF13PlayerState* PS = Cast<AF13PlayerState>(SelectingPC->PlayerState);
    if (!PS)
    {
        UE_LOG(LogTemp, Warning, TEXT("HandleCharacterSelected: no PlayerState"));
        return;
    }

    UE_LOG(LogTemp, Log, TEXT(
        "HandleCharacterSelected: Spawning pawn for %s (Role=%s, Key=%s)"
    ),
        *PS->GetPlayerName(),
        *PS->ChosenRole,
        *PS->ChosenCharacterKey.ToString()
    );

    // Get the pawn class they chose:
    PawnToSpawn = PS->GetChosenPawnClass();
    if (!PawnToSpawn)
    {
        UE_LOG(LogTemp, Warning, TEXT("HandleCharacterSelected: no PawnClass found for %s"),
            *PS->GetPlayerName());
        return;
    }

    // Find a spawn point (PlayerStart). If none, use zero‐origin:
    AActor* StartSpot = FindPlayerStart(SelectingPC);
    FTransform SpawnXF = StartSpot
        ? StartSpot->GetActorTransform()
        : FTransform(FRotator::ZeroRotator, FVector::ZeroVector);

    // Spawn the new Pawn
    FActorSpawnParameters Params;
    Params.Owner = SelectingPC;
    APawn* NewPawn = GetWorld()->SpawnActor<APawn>(
        PawnToSpawn,
        SpawnXF.GetLocation(),
        SpawnXF.GetRotation().Rotator(),
        Params
    );
    if (NewPawn)
    {
        SelectingPC->Possess(NewPawn);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("HandleCharacterSelected: failed to spawn %s for %s"),
            *PawnToSpawn->GetName(), *PS->GetPlayerName());
    }

}

void AF13Mode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    const int32 HumansNow = GameState->PlayerArray.Num();
    UE_LOG(LogF13Mode, Log, TEXT("PostLogin → Humans=%d / %d"), HumansNow, ExpectedHumans);

    if (GetMatchState() == MatchState::WaitingToStart &&
        HumansNow >= ExpectedHumans)
    {
        UE_LOG(LogF13Mode, Log, TEXT("All humans present → StartMatch() (PostLogin)"));
        StartMatch();   //  FillWithBots() happens inside
    }


    if (GetMatchState() == MatchState::InProgress)
    {
        //ReplaceBotIfPossible(NewPlayer);
    }

    if (AF13PlayerState* PS = Cast<AF13PlayerState>(NewPlayer->PlayerState))
    {
        PS->OnCharacterSelected.AddDynamic(
            this, &AF13Mode::HandleCharacterSelected);
    }
}


void AF13Mode::StartMatch()
{
    UE_LOG(LogF13Mode, Log, TEXT("=== StartMatch() called on server ==="));

    
    if (HasAuthority())
    {
        FillWithBots();        // step 1
        //PickRandomKiller();    // step 2
    }
    
    Super::StartMatch();       // *then* call parent so MatchState flips
}


/* ------------------------------------------------------------ */
void AF13Mode::FillWithBots()
{
    UE_LOG(LogF13Mode, Log, TEXT("[FillWithBots] ENTER"));

    UWorld* World = GetWorld();
    const int32 Humans = GameState->PlayerArray.Num();  // humans only (controllers already connected)
    const int32 Needed = 1;

    UE_LOG(LogF13Mode, Log, TEXT("[FillWithBots] Humans=%d  BotsToSpawn=%d"), Humans, Needed);

    for (int32 i = 0; i < Needed; ++i)
    {
        AF13BotController* Bot = World->SpawnActor<AF13BotController>(BotControllerClass);
        if (!Bot)
        {
            UE_LOG(LogF13Mode, Warning, TEXT("  !! Failed to spawn AF13BotController (%d)"), i);
            continue;
        }
        AF13PlayerState* PS = Cast<AF13PlayerState>(Bot->PlayerState);
        if (PS)
        {
            PS->SetPlayerName(FString::Printf(TEXT("Bot_%02d"), i + 1));
            PS->bIsBot = true;
        }

        // Possess an empty pawn for now; you can spawn the real survivor pawn here
        AActor* Start = FindPlayerStart(Bot);
        if (!Start)
        {
            UE_LOG(LogF13Mode, Warning, TEXT("  !! No PlayerStart found for Bot_%02d"), i + 1);
            continue;
        }

        UClass* PawnClass = DefaultPawnClass
            ? *DefaultPawnClass
            : GetDefaultPawnClassForController(Bot);

        if (!PawnClass)
        {
            UE_LOG(LogF13Mode, Error, TEXT("  !! PawnClass is NULL for Bot_%02d"), i + 1);
            continue;
        }

        FActorSpawnParameters Params;
        Params.SpawnCollisionHandlingOverride =
            ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        APawn* Pawn = World->SpawnActor<APawn>(
            PawnClass,
            Start->GetActorLocation(),
            Start->GetActorRotation(),
            Params);

        if (!Pawn)
        {
            UE_LOG(LogF13Mode, Error, TEXT("  !! FAILED to spawn pawn %s for Bot_%02d (collision?)"),
                *PawnClass->GetName(), i + 1);
            continue;
        }

        Bot->Possess(Pawn);
        UE_LOG(LogF13Mode, Log, TEXT("  ✔ Spawned %s at %s"),
            *PawnClass->GetName(), *Start->GetActorLabel());

        //Bot->Possess(World->SpawnActor<APawn>(DefaultPawnClass, Start->GetTransform()));
    }
}

/* ------------------------------------------------------------ */
void AF13Mode::PickRandomKiller()
{
    TArray<AController*> Everyone;
    for (FConstControllerIterator It = GetWorld()->GetControllerIterator(); It; ++It)
        Everyone.Add(It->Get());

    if (Everyone.Num() == 0) return;

    const int32 Index = FMath::RandRange(0, Everyone.Num() - 1);
    AController* KillerCtrl = Everyone[Index];

    for (AController* C : Everyone)
    {
        if (AF13PlayerState* PS = Cast<AF13PlayerState>(C->PlayerState))
        {
            PS->ChosenRole = (C == KillerCtrl) ? TEXT("Killer") : TEXT("Survivor");
        }
    }
}

void AF13Mode::ReplaceBotIfPossible(APlayerController* JoiningPC)
{
    // Only after the match has begun, otherwise let lobby handle it.
    if (GetMatchState() != MatchState::InProgress) return;

    for (FConstControllerIterator It = GetWorld()->GetControllerIterator(); It; ++It)
    {
        AF13BotController* Bot = Cast<AF13BotController>(It->Get());
        if (!Bot) continue;

        APawn* Pawn = Bot->GetPawn();
        AF13PlayerState* BotPS = Cast<AF13PlayerState>(Bot->PlayerState);
        AF13PlayerState* HumanPS = Cast<AF13PlayerState>(JoiningPC->PlayerState);

        if (Pawn && BotPS && HumanPS)
        {
            // Copy role & character choice
            HumanPS->ChosenRole = BotPS->ChosenRole;
            HumanPS->ChosenCharacterKey = BotPS->ChosenCharacterKey;
            HumanPS->SelectedPawnClass = BotPS->SelectedPawnClass;

            // Possess the pawn
            Bot->UnPossess();
            JoiningPC->Possess(Pawn);

            // Clean up
            Bot->Destroy();
            return;    // one is enough
        }
    }
}

AActor* AF13Mode::ChoosePlayerStart_Implementation(AController* Player)
{
    // Cache once
    static TArray<APlayerStart*> Starts;
    static int32 NextIndex = 0;

    if (Starts.IsEmpty())
    {
        TArray<AActor*> Raw;
        UGameplayStatics::GetAllActorsOfClass(this, APlayerStart::StaticClass(), Raw);

        for (AActor* A : Raw)
        {
            Starts.Add(CastChecked<APlayerStart>(A));
        }

        // Sort alphabetically so Start0…Start9 gives a predictable circle
        Starts.Sort([](const APlayerStart& A, const APlayerStart& B)
            {
                return A.PlayerStartTag.ToString() < B.PlayerStartTag.ToString();
            });
    }

    if (Starts.Num() == 0)
    {
        UE_LOG(LogF13Mode, Warning, TEXT("No PlayerStarts found – falling back"));
        return Super::ChoosePlayerStart_Implementation(Player);
    }

    // Round-robin pick
    APlayerStart* Chosen = Starts[NextIndex % Starts.Num()];
    UE_LOG(LogF13Mode, Log, TEXT("ChoosePlayerStart → %s"), *Chosen->PlayerStartTag.ToString());

    ++NextIndex;
    return Chosen;
}


void AF13Mode::HandleMatchIsWaitingToStart()
{
    Super::HandleMatchIsWaitingToStart();

    const int32 HumansNow = GameState->PlayerArray.Num();
    UE_LOG(LogF13Mode, Log, TEXT("HandleMatchIsWaitingToStart → Humans=%d / %d"),
        HumansNow, ExpectedHumans);

    if (HumansNow >= ExpectedHumans)
    {
        UE_LOG(LogF13Mode, Log, TEXT("All humans present – StartMatch() (HandleMatchIsWaitingToStart)"));
        StartMatch();               // FillWithBots() happens inside
    }
}
