// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HMS_GameMode.h"
#include "F13LobbyMenu.generated.h"

/**
 * 
 */
UCLASS()
class F13_API AF13LobbyMenu : public AHMS_GameMode
{
	GENERATED_BODY()

public:
	//AF13LobbyMenu();

	virtual void PostLogin(APlayerController* NewPlayer) override;
	
};
