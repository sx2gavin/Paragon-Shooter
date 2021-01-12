// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParagonShooter/Actors/Weapon.h"
#include "Launcher.generated.h"

/**
 * 
 */
UCLASS()
class PARAGONSHOOTER_API ALauncher : public AWeapon
{
	GENERATED_BODY()

private:
	// Components
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* MissileSpawnLocation;

private:
	// Properties
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AMissile> MissileType;

	UPROPERTY(EditAnywhere, Category = "Properties")
	float ExplosionRadius = 200.0f;
	
public:	
	// Sets default values for this actor's properties
	ALauncher();

	float GetExplosionRadius() { return ExplosionRadius; }

protected:
	virtual void FireLoadedWeapon() override;
};
