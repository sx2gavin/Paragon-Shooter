// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp_Ammo.h"
#include "ParagonShooter/Characters/ShooterCharacter.h"

bool APickUp_Ammo::CheckPickUpCondition(AShooterCharacter* ActionCharacter)
{
	if (ActionCharacter != nullptr)
	{
		return !ActionCharacter->IsFullAmmo();
	}

	return false;
}

void APickUp_Ammo::PerformPickUp(AShooterCharacter* ActionCharacter)
{
	if (ActionCharacter != nullptr)
	{
		ActionCharacter->RestockAmmo(RestockAmmoAmount);
	}

	Super::PerformPickUp(ActionCharacter);
}