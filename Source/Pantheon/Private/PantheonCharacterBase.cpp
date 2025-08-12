// PantheonCharacterBase.cpp

#include "PantheonCharacterBase.h"
#include "CharacterStats.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerInput.h"
#include "Components/InputComponent.h"
#include "Engine/LocalPlayer.h"
#include "Net/UnrealNetwork.h"

APantheonCharacterBase::APantheonCharacterBase()
    : MoveComp(nullptr)
    , bIsSprinting(false)
    , bWasAtWalkSpeed(true)
{
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




    // Increase network update rate for smoother movement replication
    // Use the new API for network-update frequency
    SetNetUpdateFrequency(100.f);
    SetMinNetUpdateFrequency(30.f);
}

void APantheonCharacterBase::BeginPlay()
{
    Super::BeginPlay();

    bUseControllerRotationYaw = false;

    // Cache the movement component
    MoveComp = GetCharacterMovement();
    if (!MoveComp) return;

    // Fetch stats from the DataTable (both client & server)
    if (CharacterStatsTable && StatsRowName != NAME_None)
    {
        static const FString Context(TEXT("CharacterStatsLookup"));
        if (const FCharacterStats* StatsRow = CharacterStatsTable->FindRow<FCharacterStats>(StatsRowName, Context, true))
        {
            WalkSpeed = StatsRow->WalkSpeed;
            WalkAccel = StatsRow->WalkAccel;
            SprintSpeed = StatsRow->SprintSpeed;
            SprintAccel = StatsRow->SprintAccel;
            BrakingDecelWalking = StatsRow->BrakingDecelWalking;
        }
    }

    // Apply initial movement settings
    if (MoveComp)
    {
        MoveComp->MaxWalkSpeed = WalkSpeed;
        MoveComp->MaxAcceleration = WalkAccel;
        MoveComp->BrakingDecelerationWalking = BrakingDecelWalking;
        MoveComp->GroundFriction = 12.0f;
        MoveComp->bOrientRotationToMovement = true;

    }

    // Network smoothing for remote proxies
    MoveComp->NetworkSmoothingMode = ENetworkSmoothingMode::Exponential;
}


void APantheonCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Enhanced Input bindings
    if (auto* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        if (IA_Move)   EnhancedInput->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APantheonCharacterBase::Move);
        if (IA_Look)   EnhancedInput->BindAction(IA_Look, ETriggerEvent::Triggered, this, &APantheonCharacterBase::Look);
        if (IA_Jump)
        {
            EnhancedInput->BindAction(IA_Jump, ETriggerEvent::Started, this, &APantheonCharacterBase::JumpPressed);
            EnhancedInput->BindAction(IA_Jump, ETriggerEvent::Completed, this, &APantheonCharacterBase::JumpReleased);
        }
        if (IA_Sprint)
        {
            EnhancedInput->BindAction(IA_Sprint, ETriggerEvent::Started, this, &APantheonCharacterBase::SprintPressed);
            EnhancedInput->BindAction(IA_Sprint, ETriggerEvent::Completed, this, &APantheonCharacterBase::SprintReleased);
        }
    }

    // Only run input-mode setup / add mapping on the locally controlled pawn
    if (IsLocallyControlled())
    {
        if (auto* PC = Cast<APlayerController>(GetController()))
        {
            PC->bShowMouseCursor = false;
            PC->SetInputMode(FInputModeGameOnly());
        }
        AddInputMappingContext();
    }
}

void APantheonCharacterBase::Move(const FInputActionValue& Value)
{
    const FVector2D MovementVector = Value.Get<FVector2D>();
    if (!Controller || !MoveComp) return;

    FRotator YawRot(0.f, Controller->GetControlRotation().Yaw, 0.f);
    AddMovementInput(FRotationMatrix(YawRot).GetUnitAxis(EAxis::X), MovementVector.Y);
    AddMovementInput(FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y), MovementVector.X);
}

void APantheonCharacterBase::Look(const FInputActionValue& Value)
{
    const FVector2D LookAxis = Value.Get<FVector2D>();
    AddControllerYawInput(LookAxis.X);
    AddControllerPitchInput(LookAxis.Y);
}

void APantheonCharacterBase::JumpPressed(const FInputActionValue&) { Jump(); }
void APantheonCharacterBase::JumpReleased(const FInputActionValue&) { StopJumping(); }

void APantheonCharacterBase::SprintPressed(const FInputActionValue&)
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
        // still below walk-speed; keep walking acc until you cross threshold
        MoveComp->MaxAcceleration = WalkAccel;
        MoveComp->BrakingDecelerationWalking = 2048.f;
        bWasAtWalkSpeed = true;
    }
    ServerSetSprinting(true);
}

void APantheonCharacterBase::SprintReleased(const FInputActionValue&)
{
    bIsSprinting = false;

    if (!MoveComp)
        return;

    // Revert immediately to walking settings
    MoveComp->MaxWalkSpeed = WalkSpeed;
    MoveComp->MaxAcceleration = WalkAccel;
    MoveComp->BrakingDecelerationWalking = 2048.f;
    bWasAtWalkSpeed = true;
    ServerSetSprinting(false);
}

void APantheonCharacterBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!MoveComp || !bIsSprinting)
        return;

    // While sprinting, detect when we cross the walk-speed threshold
    const float SpeedSqr = MoveComp->Velocity.SizeSquared();
    const float WalkSpeedSqr = WalkSpeed * WalkSpeed;

    if (bWasAtWalkSpeed && SpeedSqr >= WalkSpeedSqr)
    {
        MoveComp->MaxAcceleration = SprintAccel;
        MoveComp->BrakingDecelerationWalking = 0.f;
        bWasAtWalkSpeed = false;
    }
    // If you somehow dipped back below WalkSpeed (e.g. hit a wall), revert to walk-accel:
    else if (!bWasAtWalkSpeed && SpeedSqr < WalkSpeedSqr)
    {
        MoveComp->MaxAcceleration = WalkAccel;
        MoveComp->BrakingDecelerationWalking = 2048.f;
        bWasAtWalkSpeed = true;
    }
    
}

void APantheonCharacterBase::AddInputMappingContext()
{
    if (auto* PC = Cast<APlayerController>(GetController()))
        if (auto* LP = PC->GetLocalPlayer())
            if (auto* SubSys = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
            {
                if (IMC_JasonPart3)
                    SubSys->AddMappingContext(IMC_JasonPart3, 0);
            }
}

void APantheonCharacterBase::OnRep_IsSprinting()
{
    if (bIsSprinting)
    {
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
            // still below walk-speed; keep walking acc until you cross threshold
            MoveComp->MaxAcceleration = WalkAccel;
            MoveComp->BrakingDecelerationWalking = 2048.f;
            bWasAtWalkSpeed = true;
        }
    }
    else
    {
        // Revert to walk settings
        MoveComp->MaxWalkSpeed = WalkSpeed;
        MoveComp->MaxAcceleration = WalkAccel;
        MoveComp->BrakingDecelerationWalking = BrakingDecelWalking;
        bWasAtWalkSpeed = true;
    }
}


bool APantheonCharacterBase::ServerSetSprinting_Validate(bool bNewSprinting)
{
    return true;
}

void APantheonCharacterBase::ServerSetSprinting_Implementation(bool bNewSprinting)
{
    bIsSprinting = bNewSprinting;
    OnRep_IsSprinting();  // immediately apply on the server
}

void APantheonCharacterBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(APantheonCharacterBase, LastHumanUniqueId);
    DOREPLIFETIME(APantheonCharacterBase, bIsSprinting);
}

void APantheonCharacterBase::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    if (CameraBoom)
    {
        CameraBoom->TargetArmLength = CameraDistance;
        FollowCamera->SetRelativeRotation(CameraRelativeRotation);
        CameraBoom->SocketOffset = FVector(0.f, 0.f, CameraHeightOffset);
    }
}


