// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ParagonShooter/Characters/ShooterCharacter.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	// MoveToActor(PlayerPawn);

	RunBehaviorTree(BehaviorTree);
	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
}

bool AEnemyAIController::GetIsPawnDead()
{
	AShooterCharacter* EnemyCharacter = GetPawn<AShooterCharacter>();

	if (EnemyCharacter != nullptr)
	{
		return EnemyCharacter->GetIsDead();
	}

	return true;
}