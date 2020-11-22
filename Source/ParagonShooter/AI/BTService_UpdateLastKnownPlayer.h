// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_UpdateLastKnownPlayer.generated.h"

/**
 *
 */
UCLASS()
class PARAGONSHOOTER_API UBTService_UpdateLastKnownPlayer : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_UpdateLastKnownPlayer();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};