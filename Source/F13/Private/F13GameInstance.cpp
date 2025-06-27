// F13GameInstance.cpp
#include "F13GameInstance.h"
#include "Engine/World.h"

/* ------------------------------------------------------------ */
/*  ctor / Init                                                 */
/* ------------------------------------------------------------ */
UF13GameInstance::UF13GameInstance()
{
    if (IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get())
    {
        SessionInterface = Subsystem->GetSessionInterface();
    }
}

void UF13GameInstance::Init()
{
    Super::Init();

    IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
    if (!Subsystem) { UE_LOG(LogTemp, Error, TEXT("No OSS loaded")); return; }

    SessionInterface = Subsystem->GetSessionInterface();
    IOnlineIdentityPtr Identity = Subsystem->GetIdentityInterface();

    Identity->OnLoginCompleteDelegates->AddUObject(this, &UF13GameInstance::OnLoginComplete);
    Identity->Login(0, FOnlineAccountCredentials(TEXT("accountportal"), TEXT(""), TEXT("")));

    if (SessionInterface.IsValid())
    {
        OnCreateSessionCompleteDelegate = FOnCreateSessionCompleteDelegate::CreateUObject(
            this, &UF13GameInstance::OnCreateSessionComplete);
        OnFindSessionsCompleteDelegate = FOnFindSessionsCompleteDelegate::CreateUObject(
            this, &UF13GameInstance::OnFindSessionsComplete);
        OnJoinSessionCompleteDelegate = FOnJoinSessionCompleteDelegate::CreateUObject(
            this, &UF13GameInstance::OnJoinSessionComplete);
    }
}

/* ------------------------------------------------------------ */
/*  PUBLIC  — widget entry-point                                */
/* ------------------------------------------------------------ */
void UF13GameInstance::HostAndStartSession()
{
    HostSession();
}

/* ------------------------------------------------------------ */
/*  Search & Join                                               */
/* ------------------------------------------------------------ */
void UF13GameInstance::FindSessions()
{
    if (!SessionInterface.IsValid()) return;

    SessionSearch = MakeShareable(new FOnlineSessionSearch());
    SessionSearch->MaxSearchResults = 20;
    SessionSearch->PingBucketSize = 50;

    OnFindSessionsCompleteDelegateHandle =
        SessionInterface->AddOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegate);

    SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
}

void UF13GameInstance::JoinFoundSession(int32 SessionIndex)
{
    if (!SessionInterface.IsValid() || !SessionSearch.IsValid()) return;
    if (!SessionSearch->SearchResults.IsValidIndex(SessionIndex)) return;

    /* ---- if we still have a local GameSession, destroy first ---- */
    if (SessionInterface->GetNamedSession(NAME_GameSession))
    {
        CleanAndJoin(SessionIndex);
        return;
    }

    /* ---- proceed to join ---- */
    OnJoinSessionCompleteDelegateHandle =
        SessionInterface->AddOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegate);

    SessionInterface->JoinSession(
        0, NAME_GameSession, SessionSearch->SearchResults[SessionIndex]);
}

TArray<FString> UF13GameInstance::GetFoundSessionNames() const
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

/* ------------------------------------------------------------ */
/*  INTERNAL — Host                                             */
/* ------------------------------------------------------------ */
void UF13GameInstance::HostSession()
{
    if (!SessionInterface.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("HostSession: SessionInterface == nullptr"));
        return;
    }

    if (SessionInterface->GetNamedSession(NAME_GameSession))
    {
        SessionInterface->DestroySession(NAME_GameSession);
    }

    TSharedPtr<FOnlineSessionSettings> Settings = MakeShareable(new FOnlineSessionSettings());
    Settings->bIsLANMatch = false;
    Settings->NumPublicConnections = 10;
    Settings->bShouldAdvertise = true;
    Settings->bAllowJoinInProgress = true;
    Settings->bUsesPresence = true;

    OnCreateSessionCompleteDelegateHandle =
        SessionInterface->AddOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegate);

    SessionInterface->CreateSession(0, NAME_GameSession, *Settings);
}

/* ------------------------------------------------------------ */
/*  NEW — destroy-then-join helpers                             */
/* ------------------------------------------------------------ */
void UF13GameInstance::CleanAndJoin(int32 SearchIndex)
{
    if (!SessionInterface.IsValid()) return;

    PendingJoinIndex = SearchIndex;

    OnDestroySessionCompleteDelegate =
        FOnDestroySessionCompleteDelegate::CreateUObject(
            this, &UF13GameInstance::OnDestroySessionComplete);

    OnDestroySessionCompleteDelegateHandle =
        SessionInterface->AddOnDestroySessionCompleteDelegate_Handle(
            OnDestroySessionCompleteDelegate);

    SessionInterface->DestroySession(NAME_GameSession);
}

void UF13GameInstance::OnDestroySessionComplete(FName /*SessionName*/, bool /*bSuccess*/)
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
void UF13GameInstance::OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful,
    const FUniqueNetId& UserId, const FString& Error)
{
    UE_LOG(LogTemp, Log,
        TEXT("[EOS] Login %s | UserNum:%d | Id:%s | Error:%s"),
        bWasSuccessful ? TEXT("OK") : TEXT("FAILED"),
        LocalUserNum, *UserId.ToString(), *Error);
}

void UF13GameInstance::OnCreateSessionComplete(FName /*SessionName*/, bool bWasSuccessful)
{
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(
            OnCreateSessionCompleteDelegateHandle);
    }

    OnSessionCreated.Broadcast(bWasSuccessful);
}

void UF13GameInstance::OnFindSessionsComplete(bool bWasSuccessful)
{
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(
            OnFindSessionsCompleteDelegateHandle);
    }

    if (bWasSuccessful && SessionSearch.IsValid() && SessionSearch->SearchResults.Num() > 0)
    {
        const int32 RandomIndex =
            FMath::RandRange(0, SessionSearch->SearchResults.Num() - 1);

        UE_LOG(LogTemp, Log,
            TEXT("Attempting to join random session [%d / %d]"),
            RandomIndex, SessionSearch->SearchResults.Num());

        JoinFoundSession(RandomIndex);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No sessions found to join"));
    }
}

void UF13GameInstance::OnJoinSessionComplete(FName SessionName,
    EOnJoinSessionCompleteResult::Type Result)
{
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(
            OnJoinSessionCompleteDelegateHandle);
    }

    const bool bWasSuccessful = (Result == EOnJoinSessionCompleteResult::Success);
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
