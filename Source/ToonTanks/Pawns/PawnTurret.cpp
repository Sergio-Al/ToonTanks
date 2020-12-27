// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

APawnTurret::APawnTurret()
{
 	
}

// Called when the game starts or when spawned

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	// This is the general timer of the game world
	// Give us the time instances from the actors in the world
	GetWorld()->GetTimerManager().SetTimer(
		FireRateTimerHandle,
		this, &APawnTurret::CheckFireCondition,
		FireRate,
		true,
		FirstTimeDelay
	);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

// Called every frame

void APawnTurret::CheckFireCondition()
{
	// If Player == null || is Dead Then BAIL!!!
	if(!PlayerPawn)
	{
		return;
	}

	// If Player IS in range Then FIRE!!!
	if(ReturnDistanceToPlayer() <= FireRange)
	{
		Fire();	
	};
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if(!PlayerPawn)
	{
		return 0.f;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
	
}


void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
	{
		return;
	}
	
	RotateTurret(PlayerPawn->GetActorLocation());

}
