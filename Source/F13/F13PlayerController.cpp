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


