// Fill out your copyright notice in the Description page of Project Settings.


#include "Launcher.h"
#include "Kismet/GameplayStatics.h"
#include "paragonShooter/Actors/Missile.h"

ALauncher::ALauncher()
{
	MissileSpawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Missile Spawn Location"));
	MissileSpawnLocation->SetupAttachment(WeaponMesh);
}

void ALauncher::FireLoadedWeapon()
{
	Super::FireLoadedWeapon();
	
	if (MissileType != nullptr)
	{
		AMissile* Missile = GetWorld()->SpawnActor<AMissile>(MissileType,
			MissileSpawnLocation->GetComponentLocation(),
			MissileSpawnLocation->GetComponentRotation());
		Missile->SetOwner(this);
	}
}