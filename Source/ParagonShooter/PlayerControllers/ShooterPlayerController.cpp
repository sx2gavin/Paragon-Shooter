// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

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

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	StartWidget = CreateWidget<UUserWidget>(this, StartUserWidgetType);
	StartWidget->AddToPlayerScreen();

	FTimerHandle StartWidgetTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(StartWidgetTimerHandle, StartWidget, &UUserWidget::RemoveFromViewport, 3);

	HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetType);
	HUDWidget->AddToViewport();
}

void AShooterPlayerController::RestartGame()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}
