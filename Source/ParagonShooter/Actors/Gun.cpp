// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"


AGun::AGun()
{
}

void AGun::FireLoadedWeapon()
{
	Super::FireLoadedWeapon();

	APawn* GunOwner = Cast<APawn>(GetOwner());
	if (GunOwner != nullptr)
	{
		AController* GunController = GunOwner->GetController();

		FVector ViewPointLocation;
		FRotator ViewPointRotation;

		GunController->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);

		FVector EndPoint = ViewPointLocation + ViewPointRotation.Vector() * FireRange;

		FHitResult Hit;

		FCollisionQueryParams QueryParams;

		QueryParams.AddIgnoredActor(GunOwner);
		bool bSuccessfulHit = GetWorld()->LineTraceSingleByChannel(Hit, ViewPointLocation, EndPoint, ECC_GameTraceChannel1, QueryParams);

		if (bSuccessfulHit)
		{
			// Spawn Particle effect
			UGameplayStatics::SpawnEmitterAtLocation(this, ImpactFlash, Hit.Location, Hit.ImpactNormal.Rotation());
			UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, Hit.Location);

			// Apply damage to the hit actor if it's a pawn
			AActor* HitActor = Hit.GetActor();
			FDamageEvent DamageEvent;
			if (HitActor != nullptr)
			{
				HitActor->TakeDamage(Damage, DamageEvent, GunController, this);
			}
		}
	}
}

