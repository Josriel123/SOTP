// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PantheonBotController.generated.h"

/**
 * 
 */
UCLASS()
class PANTHEON_API APantheonBotController : public AAIController
{
	GENERATED_BODY()

public:

	APantheonBotController() { bWantsPlayerState = true; }
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(Transient, BlueprintReadOnly)
	bool bSkipLogoutRespawn = false;
};

