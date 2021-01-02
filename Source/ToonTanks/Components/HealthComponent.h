// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


class ATankGameModeBase;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOONTANKS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere)
	float DefaultHealth = 100.f;
	float Health = 0.f;
	
	ATankGameModeBase* GameModeRef;
	
public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	/**
	 * This function will emulate the AnyDamage event and not overriding,
	 * the params will be the same
	 * @param DamagedActor - Actor that will be damage.
	 * @param Damage - The base damage to apply.
	 * @param DamageType - The type of damage that will apply, class that describes the damage that was done.
	 * @param InstigatedBy - Controller that was responsible for causing this damage.
	 * @param DamageCauser - Actor that actually caused the damage (e.g. the grenade that exploded)
	 * @return Actual damage the ended up being applied to the actor.
	 */
	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
		
};
