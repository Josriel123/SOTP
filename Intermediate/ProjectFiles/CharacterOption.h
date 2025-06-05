#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CharacterOption.generated.h"

/**
 * A single row in our Character DataTable:
 *   RoleName:      “Killer” or “Survivor”
 *   CharacterName: Display string for UI
 *   PawnClass:     Which Pawn subclass to spawn when chosen
 */
USTRUCT(BlueprintType)
struct FCharacterOption : public FTableRowBase
{
    GENERATED_BODY()

    // Role string (for filtering in UI). Could also use an enum if you prefer.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterSelection")
    FString RoleName;

    // Display name in UI (e.g. “Jason (Part 3)”, “Brutal Billy”)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterSelection")
    FString CharacterDisplayName;

    // The actual Pawn subclass to spawn for this character
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterSelection")
    TSubclassOf<APawn> PawnClass;
};
