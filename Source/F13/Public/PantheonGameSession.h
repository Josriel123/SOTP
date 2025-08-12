#pragma once

#include "GameFramework/GameSession.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "PantheonGameSession.generated.h"

/** Custom GameSession that skips duplicate bot registration after
    host-migration and logs Public / Registered counts. */
UCLASS()
class APantheonGameSession : public AGameSession
{
    GENERATED_BODY()

public:
    virtual void RegisterPlayer(APlayerController* PC,
        const FUniqueNetIdRepl& UniqueId,
        bool bWasFromInvite) override;
};
