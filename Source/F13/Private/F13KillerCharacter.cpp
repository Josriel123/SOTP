// Fill out your copyright notice in the Description page of Project Settings.


// F13KillerCharacter.cpp

#include "F13KillerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AF13KillerCharacter::AF13KillerCharacter()
{
	WalkSpeed   = 300.f;       
	SprintSpeed = 400.f;      
	WalkAccel   = 1200.f;   
	SprintAccel = 300.f;

	if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
	{
		MoveComp->MaxWalkSpeed = WalkSpeed;
		MoveComp->MaxAcceleration = WalkAccel;

	}

	// MoveComp->JumpZVelocity = 0.f;
	// MoveComp->AirControl = 0.f;
}


