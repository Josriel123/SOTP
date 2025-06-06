#include "F13Mode.h"              // your GameMode header
#include "GameFramework/HUD.h" 
#include "F13PlayerController.h" 
#include "GameFramework/PlayerController.h"// because you set PlayerControllerClass
#include "F13PlayerState.h"       // because you set PlayerStateClass
#include "F13GameState.h"         // because you set GameStateClass
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"         // for SpawnActor, GetWorld()
#include "UObject/ConstructorHelpers.h"  // for FClassFinder<>


AF13Mode::AF13Mode()
{
    DefaultPawnClass = nullptr;
    PlayerControllerClass = AF13PlayerController::StaticClass();
    PlayerStateClass = AF13PlayerState::StaticClass();
    GameStateClass = AF13GameState::StaticClass();

    static ConstructorHelpers::FClassFinder<AHUD> HUD_BP_Class(
        TEXT("/Game/UI/BP_CharacterSelectionHUD.BP_CharacterSelectionHUD_C")
    );
    if (HUD_BP_Class.Succeeded())
    {
        HUDClass = HUD_BP_Class.Class;
    }
    else
    {
        UE_LOG(LogTemp, Warning,
            TEXT("Could NOT find HUD Blueprint at /Game/UI/BP_CharacterSelectionHUD"));
    }
}


void AF13Mode::BeginPlay()
{
    Super::BeginPlay();

    // Optional: if you want to catch PlayerStates as they spawn in World
    // (instead of waiting for each individual PlayerState to broadcast,
    //  you can do a ‘foreach’ existing or bind on new ones in PostLogin).
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

    // Get the pawn class they chose:
    TSubclassOf<APawn> PawnToSpawn = PS->GetChosenPawnClass();
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

    // Optionally: hide/disable the CharacterSelection UI – 
    //   you can broadcast a Widget‐event or have the PlayerController tell the UMG to remove itself.
}


void AF13Mode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    // Whenever a new player logs in, their PlayerState has just been created.
    AF13PlayerState* PS = Cast<AF13PlayerState>(NewPlayer->PlayerState);
    if (PS)
    {
        // Bind our HandleCharacterSelected function to that PlayerState’s delegate.
        PS->OnCharacterSelected.AddDynamic(this, &AF13Mode::HandleCharacterSelected);
    }

    // We could choose to spawn the selected Pawn immediately upon login,
    // but often we want to wait until the player has actually made their choice
    // via the UI widget. For now, let's assume the client will call some RPC
    // to the server (after choosing) that triggers SpawnChosenPawnForController().

    // (Alternatively, you could store a “HasChosenCharacter” bool in PlayerState,
    // and here you check: if (HasChosenCharacter) SpawnChosenPawnForController(NewPlayer).)
}

TSubclassOf<APawn> AF13Mode::GetPawnClassForController(AF13PlayerController* PC) const
{
    if (!PC) return nullptr;

    AF13PlayerState* PS = Cast<AF13PlayerState>(PC->PlayerState);
    if (!PS) return nullptr;

    return PS->GetChosenPawnClass();
}

void AF13Mode::SpawnChosenPawnForController(AF13PlayerController* PC)
{
    if (!PC) return;

    // If this player already has a pawn, skip:
    if (PC->GetPawn()) return;

    UWorld* World = GetWorld();
    if (!World) return;

    TSubclassOf<APawn> PawnClass = GetPawnClassForController(PC);
    if (!PawnClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("SpawnChosenPawnForController: PawnClass is null."));
        return;
    }

    // Determine a spawn location & rotation. For simplicity, we use the GameMode's
    // default spawn logic (FindPlayerStart & SpawnDefaultPawnFor):
    FTransform SpawnTransform;
    AActor* StartSpot = FindPlayerStart(PC);
    if (StartSpot)
    {
        SpawnTransform = StartSpot->GetActorTransform();
    }
    else
    {
        // If no PlayerStart is found, just spawn at origin:
        SpawnTransform = FTransform(FRotator::ZeroRotator, FVector::ZeroVector);
    }

    // Actually spawn the chosen Pawn.
    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = PC;
    APawn* NewPawn = World->SpawnActor<APawn>(
        PawnClass,
        SpawnTransform.GetLocation(),
        SpawnTransform.Rotator(),
        SpawnParams
    );
    if (NewPawn)
    {
        PC->Possess(NewPawn);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to Spawn Actor for PawnClass %s"),
            *PawnClass->GetName());
    }
}
