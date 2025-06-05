#include "F13PlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/DataTable.h"
#include "CharacterOption.h"         // The struct type used by our DataTable
#include "GameFramework/PlayerController.h"

AF13PlayerState::AF13PlayerState()
{
	// By default, we start with no DataTable loaded.
	CharacterOptionsTable = nullptr;

	// Server‐only: load the DataTable asset exactly once (during construction).
	// Clients will ignore this (the if‐block below only runs when we are the server/authority).
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
			CharacterOptionsTable = nullptr;
		}
	}

	// Initialize replicated properties
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
	// Cache the values on the server
	ChosenRole = NewRole;
	ChosenCharacterKey = NewCharacterKey;

	UE_LOG(LogTemp, Log, TEXT(
		"AF13PlayerState::ServerSetCharacterSelection: PlayerState[%s] → Role=%s, Key=%s"
	),
		*GetPlayerName(),
		*ChosenRole,
		*ChosenCharacterKey.ToString()
	);

	// Broadcast to any listeners (e.g. GameMode) so they can immediately spawn the chosen Pawn.
	APlayerController* OwningPC = Cast<APlayerController>(GetOwner());
	if (OwningPC)
	{
		OnCharacterSelected.Broadcast(OwningPC);
	}
}

bool AF13PlayerState::ServerSetCharacterSelection_Validate(
	const FString& NewRole,
	const FName& NewCharacterKey
)
{
#if !UE_BUILD_SHIPPING
	// In non‐shipping builds you could validate that NewRole matches either "Killer" or "Survivor",
	// and that NewCharacterKey is a valid row in the DataTable (if already loaded).
	// For now, just allow everything through.
	return true;
#else
	return true;
#endif
}

TSubclassOf<APawn> AF13PlayerState::GetChosenPawnClass() const
{
	// Only the server cares about returning a valid UClass.  If we are a client, just bail out.
	if (GetLocalRole() != ROLE_Authority)
	{
		return nullptr;
	}

	// Make sure the DataTable was successfully loaded in the constructor.
	if (CharacterOptionsTable == nullptr)
	{
		UE_LOG(LogTemp, Error,
			TEXT("GetChosenPawnClass: CharacterOptionsTable is nullptr!  Was loading in ctor successful?"));
		return nullptr;
	}

	// Lookup the row by the replicated key
	static const FString Context(TEXT("GetChosenPawnClass"));
	FCharacterOption* Row = CharacterOptionsTable->FindRow<FCharacterOption>(
		ChosenCharacterKey, Context
	);

	if (Row == nullptr)
	{
		UE_LOG(
			LogTemp, Warning,
			TEXT("GetChosenPawnClass: No row found for key '%s' in DT_CharacterOptions"),
			*ChosenCharacterKey.ToString()
		);
		return nullptr;
	}

	return Row->PawnClass;
}
