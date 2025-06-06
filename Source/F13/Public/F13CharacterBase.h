// F13CharacterBase.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"               // for FInputActionValue
#include "F13CharacterBase.generated.h"

class UInputMappingContext;
class UInputAction;
class UEnhancedInputComponent;
class UEnhancedInputLocalPlayerSubsystem;
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
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called to bind functionality to input (EnhancedInput)
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

    // ** NEW **
    // Called when this Pawn is possessed by a Controller (only runs on the server for networked games)
    virtual void PossessedBy(AController* NewController) override;


    // Called when someone calls SetActorTransform/Places this actor in the world, etc.
    virtual void OnConstruction(const FTransform& Transform) override;

    virtual void Tick(float DeltaTime) override;



    // ─── UPROPERTYs ─────────────────────────────────────────────────────────────────

    /** Which Enhanced Input Mapping Context to use (set this in Blueprint → Class Defaults). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputMappingContext* IMC_JasonPart3;

    /** Input Action: Move (Vector2D). Pressing W/A/S/D should feed here. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* IA_Move;

    /** Input Action: Look (Vector2D). Mouse X/Y drive this. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* IA_Look;

    /** Input Action: Jump (Triggered). Space bar, etc. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* IA_Jump;

    /** Input Action: Sprint (Triggered). Left Shift, etc. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* IA_Sprint;

    /** Basic walking speed (cm/s) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Speed")
    float WalkSpeed;

    /** Sprinting speed (cm/s) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Speed")
    float SprintSpeed;

    /** Acceleration (cm/s²) when starting from Rest to Walk */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Accel")
    float WalkAccel;

    /** Acceleration (cm/s²) when going from Walk to Sprint */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Accel")
    float SprintAccel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Accel")
    float BrakingDecelWalking;

    /** Spring arm that holds the camera behind the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    USpringArmComponent* CameraBoom;

    /** The actual camera that follows the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    UCameraComponent* FollowCamera;

    //Camera settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Settings")
    float CameraHeightOffset = 90.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Settings")
    float CameraDistance = 250.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Settings")
    FRotator CameraRelativeRotation = FRotator(-10.f, 0.f, 0.f);

    //___________DataTable_____________

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	UDataTable* CharacterStatsTable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    FName StatsRowName;


private:

    UCharacterMovementComponent* MoveComp;

    // Called to add our IMC to the 
    // player's EnhancedInputLocalPlayerSubsystem
    void AddInputMappingContext();

    // ─── CALLBACKS FOR ENHANCED INPUT ────────────────────────────────────────────────────

    // Called every frame that W/A/S/D is pressed (Value holds a FVector2D: X=Right, Y=Forward)
    void Move(const FInputActionValue& Value);

    // Called every frame that the mouse is moved (Value holds a FVector2D: X=Yaw, Y=Pitch)
    void Look(const FInputActionValue& Value);

    // Called when IA_Jump is first triggered (Pressed)
    void JumpPressed(const FInputActionValue& Value);

    // Called when IA_Jump is released
    void JumpReleased(const FInputActionValue& Value);

    // Called when IA_Sprint is first triggered (Pressed)
    void SprintPressed(const FInputActionValue& Value);

    // Called when IA_Sprint is released
    void SprintReleased(const FInputActionValue& Value);

	bool bIsSprinting = false;
    bool bWasAtWalkSpeed = true;

};

