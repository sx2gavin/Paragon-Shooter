// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp_Ammo.h"
#include "ParagonShooter/Characters/ShooterCharacter.h"

bool APickUp_Ammo::PerformPickUp(AShooterCharacter* ActionCharacter)
{
	Super::PerformPickUp(ActionCharacter);

	if (ActionCharacter != nullptr)
	{
		return ActionCharacter->RestockAmmo(RestockAmmoAmount);
	}

	return false;
}