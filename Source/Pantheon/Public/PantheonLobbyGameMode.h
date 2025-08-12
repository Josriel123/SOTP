// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HMS_GameMode.h"
#include "PantheonLobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PANTHEON_API APantheonLobbyGameMode : public AHMS_GameMode
{
	GENERATED_BODY()

public:
	APantheonLobbyGameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void BeginPlay() override;
	
};

