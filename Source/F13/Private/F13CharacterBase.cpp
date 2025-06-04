#include "F13CharacterBase.h"
#include "CharacterStats.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerInput.h"
#include "Components/InputComponent.h"
#include "Engine/LocalPlayer.h"


AF13CharacterBase::AF13CharacterBase()
{

	//GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	//GetCharacterMovement()->MaxAcceleration = WalkAccel;

	// 1) Create a CameraBoom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = true;


	// 2) Create the follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;


	// 4) Load your InputMappingContext asset at construction time,
    //    so it’s baked into the CDO/Blueprint defaults:
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC_AssetObject(
		TEXT("/Game/Characters/Jasons/Part_3/Input/IMC_JasonPart3.IMC_JasonPart3"));
	if (IMC_AssetObject.Succeeded())
	{
		IMC_JasonPart3 = IMC_AssetObject.Object;
	}

	// 4) Similarly, load your InputAction assets:
	static ConstructorHelpers::FObjectFinder<UInputAction> MoveActionObj(
		TEXT("/Game/Characters/Jasons/Part_3/Input/IA_Move.IA_Move"));
	if (MoveActionObj.Succeeded())
	{
		IA_Move = MoveActionObj.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> JumpActionObj(
		TEXT("/Game/Characters/Jasons/Part_3/Input/IA_Jump.IA_Jump"));
	if (JumpActionObj.Succeeded())
	{
		IA_Jump = JumpActionObj.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> LookActionObj(
		TEXT("/Game/Characters/Jasons/Part_3/Input/IA_Look.IA_Look"));
	if (LookActionObj.Succeeded())
	{
		IA_Look = LookActionObj.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> SprintActionObj(
		TEXT("/Game/Characters/Jasons/Part_3/Input/IA_Sprint.IA_Sprint"));
	if (SprintActionObj.Succeeded())
	{
		IA_Sprint = SprintActionObj.Object;
	}

}

void AF13CharacterBase::BeginPlay()
{
	Super::BeginPlay();

	// ─── 1) Read from CharacterStatsTable ─────────────────────────────────────
	if (CharacterStatsTable && StatsRowName != NAME_None)
	{
		static const FString ContextString(TEXT("CharacterStatsLookup"));
		FCharacterStats* StatsRow = CharacterStatsTable->FindRow<FCharacterStats>(StatsRowName, ContextString, /*bWarnIfNotFound=*/ true);

		if (StatsRow)
		{
			// Copy basic locomotion stats
			WalkSpeed                  = StatsRow->WalkSpeed;
			SprintSpeed                = StatsRow->SprintSpeed;
			WalkAccel                  = StatsRow->WalkAccel;
			SprintAccel                = StatsRow->SprintAccel;
			BrakingDecelerationWalking = StatsRow->BrakingDecelWalking;

			// Copy ability flags
			bCanDash     = StatsRow->bCanDash;
			DashDistance = StatsRow->DashDistance;
			DashCooldown = StatsRow->DashCooldown;

			bCanDoubleJump      = StatsRow->bCanDoubleJump;
			DoubleJumpZVelocity = StatsRow->DoubleJumpZVelocity;

			// Now apply walk/sprint/accel/braking to the MovementComponent
			if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
			{
				MoveComp->MaxWalkSpeed               = WalkSpeed;
				MoveComp->MaxAcceleration            = WalkAccel;
				MoveComp->BrakingDecelerationWalking = BrakingDecelerationWalking;

			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("%s: Could not find row '%s' in DataTable '%s'"),
				*GetName(),
				*StatsRowName.ToString(),
				*GetNameSafe(CharacterStatsTable));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s: CharacterStatsTable or StatsRowName not set."), *GetName());
	}

	// Add our Enhanced Input Mapping Context (IMC_JasonPart3) to the local player subsystem
	AddInputMappingContext();
}

void AF13CharacterBase::AddInputMappingContext()
{
	// Get the PlayerController for this pawn
	APlayerController* PC = Cast<APlayerController>(GetController());


	// The Enhanced Input subsystem only lives on the LocalPlayer
	ULocalPlayer* LP = PC->GetLocalPlayer();

	// Grab the EnhancedInputLocalPlayerSubsystem
	if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem =
		LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
	{
		if (IMC_JasonPart3)
		{
			EnhancedInputSubsystem->AddMappingContext(IMC_JasonPart3, 0);
		}
	}
}

void AF13CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Cast to EnhancedInputComponent
	if (UEnhancedInputComponent* EnhancedInput =
		Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{

		// ─── Bind Move ─────────────────────────
		if (IA_Move)
		{
			EnhancedInput->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AF13CharacterBase::Move);
		}

		// ─── Bind Look ─────────────────────────
		if (IA_Look)
		{
			EnhancedInput->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AF13CharacterBase::Look);
		}

		// ─── Bind Jump ─────────────────────────
		if (IA_Jump)
		{
			EnhancedInput->BindAction(IA_Jump, ETriggerEvent::Started, this, &AF13CharacterBase::JumpPressed);
			EnhancedInput->BindAction(IA_Jump, ETriggerEvent::Completed, this, &AF13CharacterBase::JumpReleased);
		}

		// ─── Bind Sprint ────────────────────────
		if (IA_Sprint)
		{
			EnhancedInput->BindAction(IA_Sprint, ETriggerEvent::Started, this, &AF13CharacterBase::SprintPressed);
			EnhancedInput->BindAction(IA_Sprint, ETriggerEvent::Completed, this, &AF13CharacterBase::SprintReleased);
		}
	}
}

void AF13CharacterBase::Move(const FInputActionValue& Value)
{
	// Value.Get<FVector2D>() is (X = Right/Left, Y = Forward/Backward)
	const FVector2D MovementVector = Value.Get<FVector2D>();
	if (!Controller) return;

	// Figure out which way is “forward” from the controller’s yaw
	const FRotator ControlRot = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, ControlRot.Yaw, 0.f);

	const FVector ForwardDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Feed AddMovementInput (Forward/back) and AddMovementInput (Right/left)
	AddMovementInput(ForwardDir, MovementVector.Y);
	AddMovementInput(RightDir, MovementVector.X);
}

void AF13CharacterBase::Look(const FInputActionValue& Value)
{
	// Value.Get<FVector2D>() is (X = Yaw input, Y = Pitch input)
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void AF13CharacterBase::JumpPressed(const FInputActionValue& Value)
{
	Jump();
}

void AF13CharacterBase::JumpReleased(const FInputActionValue& Value)
{
	StopJumping();
}

void AF13CharacterBase::SprintPressed(const FInputActionValue& Value)
{
	// Ramp up to SprintSpeed
	UCharacterMovementComponent* MoveComp = GetCharacterMovement();
	if (MoveComp)
	{
		MoveComp->MaxWalkSpeed = SprintSpeed;
		MoveComp->MaxAcceleration = SprintAccel;
		// Optionally reduce braking friction so the transition is smooth
		MoveComp->BrakingDecelerationWalking = 0.f;
	}
}

void AF13CharacterBase::SprintReleased(const FInputActionValue& Value)
{
	// Go back to normal WalkSpeed
	UCharacterMovementComponent* MoveComp = GetCharacterMovement();
	if (MoveComp)
	{
		MoveComp->MaxWalkSpeed = WalkSpeed;
		MoveComp->MaxAcceleration = WalkAccel;
		// Restore default braking
		MoveComp->BrakingDecelerationWalking = 2048.f; // or whatever default you want
	}
}

void AF13CharacterBase::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	// Assume you have a UPROPERTY SpringArm named CameraBoom:
	if (CameraBoom)
	{
		CameraBoom->TargetArmLength = CameraDistance;
		FollowCamera->SetRelativeRotation(CameraRelativeRotation);
		CameraBoom->SocketOffset = FVector(0.f, 0.f, CameraHeightOffset);
	}
}
