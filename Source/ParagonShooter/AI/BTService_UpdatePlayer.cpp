// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_UpdatePlayer.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTService_UpdatePlayer::UBTService_UpdatePlayer()
{
	NodeName = TEXT("Update Player");
}

void UBTService_UpdatePlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* Player = UGameplayStatics::GetPlayerPawn(this, 0);

	UBlackboardComponent* BBComp = OwnerComp.GetBlackboardComponent();

	AAIController* AIController = OwnerComp.GetAIOwner();

	if (BBComp != nullptr && AIController != nullptr && Player != nullptr && AIController->LineOfSightTo(Player))
	{
		BBComp->SetValueAsObject(GetSelectedBlackboardKey(), Player);
	}
	else
	{
		BBComp->ClearValue(GetSelectedBlackboardKey());
	}
}