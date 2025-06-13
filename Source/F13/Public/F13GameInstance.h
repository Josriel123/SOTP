// F13GameInstance.h
#pragma once

#include "CoreMinimal.h"
#include "HMS_GameInstance.h" 
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "F13GameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FOnSessionJoined,   // name of the new delegate type
    bool,               // type of the single parameter
    bWasSuccessful      // name of the parameter in callbacks
);


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FOnSessionCreated,   // name of the new delegate type
    bool,               // type of the single parameter
    bWasSuccessful      // name of the parameter in callbacks
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FOnSessionListReady,
    const TArray<FString>&,
    FoundNames
);

UCLASS()
class F13_API UF13GameInstance : public UHMS_GameInstance
{
    GENERATED_BODY()

public:
    UF13GameInstance();
    virtual void Init() override;

    /* ---------- public Blueprint-callable helpers (already present) ---------- */
    UFUNCTION(BlueprintCallable, Category = "Session") void HostSession(bool bIsLAN, int32 MaxPlayers, const FString& DisplayName);
    UFUNCTION(BlueprintCallable, Category = "Session") void FindSessions(bool bIsLAN);
    UFUNCTION(BlueprintCallable, Category = "Session") void JoinFoundSession(int32 SessionIndex);
    UFUNCTION(BlueprintCallable, Category = "Session") TArray<FString> GetFoundSessionNames() const;
    UFUNCTION(BlueprintCallable, Category = "Session") void StartGameSession();

    /* ---------- Blueprint delegates (already present) ---------- */
    UPROPERTY(BlueprintAssignable, Category = "Session") FOnSessionCreated   OnSessionCreated;
    UPROPERTY(BlueprintAssignable, Category = "Session") FOnSessionJoined    OnSessionJoined;
    UPROPERTY(BlueprintAssignable, Category = "Session") FOnSessionListReady OnSessionListReady;

private:

    /* ---------- new: login callback + helper ---------- */
    void OnLoginComplete(int32 LocalUserNum,
                         bool bWasSuccessful,
                         const FUniqueNetId& UserId,
                         const FString& Error);


    IOnlineSessionPtr                SessionInterface;
    TSharedPtr<FOnlineSessionSearch> SessionSearch;

    // Internal delegates and their handles
    FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
    FDelegateHandle                  OnCreateSessionCompleteDelegateHandle;

    FOnFindSessionsCompleteDelegate  OnFindSessionsCompleteDelegate;
    FDelegateHandle                  OnFindSessionsCompleteDelegateHandle;

    FOnJoinSessionCompleteDelegate   OnJoinSessionCompleteDelegate;
    FDelegateHandle                  OnJoinSessionCompleteDelegateHandle;

    // Callback functions bound to the online subsystem
    void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
    void OnFindSessionsComplete(bool bWasSuccessful);
    void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

    UPROPERTY()
    bool bSessionCreated;
};