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
// In F13PlayerController.cpp

bool AF13PlayerController::ServerSelectPawnClass_Validate(TSubclassOf<APawn> PawnClass)
{
	// Here you can sanity-check the class (e.g., is it in your approved DataTable?)
	return true;  // return false if you want to reject the request
}

void AF13PlayerController::ServerSelectPawnClass_Implementation(TSubclassOf<APawn> PawnClass)
{
	// This code runs on the server!
	if (AF13PlayerState* PS = GetPlayerState<AF13PlayerState>())
	{
		// Store the choice in the replicated PlayerState
		PS->SelectedPawnClass = PawnClass;
	}
}

void AF13PlayerController::ServerSetReady_Implementation(bool bNewReady)
{
	if (AF13PlayerState* PS = GetPlayerState<AF13PlayerState>())
	{
		if (PS->IsReady() != bNewReady)
		{
			PS->SetReady(bNewReady);   // write a simple setter that sets bIsReady and calls OnRep_IsReady on server
		}
	}
}

bool AF13PlayerController::ServerSetReady_Validate(bool /*bNewReady*/)
{
	return true;    // add extra checks if needed
}



