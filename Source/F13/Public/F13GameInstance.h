// F13GameInstance.h
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FOnSessionLeft,
    bool,
    bSuccess
);





UCLASS()
class F13_API UF13GameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    UF13GameInstance();
    virtual void Init() override;

    /** Start hosting a session */
    UFUNCTION(BlueprintCallable, Category = "Session")
    void HostSession(bool bIsLAN, int32 MaxPlayers, const FString& DisplayName);

    /** Search for available sessions */
    UFUNCTION(BlueprintCallable, Category = "Session")
    void FindSessions(bool bIsLAN);

    /** Join one of the found sessions by index */
    UFUNCTION(BlueprintCallable, Category = "Session")
    void JoinFoundSession(int32 SessionIndex);

    UFUNCTION(BlueprintCallable, Category = "Session")
    void LeaveGameSession();


    /** Get session names from last search */
    UFUNCTION(BlueprintCallable, Category = "Session")
    TArray<FString> GetFoundSessionNames() const;

    /** Triggered when a session is created */
    UPROPERTY(BlueprintAssignable, Category = "Session")
    FOnSessionCreated OnSessionCreated;

    /** Triggered when a session is joined */
    UPROPERTY(BlueprintAssignable, Category = "Session")
    FOnSessionJoined OnSessionJoined;

    UFUNCTION(BlueprintCallable, Category = "Session")
    void StartGameSession();

    UPROPERTY(BlueprintAssignable, Category = "Session")
    FOnSessionListReady OnSessionListReady;

    UPROPERTY(BlueprintAssignable, Category = "Session")
    FOnSessionLeft OnSessionLeft;

private:
    // Interface to the online subsystem’s session API
    IOnlineSessionPtr SessionInterface;

    // Stores the results of the last FindSessions call
    TSharedPtr<FOnlineSessionSearch> SessionSearch;

    // Internal delegates and their handles
    FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
    FDelegateHandle OnCreateSessionCompleteDelegateHandle;

    FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
    FDelegateHandle OnFindSessionsCompleteDelegateHandle;

    FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;
    FDelegateHandle OnJoinSessionCompleteDelegateHandle;

    FDelegateHandle OnEndSessionCompleteHandle;
    FDelegateHandle OnDestroySessionCompleteHandle;

    // Callback functions bound to the online subsystem
    void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
    void OnFindSessionsComplete(bool bWasSuccessful);
    void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
    void OnEndSessionComplete(FName, bool);
    void OnDestroySessionComplete(FName, bool);

    UPROPERTY()
    bool bSessionCreated;
};