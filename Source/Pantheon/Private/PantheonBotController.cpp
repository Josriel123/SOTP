// Fill out your copyright notice in the Description page of Project Settings.


#include "PantheonBotController.h"
#include "PantheonPlayerState.h"

DEFINE_LOG_CATEGORY_STATIC(LogPantheonBot, Log, All);

void APantheonBotController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    UE_LOG(LogPantheonBot, Log, TEXT("BotController possessed %s"), *InPawn->GetName());

    
    if (APantheonPlayerState* PS = GetPlayerState<APantheonPlayerState>())
    {
        PS->EnsureUniqueIdForBot();
    }
}
