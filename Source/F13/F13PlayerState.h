#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "F13PlayerState.generated.h"

// Forward declarations
class UDataTable;

/**
 * Our custom PlayerState, stores role/character choices.
 */
UCLASS()
class F13_API AF13PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AF13PlayerState();

	/** The role this player chose: “Killer” or “Survivor” */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "CharacterSelection")
	FString ChosenRole;

	/** The DataTable RowName (key) for the character they picked. */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "CharacterSelection")
	FName ChosenCharacterKey;

	/** Set both fields on the server (called via RPC). */
	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "CharacterSelection")
	void ServerSetCharacterSelection(const FString& NewRole, const FName& NewCharacterKey);

	/** Returns the actual Pawn class (looks up the DataTable row by ChosenCharacterKey). */
	UFUNCTION(BlueprintCallable, Category = "CharacterSelection")
	TSubclassOf<APawn> GetChosenPawnClass() const;

protected:
	// Always call this so the replication system knows to replicate our new vars:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	// Cached pointer to our DataTable. We will lazy‐load it the first time GetChosenPawnClass() is called.
	UPROPERTY()
	mutable UDataTable* CharacterOptionsTable;
};
