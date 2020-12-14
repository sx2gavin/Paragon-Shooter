// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp_Gun.h"
#include "ParagonShooter/Characters/ShooterCharacter.h"
#include "ParagonShooter/Actors/Gun.h"
#include "Components/SkeletalMeshComponent.h"

APickUp_Gun::APickUp_Gun()
{
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Mesh"));
	GunMesh->SetupAttachment(RootComponent);
}

bool APickUp_Gun::CheckPickUpCondition(AShooterCharacter* ActionCharacter)
{
	return true;
}

void APickUp_Gun::PerformPickUp(AShooterCharacter* ActionCharacter)
{
	if (ActionCharacter != nullptr && GunType != nullptr)
	{
		int32 NewGunIndex = ActionCharacter->AddGun(GunType);
		ActionCharacter->SwitchActiveGun(NewGunIndex);
	}

	Super::PerformPickUp(ActionCharacter);
}
