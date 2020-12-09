// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp_Health.h"
#include "ParagonShooter/Characters/ShooterCharacter.h"

bool APickUp_Health::PerformPickUp(AShooterCharacter* ActionCharacter)
{
	Super::PerformPickUp(ActionCharacter);

	FDamageEvent DamageEvent;
	float HealAmount = ActionCharacter->TakeDamage(-RecoverHealth, DamageEvent, nullptr, this);

	return HealAmount != 0;
}
