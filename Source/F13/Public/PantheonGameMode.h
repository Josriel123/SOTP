#pragma once

#include "CoreMinimal.h"
#include "HMS_GameMode.h"
#include "GameFramework/GameModeBase.h"
#include "PantheonGameMode.generated.h"

class APantheonPlayerController;
class APantheonPlayerState;
class APantheonGameState;
class AAIController;
class APantheonBotController;

USTRUCT()
struct FPendingReplace
{
	GENERATED_BODY()

	TWeakObjectPtr<APawn> Pawn;
	FTransform             Transform;
	FVector                Velocity = FVector::ZeroVector;
	TSubclassOf<APawn>     PawnClass = nullptr;
};


UCLASS()
class F13_API APantheonGameMode : public AHMS_GameMode
{
	GENERATED_BODY()

public:
	APantheonGameMode();

	// When a new player has fully connected, this function is called.
	virtual void PostLogin(APlayerController* NewPlayer) override;

	/** Override so we can auto-spawn bots and pick the killer before play begins */
	virtual void StartMatch() override;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& Error) override;

	UPROPERTY(BlueprintReadWrite, Category = "Variables")
	TSubclassOf<APawn> PawnToSpawn;

	UPROPERTY(EditDefaultsOnly, Category = "Bots")
	TSubclassOf<AAIController> BotControllerClass;

	static constexpr int32 kMaxPlayers = 10;   // killer + 9 survivors

	virtual AHMS_PlayerController* HMS_PickNewHost_Implementation() override;
	/** Prevent a second pawn being spawned after we swap a human into a bot */
	virtual void RestartPlayer(AController* NewPlayer) override;
	virtual void Logout(AController* Exiting) override;
	void RememberLeavingPawn(AController* PC, APawn* Pawn, const FTransform& Xform, const FVector& Vel = FVector::ZeroVector);
	virtual void HandleMatchIsWaitingToStart() override;

	TArray<APlayerStart*> CachedStarts;
	int32                 NextStartIndex = 0;

	UPROPERTY(VisibleAnywhere)
	bool bIsRehostGame = false;

	// Should we fill the match with bots when starting?
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bots")
	bool bSpawnBots = true;

	UPROPERTY()
	TSet<TWeakObjectPtr<AController>> PendingSilentRemovals;

	// --- Keep pawn in place after a bot->player swap ---
	TSet<TWeakObjectPtr<AController>> SkipNextRestart;


protected:
	/* ---------- helpers implemented in PantheonGameMode.cpp ---------- */
	void AssignRoles();
	void FillWithBots();
	void PickRandomKiller();
	void ReplaceBotIfPossible(APlayerController* JoiningPC);
	int32 ExpectedHumans = 1;
	void SpawnReplacementBotAt(const FTransform& Xf, TSubclassOf<APawn> PawnClass, const FVector& InVelocity);
	void TagPawnWithPlayer(APawn* Pawn, APantheonPlayerState* PS);

	void EnsureBotPlayerState(AAIController* AI);


	UPROPERTY()
	TMap<TWeakObjectPtr<AController>, FPendingReplace> PendingReplacements;

	//void RememberLeavingPawn(AController* PC, APawn* Pawn, const FTransform& Xform);
	
	UFUNCTION(BlueprintCallable, Category = "HMS")
	void HMS_OnGameRehosted_Cpp();


private:

	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;
	class AAIController* SpawnBotControllerAndPossessExisting(APawn* ExistingPawn, const FTransform& DesiredTransform);
	
};