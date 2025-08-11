#pragma once

#include "CoreMinimal.h"
#include "HMS_PlayerController.h"
#include "F13PlayerProfileSave.h"
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

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
	void ServerSetReady(bool bNewReady);

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
	void ServerSetCharacterPreference(FName RowKey, const FString& InRole);   // Role = "Killer" or "Survivor"

	UFUNCTION(Client, Reliable)
	void Client_SaveLocalProfile(const FPlayerProfileData& InProfile);

private:
	FTimerHandle ReconnectAddrTimer;

protected:
	/** Override to cache our typed PlayerState. */
	virtual void BeginPlay() override;
	virtual void PawnLeavingGame() override;
	virtual FString HMS_GetReconnectNetAddress_Implementation() override;
};
