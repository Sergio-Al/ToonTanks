// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
	// Get references and game win/lose conditions.
	// Call HandleGameStart() to initialise the start countdown, turret activation, pawn check etc.
	Super::BeginPlay();
	
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	
}

void ATankGameModeBase::HandleGameStart()
{
	
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	
}
