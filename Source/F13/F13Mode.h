#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "F13Mode.generated.h"

class AF13PlayerController;
class AF13PlayerState;
class AF13GameState;

UCLASS()
class F13_API AF13Mode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AF13Mode();

	// This is the function that actually spawns the pawn for a given PlayerController
	UFUNCTION()
	void HandleCharacterSelected(APlayerController* SelectingPC);

	// When a new player has fully connected, this function is called.
	virtual void PostLogin(APlayerController* NewPlayer) override;

	// (Optionally) when the match officially “starts,” you could override 
	// StartPlay() or BeginPlay() to check if everyone has chosen and then spawn.

protected:

	virtual void BeginPlay() override;

};