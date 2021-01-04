// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

class APawnTurret;
class APawnTank;
class APlayerControllerBase;
UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	APawnTank* PlayerTank;
	int32 TargetTurrets = 0;
	APlayerControllerBase* PlayerControllerRef;

	int32 GetTargetTurretCount();
	/**
	 * Initialise the start countdown, turret activation, pawn check, etc.
	 * Call Blueprint version GameStart().
	 */
	void HandleGameStart();
	/**
	 * See if the player has destroyed all the turrets, show win result.
	 * else if turret destroyed player, show lose result.
	 * call Blueprint version GameOver(bool).
	 * @param PlayerWon True for player Won, false for turret won
	 */
	void HandleGameOver(bool PlayerWon);


public:

	/**
	 * Check what type of Actor died.
	 * If turret, tally.
	 * If Player -> go to lose condition
	 * @param DeadActor The actor who dies (tank - turret)
	 */
	void ActorDied(AActor* DeadActor);

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Game Loop")
	int32 StartDelay = 3;

	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);
	
};
