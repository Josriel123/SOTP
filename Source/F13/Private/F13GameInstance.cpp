// F13GameInstance.cpp
#include "F13GameInstance.h"
#include "Engine/World.h"


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

void UF13GameInstance::HostSession(bool bIsLAN, int32 MaxPlayers, const FString& DisplayName)
{
    if (!SessionInterface.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("HostSession called but SessionInterface == nullptr"));
        return;
    }

    if (SessionInterface->GetNamedSession(NAME_GameSession) != nullptr)
    {
        SessionInterface->DestroySession(NAME_GameSession);
    }
    const FName KEY_ServerName(TEXT("SERVER_NAME"));

    TSharedPtr<FOnlineSessionSettings> Settings = MakeShareable(new FOnlineSessionSettings());
    Settings->bIsLANMatch = bIsLAN;
    Settings->NumPublicConnections = MaxPlayers;
    Settings->bShouldAdvertise = true;
    Settings->bAllowJoinInProgress = true;
    Settings->bUsesPresence = true;
    Settings->Set<FString>(KEY_ServerName,
        DisplayName,          // or a widget-field value
        EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

    OnCreateSessionCompleteDelegateHandle =
        SessionInterface->AddOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegate);

    SessionInterface->CreateSession(0, NAME_GameSession, *Settings);
}

void UF13GameInstance::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{

    UE_LOG(LogTemp, Warning, TEXT("OnCreateSessionComplete: %s  success=%d"),
        *SessionName.ToString(), bWasSuccessful);
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegateHandle);
    }

    bSessionCreated = bWasSuccessful;

    OnSessionCreated.Broadcast(bWasSuccessful);
}

void UF13GameInstance::StartGameSession()
{
    if (bSessionCreated && GetWorld())
    {
        GetWorld()->ServerTravel(TEXT("/Game/ThirdPerson/Maps/ThirdPersonMap?listen?game=/Game/BP_F13Mode.BP_F13Mode_C"));

    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("StartGameSession called before session was created!"));
    }
}

void UF13GameInstance::FindSessions(bool bIsLAN)
{
    if (!SessionInterface.IsValid()) return;

    SessionSearch = MakeShareable(new FOnlineSessionSearch());
    SessionSearch->bIsLanQuery = bIsLAN;
    SessionSearch->MaxSearchResults = 20;
    SessionSearch->PingBucketSize = 50;

    OnFindSessionsCompleteDelegateHandle =
        SessionInterface->AddOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegate);

    SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
}

void UF13GameInstance::OnFindSessionsComplete(bool bWasSuccessful)
{
    UE_LOG(LogTemp, Warning, TEXT("OnFindSessionsComplete: success=%d  results=%d"),
        bWasSuccessful, SessionSearch.IsValid() ? SessionSearch->SearchResults.Num() : -1);

    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegateHandle);
    }


    TArray<FString> Names;
    if (bWasSuccessful && SessionSearch.IsValid())
    {
        const FName KEY_ServerName(TEXT("SERVER_NAME"));
        for (const auto& Result : SessionSearch->SearchResults)
        {
            FString Display;
            if (Result.Session.SessionSettings.Get(KEY_ServerName, Display))
            {
                Names.Add(Display);              // “MySession”
            }
            else
            {
                Names.Add(Result.GetSessionIdStr()); // fallback GUID
            }
        }
    }

    OnSessionListReady.Broadcast(Names);
}

void UF13GameInstance::JoinFoundSession(int32 SessionIndex)
{
    if (!SessionInterface.IsValid() || !SessionSearch.IsValid()) return;

    if (SessionSearch->SearchResults.IsValidIndex(SessionIndex))
    {
        OnJoinSessionCompleteDelegateHandle =
            SessionInterface->AddOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegate);

        SessionInterface->JoinSession(0, NAME_GameSession, SessionSearch->SearchResults[SessionIndex]);
    }
}

void UF13GameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegateHandle);
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
