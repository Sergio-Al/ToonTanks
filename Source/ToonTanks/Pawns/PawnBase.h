// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Include allows detailed information for the classes
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

// Class declarations are used commonly in header files for referencing
class UCapsuleComponent;
class AProjectileBase;
class UHealthComponent;
UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

private:
	// COMPONENTS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;
	// VARIABLES
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile Type", meta=(AllowPrivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY(EditAnywhere, Category="Effects")
	UParticleSystem* DeathParticle;
	UPROPERTY(EditAnywhere, Category="Effects")
	USoundBase* DeathSound;
	UPROPERTY(EditAnywhere, Category="Effects")
	TSubclassOf<UMatineeCameraShake> DeathShake;
	 
public:
	// Sets default values for this pawn's properties
	APawnBase();

	/**
	* @brief
	* This function will manage the Destruction. 
	* Plays Death Effects, sound and camera shake.
	* In Turret, informs GameMode Turret died then Destroy() self.
	* In Tank, inform GameMode Player Died	then hide all components and disable movement input.
	* It is a virtual because the destruction will be different in child classes.
	*/
	virtual void HandleDestruction();
protected:

	/**
	 * @brief
	 * This function rotate the turret to face towards the LookAtTarget	when we specified a FVector 
	 * It is not virtual because we don't need to overwrite in child classes
	 * @param LookAtTarget This is required for general purposes passed in from Child classes
	 */
	void RotateTurret(FVector LookAtTarget);

	/**
	 * @brief
	 * This function fires a projectile class at Location facing towards Rotation
	 * Get Projectile Spawn point location and Rotation
	 * It is not virtual because we don't need to overwrite in child classes
	 */
	void Fire();

};
