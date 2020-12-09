// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterHUD.h"
#include "ParagonShooter/PlayerControllers/ShooterPlayerController.h"
#include "ParagonShooter/Actors/PickUp.h"

void AShooterHUD::DrawHUD()
{
	Super::DrawHUD();

	if (Controller)
	{
		APickUp* PickUp = Controller->GetCharacterOverlappedPickUp();

		if (PickUp)
		{
			FVector2D ScreenLocation;
			Controller->ProjectWorldLocationToScreen(PickUp->GetColliderCenter(), ScreenLocation);
			DrawText(TEXT("E: Pick Up"), FLinearColor::White, ScreenLocation.X, ScreenLocation.Y, HUDFont);
		}
	}

}

void AShooterHUD::BeginPlay()
{
	Super::BeginPlay();

	Controller = Cast<AShooterPlayerController>(GetOwningPlayerController());
}
