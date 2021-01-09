// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParagonShooter/Actors/PickUp.h"
#include "PickUp_Weapon.generated.h"

class AWeapon;
UCLASS()
class PARAGONSHOOTER_API APickUp_Weapon : public APickUp
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AWeapon> WeaponType;

public:
	APickUp_Weapon();
	virtual bool CheckPickUpCondition(class AShooterCharacter* ActionCharacter) override;
	virtual void PerformPickUp(AShooterCharacter* ActionCharacter) override;
	
};
