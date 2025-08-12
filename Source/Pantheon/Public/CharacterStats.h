#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CharacterStats.generated.h"

/**
 * A single row in our CharacterStats DataTable.
 * Contains both basic movement floats and flags/parameters for custom abilities.
 */

USTRUCT(BlueprintType)
struct FCharacterStats : public FTableRowBase
{
    GENERATED_BODY()

    // ─── Basic Locomotion ───────────────────────────────────────────────────

    /** Walking speed (cm/s). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Speed")
    float WalkSpeed = 350.f;

    /** Sprinting speed (cm/s). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Speed")
    float SprintSpeed = 600.f;

    /** Acceleration (cm/s²) from Rest → Walk. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Accel")
    float WalkAccel = 2048.f;

    /** Acceleration (cm/s²) from Walk → Sprint. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Accel")
    float SprintAccel = 4096.f;

    /** Braking deceleration (cm/s²) when walking. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Braking")
    float BrakingDecelWalking = 2048.f;


    // ─── Custom Ability Flags & Parameters ──────────────────────────────────

    /** Does this character have a “dash” ability? */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
    bool bCanDash = false;

    /** If bCanDash = true, how far (units) does the dash move? */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities", meta = (EditCondition = "bCanDash"))
    float DashDistance = 0.f;

    /** If bCanDash = true, how long (seconds) is the dash cooldown? */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities", meta = (EditCondition = "bCanDash"))
    float DashCooldown = 0.f;

    /** Does this character have a double‐jump? */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
    bool bCanDoubleJump = false;

    /** If bCanDoubleJump = true, what is the double‐jump Z velocity? */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities", meta = (EditCondition = "bCanDoubleJump"))
    float DoubleJumpZVelocity = 0.f;

    /** Default constructor with sensible defaults. */
    FCharacterStats()
        : WalkSpeed(350.f)
        , SprintSpeed(600.f)
        , WalkAccel(2048.f)
        , SprintAccel(4096.f)
        , BrakingDecelWalking(2048.f)
        , bCanDash(false)
        , DashDistance(0.f)
        , DashCooldown(0.f)
        , bCanDoubleJump(false)
        , DoubleJumpZVelocity(0.f)
    {
    }
};

