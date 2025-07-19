#include "F13PlayerController.h"
#include "F13PlayerState.h"
#include "F13GameInstance.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerState.h"

AF13PlayerController::AF13PlayerController()
{
}

void AF13PlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AF13PlayerController::ServerSetReady_Implementation(bool bNewReady)
{
	if (AF13PlayerState* PS = GetPlayerState<AF13PlayerState>())
	{
		if (PS->IsReady() != bNewReady)
		{
			PS->SetReady(bNewReady);   // write a simple setter that sets bIsReady and calls OnRep_IsReady on server
		}
	}
}

bool AF13PlayerController::ServerSetReady_Validate(bool /*bNewReady*/)
{
	return true;    // add extra checks if needed
}


bool AF13PlayerController::ServerSetCharacterPreference_Validate(
	FName, const FString&) {
	return true;
}

void AF13PlayerController::ServerSetCharacterPreference_Implementation(
	FName RowKey, const FString& InRole)
{
	AF13PlayerState* PS = GetPlayerState<AF13PlayerState>();
	if (PS)
	{
		if (InRole == TEXT("Killer"))
			PS->KillerRowKey = RowKey;
		else
			PS->SurvivorRowKey = RowKey;
	}

	if (UF13GameInstance* GI = GetGameInstance<UF13GameInstance>())
	{
		FPlayerProfileData P;
		P.SurvivorRowKey = PS ? PS->SurvivorRowKey : RowKey;
		P.KillerRowKey = PS ? PS->KillerRowKey : RowKey;
		GI->SaveLocalProfile(P);
	}
}


