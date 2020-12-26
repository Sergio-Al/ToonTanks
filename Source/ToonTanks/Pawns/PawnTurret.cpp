// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
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
}

// Called every frame

void APawnTurret::CheckFireCondition()
{
	// If Player == null || is Dead Then BAIL!!!

	// If Player IS in range Then FIRE!!!

	UE_LOG(LogTemp, Warning, TEXT("Fire Condition Checked!"));
}


void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
