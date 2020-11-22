// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 *
 */
UCLASS()
class PARAGONSHOOTER_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	bool GetIsPawnDead();

private:
	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* BehaviorTree;

};
