// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "ParagonShooter/Characters/ShooterCharacter.h"
#include "ParagonShooter/AI/EnemyAIController.h"
#include "EngineUtils.h"


void AKillEmAllGameMode::ActorDied(APawn* Actor)
{
	Super::ActorDied(Actor);


	if (Actor->GetController<APlayerController>() != nullptr)
	{
		GameOver(false);
		return;
	}

	bool bHasEnemy = false;
	for (AEnemyAIController* AIController : TActorRange<AEnemyAIController>(GetWorld()))
	{
		if (AIController != nullptr && !AIController->GetIsPawnDead())
		{
			bHasEnemy = true;
			break;
		}
	}

	if (!bHasEnemy)
	{
		GameOver(true);
	}

}

void AKillEmAllGameMode::GameOver(bool bPlayerIsWinner)
{
	TArray<AActor*> ControllerArray;
	UGameplayStatics::GetAllActorsOfClass(this, AController::StaticClass(), ControllerArray);

	for (AActor* Actor : ControllerArray)
	{
		AController* Controller = Cast<AController>(Actor);
		if (Controller != nullptr)
		{
			bool bIsPlayerController = Cast<APlayerController>(Controller) != nullptr;
			Controller->GameHasEnded(Controller->GetPawn(), bIsPlayerController == bPlayerIsWinner);
		}
	}
}

