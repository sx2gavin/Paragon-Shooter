// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParagonShooter/Actors/PickUp.h"
#include "PickUp_Ammo.generated.h"

/**
 * 
 */
UCLASS()
class PARAGONSHOOTER_API APickUp_Ammo : public APickUp
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	int32 RestockAmmoAmount = 90;

public:
	virtual bool CheckPickUpCondition(class AShooterCharacter* ActionCharacter) override;
	virtual void PerformPickUp(AShooterCharacter* ActionCharacter) override;
	
};
