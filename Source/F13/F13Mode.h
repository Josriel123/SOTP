#pragma once

#include "CoreMinimal.h"
#include "HMS_GameMode.h"
#include "GameFramework/GameModeBase.h"
#include "F13Mode.generated.h"

class AF13PlayerController;
class AF13PlayerState;
class AF13GameState;
class AAIController;
class AF13BotController;

UCLASS()
class F13_API AF13Mode : public AHMS_GameMode
{
	GENERATED_BODY()

public:
	AF13Mode();

	// This is the function that actually spawns the pawn for a given PlayerController
	UFUNCTION()
	void HandleCharacterSelected(APlayerController* SelectingPC);

	// When a new player has fully connected, this function is called.
	virtual void PostLogin(APlayerController* NewPlayer) override;

	UPROPERTY(BlueprintReadWrite, Category = "Variables")
	TSubclassOf<APawn> PawnToSpawn;

	UPROPERTY(EditDefaultsOnly, Category = "Bots")
	TSubclassOf<AAIController> BotControllerClass;

	static constexpr int32 kMaxPlayers = 10;   // killer + 9 survivors

	/** Override so we can auto-spawn bots and pick the killer before play begins */
	virtual void StartMatch() override;
	virtual void InitGame(const FString& MapName, const FString& Options, FString& Error) override;
	virtual void HandleMatchIsWaitingToStart() override;



protected:

	virtual void BeginPlay() override;

	/* ---------- helpers implemented in F13Mode.cpp ---------- */
	void FillWithBots();
	void PickRandomKiller();
	void ReplaceBotIfPossible(APlayerController* JoiningPC);
	int32 ExpectedHumans = 1;

private:

	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

};