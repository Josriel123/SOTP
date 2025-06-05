#include "F13Mode.h"              // your GameMode header
#include "F13PlayerController.h"  // because you set PlayerControllerClass
#include "F13PlayerState.h"       // because you set PlayerStateClass
#include "F13GameState.h"         // because you set GameStateClass

#include "Engine/World.h"         // for SpawnActor, GetWorld()
#include "UObject/ConstructorHelpers.h"  // for FClassFinder<>


AF13Mode::AF13Mode()
{
    DefaultPawnClass = nullptr;
    PlayerControllerClass = AF13PlayerController::StaticClass();
    PlayerStateClass = AF13PlayerState::StaticClass();
    GameStateClass = AF13GameState::StaticClass();
}

void AF13Mode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    // We could choose to spawn the selected Pawn immediately upon login,
    // but often we want to wait until the player has actually made their choice
    // via the UI widget. For now, let's assume the client will call some RPC
    // to the server (after choosing) that triggers SpawnChosenPawnForController().

    // (Alternatively, you could store a “HasChosenCharacter” bool in PlayerState,
    // and here you check: if (HasChosenCharacter) SpawnChosenPawnForController(NewPlayer).)
}

TSubclassOf<APawn> AF13Mode::GetPawnClassForController(APlayerController* PC) const
{
    if (!PC) return nullptr;

    AF13PlayerState* PS = Cast<AF13PlayerState>(PC->PlayerState);
    if (!PS) return nullptr;

    return PS->GetChosenPawnClass();
}

void AF13Mode::SpawnChosenPawnForController(APlayerController* PC)
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
