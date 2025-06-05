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
#include "Components/InputComponent.h"
#include "Engine/LocalPlayer.h"
#include "UObject/ConstructorHelpers.h"

AF13CharacterBase::AF13CharacterBase()
{
    // Create a CameraBoom (spring arm)
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->bUsePawnControlRotation = true;

    // Create the follow camera
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    // Load the IMC asset at construction time:
    static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMCAsset(
        TEXT("/Game/Characters/Input/IMC_JasonPart3.IMC_JasonPart3"));
    if (IMCAsset.Succeeded())
    {
        IMC_JasonPart3 = IMCAsset.Object;
    }

    // Load InputAction assets
    static ConstructorHelpers::FObjectFinder<UInputAction> MoveActionObj(
        TEXT("/Game/Characters/Input/IA_Move.IA_Move"));
    if (MoveActionObj.Succeeded())
    {
        IA_Move = MoveActionObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UInputAction> JumpActionObj(
        TEXT("/Game/Characters/Input/IA_Jump.IA_Jump"));
    if (JumpActionObj.Succeeded())
    {
        IA_Jump = JumpActionObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UInputAction> LookActionObj(
        TEXT("/Game/Characters/Input/IA_Look.IA_Look"));
    if (LookActionObj.Succeeded())
    {
        IA_Look = LookActionObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UInputAction> SprintActionObj(
        TEXT("/Game/Characters/Input/IA_Sprint.IA_Sprint"));
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
        FCharacterStats* StatsRow = CharacterStatsTable->FindRow<FCharacterStats>(
            StatsRowName, ContextString, /*bWarnIfNotFound=*/ true);

        if (StatsRow)
        {
            // Copy locomotion stats
            WalkSpeed = StatsRow->WalkSpeed;
            SprintSpeed = StatsRow->SprintSpeed;
            WalkAccel = StatsRow->WalkAccel;
            SprintAccel = StatsRow->SprintAccel;
            BrakingDecelerationWalking = StatsRow->BrakingDecelWalking;

            // Copy ability flags
            bCanDash = StatsRow->bCanDash;
            DashDistance = StatsRow->DashDistance;
            DashCooldown = StatsRow->DashCooldown;

            bCanDoubleJump = StatsRow->bCanDoubleJump;
            DoubleJumpZVelocity = StatsRow->DoubleJumpZVelocity;

            // Apply to CharacterMovementComponent
            if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
            {
                MoveComp->MaxWalkSpeed = WalkSpeed;
                MoveComp->MaxAcceleration = WalkAccel;
                MoveComp->BrakingDecelerationWalking = BrakingDecelerationWalking;
            }
        }
        else
        {
            UE_LOG(LogTemp, Error,
                TEXT("%s: Could not find row '%s' in DataTable '%s'"),
                *GetName(),
                *StatsRowName.ToString(),
                *GetNameSafe(CharacterStatsTable));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning,
            TEXT("%s: CharacterStatsTable or StatsRowName not set."),
            *GetName());
    }

    // Finally, attempt to add our Enhanced Input Mapping Context
    AddInputMappingContext();
}

void AF13CharacterBase::AddInputMappingContext()
{
    APlayerController* PC = Cast<APlayerController>(GetController());
    if (PC == nullptr)
    {
        // We don’t have a valid PlayerController yet—skip adding mapping context.
        UE_LOG(LogTemp, Warning,
            TEXT("%s: Cannot add InputMappingContext because GetController() is null."),
            *GetName());
        return;
    }

    ULocalPlayer* LP = PC->GetLocalPlayer();
    if (LP == nullptr)
    {
        UE_LOG(LogTemp, Warning,
            TEXT("%s: Cannot add InputMappingContext because PlayerController has no LocalPlayer."),
            *GetName());
        return;
    }

    // Now safely grab the Enhanced Input subsystem
    if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem =
        LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
    {
        if (IMC_JasonPart3)
        {
            EnhancedInputSubsystem->AddMappingContext(IMC_JasonPart3, 0);
        }
        else
        {
            UE_LOG(LogTemp, Warning,
                TEXT("%s: IMC_JasonPart3 is null in Blueprint or constructor."),
                *GetName());
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning,
            TEXT("%s: Failed to get UEnhancedInputLocalPlayerSubsystem on LocalPlayer."),
            *GetName());
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
            EnhancedInput->BindAction(
                IA_Move, ETriggerEvent::Triggered, this, &AF13CharacterBase::Move);
        }

        // ─── Bind Look ─────────────────────────
        if (IA_Look)
        {
            EnhancedInput->BindAction(
                IA_Look, ETriggerEvent::Triggered, this, &AF13CharacterBase::Look);
        }

        // ─── Bind Jump ─────────────────────────
        if (IA_Jump)
        {
            EnhancedInput->BindAction(
                IA_Jump, ETriggerEvent::Started, this, &AF13CharacterBase::JumpPressed);
            EnhancedInput->BindAction(
                IA_Jump, ETriggerEvent::Completed, this, &AF13CharacterBase::JumpReleased);
        }

        // ─── Bind Sprint ────────────────────────
        if (IA_Sprint)
        {
            EnhancedInput->BindAction(
                IA_Sprint, ETriggerEvent::Started, this, &AF13CharacterBase::SprintPressed);
            EnhancedInput->BindAction(
                IA_Sprint, ETriggerEvent::Completed, this, &AF13CharacterBase::SprintReleased);
        }
    }
}

void AF13CharacterBase::Move(const FInputActionValue& Value)
{
    const FVector2D MovementVector = Value.Get<FVector2D>();
    if (!Controller)
    {
        return;
    }

    const FRotator ControlRot = Controller->GetControlRotation();
    const FRotator YawRot(0.f, ControlRot.Yaw, 0.f);

    const FVector ForwardDir = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
    const FVector RightDir = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);

    AddMovementInput(ForwardDir, MovementVector.Y);
    AddMovementInput(RightDir, MovementVector.X);
}

void AF13CharacterBase::Look(const FInputActionValue& Value)
{
    const FVector2D LookAxis = Value.Get<FVector2D>();
    AddControllerYawInput(LookAxis.X);
    AddControllerPitchInput(LookAxis.Y);
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
    if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
    {
        MoveComp->MaxWalkSpeed = SprintSpeed;
        MoveComp->MaxAcceleration = SprintAccel;
        MoveComp->BrakingDecelerationWalking = 0.f; // Smooth transition
    }
}

void AF13CharacterBase::SprintReleased(const FInputActionValue& Value)
{
    if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
    {
        MoveComp->MaxWalkSpeed = WalkSpeed;
        MoveComp->MaxAcceleration = WalkAccel;
        MoveComp->BrakingDecelerationWalking = 2048.f; // Restore default
    }
}

void AF13CharacterBase::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    if (CameraBoom)
    {
        CameraBoom->TargetArmLength = CameraDistance;
        FollowCamera->SetRelativeRotation(CameraRelativeRotation);
        CameraBoom->SocketOffset = FVector(0.f, 0.f, CameraHeightOffset);
    }
}
