// Fill out your copyright notice in the Description page of Project Settings.


#include "PantheonLobbyGameMode.h"
#include "PantheonGameInstance.h"
#include "PantheonPlayerState.h"

APantheonLobbyGameMode::APantheonLobbyGameMode()
{
    // prevents HMS timer-based “last save” from running on Lobby
    HMS_MigrationSettings.AutoStartGameSaveUpdate = false;
}

void APantheonLobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    /*
    if (APantheonPlayerState* PS = Cast<APantheonPlayerState>(NewPlayer->PlayerState))
    {
        const UPantheonGameInstance* GI = GetGameInstance<UPantheonGameInstance>();
        PS->SurvivorRowKey = GI->CachedStartupProfile.SurvivorRowKey;
        PS->KillerRowKey = GI->CachedStartupProfile.KillerRowKey;
    }
    */
}

void APantheonLobbyGameMode::BeginPlay()
{
    Super::BeginPlay();
    if (HasAuthority())
    {
        // wipe any stale rehost info as soon as we land in the lobby
        if (auto* GI = Cast<UHMS_GameInstance>(GetGameInstance()))
        {
            GI->HMS_ResetHostMigration();
        }
    }
}


