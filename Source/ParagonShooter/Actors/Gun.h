// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParagonShooter/Actors/Weapon.h"
#include "Gun.generated.h"

UCLASS()
class PARAGONSHOOTER_API AGun : public AWeapon
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRange = 2000;

	UPROPERTY(EditDefaultsOnly)
	UParticleSystem* ImpactFlash;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* ImpactSound;

public:	
	// Sets default values for this actor's properties
	AGun();

	virtual void FireLoadedWeapon() override;

};
