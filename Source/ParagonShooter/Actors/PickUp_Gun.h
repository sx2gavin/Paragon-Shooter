// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParagonShooter/Actors/PickUp.h"
#include "PickUp_Gun.generated.h"

class AGun;
UCLASS()
class PARAGONSHOOTER_API APickUp_Gun : public APickUp
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* GunMesh;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AGun> GunType;

public:
	APickUp_Gun();
	virtual bool CheckPickUpCondition(class AShooterCharacter* ActionCharacter) override;
	virtual void PerformPickUp(AShooterCharacter* ActionCharacter) override;
	
};
