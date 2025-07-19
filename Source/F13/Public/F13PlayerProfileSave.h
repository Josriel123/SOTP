// F13PlayerProfileSave.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "F13PlayerProfileSave.generated.h"

USTRUCT(BlueprintType)
struct FPlayerProfileData
{
    GENERATED_BODY()

    UPROPERTY() FName SurvivorRowKey;
    UPROPERTY() FName KillerRowKey;
};

UCLASS()
class UF13PlayerProfileSave : public USaveGame
{
    GENERATED_BODY()

public:
    UPROPERTY() int32              SaveVersion = 1;
    UPROPERTY() FPlayerProfileData Profile;
};
