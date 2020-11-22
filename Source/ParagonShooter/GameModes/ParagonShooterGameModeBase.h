// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ParagonShooterGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PARAGONSHOOTER_API AParagonShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void ActorDied(APawn* Actor);
	
};
