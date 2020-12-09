// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShooterHUD.generated.h"

/**
 * 
 */
UCLASS()
class PARAGONSHOOTER_API AShooterHUD : public AHUD
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class AShooterPlayerController* Controller;

	UPROPERTY(EditDefaultsOnly)
	class UFont* HUDFont;

public:
	/** The Main Draw loop for the hud.  Gets called before any messaging.  Should be subclassed */
	virtual void DrawHUD() override;

protected:

	virtual void BeginPlay() override;
	
};
