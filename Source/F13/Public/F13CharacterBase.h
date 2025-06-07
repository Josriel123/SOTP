// F13CharacterBase.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Engine/DataTable.h"
#include "F13CharacterBase.generated.h"

class UInputMappingContext;
class UInputAction;
class UEnhancedInputComponent;
class UEnhancedInputLocalPlayerSubsystem;
class UCharacterMovementComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class F13_API AF13CharacterBase : public ACharacter
{
    GENERATED_BODY()

public:
    AF13CharacterBase();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
    virtual void OnConstruction(const FTransform& Transform) override;

    // ── Network replication ───────────────────────────────────────────────────────────
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    /** Stats (filled from your DataTable via Blueprint) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    UDataTable* CharacterStatsTable;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    FName StatsRowName;

    /** Speeds & accels (populated in BeginPlay) */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement|Speed")
    float WalkSpeed;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement|Speed")
    float SprintSpeed;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement|Accel")
    float WalkAccel;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement|Accel")
    float SprintAccel;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement|Accel")
    float BrakingDecelWalking;

    /** Enhanced Input assets (set via Blueprint defaults) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputMappingContext* IMC_JasonPart3;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* IA_Move;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* IA_Look;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* IA_Jump;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* IA_Sprint;

    //-------------Camera setup----------------------------
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    UCameraComponent* FollowCamera;

    // If you have these properties in Blueprint:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    float CameraDistance = 250.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    float CameraHeightOffset = 90.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    FRotator CameraRelativeRotation = FRotator(-10.f, 0.f, 0.f);


private:
    UCharacterMovementComponent* MoveComp;

    /** Sprint state, replicated to server so movement stays in sync */
    UPROPERTY(ReplicatedUsing = OnRep_IsSprinting)
    bool bIsSprinting;

    /** Internal flag to detect crossing the walk-speed threshold */
    bool bWasAtWalkSpeed;

    /** Called on clients when bIsSprinting changes */
    UFUNCTION()
    void OnRep_IsSprinting();

    /** RPC to tell the server “I started/stopped sprinting” */
    UFUNCTION(Server, Reliable, WithValidation)
    void ServerSetSprinting(bool bNewSprinting);


    /** Add your Enhanced Input Mapping Context to the local player */
    void AddInputMappingContext();

    /** Input callbacks */
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
    void JumpPressed(const FInputActionValue& Value);
    void JumpReleased(const FInputActionValue& Value);
    void SprintPressed(const FInputActionValue& Value);
    void SprintReleased(const FInputActionValue& Value);
};
