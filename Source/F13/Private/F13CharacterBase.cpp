// F13CharacterBase.cpp

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

//////////////////////////////////////////////////////////////////////////
// AF13CharacterBase

AF13CharacterBase::AF13CharacterBase()
{
    // Tell engine to tick this Actor
    PrimaryActorTick.bCanEverTick = true;


    // 1) Create the spring arm (CameraBoom):
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->bUsePawnControlRotation = true;

    // 2) Create the follow camera
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    // 3) Load your InputMappingContext asset at construction time,
    //    so it’s baked into the CDO/Blueprint defaults:
    static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC_AssetObject(
        TEXT("/Game/Characters/Input/IMC_JasonPart3.IMC_JasonPart3"));
    if (IMC_AssetObject.Succeeded())
    {
        IMC_JasonPart3 = IMC_AssetObject.Object;
    }

    // 4) Similarly, load your InputAction assets:
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


}

void AF13CharacterBase::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    bUseControllerRotationYaw = false;

    if (CharacterStatsTable && StatsRowName != NAME_None)
    {
        static const FString ContextString(TEXT("CharacterStatsLookup"));
        FCharacterStats* StatsRow = CharacterStatsTable->FindRow<FCharacterStats>(StatsRowName, ContextString, true);

        if (StatsRow)
        {
            // Set the character stats from the row
            WalkSpeed = StatsRow->WalkSpeed;
            WalkAccel = StatsRow->WalkAccel;
            SprintSpeed = StatsRow->SprintSpeed;
            SprintAccel = StatsRow->SprintAccel;
            BrakingDecelWalking = StatsRow->BrakingDecelWalking;


            // Apply the initial walk speed
            MoveComp = GetCharacterMovement();
            if (MoveComp)
            {
                MoveComp->MaxWalkSpeed = WalkSpeed;
                MoveComp->MaxAcceleration = WalkAccel;
                MoveComp->BrakingDecelerationWalking = BrakingDecelWalking;
                MoveComp->GroundFriction = 12.0f;
                MoveComp->bOrientRotationToMovement = true;

            }
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("AF13CharacterBase::BeginPlay(): Could not find row '%s' in CharacterStatsTable."), *StatsRowName.ToString());
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AF13CharacterBase::BeginPlay(): CharacterStatsTable or StatsRowName is not set."));
    }

    // Now that the pawn definitely has a valid PlayerController (and thus a LocalPlayer),
    // we can register our Enhanced Input Mapping Context:
    AddInputMappingContext();
}

void AF13CharacterBase::AddInputMappingContext()
{
    // Get the PlayerController for this pawn
    APlayerController* PC = Cast<APlayerController>(GetController());
    if (PC == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("AF13CharacterBase::AddInputMappingContext(): Pawn has no PlayerController yet."));
        return;
    }

    // The Enhanced Input subsystem only lives on the LocalPlayer
    ULocalPlayer* LP = PC->GetLocalPlayer();
    if (LP == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("AF13CharacterBase::AddInputMappingContext(): PlayerController has no LocalPlayer."));
        return;
    }

    // Grab the EnhancedInputLocalPlayerSubsystem
    if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem =
        LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
    {
        if (IMC_JasonPart3)
        {
            EnhancedInputSubsystem->AddMappingContext(IMC_JasonPart3, 0);
            UE_LOG(LogTemp, Log, TEXT("Added IMC_JasonPart3 to EnhancedInputLocalPlayerSubsystem."));
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("AF13CharacterBase::AddInputMappingContext(): IMC_JasonPart3 is NULL in Blueprint!"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("AF13CharacterBase::AddInputMappingContext(): Could not get EnhancedInputLocalPlayerSubsystem"));
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

    AddMovementInput(ForwardDir, MovementVector.Y);
    AddMovementInput(RightDir, MovementVector.X);
}

void AF13CharacterBase::Look(const FInputActionValue& Value)
{
    // Value.Get<FVector2D>() is (X = Yaw input, Y = Pitch input)
    const FVector2D LookAxisVector = Value.Get<FVector2D>();

    UE_LOG(LogTemp, Warning, TEXT("Look fired: X=%f  Y=%f"),
        LookAxisVector.X, LookAxisVector.Y);


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
    bIsSprinting = true;

    if (!MoveComp)
        return;

    MoveComp->MaxWalkSpeed = SprintSpeed;

    const float SpeedSqr = GetVelocity().SizeSquared();
    if (SpeedSqr >= WalkSpeed * WalkSpeed)
    {
        MoveComp->MaxAcceleration = SprintAccel;
        MoveComp->BrakingDecelerationWalking = 0.f;
        bWasAtWalkSpeed = false;
    }
    else
    {
        // still below walk‐speed; keep walking acc until you cross threshold
        MoveComp->MaxAcceleration = WalkAccel;
        MoveComp->BrakingDecelerationWalking = 2048.f;
        bWasAtWalkSpeed = true;
    }
}

void AF13CharacterBase::SprintReleased(const FInputActionValue& Value)
{
    bIsSprinting = true;

    if (!MoveComp)
        return;

    // Revert immediately to walking settings
    MoveComp->MaxWalkSpeed = WalkSpeed;
    MoveComp->MaxAcceleration = WalkAccel;
    MoveComp->BrakingDecelerationWalking = 2048.f;
    bWasAtWalkSpeed = true;
}

void AF13CharacterBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!MoveComp || !bIsSprinting)
        return;

    // Only check threshold crossing while sprinting:
    const float SpeedSqr = GetVelocity().SizeSquared();
    const float WalkSpeedSqr = WalkSpeed * WalkSpeed;

    // If we just crossed from below WalkSpeed to ≥WalkSpeed, switch to sprint‐accel:
    if (bWasAtWalkSpeed && SpeedSqr >= WalkSpeedSqr)
    {
        MoveComp->MaxAcceleration = SprintAccel;
        MoveComp->BrakingDecelerationWalking = 0.f;
        bWasAtWalkSpeed = false;
    }
    // If you somehow dipped back below WalkSpeed (e.g. hit a wall), revert to walk‐accel:
    else if (!bWasAtWalkSpeed && SpeedSqr < WalkSpeedSqr)
    {
        MoveComp->MaxAcceleration = WalkAccel;
        MoveComp->BrakingDecelerationWalking = 2048.f;
        bWasAtWalkSpeed = true;
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
