// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:

	/**
	 * This function will disable input in the player depending the bool param
	 * @param SetPlayerEnabled true will enable the input, false will disable.
	 */
	void SetPlayerEnabledState(bool SetPlayerEnabled);
	
};
