#include "PantheonGameMode.h"
#include "PantheonCharacterBase.h" 
#include "PantheonPlayerController.h" 
#include "PantheonBotController.h"
#include "PantheonGameSession.h"   
#include "PantheonPlayerState.h"    
#include "PantheonGameState.h"
#include "AIController.h" 
#include "GameFramework/PlayerController.h"
#include "GameFramework/HUD.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h" 


DEFINE_LOG_CATEGORY_STATIC(LogPantheonGameMode, Log, All);

APantheonGameMode::APantheonGameMode()
{
    PlayerControllerClass = APantheonPlayerController::StaticClass();
    PlayerStateClass = APantheonPlayerState::StaticClass();
    GameStateClass = APantheonGameState::StaticClass();
    BotControllerClass = APantheonBotController::StaticClass();
    GameSessionClass = APantheonGameSession::StaticClass();

    HMS_MigrationSettings.CreateGameSaveUpdateParams.IgnoreHostPawn = false; // keep the host pawn
}

void APantheonGameMode::InitGame(const FString& MapName, const FString& Options, FString& Error)
{
    Super::InitGame(MapName, Options, Error);

    UE_LOG(LogTemp, Warning, TEXT("InitGame ? Map: %s  Options: %s"),
        *MapName, *Options);

    bIsRehostGame = UGameplayStatics::HasOption(Options, TEXT("hms_rehost"));

    
    FParse::Value(*Options, TEXT("humans="), ExpectedHumans);
    UE_LOG(LogPantheonGameMode, Log, TEXT("InitGame ? Expecting %d human players"), ExpectedHumans);

    int32 BotsFlag = 1;                           // default: bots ON
    FParse::Value(*Options, TEXT("bots="), BotsFlag);
    bSpawnBots = (BotsFlag != 0);

    UE_LOG(LogPantheonGameMode, Log, TEXT("InitGame ? bSpawnBots: %s"),
        bSpawnBots ? TEXT("true") : TEXT("false"));

}



void APantheonGameMode::PostLogin(APlayerController* NewPlayer)
{
    // Call bot-replacement BEFORE Super so the engine doesn't spawn a new pawn yet

    if (GetMatchState() == MatchState::InProgress)
    {
        ReplaceBotIfPossible(NewPlayer);
    }

    Super::PostLogin(NewPlayer);

    const int32 HumansNow = GameState->PlayerArray.Num();
    UE_LOG(LogPantheonGameMode, Log, TEXT("PostLogin ? Humans=%d / %d"), HumansNow, ExpectedHumans);
}



void APantheonGameMode::StartMatch()
{
    UE_LOG(LogPantheonGameMode, Log, TEXT("=== StartMatch() called on server ==="));
    UE_LOG(LogTemp, Warning, TEXT("StartMatch ? bIsRehostGame: %s"),
        bIsRehostGame ? TEXT("true") : TEXT("false"));

    if (HasAuthority() && !bIsRehostGame)
    {
        AssignRoles();
        if (bSpawnBots)            // <<< gate here
        {
            FillWithBots();
        }
    }
    Super::StartMatch();
}


void APantheonGameMode::HMS_OnGameRehosted_Cpp()
{
    if (!HasAuthority())
    {
        return;
    }

    UE_LOG(LogPantheonGameMode, Log, TEXT("[HMS_OnGameRehosted_Cpp] Server repairing state after host migration"));

    TArray<APawn*> Pawns;
    for (TActorIterator<APawn> It(GetWorld()); It; ++It)
    {
        APawn* P = *It;
        if (!IsValid(P) || P->IsActorBeingDestroyed())
        {
            continue;
        }

        if (P->GetController() == nullptr)
        {
            // Prefer your bot controller; fall back to base AIController if needed
            TSubclassOf<AAIController> BotControllerClassToUse = APantheonBotController::StaticClass();
            if (!BotControllerClassToUse)
            {
                BotControllerClassToUse = AAIController::StaticClass();
            }

            AAIController* NewBot = GetWorld()->SpawnActor<AAIController>(
                BotControllerClassToUse,
                P->GetActorLocation(),
                P->GetActorRotation()
            );

            if (NewBot)
            {
                NewBot->Possess(P);
                UE_LOG(LogPantheonGameMode, Log, TEXT("[HMS_OnGameRehosted_Cpp] Repossessed orphan pawn %s with %s"),
                    *GetNameSafe(P), *GetNameSafe(NewBot));
            }
        }

        Pawns.Add(P);
    }

    // Make sure AI pawns have a visible bot-style name so UI/logic works.
    static int32 BotCounter = 0;
    for (APawn* P : Pawns)
    {
        if (!IsValid(P) || P->IsActorBeingDestroyed()) continue;

        const AController* C = P->GetController();
        const bool bIsBot = (C && C->IsA(AAIController::StaticClass()));

        if (bIsBot)
        {
            if (APlayerState* PS = P->GetPlayerState())
            {
                if (PS->GetPlayerName().IsEmpty())
                {
                    PS->SetPlayerName(FString::Printf(TEXT("Bot_%02d"), ++BotCounter));
                }
            }
        }
    }

    // Tell PostLogin/replace logic we’re in a rehosted match
    bIsRehostGame = true;
}


void APantheonGameMode::EnsureBotPlayerState(AAIController* AI)
{
    if (!AI) return;

    // Make sure the AI actually has a PlayerState instance
    if (AI->PlayerState == nullptr)
    {
        AI->InitPlayerState(); // gives us an APantheonPlayerState (based on GameMode's PlayerStateClass)
    }

    if (APantheonPlayerState* PS = Cast<APantheonPlayerState>(AI->PlayerState))
    {
        // If your PS has a bIsBot flag, set it here
        if (!PS->bIsBot)
        {
            PS->bIsBot = true;
        }

        PS->ForceNetUpdate();
    }
}


void APantheonGameMode::FillWithBots()
{
    UE_LOG(LogPantheonGameMode, Log, TEXT("[FillWithBots] ENTER"));

    UWorld* World = GetWorld();
    const int32 Humans = GameState->PlayerArray.Num();
    const int32 Needed = kMaxPlayers - Humans;               // spawn target
    UE_LOG(LogPantheonGameMode, Log, TEXT("[FillWithBots] Humans=%d  BotsToSpawn=%d"), Humans, Needed);

    for (int32 i = 0; i < Needed; ++i)
    {
        APantheonBotController* Bot = World->SpawnActor<APantheonBotController>(BotControllerClass);
        if (!Bot)
        {
            UE_LOG(LogPantheonGameMode, Warning, TEXT("  !! Failed to spawn APantheonBotController [%d]"), i);
            continue;
        }

        //------------------------------------------------------------------
        // 1) Player-state setup
        //------------------------------------------------------------------
        APantheonPlayerState* PS = Cast<APantheonPlayerState>(Bot->PlayerState);
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
            UE_LOG(LogPantheonGameMode, Warning, TEXT("No valid PlayerStart – skipping bot"));
            continue;
        }

        UClass* PawnClass = DefaultPawnClass
            ? *DefaultPawnClass
            : GetDefaultPawnClassForController(Bot);

        if (!PawnClass)
        {
            UE_LOG(LogPantheonGameMode, Error, TEXT("  !! PawnClass is NULL for Bot_%02d"), i + 1);
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
            UE_LOG(LogPantheonGameMode, Error, TEXT("  !! FAILED to spawn pawn %s for Bot_%02d"),
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

        UE_LOG(LogPantheonGameMode, Log,
            TEXT("[FillWithBots] %s spawned  UniqueId=%s"),
            *PS->GetPlayerName(),
            *IdStr);
    }
}

/* ------------------------------------------------------------ */
void APantheonGameMode::PickRandomKiller()
{
    TArray<AController*> Everyone;
    for (FConstControllerIterator It = GetWorld()->GetControllerIterator(); It; ++It)
        Everyone.Add(It->Get());

    if (Everyone.Num() == 0) return;

    const int32 Index = FMath::RandRange(0, Everyone.Num() - 1);
    AController* KillerCtrl = Everyone[Index];

    for (AController* C : Everyone)
    {
        if (APantheonPlayerState* PS = Cast<APantheonPlayerState>(C->PlayerState))
        {
            PS->ChosenRole = (C == KillerCtrl) ? TEXT("Killer") : TEXT("Survivor");
        }
    }
}

void APantheonGameMode::AssignRoles()
{
    PickRandomKiller();                      // void – assigns ChosenRole

    UE_LOG(LogPantheonGameMode, Log, TEXT("----- Role Assignment -----"));

    for (APlayerState* State : GameState->PlayerArray)
    {
        APantheonPlayerState* PS = Cast<APantheonPlayerState>(State);
        if (!PS) continue;

        /* Only compute the pawn class; role already set */
        PS->SelectedPawnClass = PS->GetChosenPawnClassForRole(PS->ChosenRole);

        const FName   RowKey = (PS->ChosenRole == TEXT("Killer"))
            ? PS->KillerRowKey
            : PS->SurvivorRowKey;

        const TCHAR* PawnName = PS->SelectedPawnClass
            ? *PS->SelectedPawnClass->GetName()
            : TEXT("NONE");

        UE_LOG(LogPantheonGameMode, Log,
            TEXT("Player %-18s  Role=%-9s  Row=%-14s  Pawn=%s"),
            *PS->GetPlayerName(),
            *PS->ChosenRole,
            *RowKey.ToString(),
            PawnName);
    }
    UE_LOG(LogPantheonGameMode, Log, TEXT("---------------------------"));

}

void APantheonGameMode::ReplaceBotIfPossible(APlayerController* JoiningPC)
{
    if (!HasAuthority() || !IsValid(JoiningPC) || GetMatchState() != MatchState::InProgress)
        return;

    APantheonPlayerState* HumanPS = Cast<APantheonPlayerState>(JoiningPC->PlayerState);
    if (!HumanPS) return;

    APantheonBotController* ChosenBot = nullptr;

    // Prefer a bot that is controlling a pawn that used to be human (has a "UniqueId=" tag)
    static const FString UniquePrefix = TEXT("UniqueId=");
    for (FConstControllerIterator It = GetWorld()->GetControllerIterator(); It; ++It)
    {
        APantheonBotController* BC = Cast<APantheonBotController>(It->Get());
        if (!BC) continue;

        APantheonPlayerState* BotPS = Cast<APantheonPlayerState>(BC->PlayerState);
        if (!BotPS || BotPS->ChosenRole == TEXT("Killer")) continue;

        if (APawn* P = BC->GetPawn())
        {
            bool bLooksLikeAbandonedHumanPawn = false;
            for (const FName& Tag : P->Tags)
            {
                if (Tag.ToString().StartsWith(UniquePrefix))
                {
                    bLooksLikeAbandonedHumanPawn = true;
                    break;
                }
            }

            if (bLooksLikeAbandonedHumanPawn)
            {
                ChosenBot = BC;
                break; // best possible candidate
            }

            // Keep the first valid survivor bot as a fallback
            if (!ChosenBot) ChosenBot = BC;
        }
    }

    if (!ChosenBot) return;

    APawn* BotPawn = ChosenBot->GetPawn();
    if (!BotPawn) return;

    const FTransform BotXf = BotPawn->GetActorTransform();
    const FVector    BotVel = BotPawn->GetVelocity();

    // Decide the player’s desired class; fall back to the bot’s current class
    FString DesiredRole = HumanPS->ChosenRole;
    if (DesiredRole.IsEmpty())
    {
        if (APantheonPlayerState* BotPS = Cast<APantheonPlayerState>(ChosenBot->PlayerState))
            DesiredRole = BotPS->ChosenRole.IsEmpty() ? TEXT("Survivor") : BotPS->ChosenRole;
        else
            DesiredRole = TEXT("Survivor");
    }

    TSubclassOf<APawn> DesiredClass = HumanPS->GetChosenPawnClassForRole(DesiredRole);
    if (!DesiredClass) DesiredClass = BotPawn->GetClass();
    HumanPS->SelectedPawnClass = DesiredClass;

    // Clean up any pawn the joining PC might already have
    if (APawn* Existing = JoiningPC->GetPawn())
    {
        JoiningPC->UnPossess();
        if (Existing != BotPawn) { Existing->Destroy(); }
    }

    // Free the bot controller
    ChosenBot->UnPossess();

    if (DesiredClass == BotPawn->GetClass())
    {
        JoiningPC->Possess(BotPawn);
        TagPawnWithPlayer(BotPawn, HumanPS);

        if (ACharacter* Char = Cast<ACharacter>(BotPawn))
            if (UCharacterMovementComponent* Move = Char->GetCharacterMovement())
                Move->Velocity = BotVel;

        JoiningPC->SetControlRotation(BotXf.GetRotation().Rotator());
        BotPawn->ForceNetUpdate();
    }
    else
    {
        FActorSpawnParameters P;
        P.Owner = JoiningPC;
        P.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        APawn* NewPawn = GetWorld()->SpawnActor<APawn>(DesiredClass, BotXf, P);
        if (NewPawn)
        {
            if (ACharacter* NewChar = Cast<ACharacter>(NewPawn))
                if (UCharacterMovementComponent* Move = NewChar->GetCharacterMovement())
                    Move->Velocity = BotVel;

            JoiningPC->Possess(NewPawn);
            TagPawnWithPlayer(NewPawn, HumanPS);
            JoiningPC->SetControlRotation(BotXf.GetRotation().Rotator());
            NewPawn->ForceNetUpdate();
            BotPawn->Destroy();
        }
        else
        {
            JoiningPC->Possess(BotPawn);
        }
    }

    // Engine may call RestartPlayer after PostLogin; skip once
    SkipNextRestart.Add(JoiningPC);

    // Remove the bot controller cleanly
    PendingSilentRemovals.Add(ChosenBot);
    ChosenBot->bSkipLogoutRespawn = true;
    ChosenBot->Destroy();
}


void APantheonGameMode::SpawnReplacementBotAt(const FTransform& Xf, TSubclassOf<APawn> PawnClass, const FVector& InVelocity)
{
    if (!HasAuthority()) return;

    UWorld* World = GetWorld();
    if (!World) return;

    // Resolve pawn class to a UClass*
    UClass* EffectivePawnClass = nullptr;
    if (PawnClass)
    {
        EffectivePawnClass = *PawnClass;
    }
    else if (DefaultPawnClass)
    {
        EffectivePawnClass = *DefaultPawnClass;
    }
    else
    {
        EffectivePawnClass = GetDefaultPawnClassForController(nullptr);
    }

    if (!EffectivePawnClass)
    {
        UE_LOG(LogPantheonGameMode, Warning, TEXT("[SpawnReplacementBotAt] No valid pawn class to spawn."));
        return;
    }

    // Resolve AI controller class to a UClass*
    UClass* EffectiveAIControllerClass = nullptr;
    if (BotControllerClass)
    {
        EffectiveAIControllerClass = *BotControllerClass;
    }
    else
    {
        EffectiveAIControllerClass = APantheonBotController::StaticClass();
    }

    // Spawn bot controller
    FActorSpawnParameters CParams;
    CParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    AAIController* Bot = World->SpawnActor<AAIController>(EffectiveAIControllerClass, Xf, CParams);
    if (!Bot)
    {
        UE_LOG(LogPantheonGameMode, Warning, TEXT("[SpawnReplacementBotAt] Failed to spawn bot controller."));
        return;
    }

    // Spawn pawn exactly at desired spot
    FActorSpawnParameters P;
    P.Owner = Bot;
    P.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    APawn* NewPawn = World->SpawnActor<APawn>(EffectivePawnClass, Xf, P);
    if (!NewPawn)
    {
        UE_LOG(LogPantheonGameMode, Warning, TEXT("[SpawnReplacementBotAt] Failed to spawn pawn for bot. Destroying controller."));
        Bot->Destroy();
        return;
    }

    Bot->Possess(NewPawn);

    // Lock transform and carry initial velocity if provided
    NewPawn->SetActorTransform(Xf, false, nullptr, ETeleportType::TeleportPhysics);

    if (ACharacter* AsChar = Cast<ACharacter>(NewPawn))
    {
        if (!InVelocity.IsNearlyZero())
        {
            if (UCharacterMovementComponent* MoveComp = AsChar->GetCharacterMovement())
            {
                MoveComp->Velocity = InVelocity;
            }
        }
    }

    UE_LOG(LogPantheonGameMode, Log, TEXT("[SpawnReplacementBotAt] Spawned replacement bot %s with pawn %s at X=%.3f Y=%.3f Z=%.3f"),
        *GetNameSafe(Bot),
        *GetNameSafe(NewPawn),
        NewPawn->GetActorLocation().X,
        NewPawn->GetActorLocation().Y,
        NewPawn->GetActorLocation().Z);
}


AAIController* APantheonGameMode::SpawnBotControllerAndPossessExisting(APawn* ExistingPawn, const FTransform& DesiredTransform)
{
    if (!HasAuthority() || !ExistingPawn) return nullptr;

    UWorld* World = GetWorld();
    if (!World) return nullptr;

    // Move the pawn first (teleport, no sweep)
    ExistingPawn->SetActorTransform(DesiredTransform, false, nullptr, ETeleportType::TeleportPhysics);

    // Make sure nothing is still possessing this pawn
    if (AController* Old = ExistingPawn->GetController())
    {
        Old->UnPossess();
    }

    // Decide AI controller class as UClass*
    UClass* EffectiveAIControllerClass = nullptr;
    if (BotControllerClass)
    {
        EffectiveAIControllerClass = *BotControllerClass;
    }
    else
    {
        EffectiveAIControllerClass = APantheonBotController::StaticClass();
    }

    // Spawn the AI controller
    FActorSpawnParameters CParams;
    CParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    AAIController* NewBot = World->SpawnActor<AAIController>(EffectiveAIControllerClass, DesiredTransform, CParams);
    if (!NewBot)
    {
        UE_LOG(LogPantheonGameMode, Warning, TEXT("[SpawnBotControllerAndPossessExisting] Failed to spawn bot controller."));
        return nullptr;
    }

    // Possess the existing pawn
    NewBot->Possess(ExistingPawn);

    // Force net update
    ExistingPawn->ForceNetUpdate();
    NewBot->ForceNetUpdate();

    UE_LOG(LogPantheonGameMode, Log, TEXT("[SpawnBotControllerAndPossessExisting] Bot %s took over pawn %s at X=%.3f Y=%.3f Z=%.3f"),
        *GetNameSafe(NewBot),
        *GetNameSafe(ExistingPawn),
        ExistingPawn->GetActorLocation().X,
        ExistingPawn->GetActorLocation().Y,
        ExistingPawn->GetActorLocation().Z);

    return NewBot;
}


AActor* APantheonGameMode::ChoosePlayerStart_Implementation(AController* Player)
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


void APantheonGameMode::HandleMatchIsWaitingToStart()
{
    Super::HandleMatchIsWaitingToStart();

    const int32 HumansNow = GameState->PlayerArray.Num();
    UE_LOG(LogPantheonGameMode, Log, TEXT("HandleMatchIsWaitingToStart ? Humans=%d / %d"),
        HumansNow, ExpectedHumans);

    if (HumansNow >= ExpectedHumans)
    {
        UE_LOG(LogPantheonGameMode, Log, TEXT("All humans present – StartMatch() (HandleMatchIsWaitingToStart)"));
        StartMatch();               // FillWithBots() happens inside
    }
}


AHMS_PlayerController* APantheonGameMode::HMS_PickNewHost_Implementation()
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


    UE_LOG(LogTemp, Log, TEXT("[HMS] Picked host ? %s  (Ping %.0f ms)"),
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

void APantheonGameMode::RestartPlayer(AController* NewPlayer)
{
    if (SkipNextRestart.Contains(NewPlayer))
    {
        SkipNextRestart.Remove(NewPlayer);
        UE_LOG(LogPantheonGameMode, Log, TEXT("[RestartPlayer] Skipping due to bot replacement for %s"), *GetNameSafe(NewPlayer));
        return;
    }

    const bool bAlreadyHasPawn = NewPlayer && NewPlayer->GetPawn();
    UE_LOG(LogPantheonGameMode, Log,
        TEXT("RestartPlayer ? PawnIsNull=%s"),
        bAlreadyHasPawn ? TEXT("false") : TEXT("true"));

    // A) If this controller just replaced a bot it already owns a pawn.
    if (bAlreadyHasPawn)
    {
        if (APantheonCharacterBase* Char = Cast<APantheonCharacterBase>(NewPlayer->GetPawn()))
        {
            Char->LastHumanOwnerPS = NewPlayer->PlayerState;
            Char->LastHumanUniqueId = NewPlayer->PlayerState->GetUniqueId();

            if (APantheonPlayerState* PS = Cast<APantheonPlayerState>(NewPlayer->PlayerState))
            {
                TagPawnWithPlayer(Char, PS);
            }

            UE_LOG(LogPantheonGameMode, Log,
                TEXT("[RestartPlayer] Existing pawn %s tagged with UniqueId=%s"),
                *GetNameSafe(Char),
                (Char->LastHumanUniqueId.IsValid()
                    ? *Char->LastHumanUniqueId->ToString()
                    : TEXT("None")));
        }
        return;
    }

    // B) Normal spawn path
    if (!HMS_MigrationFlags.IsGameRehosted || HMS_MigrationFlags.IsLastSaveLoaded)
    {
        Super::RestartPlayer(NewPlayer);

        APantheonPlayerState* PS = Cast<APantheonPlayerState>(NewPlayer->PlayerState);
        if (!PS || !PS->SelectedPawnClass)
            return;

        APawn* CurrentPawn = NewPlayer->GetPawn();

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
                AActor* Start = FindPlayerStart(NewPlayer);
                SpawnLoc = Start ? Start->GetActorLocation() : FVector::ZeroVector;
                SpawnRot = Start ? Start->GetActorRotation() : FRotator::ZeroRotator;
            }

            FActorSpawnParameters P;
            P.Owner = NewPlayer;
            P.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

            APawn* Final = GetWorld()->SpawnActor<APawn>(PS->SelectedPawnClass, SpawnLoc, SpawnRot, P);

            if (IsValid(Final))
            {
                const FName RowKey = (PS->ChosenRole == TEXT("Killer"))
                    ? PS->KillerRowKey
                    : PS->SurvivorRowKey;

                NewPlayer->Possess(Final);

                if (APantheonPlayerState* PS2 = Cast<APantheonPlayerState>(NewPlayer->PlayerState))
                {
                    TagPawnWithPlayer(Final, PS2);
                }

                UE_LOG(LogPantheonGameMode, Log,
                    TEXT("[RestartPlayer] Spawned %s (row %s) for %s"),
                    *Final->GetName(), *RowKey.ToString(),
                    *NewPlayer->GetName());
            }
            else
            {
                UE_LOG(LogPantheonGameMode, Error,
                    TEXT("[RestartPlayer] FAILED to spawn pawn class %s"),
                    *PS->SelectedPawnClass->GetName());
            }
        }

        if (APantheonCharacterBase* Char = Cast<APantheonCharacterBase>(NewPlayer->GetPawn()))
        {
            Char->LastHumanOwnerPS = NewPlayer->PlayerState;
            Char->LastHumanUniqueId = NewPlayer->PlayerState->GetUniqueId();

            UE_LOG(LogPantheonGameMode, Log,
                TEXT("[RestartPlayer] Existing pawn %s tagged with UniqueId=%s"),
                *GetNameSafe(Char),
                (Char->LastHumanUniqueId.IsValid()
                    ? *Char->LastHumanUniqueId->ToString()
                    : TEXT("None")));
        }
    }
}


void APantheonGameMode::Logout(AController* Exiting)
{
    if (!HasAuthority())
    {
        Super::Logout(Exiting);
        return;
    }

    UE_LOG(LogPantheonGameMode, Log, TEXT("[Logout] %s leaving"), *GetNameSafe(Exiting));

    const bool bWasHuman = Cast<APlayerController>(Exiting) != nullptr;
    APantheonPlayerState* PS = Exiting ? Exiting->GetPlayerState<APantheonPlayerState>() : nullptr;

    // Try to get (or find) the pawn this controller was using
    APawn* LeavingPawn = Exiting ? Exiting->GetPawn() : nullptr;

    if (!LeavingPawn && PS)
    {
        const FName TagToFind(*FString::Printf(TEXT("UniqueId=%s"), *PS->GetPlayerName()));
        for (TActorIterator<APawn> It(GetWorld()); It; ++It)
        {
            APawn* P = *It;
            if (P && !P->IsPendingKillPending() && P->GetController() == nullptr && P->Tags.Contains(TagToFind))
            {
                LeavingPawn = P;
                break;
            }
        }
    }

    if (bWasHuman && LeavingPawn && !LeavingPawn->IsPendingKillPending())
    {
        // Stop any residual motion for a clean hand-off
        if (ACharacter* C = Cast<ACharacter>(LeavingPawn))
            if (UCharacterMovementComponent* Move = C->GetCharacterMovement())
                Move->StopMovementImmediately();

        // IMPORTANT: put an APantheonBotController (not base AAIController) back on THIS pawn.
        const FTransform Xf = LeavingPawn->GetActorTransform();
        if (AAIController* NewBot = SpawnBotControllerAndPossessExisting(LeavingPawn, Xf))
        {
            UE_LOG(LogPantheonGameMode, Log, TEXT("[Logout] Bot %s took over pawn %s at %s"),
                *GetNameSafe(NewBot), *GetNameSafe(LeavingPawn), *LeavingPawn->GetActorLocation().ToCompactString());
        }
        else
        {
            UE_LOG(LogPantheonGameMode, Warning, TEXT("[Logout] Failed to spawn bot controller for leaving pawn"));
        }

        // Do normal controller cleanup; we've kept the pawn alive.
        Super::Logout(Exiting);
        return;
    }

    // Bot left or no pawn to reuse
    Super::Logout(Exiting);
}


void APantheonGameMode::TagPawnWithPlayer(APawn* Pawn, APantheonPlayerState* PS)
{
    if (!Pawn || !PS) return;

    // Update character-side bookkeeping (you already use these)
    if (APantheonCharacterBase* Char = Cast<APantheonCharacterBase>(Pawn))
    {
        Char->LastHumanOwnerPS = PS;
        Char->LastHumanUniqueId = PS->GetUniqueId();
    }

    // Keep a simple, easy-to-find actor tag: "UniqueId=<PlayerName>"
    static const FString Prefix = TEXT("UniqueId=");
    // Remove any existing UniqueId= tags
    for (int32 i = Pawn->Tags.Num() - 1; i >= 0; --i)
    {
        const FString S = Pawn->Tags[i].ToString();
        if (S.StartsWith(Prefix)) { Pawn->Tags.RemoveAt(i); }
    }
    Pawn->Tags.Add(FName(Prefix + PS->GetPlayerName()));
    Pawn->ForceNetUpdate();
}

void APantheonGameMode::RememberLeavingPawn(AController* PC, APawn* Pawn, const FTransform& Xform, const FVector& Vel)
{
    if (!HasAuthority() || !PC || !Pawn) return;

    FPendingReplace Rec;
    Rec.Pawn = Pawn;
    Rec.Transform = Xform;
    Rec.Velocity = Vel;

    PendingReplacements.Add(PC, Rec);
}
