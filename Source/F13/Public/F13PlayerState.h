#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "F13PlayerState.generated.h"

// Forward‐declare
class UDataTable;
class APawn;
class APlayerController;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnCharacterSelectedSignature,
	APlayerController*, SelectingPC
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnReadyChanged, 
	AF13PlayerState*, PlayerState, bool, bNowReady
);


UCLASS()
class F13_API AF13PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AF13PlayerState();

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

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "CharacterSelection")
	FName ChosenCharacterKey;

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "CharacterSelection")
	void ServerSetCharacterSelection(const FString& NewRole, const FName& NewCharacterKey);

	UFUNCTION(BlueprintCallable, Category = "CharacterSelection")
	TSubclassOf<APawn> GetChosenPawnClass() const;

	UPROPERTY(BlueprintAssignable, Category = "CharacterSelection")
	FOnCharacterSelectedSignature OnCharacterSelected;

	UPROPERTY(Replicated, BlueprintReadOnly) bool bIsBot = false;

protected:
	// Make sure ChosenRole and ChosenCharacterKey replicate.
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION() void OnRep_IsReady();

private:

	UPROPERTY()
	UDataTable* CharacterOptionsTable;

	UPROPERTY(ReplicatedUsing = OnRep_IsReady) bool bIsReady = false;

	
};
