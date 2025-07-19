#include "F13Mode.h"
#include "F13CharacterBase.h"
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
#include "EngineUtils.h"
#include "UObject/ConstructorHelpers.h" 


DEFINE_LOG_CATEGORY_STATIC(LogF13Mode, Log, All);

AF13Mode::AF13Mode()
{
    PlayerControllerClass = AF13PlayerController::StaticClass();
    PlayerStateClass = AF13PlayerState::StaticClass();
    GameStateClass = AF13GameState::StaticClass();
    BotControllerClass = AF13BotController::StaticClass();
    GameSessionClass = AF13GameSession::StaticClass();
}

void AF13Mode::InitGame(const FString& MapName, const FString& Options, FString& Error)
{
    Super::InitGame(MapName, Options, Error);

    UE_LOG(LogTemp, Warning, TEXT("InitGame → Map: %s  Options: %s"),
        *MapName, *Options);

    bIsRehostGame = UGameplayStatics::HasOption(Options, TEXT("hms_rehost"));

    
    FParse::Value(*Options, TEXT("humans="), ExpectedHumans);
    UE_LOG(LogF13Mode, Log, TEXT("InitGame → Expecting %d human players"), ExpectedHumans);
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

}


void AF13Mode::StartMatch()
{
    UE_LOG(LogF13Mode, Log, TEXT("=== StartMatch() called on server ==="));

    UE_LOG(LogTemp, Warning, TEXT("StartMatch → bIsRehostGame: %s"),
        bIsRehostGame ? TEXT("true") : TEXT("false"));
    //*
    if (HasAuthority() && !bIsRehostGame)
    {
        AssignRoles();
        FillWithBots();        // step 1
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

void AF13Mode::AssignRoles()
{
    PickRandomKiller();                      // void – assigns ChosenRole

    UE_LOG(LogF13Mode, Log, TEXT("----- Role Assignment -----"));

    for (APlayerState* State : GameState->PlayerArray)
    {
        AF13PlayerState* PS = Cast<AF13PlayerState>(State);
        if (!PS) continue;

        /* Only compute the pawn class; role already set */
        PS->SelectedPawnClass = PS->GetChosenPawnClassForRole(PS->ChosenRole);

        const FName   RowKey = (PS->ChosenRole == TEXT("Killer"))
            ? PS->KillerRowKey
            : PS->SurvivorRowKey;

        const TCHAR* PawnName = PS->SelectedPawnClass
            ? *PS->SelectedPawnClass->GetName()
            : TEXT("NONE");

        UE_LOG(LogF13Mode, Log,
            TEXT("Player %-18s  Role=%-9s  Row=%-14s  Pawn=%s"),
            *PS->GetPlayerName(),
            *PS->ChosenRole,
            *RowKey.ToString(),
            PawnName);
    }
    UE_LOG(LogF13Mode, Log, TEXT("---------------------------"));

}

void AF13Mode::ReplaceBotIfPossible(APlayerController* JoiningPC)
{
    // Only after the match has begun, otherwise let lobby handle it.
    if (GetMatchState() != MatchState::InProgress) return;

    UE_LOG(LogF13Mode, Warning, TEXT("Trying to replace bot"));

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
            HumanPS->SurvivorRowKey = BotPS->SurvivorRowKey;
            HumanPS->KillerRowKey = BotPS->KillerRowKey;
            HumanPS->SelectedPawnClass = BotPS->SelectedPawnClass;

            // Possess the pawn
            Bot->UnPossess();
            JoiningPC->Possess(Pawn);

            if (AF13CharacterBase* Char = Cast<AF13CharacterBase>(Pawn))
            {
                // Set both for compatibility
                Char->LastHumanOwnerPS = JoiningPC->PlayerState;
                Char->LastHumanUniqueId = JoiningPC->PlayerState->GetUniqueId();
            }

            UE_LOG(LogF13Mode, Log,
                TEXT("Bot %s replaced by %s, controller now owns %s"),
                *GetNameSafe(Bot), *GetNameSafe(JoiningPC),
                *GetNameSafe(JoiningPC->GetPawn()));

            // Clean up the bot
            Bot->Destroy();
            return;    // one replacement is enough
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

    /*
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
    */

    return Cast<AHMS_PlayerController>(Best->GetPlayerController());
}

void AF13Mode::RestartPlayer(AController* NewPlayer)
{
    const bool bAlreadyHasPawn = NewPlayer && NewPlayer->GetPawn();
    UE_LOG(LogF13Mode, Log,
        TEXT("RestartPlayer → PawnIsNull=%s"),
        bAlreadyHasPawn ? TEXT("false") : TEXT("true"));

    /*  A. If this controller just replaced a bot it already owns a pawn.
     *     Tag it and bail out so we don’t spawn a duplicate.                */
    if (bAlreadyHasPawn)
    {
        if (AF13CharacterBase* Char = Cast<AF13CharacterBase>(NewPlayer->GetPawn()))
        {
            Char->LastHumanOwnerPS = NewPlayer->PlayerState;
            Char->LastHumanUniqueId = NewPlayer->PlayerState->GetUniqueId();

            UE_LOG(LogF13Mode, Log,
                TEXT("[RestartPlayer] Existing pawn %s tagged with UniqueId=%s"),
                *GetNameSafe(Char),                                                         // 1st %s
                (Char->LastHumanUniqueId.IsValid()                                          // 2nd %s
                    ? *Char->LastHumanUniqueId->ToString()   // FString → const TCHAR*
                    : TEXT("None")));
        }
        return;
    }

    /*  B. Normal spawn path  ------------------------------------------------*/
    if (!HMS_MigrationFlags.IsGameRehosted || HMS_MigrationFlags.IsLastSaveLoaded)
    {
        Super::RestartPlayer(NewPlayer);

        AF13PlayerState* PS = Cast<AF13PlayerState>(NewPlayer->PlayerState);
        if (!PS || !PS->SelectedPawnClass)             // still no choice? abort
            return;

        APawn* CurrentPawn = NewPlayer->GetPawn();     // could be nullptr

        // If a wrong pawn spawned (or none), replace it with the chosen one
        if (!CurrentPawn || !CurrentPawn->IsA(PS->SelectedPawnClass))
        {
            FVector  SpawnLoc;
            FRotator SpawnRot;

            if (IsValid(CurrentPawn))
            {
                SpawnLoc = CurrentPawn->GetActorLocation();
                SpawnRot = CurrentPawn->GetActorRotation();
                CurrentPawn->Destroy();
            }
            else
            {
                // No pawn at all – use PlayerStart location
                AActor* Start = FindPlayerStart(NewPlayer);
                SpawnLoc = Start ? Start->GetActorLocation() : FVector::ZeroVector;
                SpawnRot = Start ? Start->GetActorRotation() : FRotator::ZeroRotator;
            }

            FActorSpawnParameters P;
            P.Owner = NewPlayer;
            P.SpawnCollisionHandlingOverride =
                ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

            APawn* Final = GetWorld()->SpawnActor<APawn>(
                PS->SelectedPawnClass, SpawnLoc, SpawnRot, P);

            if (IsValid(Final))
            {
                const FName RowKey = (PS->ChosenRole == TEXT("Killer"))
                    ? PS->KillerRowKey
                    : PS->SurvivorRowKey;

                NewPlayer->Possess(Final);
                UE_LOG(LogF13Mode, Log,
                    TEXT("[RestartPlayer] Spawned %s (row %s) for %s"),
                    *Final->GetName(), *RowKey.ToString(),
                    *NewPlayer->GetName());
            }
            else
            {
                UE_LOG(LogF13Mode, Error,
                    TEXT("[RestartPlayer] FAILED to spawn pawn class %s"),
                    *PS->SelectedPawnClass->GetName());
            }
        }

        if (AF13CharacterBase* Char = Cast<AF13CharacterBase>(NewPlayer->GetPawn()))
        {
            Char->LastHumanOwnerPS = NewPlayer->PlayerState;
            Char->LastHumanUniqueId = NewPlayer->PlayerState->GetUniqueId();

            UE_LOG(LogF13Mode, Log,
                TEXT("[RestartPlayer] Existing pawn %s tagged with UniqueId=%s"),
                *GetNameSafe(Char),                                                         // 1st %s
                (Char->LastHumanUniqueId.IsValid()                                          // 2nd %s
                    ? *Char->LastHumanUniqueId->ToString()   // FString → const TCHAR*
                    : TEXT("None")));
        }
    }
}

void AF13Mode::Logout(AController* Exiting)
{
    UE_LOG(LogF13Mode, Log, TEXT("[Logout] %s leaving"), *GetNameSafe(Exiting));

    /* 1. Grab the pawn *before* we call the parent.                         */
    APawn* OrphanPawn = Exiting ? Exiting->GetPawn() : nullptr;

    /* Un‑possess right away so the pawn isn’t auto‑destroyed in edge cases. */
    if (Exiting && OrphanPawn)
        Exiting->UnPossess();

    const FUniqueNetIdRepl ExitingId =
        (Exiting && Exiting->PlayerState) ? Exiting->PlayerState->GetUniqueId()
        : FUniqueNetIdRepl();

    /* 2. Call parent – this removes the controller & its PlayerState.       */
    Super::Logout(Exiting);

    /* 3. If we didn’t have a pawn pointer (or it became invalid),           */
    /*    scan for the pawn using the UniqueNetId we saved.                  */
    if (!IsValid(OrphanPawn) && ExitingId.IsValid())
    {
        for (TActorIterator<AF13CharacterBase> It(GetWorld()); It; ++It)
        {
            if (It->LastHumanUniqueId == ExitingId)
            {
                OrphanPawn = *It;
                break;
            }
        }
    }

    /* 4. Spawn a bot and give it the pawn.                                  */
    if (IsValid(OrphanPawn))
    {
        FActorSpawnParameters Params;
        Params.SpawnCollisionHandlingOverride =
            ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        AF13BotController* NewBot =
            GetWorld()->SpawnActor<AF13BotController>(BotControllerClass, Params);

        if (NewBot)
        {
            NewBot->Possess(OrphanPawn);

            if (AF13CharacterBase* Char = Cast<AF13CharacterBase>(OrphanPawn))
            {
                Char->LastHumanOwnerPS = nullptr;
                Char->LastHumanUniqueId = FUniqueNetIdRepl();   // clear tag
            }

            UE_LOG(LogF13Mode, Log,
                TEXT("[Logout] Bot %s now controls pawn %s"),
                *GetNameSafe(NewBot), *GetNameSafe(OrphanPawn));
        }
        else
        {
            UE_LOG(LogF13Mode, Error,
                TEXT("[Logout] FAILED to spawn bot; pawn %s left idle"),
                *GetNameSafe(OrphanPawn));
        }
    }
    else
    {
        UE_LOG(LogF13Mode, Warning,
            TEXT("[Logout] No pawn found to hand to a bot"));
    }
}
