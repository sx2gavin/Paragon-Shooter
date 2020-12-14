// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParagonShooter/Actors/PickUp.h"
#include "PickUp_Health.generated.h"

/**
 * 
 */
UCLASS()
class PARAGONSHOOTER_API APickUp_Health : public APickUp
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	float RecoverHealth = 100.f;

public:
	virtual bool CheckPickUpCondition(class AShooterCharacter* ActionCharacter) override;

	/// <summary>
	/// Heal the character for a certain amount of health. If character's health is full, don't pick up the health.
	/// </summary>
	/// <param name="ActionCharacter"></param>
	/// <returns></returns>
	virtual void PerformPickUp(class AShooterCharacter* ActionCharacter) override;
	
};
