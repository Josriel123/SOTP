#include "F13GameSession.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "OnlineSubsystem.h"
#include "GameFramework/PlayerState.h"

void AF13GameSession::RegisterPlayer(APlayerController* PC,
    const FUniqueNetIdRepl& UniqueId,
    bool bWasFromInvite)
{
    if (PC && PC->PlayerState && PC->PlayerState->IsABot())
    {
        // Skip adding bots to RegisteredPlayers
        return;
    }
    // Call parent FIRST – it updates the RegisteredPlayers array.
    Super::RegisterPlayer(PC, UniqueId, bWasFromInvite);

    // Now log / sanity-check
    IOnlineSubsystem* OSS = IOnlineSubsystem::Get();
    IOnlineSessionPtr SessionInt = OSS ? OSS->GetSessionInterface() : nullptr;

    if (SessionInt.IsValid())
    {
        if (const FNamedOnlineSession* Session =
            SessionInt->GetNamedSession(NAME_GameSession))
        {
            UE_LOG(LogTemp, Warning,
                TEXT("RegisterPlayer → Public=%d  Registered=%d  (%s)"),
                Session->SessionSettings.NumPublicConnections,
                Session->RegisteredPlayers.Num(),
                (PC && PC->PlayerState) ? *PC->PlayerState->GetPlayerName()
                : TEXT("Unknown"));
        }
    }
}
