// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "F13GameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayersChanged);

UCLASS()
class F13_API AF13GameState : public AGameState
{
    GENERATED_BODY()
};