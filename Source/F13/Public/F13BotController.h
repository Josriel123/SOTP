// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "F13BotController.generated.h"

/**
 * 
 */
UCLASS()
class F13_API AF13BotController : public AAIController
{
	GENERATED_BODY()

public:

	AF13BotController() { bWantsPlayerState = true; }
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(Transient, BlueprintReadOnly)
	bool bSkipLogoutRespawn = false;
};
