// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParagonShooterGameModeBase.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PARAGONSHOOTER_API AKillEmAllGameMode : public AParagonShooterGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void ActorDied(APawn* Actor) override;

private:
	void GameOver(bool bPlayerIsWinner);
	
};
