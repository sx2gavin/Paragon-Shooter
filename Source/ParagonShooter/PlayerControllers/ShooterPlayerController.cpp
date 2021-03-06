// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "ParagonShooter/Actors/PickUp.h"
#include "ParagonShooter/Characters/ShooterCharacter.h"

AShooterPlayerController::AShooterPlayerController()
{}

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	bIsPlayerWinner = bIsWinner;

	EndWidget = CreateWidget<UUserWidget>(this, GameOverUserWidgetType);
	EndWidget->AddToPlayerScreen();

	FTimerHandle RestartTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(RestartTimerHandle, this, &AShooterPlayerController::RestartGame, 5);
}

bool AShooterPlayerController::GetIsPlayerWinner() const
{
	return bIsPlayerWinner;
}

APickUp* AShooterPlayerController::GetCharacterOverlappedPickUp()
{
	AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(GetCharacter());

	if (ShooterCharacter != nullptr)
	{
		return ShooterCharacter->GetOverlappedPickUp();
	}

	return nullptr;
}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	StartWidget = CreateWidget<UUserWidget>(this, StartUserWidgetType);
	StartWidget->AddToPlayerScreen();

	FTimerHandle StartWidgetTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(StartWidgetTimerHandle, StartWidget, &UUserWidget::RemoveFromViewport, 10);

	HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetType);
	HUDWidget->AddToViewport();
}

void AShooterPlayerController::RestartGame()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}
