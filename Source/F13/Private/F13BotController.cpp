// Fill out your copyright notice in the Description page of Project Settings.


#include "F13BotController.h"

DEFINE_LOG_CATEGORY_STATIC(LogF13Bot, Log, All);

void AF13BotController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    UE_LOG(LogF13Bot, Log, TEXT("BotController possessed %s"), *InPawn->GetName());
}