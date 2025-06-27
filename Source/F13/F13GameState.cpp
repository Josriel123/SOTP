// Fill out your copyright notice in the Description page of Project Settings.


#include "F13GameState.h"

void AF13GameState::AddPlayerState(APlayerState* PS)
{
    Super::AddPlayerState(PS);
    OnPlayersChanged.Broadcast();        // fires on server **and** clients
}
void AF13GameState::RemovePlayerState(APlayerState* PS)
{
    Super::RemovePlayerState(PS);
    OnPlayersChanged.Broadcast();
}
