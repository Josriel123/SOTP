#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"     
#include "Engine/DataTable.h"
#include "F13CharacterBase.generated.h"

//
class UInputMappingContext;
class UInputAction;
class UEnhancedInputLocalPlayerSubsystem;
class UEnhancedInputComponent;
class USpringArmComponent;
class UCameraComponent;

/**
 *  Base class for both Killer and Survivor pawns.
 *  Implements:
 *   - Enhanced Input setup (IMC, IA_Move, IA_Look, IA_Jump, IA_Sprint)
 *   - Walk / Look / Jump / Sprint logic
 */
UCLASS()
class F13_API AF13CharacterBase : public ACharacter
{
    GENERATED_BODY()

public:
    AF13CharacterBase();

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
    virtual void OnConstruction(const FTransform& Transform) override;

    //----- Character stats/abilities ----------------------------------------------------------

    /** DataTable containing per‐character stats (WalkSpeed, etc.) */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
    UDataTable* CharacterStatsTable;

    /** Row name in CharacterStatsTable to look up for this character */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
    FName StatsRowName;

    /** Locomotion / Ability properties that get filled in from CharacterStatsTable row */
    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    float WalkSpeed;

    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    float SprintSpeed;

    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    float WalkAccel;

    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    float SprintAccel;

    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    float BrakingDecelerationWalking;

    bool bCanDash;
    float DashDistance;
    float DashCooldown;
    bool bCanDoubleJump;
    float DoubleJumpZVelocity;

    // ─── Enhanced Input Actions ─────────────────────────────────────────────────────────────────

    /** The IMC (Input Mapping Context) asset (set automatically via ConstructorHelpers) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputMappingContext* IMC_JasonPart3;

    /** Input Actions (also loaded with ConstructorHelpers) */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
    UInputAction* IA_Move;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
    UInputAction* IA_Look;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
    UInputAction* IA_Jump;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
    UInputAction* IA_Sprint;

    //------------Camera settings -------------------------------------------------

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    UCameraComponent* FollowCamera;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Settings")
    float CameraHeightOffset = 90.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Settings")
    float CameraDistance = 250.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Settings")
    FRotator CameraRelativeRotation = FRotator(-10.f, 0.f, 0.f);

private:
    /** Safely attempt to add our Enhanced Input Mapping Context to the local player subsystem */
    void AddInputMappingContext();

    // ─── CALLBACKS FOR ENHANCED INPUT ────────────────────────────────────────────────────

    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
    void JumpPressed(const FInputActionValue& Value);
    void JumpReleased(const FInputActionValue& Value);
    void SprintPressed(const FInputActionValue& Value);
    void SprintReleased(const FInputActionValue& Value);
};
