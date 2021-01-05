// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

/**
 * 
 */
class USpringArmComponent;
class UCameraComponent;
UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	FVector MoveDirection;
	FQuat RotationDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta=(AllowPrivateAccess = "true"))
	float MoveSpeed = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta=(AllowPrivateAccess = "true"))
	float RotateSpeed = 100.f;

	/**
	 * @brief
	 * This will give us the player controller to add functionality
	 */
	APlayerController* PlayerControllerRef;
	bool bIsPlayerAlive = true;

	void CalculateMoveInput(float Value);
	void CalculateRotateInput(float Value);

	void Move();
	void Rotate();

public:
	APawnTank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	/**
     * Call BasePawn HandleDestruction to play effects
     */
    virtual void HandleDestruction() override;

	bool GetIsPlayerAlive();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
};
