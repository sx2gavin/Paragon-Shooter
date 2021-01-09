// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp_Weapon.h"
#include "ParagonShooter/Characters/ShooterCharacter.h"
#include "ParagonShooter/Actors/Weapon.h"
#include "Components/SkeletalMeshComponent.h"

APickUp_Weapon::APickUp_Weapon()
{
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon Mesh"));
	WeaponMesh->SetupAttachment(RootComponent);
}

bool APickUp_Weapon::CheckPickUpCondition(AShooterCharacter* ActionCharacter)
{
	return true;
}

void APickUp_Weapon::PerformPickUp(AShooterCharacter* ActionCharacter)
{
	if (ActionCharacter != nullptr && WeaponType != nullptr)
	{
		int32 NewGunIndex = ActionCharacter->AddWeapon(WeaponType);
		ActionCharacter->SwitchActiveWeapon(NewGunIndex);
	}

	Super::PerformPickUp(ActionCharacter);
}
