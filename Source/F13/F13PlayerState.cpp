#include "F13PlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/DataTable.h"
#include "CharacterOption.h"

AF13PlayerState::AF13PlayerState()
{
	// Do not force‐load the DataTable here. We will lazy‐load it in GetChosenPawnClass().
	CharacterOptionsTable = nullptr;

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
	ChosenRole = NewRole;
	ChosenCharacterKey = NewCharacterKey;

	UE_LOG(LogTemp, Log, TEXT(
		"PlayerState[%s] set to Role=%s, Key=%s"
	), *GetPlayerName(), *ChosenRole, *ChosenCharacterKey.ToString());
}

#if !UE_BUILD_SHIPPING
bool AF13PlayerState::ServerSetCharacterSelection_Validate(
	const FString& NewRole,
	const FName& NewCharacterKey
)
{
	// Here you could validate that NewRole is either “Killer” or “Survivor”,
	// and that NewCharacterKey actually exists in your DataTable (if already loaded).
	// For now, we just allow all incoming values.
	return true;
}
#endif

TSubclassOf<APawn> AF13PlayerState::GetChosenPawnClass() const
{
	// If we haven't loaded the DataTable yet, do so now (lazy‐load).
	// Only the server should attempt to load it, since the DataTable asset lives
	// on the content side. Clients can rely on the replicated ChosenCharacterKey
	// and server‐validated lookup results.
	if (CharacterOptionsTable == nullptr)
	{
		if (GetLocalRole() == ROLE_Authority)
		{
			static ConstructorHelpers::FObjectFinder<UDataTable> DT_Obj(
				TEXT("/Game/Character/Data/DT_CharacterOptions.DT_CharacterOptions")
			);
			if (DT_Obj.Succeeded())
			{
				CharacterOptionsTable = DT_Obj.Object;
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT(
					"GetChosenPawnClass: Failed to find DataTable at path /Game/Character/Data/DT_CharacterOptions"
				));
				return nullptr;
			}
		}
		else
		{
			// Clients just bail out; they only need to wait until server has already loaded the DT
			return nullptr;
		}
	}

	// At this point, CharacterOptionsTable is valid (on server).
	static const FString ContextString(TEXT("GetChosenPawnClass"));
	FCharacterOption* Row = CharacterOptionsTable->FindRow<FCharacterOption>(
		ChosenCharacterKey, ContextString
	);

	if (Row != nullptr)
	{
		return Row->PawnClass;
	}

	// Only the server logs this missing‐row warning once; clients skip it.
	if (GetLocalRole() == ROLE_Authority)
	{
		UE_LOG(LogTemp, Warning, TEXT(
			"GetChosenPawnClass: no row with key '%s' in DataTable"
		), *ChosenCharacterKey.ToString());
	}
	return nullptr;
}
