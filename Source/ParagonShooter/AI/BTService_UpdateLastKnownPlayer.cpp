// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_UpdateLastKnownPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTService_UpdateLastKnownPlayer::UBTService_UpdateLastKnownPlayer()
{
	NodeName = TEXT("Update Last Known Player Location");
}

void UBTService_UpdateLastKnownPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	APawn* Player = UGameplayStatics::GetPlayerPawn(this, 0);

	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();

	if (BlackboardComponent != nullptr && Player != nullptr)
	{
		BlackboardComponent->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
	}
}
