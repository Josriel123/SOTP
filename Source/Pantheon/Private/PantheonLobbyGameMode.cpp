// Fill out your copyright notice in the Description page of Project Settings.


#include "PantheonLobbyGameMode.h"
#include "PantheonGameInstance.h"
#include "PantheonPlayerState.h"

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


