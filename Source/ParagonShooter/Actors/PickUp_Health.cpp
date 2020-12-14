// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp_Health.h"
#include "ParagonShooter/Characters/ShooterCharacter.h"



bool APickUp_Health::CheckPickUpCondition(AShooterCharacter* ActionCharacter)
{
	if (ActionCharacter)
	{
		return !ActionCharacter->IsFullHealth();
	}

	return false;
}

void APickUp_Health::PerformPickUp(AShooterCharacter* ActionCharacter)
{
	FDamageEvent DamageEvent;
	float HealAmount = ActionCharacter->TakeDamage(-RecoverHealth, DamageEvent, nullptr, this);

	Super::PerformPickUp(ActionCharacter);
}
