// PantheonGameInstance.h
#pragma once

#include "CoreMinimal.h"
#include "HMS_GameInstance.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "PantheonPlayerProfileSave.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "PantheonGameInstance.generated.h"

/* ---------------- Blueprint-facing delegates ---------------- */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionJoined, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionCreated, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionListReady, const TArray<FString>&, FoundNames);

UCLASS()
class PANTHEON_API UPantheonGameInstance : public UHMS_GameInstance
{
    GENERATED_BODY()

public:
    UPantheonGameInstance();

    bool  LoadLocalProfile(FPlayerProfileData& Out);
    void  SaveLocalProfile(const FPlayerProfileData& In);

    /** Accessible at runtime – holds what we loaded on startup */
    UPROPERTY() FPlayerProfileData CachedStartupProfile;

    virtual void Init() override;

    /* ----------  UI entry-points ---------- */
    UFUNCTION(BlueprintCallable, Category = "Session") void HostAndStartSession();
    UFUNCTION(BlueprintCallable, Category = "Session") void FindSessions();
    UFUNCTION(BlueprintCallable, Category = "Session") void JoinFoundSession(int32 SessionIndex);
    UFUNCTION(BlueprintCallable, Category = "Session") TArray<FString> GetFoundSessionNames() const;
    /* ----------  Delegates exposed to Blueprints ---------- */
    UPROPERTY(BlueprintAssignable, Category = "Session") FOnSessionCreated   OnSessionCreated;
    UPROPERTY(BlueprintAssignable, Category = "Session") FOnSessionJoined    OnSessionJoined;
    UPROPERTY(BlueprintAssignable, Category = "Session") FOnSessionListReady OnSessionListReady;

private:

    /* ----------  Internal helpers ---------- */
    void HostSession();

    /* —— destroy-then-join helpers (NEW) —— */
    void CleanAndJoin(int32 SearchIndex);
    void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);

    /* ----------  Online-subsystem callbacks ---------- */
    void OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful,
        const FUniqueNetId& UserId, const FString& Error);
    void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
    void OnFindSessionsComplete(bool bWasSuccessful);
    void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

    /* ----------  OSS handles ---------- */
    IOnlineSessionPtr                SessionInterface;
    TSharedPtr<FOnlineSessionSearch> SessionSearch;

    FOnCreateSessionCompleteDelegate     OnCreateSessionCompleteDelegate;
    FDelegateHandle                      OnCreateSessionCompleteDelegateHandle;

    FOnFindSessionsCompleteDelegate      OnFindSessionsCompleteDelegate;
    FDelegateHandle                      OnFindSessionsCompleteDelegateHandle;

    FOnJoinSessionCompleteDelegate       OnJoinSessionCompleteDelegate;
    FDelegateHandle                      OnJoinSessionCompleteDelegateHandle;

    FOnDestroySessionCompleteDelegate    OnDestroySessionCompleteDelegate;      // NEW
    FDelegateHandle                      OnDestroySessionCompleteDelegateHandle;// NEW

    int32                                PendingJoinIndex = INDEX_NONE;         // NEW
};

