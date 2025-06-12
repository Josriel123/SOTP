#pragma once

#include "CoreMinimal.h"
#include "HMS_PlayerController.h"
#include "GameFramework/PlayerController.h"
#include "F13PlayerController.generated.h"

class AF13PlayerState;

/**
 * PlayerController responsible for receiving character‐selection clicks from UI
 * and forwarding them to the server‐side PlayerState RPC.
 */
UCLASS()
class F13_API AF13PlayerController : public AHMS_PlayerController
{
	GENERATED_BODY()

public:
	AF13PlayerController();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSelectPawnClass(TSubclassOf<APawn> PawnClass);

protected:
	/** Override to cache our typed PlayerState. */
	virtual void BeginPlay() override;


private:
	/** Cached pointer to our PlayerState, cast to AF13PlayerState. */
	UPROPERTY()
	AF13PlayerState* F13PlayerStateCached;
};
