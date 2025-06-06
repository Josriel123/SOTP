#include "F13PlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/DataTable.h"
#include "CharacterOption.h"         // Your row struct type
#include "GameFramework/PlayerController.h"

AF13PlayerState::AF13PlayerState()
{
	// Start with no DataTable loaded.
	CharacterOptionsTable = nullptr;

	// Only the server (ROLE_Authority) should load the DataTable once in the constructor.
	if (HasAuthority())
	{
		static ConstructorHelpers::FObjectFinder<UDataTable> DT_Finder(
			TEXT("/Game/Characters/Data/DT_CharacterOptions.DT_CharacterOptions")
		);
		if (DT_Finder.Succeeded())
		{
			CharacterOptionsTable = DT_Finder.Object;
		}
		else
		{
			UE_LOG(LogTemp, Error,
				TEXT("AF13PlayerState ctor: Failed to find DataTable '/Game/Characters/Data/DT_CharacterOptions'"));
		}
	}

	// Initialize replicated fields to defaults.
	ChosenRole = TEXT("");
	ChosenCharacterKey = NAME_None;
}

void AF13PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AF13PlayerState, ChosenRole);
	DOREPLIFETIME(AF13PlayerState, ChosenCharacterKey);
}

void AF13PlayerState::ServerSetCharacterSelection_Implementation(
	const FString& NewRole,
	const FName& NewCharacterKey
)
{
	// Cache the new values on the server
	ChosenRole = NewRole;
	ChosenCharacterKey = NewCharacterKey;

	UE_LOG(LogTemp, Log, TEXT(
		"AF13PlayerState::ServerSetCharacterSelection: PlayerState[%s] → Role=%s, Key=%s"
	),
		*GetPlayerName(),
		*ChosenRole,
		*ChosenCharacterKey.ToString()
	);

	// Notify any listeners (GameMode will bind to this) to spawn the chosen Pawn right away.
	if (APlayerController* OwningPC = Cast<APlayerController>(GetOwner()))
	{
		OnCharacterSelected.Broadcast(OwningPC);
	}
}

bool AF13PlayerState::ServerSetCharacterSelection_Validate(
	const FString& NewRole,
	const FName& NewCharacterKey
)
{
	// In non–shipping builds you could verify NewRole is “Killer” or “Survivor”
	// and NewCharacterKey actually exists in the DataTable. For now, allow all.
	return true;
}

TSubclassOf<APawn> AF13PlayerState::GetChosenPawnClass() const
{
	// Only the server cares about returning a valid UClass.
	// If we’re a client, just return null.
	if (GetLocalRole() != ROLE_Authority)
	{
		return nullptr;
	}

	// If the DataTable failed to load in the ctor, warn & bail.
	if (CharacterOptionsTable == nullptr)
	{
		UE_LOG(LogTemp, Error,
			TEXT("GetChosenPawnClass: CharacterOptionsTable is nullptr!"));
		return nullptr;
	}

	// Look up the row by the replicated key.
	static const FString Context(TEXT("GetChosenPawnClass"));
	const FCharacterOption* Row = CharacterOptionsTable->FindRow<FCharacterOption>(
		ChosenCharacterKey, Context
	);

	if (Row == nullptr)
	{
		UE_LOG(LogTemp, Warning,
			TEXT("GetChosenPawnClass: No row found for key '%s' in DT_CharacterOptions"),
			*ChosenCharacterKey.ToString()
		);
		return nullptr;
	}

	return Row->PawnClass;
}
