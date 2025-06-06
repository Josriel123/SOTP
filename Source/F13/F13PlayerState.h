#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "F13PlayerState.generated.h"

// Forward‐declare
class UDataTable;
class APawn;
class APlayerController;

// Delegate signature: when the server accepts a character choice,
// broadcast to anyone (e.g. GameMode) so they can spawn the Pawn.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnCharacterSelectedSignature,
	APlayerController*, SelectingPC
);

/**
 *  Custom PlayerState: stores Role + DataTable row key,
 *  and publishes an event when the server “locks in” the character choice.
 */
UCLASS()
class F13_API AF13PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AF13PlayerState();

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
	 *  broadcasts OnCharacterSelected so that GameMode (or whoever) can react.
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

private:
	/**
	 *  Cached pointer to our Character‐options DataTable.
	 *  We load it once in the constructor (server only).
	 *  After that, any call to FindRow<…>() is very cheap at runtime.
	 */
	UPROPERTY()
	UDataTable* CharacterOptionsTable;
};
