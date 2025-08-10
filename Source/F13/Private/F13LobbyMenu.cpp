// Fill out your copyright notice in the Description page of Project Settings.


#include "F13LobbyMenu.h"
#include "F13GameInstance.h"
#include "F13PlayerState.h"

void AF13LobbyMenu::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    /*
    if (AF13PlayerState* PS = Cast<AF13PlayerState>(NewPlayer->PlayerState))
    {
        const UF13GameInstance* GI = GetGameInstance<UF13GameInstance>();
        PS->SurvivorRowKey = GI->CachedStartupProfile.SurvivorRowKey;
        PS->KillerRowKey = GI->CachedStartupProfile.KillerRowKey;
    }
    */
}

