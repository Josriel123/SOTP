#include "F13PlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"
#include "OnlineSubsystemUtils.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/DataTable.h"
#include "CharacterOption.h" 
#include "Misc/Guid.h"
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
	bIsReady = false;
}

void AF13PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AF13PlayerState, bIsReady);
	DOREPLIFETIME(AF13PlayerState, ChosenRole);
	DOREPLIFETIME(AF13PlayerState, SelectedPawnClass);
	DOREPLIFETIME(AF13PlayerState, bIsBot);
	DOREPLIFETIME(AF13PlayerState, SurvivorRowKey);
	DOREPLIFETIME(AF13PlayerState, KillerRowKey);
}


TSubclassOf<APawn> AF13PlayerState::GetChosenPawnClassForRole(const FString& InRole) const
{
	// Only the server should do the DataTable lookup
	if (GetLocalRole() != ROLE_Authority)
		return nullptr;

	if (!CharacterOptionsTable)
	{
		UE_LOG(LogTemp, Error,
			TEXT("GetPawnClassForRole: CharacterOptionsTable is nullptr!"));
		return nullptr;
	}

	/* Pick the correct row key based on the requested role */
	const FName Key = (InRole == TEXT("Killer")) ? KillerRowKey : SurvivorRowKey;

	static const FString Ctx(TEXT("GetPawnClassForRole"));
	const FCharacterOption* Row = CharacterOptionsTable->FindRow<FCharacterOption>(Key, Ctx);

	if (!Row)
	{
		UE_LOG(LogTemp, Warning,
			TEXT("GetPawnClassForRole: No row found for key '%s' (role %s)"),
			*Key.ToString(), *InRole);
		return nullptr;
	}

	return Row->PawnClass;
}

void AF13PlayerState::SetReady(bool bNewReady)
{
	if (bIsReady == bNewReady) return;     // no change

	bIsReady = bNewReady;
	OnRep_IsReady();                       // update server immediately
}


void AF13PlayerState::OnRep_IsReady()
{
	OnReadyChanged.Broadcast(this, bIsReady);

	UE_LOG(LogTemp, Log, TEXT("PlayerState[%s] Ready = %s (OnRep)"),
		*GetPlayerName(), bIsReady ? TEXT("TRUE") : TEXT("FALSE"));
}

void AF13PlayerState::EnsureUniqueIdForBot()
{
	if (!bIsBot || GetUniqueId().IsValid())
	{
		return;
	}

	const FString FakeId = FString::Printf(TEXT("Bot-%08X"), FMath::Rand());

	FUniqueNetIdStringRef NewId =
		FUniqueNetIdString::Create(FakeId, TEXT("BOT"));

	SetUniqueId(FUniqueNetIdRepl(FUniqueNetIdRef(NewId)));
}

void AF13PlayerState::CopyProperties(APlayerState* NewPlayerState)
{
	Super::CopyProperties(NewPlayerState);

	if (AF13PlayerState* NewPS = Cast<AF13PlayerState>(NewPlayerState))
	{
		NewPS->SurvivorRowKey = SurvivorRowKey;
		NewPS->KillerRowKey = KillerRowKey;
		NewPS->ChosenRole = ChosenRole;
		NewPS->SelectedPawnClass = SelectedPawnClass;
	}
}