#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PantheonPlayerState.generated.h"

// Forward-declare
class UDataTable;
class APawn;
class APlayerController;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnCharacterSelectedSignature,
	APlayerController*, SelectingPC
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnReadyChanged, 
	APantheonPlayerState*, PlayerState, bool, bNowReady
);


UCLASS()
class F13_API APantheonPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	APantheonPlayerState();

	void EnsureUniqueIdForBot();

	/* --------------------  READY  -------------------- */
	/** Current ready state (replicated). */
	UFUNCTION(BlueprintPure, Category = "Lobby") bool IsReady() const { return bIsReady; }

	/** Call from UI to toggle ready. */
	UFUNCTION(BlueprintCallable, Category = "Lobby")
	void SetReady(bool bNewReady);

	/** Fired on both server & clients whenever ready changes. */
	UPROPERTY(BlueprintAssignable, Category = "Lobby")
	FOnReadyChanged OnReadyChanged;

	UPROPERTY(Replicated)
	TSubclassOf<APawn> SelectedPawnClass;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "CharacterSelection")
	FString ChosenRole;

	UFUNCTION(BlueprintCallable, Category = "CharacterSelection")
	TSubclassOf<APawn> GetChosenPawnClassForRole(const FString& InRole) const;

	UPROPERTY(BlueprintAssignable, Category = "CharacterSelection")
	FOnCharacterSelectedSignature OnCharacterSelected;

	UPROPERTY(Replicated, BlueprintReadOnly) bool bIsBot = false;

	UPROPERTY(Replicated) FName SurvivorRowKey;

	UPROPERTY(Replicated) FName KillerRowKey;

	virtual void CopyProperties(APlayerState* NewPlayerState) override;

protected:
	// Make sure ChosenRole and ChosenCharacterKey replicate.
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION() void OnRep_IsReady();

private:

	UPROPERTY()
	UDataTable* CharacterOptionsTable;

	UPROPERTY(ReplicatedUsing = OnRep_IsReady) bool bIsReady = false;

	
};
