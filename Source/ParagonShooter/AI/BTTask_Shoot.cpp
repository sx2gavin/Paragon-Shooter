// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "ParagonShooter/Characters/ShooterCharacter.h"
#include "AIController.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAIController* AIController = OwnerComp.GetAIOwner();

	if (AIController)
	{
		AShooterCharacter* Character = AIController->GetPawn<AShooterCharacter>();
		if (Character != nullptr)
		{
			Character->Fire();
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
