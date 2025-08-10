#include "F13PlayerController.h"
#include "F13PlayerState.h"
#include "F13GameInstance.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Engine/World.h"
#include "Engine/NetDriver.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerState.h"

AF13PlayerController::AF13PlayerController()
{
}

void AF13PlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController())
	{
		if (UF13GameInstance* GI = GetGameInstance<UF13GameInstance>())
		{
			FPlayerProfileData Profile;
			if (GI->LoadLocalProfile(Profile))
			{
				// Adjust to your RPC signature
				ServerSetCharacterPreference(Profile.SurvivorRowKey, TEXT("Survivor"));
				ServerSetCharacterPreference(Profile.KillerRowKey, TEXT("Killer"));
			}
		}
	}

	if (IsLocalController() && GetNetMode() == NM_Client)
	{
		GetWorldTimerManager().SetTimer(ReconnectAddrTimer, [this]()
			{
				if (NetConnection && NetConnection->IsNetReady(false))
				{
					HMS_SetMyReconnectAddressForTheServer(HMS_GetReconnectNetAddress());
					GetWorldTimerManager().ClearTimer(ReconnectAddrTimer);
				}
			}, 0.2f, true);
	}
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
		Client_SaveLocalProfile(P);
	}
}

void AF13PlayerController::Client_SaveLocalProfile_Implementation(const FPlayerProfileData& InProfile)
{
	if (UF13GameInstance* GI = GetGameInstance<UF13GameInstance>())
	{
		GI->SaveLocalProfile(InProfile); // now saves on the player machine
	}
}

FString AF13PlayerController::HMS_GetReconnectNetAddress_Implementation()
{
	bool bCanBind = false;
	TSharedRef<FInternetAddr> LocalAddr =
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, bCanBind);

	// Return IP only; we’ll add the port in the GameInstance BP
	return LocalAddr->ToString(/*bUseIPv6=*/false);
}

