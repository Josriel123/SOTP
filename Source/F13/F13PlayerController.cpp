#include "F13PlayerController.h"
#include "F13PlayerState.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerState.h"

AF13PlayerController::AF13PlayerController()
	: F13PlayerStateCached(nullptr)
{
	// We can set any default parameters for the PlayerController here if needed.
	// For now, nothing special is required.
}

void AF13PlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Cache our custom PlayerState once on BeginPlay.
	// We know that when a client possesses a Pawn, its PlayerState will be AF13PlayerState.
	if (APlayerState* PS = GetPlayerState<APlayerState>())
	{
		F13PlayerStateCached = Cast<AF13PlayerState>(PS);
	}

}

void AF13PlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	// 1) Hide the OS cursor so you never have to hold any button.
	bShowMouseCursor = false;

	// 2) Force GameOnly input mode. That tells UE: “Lock mouse to viewport & send all
	//    Mouse X/Y deltas directly to Enhanced Input.” 
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);

	// Now, at this point, raw mouse movement will fire IA_Look every frame,
	// without any Left- or Right-Click.
}

void AF13PlayerController::ClientClickedSelectOption(const FString& ChosenRole, const FName& ChosenKey)
{
	// Only forward to server if we have a valid cached PlayerState
	if (F13PlayerStateCached && HasAuthority() == false)
	{
		// Invoke the server RPC. If we somehow already have authority, skip it because the GameMode
		// will pick up our replicated values immediately.
		F13PlayerStateCached->ServerSetCharacterSelection(ChosenRole, ChosenKey);
	}
}
