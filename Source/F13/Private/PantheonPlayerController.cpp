#include "PantheonPlayerController.h"
#include "PantheonPlayerState.h"
#include "PantheonGameInstance.h"
#include "PantheonGameMode.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Engine/World.h"
#include "Engine/NetDriver.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


APantheonPlayerController::APantheonPlayerController()
{
}

void APantheonPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController())
	{
		if (UPantheonGameInstance* GI = GetGameInstance<UPantheonGameInstance>())
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

void APantheonPlayerController::ServerSetReady_Implementation(bool bNewReady)
{
	if (APantheonPlayerState* PS = GetPlayerState<APantheonPlayerState>())
	{
		if (PS->IsReady() != bNewReady)
		{
			PS->SetReady(bNewReady);   // write a simple setter that sets bIsReady and calls OnRep_IsReady on server
		}
	}
}

bool APantheonPlayerController::ServerSetReady_Validate(bool /*bNewReady*/)
{
	return true;    // add extra checks if needed
}


bool APantheonPlayerController::ServerSetCharacterPreference_Validate(
	FName, const FString&) {
	return true;
}

void APantheonPlayerController::ServerSetCharacterPreference_Implementation(
	FName RowKey, const FString& InRole)
{
	APantheonPlayerState* PS = GetPlayerState<APantheonPlayerState>();
	if (PS)
	{
		if (InRole == TEXT("Killer"))
			PS->KillerRowKey = RowKey;
		else
			PS->SurvivorRowKey = RowKey;
	}

	if (UPantheonGameInstance* GI = GetGameInstance<UPantheonGameInstance>())
	{
		FPlayerProfileData P;
		P.SurvivorRowKey = PS ? PS->SurvivorRowKey : RowKey;
		P.KillerRowKey = PS ? PS->KillerRowKey : RowKey;
		Client_SaveLocalProfile(P);
	}
}

void APantheonPlayerController::Client_SaveLocalProfile_Implementation(const FPlayerProfileData& InProfile)
{
	if (UPantheonGameInstance* GI = GetGameInstance<UPantheonGameInstance>())
	{
		GI->SaveLocalProfile(InProfile); // now saves on the player machine
	}
}

FString APantheonPlayerController::HMS_GetReconnectNetAddress_Implementation()
{
	bool bCanBind = false;
	TSharedRef<FInternetAddr> LocalAddr =
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, bCanBind);

	// Return IP only; we’ll add the port in the GameInstance BP
	return LocalAddr->ToString(/*bUseIPv6=*/false);
}

void APantheonPlayerController::PawnLeavingGame()
{
	// Server only
	if (GetLocalRole() == ROLE_Authority)
	{
		APawn* P = GetPawn();
		if (P)
		{
			const FTransform Tf = P->GetActorTransform();

			// optional: capture current velocity for a smoother hand-off
			FVector Vel = FVector::ZeroVector;
			if (const ACharacter* C = Cast<ACharacter>(P))
			{
				if (const UCharacterMovementComponent* Move = C->GetCharacterMovement())
				{
					Vel = Move->Velocity;
				}
			}

			if (APantheonGameMode* GM = GetWorld()->GetAuthGameMode<APantheonGameMode>())
			{
				// You already have this helper in your GameMode; if yours only takes (PC,Pawn,Transform),
				// just drop "Vel" from the call and store only the transform.
				GM->RememberLeavingPawn(this, P, Tf /*, Vel */);
			}

			// Keep the pawn alive: unpossess but DON'T call Super (it destroys the pawn)
			UnPossess();

			// Make sure the actor stays around & replicating
			P->SetReplicates(true);
			P->SetAutonomousProxy(false);
		}
	}

	// Intentionally do NOT call Super::PawnLeavingGame();
	// Super destroys the pawn by default, which is exactly what we want to avoid. :contentReference[oaicite:1]{index=1}
}