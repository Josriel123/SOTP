#pragma once

#include "GameFramework/GameSession.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "F13GameSession.generated.h"

/** Custom GameSession that skips duplicate bot registration after
    host-migration and logs Public / Registered counts. */
UCLASS()
class AF13GameSession : public AGameSession
{
    GENERATED_BODY()

public:
    virtual void RegisterPlayer(APlayerController* PC,
        const FUniqueNetIdRepl& UniqueId,
        bool bWasFromInvite) override;
};
