// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

class UUserWidget;

UCLASS()
class PARAGONSHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AShooterPlayerController();

	/**
	 * Called from game mode upon end of the game, used to transition to proper state. 
	 * @param EndGameFocus Actor to set as the view target on end game
	 * @param bIsWinner true if this controller is on winning team
	 */
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

	UFUNCTION(BlueprintPure)
	bool GetIsPlayerWinner() const;
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> StartUserWidgetType;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> GameOverUserWidgetType;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> HUDWidgetType;

	UPROPERTY()
	UUserWidget* StartWidget;
	
	UPROPERTY()
	UUserWidget* EndWidget;

	UPROPERTY()
	UUserWidget* HUDWidget;

	bool bIsPlayerWinner;

	void RestartGame();
};
