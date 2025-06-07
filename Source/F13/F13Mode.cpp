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

    UE_LOG(LogTemp, Log, TEXT(
        "HandleCharacterSelected: Spawning pawn for %s (Role=%s, Key=%s)"
    ),
        *PS->GetPlayerName(),
        *PS->ChosenRole,
        *PS->ChosenCharacterKey.ToString()
    );

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

