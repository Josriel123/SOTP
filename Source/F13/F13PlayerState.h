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

	/**
	 *  The “role” string the player chose (e.g. “Killer” or “Survivor”).
	 */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "CharacterSelection")
	FString ChosenRole;

	/**
	 *  The DataTable row name/key for the character this player picked.
	 */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "CharacterSelection")
	FName ChosenCharacterKey;

	/**
	 *  Called on the client when the player picks something in the UI.
	 *  This RPC is executed on the server, which caches the new values and
	 *  broadcasts OnCharacterSelected so that GameM6ode (or whoever) can react.
	 */
	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "CharacterSelection")
	void ServerSetCharacterSelection(const FString& NewRole, const FName& NewCharacterKey);

	/**
	 *  Given the already‐loaded DataTable and the replicated RowKey,
	 *  return the Pawn subclass that corresponds to ChosenCharacterKey.
	 *  Only valid on the server; clients will simply get nullptr.
	 */
	UFUNCTION(BlueprintCallable, Category = "CharacterSelection")
	TSubclassOf<APawn> GetChosenPawnClass() const;

	/**
	 *  Fired on the server once ServerSetCharacterSelection is accepted.  Passes
	 *  the APlayerController* that owns this PlayerState as the single argument.
	 *  GameMode can bind to this event and then call SpawnChosenPawnForController(SelectingPC).
	 */
	UPROPERTY(BlueprintAssignable, Category = "CharacterSelection")
	FOnCharacterSelectedSignature OnCharacterSelected;

protected:
	// Make sure ChosenRole and ChosenCharacterKey replicate.
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION() void OnRep_IsReady();

private:

	UPROPERTY()
	UDataTable* CharacterOptionsTable;

	UPROPERTY(ReplicatedUsing = OnRep_IsReady) bool bIsReady = false;
};
