// PantheonGameInstance.cpp
#include "PantheonGameInstance.h"
#include "PantheonPlayerProfileSave.h"
#include "Online/OnlineSessionNames.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

/* ------------------------------------------------------------ */
/*  ctor / Init                                                 */
/* ------------------------------------------------------------ */

static const TCHAR* kProfileSlot = TEXT("PlayerProfile");
static const int32  kProfileUserIdx = 0;

UPantheonGameInstance::UPantheonGameInstance()
{
    if (IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get())
    {
        SessionInterface = Subsystem->GetSessionInterface();
    }
}

void UPantheonGameInstance::Init()
{
    Super::Init();

    LoadLocalProfile(CachedStartupProfile);

    if (IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get())
    {
        SessionInterface = Subsystem->GetSessionInterface();
        if (IOnlineIdentityPtr Identity = Subsystem->GetIdentityInterface())
        {
            Identity->OnLoginCompleteDelegates->AddUObject(this, &UPantheonGameInstance::OnLoginComplete);

            const auto Status = Identity->GetLoginStatus(0);
            if (Status != ELoginStatus::LoggedIn)
            {
                Identity->Login(0, FOnlineAccountCredentials(TEXT("accountportal"), TEXT(""), TEXT("")));
            }
        }

        // one-time bind of the session delegates
        if (SessionInterface.IsValid())
        {
            OnCreateSessionCompleteDelegate = FOnCreateSessionCompleteDelegate::CreateUObject(this, &UPantheonGameInstance::OnCreateSessionComplete);
            OnFindSessionsCompleteDelegate = FOnFindSessionsCompleteDelegate::CreateUObject(this, &UPantheonGameInstance::OnFindSessionsComplete);
            OnJoinSessionCompleteDelegate = FOnJoinSessionCompleteDelegate::CreateUObject(this, &UPantheonGameInstance::OnJoinSessionComplete);
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("No Online Subsystem loaded"));
    }
}

/* ------------------------------------------------------------ */
/*  Search & Join                                               */
/* ------------------------------------------------------------ */

void UPantheonGameInstance::FindSessions()
{
    if (!SessionInterface.IsValid()) return;

    SessionSearch = MakeShared<FOnlineSessionSearch>();
    SessionSearch->MaxSearchResults = 50;
    SessionSearch->PingBucketSize = 50;

    // Only show sessions advertising presence (join-in-progress, etc.)
    SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);

    OnFindSessionsCompleteDelegateHandle =
        SessionInterface->AddOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegate);

    SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
}



void UPantheonGameInstance::JoinFoundSession(int32 SessionIndex)
{
    if (!SessionInterface.IsValid() || !SessionSearch.IsValid()) return;
    if (!SessionSearch->SearchResults.IsValidIndex(SessionIndex)) return;

    /* ---- if we still have a local GameSession, destroy first ----*/
    if (SessionInterface->GetNamedSession(NAME_GameSession))
    {
        CleanAndJoin(SessionIndex);
        return;
    }

    /* ---- proceed to join ----*/
    OnJoinSessionCompleteDelegateHandle =
        SessionInterface->AddOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegate);

    SessionInterface->JoinSession(
        0, NAME_GameSession, SessionSearch->SearchResults[SessionIndex]);
}




TArray<FString> UPantheonGameInstance::GetFoundSessionNames() const
{
    TArray<FString> Names;
    if (SessionSearch.IsValid())
    {
        for (const auto& Result : SessionSearch->SearchResults)
        {
            Names.Add(Result.GetSessionIdStr());
        }
    }
    return Names;
}


/*------------------------------------------------------------ * /
/*  NEW — destroy-then-join helpers                             */
/* ------------------------------------------------------------ */
void UPantheonGameInstance::CleanAndJoin(int32 SearchIndex)
{
    if (!SessionInterface.IsValid()) return;
    if (PendingJoinIndex != INDEX_NONE) return; // already in progress

    UE_LOG(LogTemp, Log, TEXT("Clean and Join runs"));
    PendingJoinIndex = SearchIndex;

    OnDestroySessionCompleteDelegate = FOnDestroySessionCompleteDelegate::CreateUObject(this, &UPantheonGameInstance::OnDestroySessionComplete);
    OnDestroySessionCompleteDelegateHandle =
        SessionInterface->AddOnDestroySessionCompleteDelegate_Handle(OnDestroySessionCompleteDelegate);

    SessionInterface->DestroySession(NAME_GameSession);
}




void UPantheonGameInstance::OnDestroySessionComplete(FName /*SessionName*/, bool /*bSuccess*/)
{

    
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnDestroySessionCompleteDelegate_Handle(
            OnDestroySessionCompleteDelegateHandle);
    }

    if (PendingJoinIndex != INDEX_NONE)
    {
        const int32 RetryIndex = PendingJoinIndex;
        PendingJoinIndex = INDEX_NONE;
        JoinFoundSession(RetryIndex);   // will skip destroy path now
    }
}


/* ------------------------------------------------------------ */
/*  Online-subsystem callbacks                                   */
/* ------------------------------------------------------------ */
void UPantheonGameInstance::OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful,
    const FUniqueNetId& UserId, const FString& Error)
{
    UE_LOG(LogTemp, Log,
        TEXT("[EOS] Login %s | UserNum:%d | Id:%s | Error:%s"),
        bWasSuccessful ? TEXT("OK") : TEXT("FAILED"),
        LocalUserNum, *UserId.ToString(), *Error);
}


void UPantheonGameInstance::OnCreateSessionComplete(FName /*SessionName*/, bool bWasSuccessful)
{
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(
            OnCreateSessionCompleteDelegateHandle);
    }


    OnSessionCreated.Broadcast(bWasSuccessful);
}



void UPantheonGameInstance::OnFindSessionsComplete(bool bWasSuccessful)
{
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegateHandle);
    }

    TArray<FString> Names;
    if (bWasSuccessful && SessionSearch.IsValid())
    {
        Names.Reserve(SessionSearch->SearchResults.Num());
        for (const auto& R : SessionSearch->SearchResults)
        {
            Names.Add(R.GetSessionIdStr());
        }
    }
    OnSessionListReady.Broadcast(Names); // <- feed UI

    if (Names.Num() > 0)
    {
        const int32 RandomIndex = FMath::RandRange(0, Names.Num() - 1);
        UE_LOG(LogTemp, Log, TEXT("Attempting to join random session [%d / %d]"), RandomIndex, Names.Num());
        JoinFoundSession(RandomIndex);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No sessions found to join"));
    }
}


void UPantheonGameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegateHandle);
    }

    const bool bWasSuccessful = (Result == EOnJoinSessionCompleteResult::Success);
    UE_LOG(LogTemp, Log, TEXT("JoinSessionComplete: %s (Result=%d)"), bWasSuccessful ? TEXT("Success") : TEXT("Fail"), (int32)Result);

    if (bWasSuccessful)
    {
        FString ConnectString;
        if (SessionInterface->GetResolvedConnectString(SessionName, ConnectString))
        {
            if (APlayerController* PC = GetFirstLocalPlayerController())
            {
                PC->ClientTravel(ConnectString, TRAVEL_Absolute);
            }
        }
    }

    OnSessionJoined.Broadcast(bWasSuccessful);
}



bool UPantheonGameInstance::LoadLocalProfile(FPlayerProfileData& Out)
{
    if (USaveGame* Base = UGameplayStatics::LoadGameFromSlot(kProfileSlot, kProfileUserIdx))
    {
        if (auto* Typed = Cast<UPantheonPlayerProfileSave>(Base))
        {
            Out = Typed->Profile;
            return true;
        }
        UE_LOG(LogTemp, Warning, TEXT("Profile slot exists but type mismatch"));
    }
    return false;
}

void UPantheonGameInstance::SaveLocalProfile(const FPlayerProfileData& In)
{
    if (auto* Obj = Cast<UPantheonPlayerProfileSave>(UGameplayStatics::CreateSaveGameObject(UPantheonPlayerProfileSave::StaticClass())))
    {
        Obj->Profile = In;
        if (!UGameplayStatics::SaveGameToSlot(Obj, kProfileSlot, kProfileUserIdx))
        {
            UE_LOG(LogTemp, Warning, TEXT("SaveLocalProfile: SaveGameToSlot failed"));
        }
    }
}

void UPantheonGameInstance::Shutdown()
{
    Super::Shutdown();
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegateHandle);
        SessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegateHandle);
        SessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegateHandle);
        SessionInterface->ClearOnDestroySessionCompleteDelegate_Handle(OnDestroySessionCompleteDelegateHandle);
    }
}



