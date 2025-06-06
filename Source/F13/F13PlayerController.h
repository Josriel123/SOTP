#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "F13PlayerController.generated.h"

class AF13PlayerState;

/**
 * PlayerController responsible for receiving character‐selection clicks from UI
 * and forwarding them to the server‐side PlayerState RPC.
 */
UCLASS()
class F13_API AF13PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AF13PlayerController();

	/**
	 * Called by the UI (Blueprint) when the player clicks on a character option.
	 * Forwards to the PlayerState server RPC.
	 */
	UFUNCTION(BlueprintCallable, Category = "CharacterSelection")
	void ClientClickedSelectOption(const FString& ChosenRole, const FName& ChosenKey);

protected:
	/** Override to cache our typed PlayerState. */
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* aPawn) override;


private:
	/** Cached pointer to our PlayerState, cast to AF13PlayerState. */
	UPROPERTY()
	AF13PlayerState* F13PlayerStateCached;
};
