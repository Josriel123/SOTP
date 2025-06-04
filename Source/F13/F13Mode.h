#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "F13Mode.generated.h"

class AF13PlayerController;
class AF13PlayerState;
class AF13GameState;
class AF13KillerCharacter;
class AF13SurvivorCharacter;

UCLASS()
class F13_API AF13Mode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AF13Mode();
};

