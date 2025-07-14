#include "F13Mode.h"
#include "GameFramework/HUD.h" 
#include "F13PlayerController.h" 
#include "F13BotController.h"
#include "F13GameSession.h"
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
    GameSessionClass = AF13GameSession::StaticClass();

}


void AF13Mode::BeginPlay()
{
    Super::BeginPlay();
}

void AF13Mode::InitGame(const FString& MapName, const FString& Options, FString& Error)
{
    Super::InitGame(MapName, Options, Error);

    UE_LOG(LogTemp, Warning, TEXT("InitGame → Map: %s  Options: %s"),
        *MapName, *Options);

    bIsRehostGame = UGameplayStatics::HasOption(Options, TEXT("hms_rehost"));
    K2_OnInitGame(Options);

    
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
    if (GetMatchState() == MatchState::InProgress)
    {
        ReplaceBotIfPossible(NewPlayer);
    }

    Super::PostLogin(NewPlayer);

    const int32 HumansNow = GameState->PlayerArray.Num();
    UE_LOG(LogF13Mode, Log, TEXT("PostLogin → Humans=%d / %d"), HumansNow, ExpectedHumans);


    if (AF13PlayerState* PS = Cast<AF13PlayerState>(NewPlayer->PlayerState))
    {
        PS->OnCharacterSelected.AddDynamic(
            this, &AF13Mode::HandleCharacterSelected);
    }
}


void AF13Mode::StartMatch()
{
    UE_LOG(LogF13Mode, Log, TEXT("=== StartMatch() called on server ==="));

    UE_LOG(LogTemp, Warning, TEXT("StartMatch → bIsRehostGame: %s"),
        bIsRehostGame ? TEXT("true") : TEXT("false"));
    //*
    if (HasAuthority() && !bIsRehostGame)
    {
        FillWithBots();        // step 1
        //PickRandomKiller();    // step 2
    }
    //*/
    Super::StartMatch();       // *then* call parent so MatchState flips
}


void AF13Mode::FillWithBots()
{
    UE_LOG(LogF13Mode, Log, TEXT("[FillWithBots] ENTER"));

    UWorld* World = GetWorld();
    const int32 Humans = GameState->PlayerArray.Num();
    const int32 Needed = kMaxPlayers - Humans;               // spawn target
    UE_LOG(LogF13Mode, Log, TEXT("[FillWithBots] Humans=%d  BotsToSpawn=%d"), Humans, Needed);

    for (int32 i = 0; i < Needed; ++i)
    {
        AF13BotController* Bot = World->SpawnActor<AF13BotController>(BotControllerClass);
        if (!Bot)
        {
            UE_LOG(LogF13Mode, Warning, TEXT("  !! Failed to spawn AF13BotController [%d]"), i);
            continue;
        }

        //------------------------------------------------------------------
        // 1) Player-state setup
        //------------------------------------------------------------------
        AF13PlayerState* PS = Cast<AF13PlayerState>(Bot->PlayerState);
        if (PS)
        {
            PS->SetPlayerName(FString::Printf(TEXT("Bot_%02d"), i + 1));
            PS->bIsBot = true;
            PS->EnsureUniqueIdForBot();     // << give it a valid id
        }

        //------------------------------------------------------------------
        // 2) Choose spawn and create pawn
        //------------------------------------------------------------------
        AActor* Start = FindPlayerStart(Bot);
        if (!IsValid(Start))
        {
            UE_LOG(LogF13Mode, Warning, TEXT("No valid PlayerStart – skipping bot"));
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
        Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        APawn* Pawn = World->SpawnActor<APawn>(
            PawnClass,
            Start->GetActorLocation(),
            Start->GetActorRotation(),
            Params);

        if (!Pawn)
        {
            UE_LOG(LogF13Mode, Error, TEXT("  !! FAILED to spawn pawn %s for Bot_%02d"),
                *PawnClass->GetName(), i + 1);
            continue;
        }

        Bot->Possess(Pawn);

        //------------------------------------------------------------------
        // 3) Verify UniqueId in the log
        //------------------------------------------------------------------
        const FString IdStr = (PS && PS->GetUniqueId().IsValid())
            ? PS->GetUniqueId()->ToString()
            : TEXT("INVALID");

        UE_LOG(LogF13Mode, Log,
            TEXT("[FillWithBots] %s spawned  UniqueId=%s"),
            *PS->GetPlayerName(),
            *IdStr);
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

    UE_LOG(LogF13Mode, Warning, TEXT("Trying to replace bot (Outside)"));

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

            UE_LOG(LogF13Mode, Log,
                TEXT("Bot %s replaced by %s, controller now owns %s"),
                *GetNameSafe(Bot), *GetNameSafe(JoiningPC),
                *GetNameSafe(JoiningPC->GetPawn()));

            // Clean up
            Bot->Destroy();

            UE_LOG(LogF13Mode, Warning, TEXT("Trying to replace bot (Inside)"));
            return;    // one is enough
        }
    }
}

AActor* AF13Mode::ChoosePlayerStart_Implementation(AController* Player)
{
    // Instance-local cache; will be rebuilt each time a map is loaded
    if (CachedStarts.IsEmpty())
    {
        TArray<AActor*> Raw;
        UGameplayStatics::GetAllActorsOfClass(this, APlayerStart::StaticClass(), Raw);

        for (AActor* A : Raw)
            CachedStarts.Add(CastChecked<APlayerStart>(A));

        CachedStarts.Sort([](const APlayerStart& A, const APlayerStart& B)
            {
                return A.PlayerStartTag.ToString() < B.PlayerStartTag.ToString();
            });

        NextStartIndex = 0;          // reset for this match
    }

    if (CachedStarts.Num() == 0)
        return Super::ChoosePlayerStart_Implementation(Player);

    APlayerStart* Chosen = CachedStarts[NextStartIndex % CachedStarts.Num()];
    ++NextStartIndex;
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


AHMS_PlayerController* AF13Mode::HMS_PickNewHost_Implementation()
{
    TArray<APlayerState*> Eligible;

    // Collect real clients (skip bots and current host)
    for (APlayerState* PS : GameState->PlayerArray)
    {
        APlayerController* PC = Cast<APlayerController>(PS->GetOwner());
        if (!PC)                         continue;              // bot
        if (PC->NetConnection == nullptr) continue;             // current host
        Eligible.Add(PS);
    }
    if (Eligible.Num() == 0) return nullptr;

    // Choose the player whose ping is closest to the average
    float Avg = 0.f;
    for (APlayerState* PS : Eligible) Avg += PS->GetPingInMilliseconds();
    Avg /= Eligible.Num();

    APlayerState* Best = Eligible[0];
    for (APlayerState* PS : Eligible)
    {
        if (FMath::Abs(PS->GetPingInMilliseconds() - Avg) <
            FMath::Abs(Best->GetPingInMilliseconds() - Avg))
        {
            Best = PS;
        }
    }

    UE_LOG(LogTemp, Log, TEXT("[HMS] Picked host → %s  (Ping %.0f ms)"),
        *GetNameSafe(Best->GetPlayerController()),
        Best->GetPingInMilliseconds());

    // Optional: dump the whole array for deeper inspection
    for (APlayerState* PS : GameState->PlayerArray)
    {
        const bool bIsBot = !Cast<APlayerController>(PS->GetOwner());
        UE_LOG(LogTemp, Log,
            TEXT("[HMS] Candidate  %-20s  Bot:%s  Ping:%.0f"),
            *GetNameSafe(PS->GetOwner()),
            bIsBot ? TEXT("YES") : TEXT("NO"),
            PS->GetPingInMilliseconds());
    }

    return Cast<AHMS_PlayerController>(Best->GetPlayerController());
}

void AF13Mode::RestartPlayer(AController* NewPlayer)
{
    // If ReplaceBotIfPossible already gave this controller a pawn,
    // skip the default spawn so we don’t leave an extra bot in the world.

    UE_LOG(LogF13Mode, Log,
        TEXT("RestartPlayer called – PawnIsNull=%s"),
        NewPlayer && NewPlayer->GetPawn() ? TEXT("false") : TEXT("true"));

    if (NewPlayer && NewPlayer->GetPawn())
    {
        return;   // ← early‑out, no Super::RestartPlayer call
    }

    // Keep the host‑migration guard you already had
    if (!HMS_MigrationFlags.IsGameRehosted
        || HMS_MigrationFlags.IsLastSaveLoaded)
    {
        Super::RestartPlayer(NewPlayer);    // normal path
    }
}