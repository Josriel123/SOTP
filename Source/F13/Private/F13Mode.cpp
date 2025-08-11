#include "F13Mode.h"
#include "F13CharacterBase.h" 
#include "F13PlayerController.h" 
#include "F13BotController.h"
#include "F13GameSession.h"   
#include "F13PlayerState.h"    
#include "F13GameState.h"
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
    // Call bot-replacement BEFORE Super so the engine doesn't spawn a new pawn yet

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
    if (!HasAuthority() || !IsValid(JoiningPC) || GetMatchState() != MatchState::InProgress)
        return;

    AF13PlayerState* HumanPS = Cast<AF13PlayerState>(JoiningPC->PlayerState);
    if (!HumanPS) return;

    // Find any *survivor* bot to replace
    AF13BotController* Bot = nullptr;
    for (FConstControllerIterator It = GetWorld()->GetControllerIterator(); It; ++It)
    {
        AF13BotController* Candidate = Cast<AF13BotController>(It->Get());
        if (!Candidate) continue;

        AF13PlayerState* BotPS = Cast<AF13PlayerState>(Candidate->PlayerState);
        if (BotPS && BotPS->ChosenRole != TEXT("Killer"))
        {
            Bot = Candidate;
            break;
        }
    }
    if (!Bot) return;

    APawn* BotPawn = Bot->GetPawn();
    if (!BotPawn) return;

    // Cache the *exact* transform & motion of the bot pawn
    const FTransform BotXf = BotPawn->GetActorTransform();
    const FVector    BotVel = BotPawn->GetVelocity();

    // Decide desired role/class; fall back to the bot's actual class if prefs are unset
    FString DesiredRole = HumanPS->ChosenRole;
    if (DesiredRole.IsEmpty())
    {
        if (AF13PlayerState* BotPS = Cast<AF13PlayerState>(Bot->PlayerState))
            DesiredRole = BotPS->ChosenRole.IsEmpty() ? TEXT("Survivor") : BotPS->ChosenRole;
        else
            DesiredRole = TEXT("Survivor");
    }
    TSubclassOf<APawn> DesiredClass = HumanPS->GetChosenPawnClassForRole(DesiredRole);
    if (!DesiredClass)
    {
        DesiredClass = BotPawn->GetClass();               // hard fallback
    }
    HumanPS->SelectedPawnClass = DesiredClass;            // keep PS consistent

    // Clean up any stray pawn created during login
    if (APawn* Existing = JoiningPC->GetPawn())
    {
        JoiningPC->UnPossess();
        if (Existing != BotPawn) { Existing->Destroy(); }
    }

    Bot->UnPossess();

    if (DesiredClass == BotPawn->GetClass())
    {
        // Take over the bot pawn as-is
        BotPawn->SetActorTransform(BotXf, false, nullptr, ETeleportType::TeleportPhysics);
        JoiningPC->Possess(BotPawn);
        TagPawnWithPlayer(BotPawn, HumanPS);

        if (ACharacter* Char = Cast<ACharacter>(BotPawn))
        {
            if (UCharacterMovementComponent* Move = Char->GetCharacterMovement())
                Move->Velocity = BotVel;
        }
        JoiningPC->SetControlRotation(BotXf.GetRotation().Rotator());
        BotPawn->ForceNetUpdate();
    }
    else
    {
        // Spawn the player’s preferred class at the bot's exact spot
        FActorSpawnParameters P;
        P.Owner = JoiningPC;
        P.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        APawn* NewPawn = GetWorld()->SpawnActor<APawn>(DesiredClass, BotXf, P);
        if (NewPawn)
        {
            if (ACharacter* NewChar = Cast<ACharacter>(NewPawn))
            {
                if (UCharacterMovementComponent* Move = NewChar->GetCharacterMovement())
                    Move->Velocity = BotVel;
            }
            JoiningPC->Possess(NewPawn);
            TagPawnWithPlayer(NewPawn, HumanPS);
            JoiningPC->SetControlRotation(BotXf.GetRotation().Rotator());
            NewPawn->ForceNetUpdate();
            BotPawn->Destroy(); // we replaced the body
        }
        else
        {
            // Fallback: just possess the bot pawn
            JoiningPC->Possess(BotPawn);
        }
    }

    // Engine may still call RestartPlayer for this controller; skip it once
    SkipNextRestart.Add(JoiningPC);

    // Remove the bot controller now that the human took over
    PendingSilentRemovals.Add(Bot);
    Bot->bSkipLogoutRespawn = true;
    Bot->Tags.AddUnique(FName(TEXT("SkipRespawn"))); // mark for silent removal
    Bot->Destroy();
}


void AF13Mode::SpawnReplacementBotAt(const FTransform& Xf, TSubclassOf<APawn> PawnClass, const FVector& InVelocity)
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
        UE_LOG(LogF13Mode, Warning, TEXT("[SpawnReplacementBotAt] No valid pawn class to spawn."));
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
        EffectiveAIControllerClass = AF13BotController::StaticClass();
    }

    // Spawn bot controller
    FActorSpawnParameters CParams;
    CParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    AAIController* Bot = World->SpawnActor<AAIController>(EffectiveAIControllerClass, Xf, CParams);
    if (!Bot)
    {
        UE_LOG(LogF13Mode, Warning, TEXT("[SpawnReplacementBotAt] Failed to spawn bot controller."));
        return;
    }

    // Spawn pawn exactly at desired spot
    FActorSpawnParameters P;
    P.Owner = Bot;
    P.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    APawn* NewPawn = World->SpawnActor<APawn>(EffectivePawnClass, Xf, P);
    if (!NewPawn)
    {
        UE_LOG(LogF13Mode, Warning, TEXT("[SpawnReplacementBotAt] Failed to spawn pawn for bot. Destroying controller."));
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

    UE_LOG(LogF13Mode, Log, TEXT("[SpawnReplacementBotAt] Spawned replacement bot %s with pawn %s at X=%.3f Y=%.3f Z=%.3f"),
        *GetNameSafe(Bot),
        *GetNameSafe(NewPawn),
        NewPawn->GetActorLocation().X,
        NewPawn->GetActorLocation().Y,
        NewPawn->GetActorLocation().Z);
}


AAIController* AF13Mode::SpawnBotControllerAndPossessExisting(APawn* ExistingPawn, const FTransform& DesiredTransform)
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
        EffectiveAIControllerClass = AF13BotController::StaticClass();
    }

    // Spawn the AI controller
    FActorSpawnParameters CParams;
    CParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    AAIController* NewBot = World->SpawnActor<AAIController>(EffectiveAIControllerClass, DesiredTransform, CParams);
    if (!NewBot)
    {
        UE_LOG(LogF13Mode, Warning, TEXT("[SpawnBotControllerAndPossessExisting] Failed to spawn bot controller."));
        return nullptr;
    }

    // Possess the existing pawn
    NewBot->Possess(ExistingPawn);

    // Force net update
    ExistingPawn->ForceNetUpdate();
    NewBot->ForceNetUpdate();

    UE_LOG(LogF13Mode, Log, TEXT("[SpawnBotControllerAndPossessExisting] Bot %s took over pawn %s at X=%.3f Y=%.3f Z=%.3f"),
        *GetNameSafe(NewBot),
        *GetNameSafe(ExistingPawn),
        ExistingPawn->GetActorLocation().X,
        ExistingPawn->GetActorLocation().Y,
        ExistingPawn->GetActorLocation().Z);

    return NewBot;
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
    if (SkipNextRestart.Contains(NewPlayer))
    {
        SkipNextRestart.Remove(NewPlayer);
        UE_LOG(LogF13Mode, Log, TEXT("[RestartPlayer] Skipping due to bot replacement for %s"), *GetNameSafe(NewPlayer));
        return;
    }

    const bool bAlreadyHasPawn = NewPlayer && NewPlayer->GetPawn();
    UE_LOG(LogF13Mode, Log,
        TEXT("RestartPlayer → PawnIsNull=%s"),
        bAlreadyHasPawn ? TEXT("false") : TEXT("true"));

    // A) If this controller just replaced a bot it already owns a pawn.
    if (bAlreadyHasPawn)
    {
        if (AF13CharacterBase* Char = Cast<AF13CharacterBase>(NewPlayer->GetPawn()))
        {
            Char->LastHumanOwnerPS = NewPlayer->PlayerState;
            Char->LastHumanUniqueId = NewPlayer->PlayerState->GetUniqueId();

            if (AF13PlayerState* PS = Cast<AF13PlayerState>(NewPlayer->PlayerState))
            {
                TagPawnWithPlayer(Char, PS);
            }

            UE_LOG(LogF13Mode, Log,
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

        AF13PlayerState* PS = Cast<AF13PlayerState>(NewPlayer->PlayerState);
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

                if (AF13PlayerState* PS2 = Cast<AF13PlayerState>(NewPlayer->PlayerState))
                {
                    TagPawnWithPlayer(Final, PS2);
                }

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
                *GetNameSafe(Char),
                (Char->LastHumanUniqueId.IsValid()
                    ? *Char->LastHumanUniqueId->ToString()
                    : TEXT("None")));
        }
    }
}


void AF13Mode::Logout(AController* Exiting)
{
    if (!HasAuthority())
    {
        Super::Logout(Exiting);
        return;
    }

    UE_LOG(LogF13Mode, Log, TEXT("[Logout] %s leaving"), *GetNameSafe(Exiting));

    // Was this a human? If not, just do normal cleanup.
    const bool bWasHuman = Cast<APlayerController>(Exiting) != nullptr;
    AF13PlayerState* PS = Exiting ? Exiting->GetPlayerState<AF13PlayerState>() : nullptr;

    // Try to get the pawn they were using
    APawn* LeavingPawn = Exiting ? Exiting->GetPawn() : nullptr;

    // If the controller already unpossessed, find the pawn we tagged for this player.
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

    // If a human left and we found an unpossessed pawn, drop a bot controller onto it.
    if (bWasHuman && LeavingPawn && !LeavingPawn->IsPendingKillPending() && LeavingPawn->GetController() == nullptr)
    {
        // optional: stop any residual velocity so possession is clean
        if (ACharacter* C = Cast<ACharacter>(LeavingPawn))
        {
            if (UCharacterMovementComponent* Move = C->GetCharacterMovement())
            {
                Move->StopMovementImmediately();
            }
        }

        // Spawn a bot controller and possess the *existing* pawn.
        FActorSpawnParameters SP;
        SP.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        // If you have a specific bot controller class, use it here instead of AAIController::StaticClass()
        AAIController* NewBot = GetWorld()->SpawnActor<AAIController>(AAIController::StaticClass(),
            LeavingPawn->GetActorLocation(),
            LeavingPawn->GetActorRotation(),
            SP);
        if (NewBot)
        {
            NewBot->Possess(LeavingPawn);
            UE_LOG(LogF13Mode, Log, TEXT("[Logout] Bot took over pawn %s at %s"),
                *GetNameSafe(LeavingPawn), *LeavingPawn->GetActorLocation().ToCompactString());
        }
        else
        {
            UE_LOG(LogF13Mode, Warning, TEXT("[Logout] Failed to spawn bot controller; leaving pawn unpossessed"));
        }

        // Important: DO NOT spawn any new pawn here.
        Super::Logout(Exiting);
        return;
    }

    // If we reach here:
    //  - A bot left, OR
    //  - We couldn't find an unpossessed pawn to reuse.
    // Do **not** spawn a new pawn here; let your regular fill logic handle it later.
    if (bWasHuman && !LeavingPawn)
    {
        UE_LOG(LogF13Mode, Warning, TEXT("[Logout] No unpossessed pawn found for %s; skipping spawn on Logout"),
            *GetNameSafe(Exiting));
    }

    Super::Logout(Exiting);
}

void AF13Mode::TagPawnWithPlayer(APawn* Pawn, AF13PlayerState* PS)
{
    if (!Pawn || !PS) return;

    // Update character-side bookkeeping (you already use these)
    if (AF13CharacterBase* Char = Cast<AF13CharacterBase>(Pawn))
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

void AF13Mode::RememberLeavingPawn(AController* PC, APawn* Pawn, const FTransform& Xform, const FVector& Vel)
{
    if (!HasAuthority() || !PC || !Pawn) return;

    FPendingReplace Rec;
    Rec.Pawn = Pawn;
    Rec.Transform = Xform;
    Rec.Velocity = Vel;

    PendingReplacements.Add(PC, Rec);
}
