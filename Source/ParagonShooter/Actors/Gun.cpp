// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Mesh"));
	GunMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGun::PullTrigger()
{
	if (Ammo == 0)
	{
		UGameplayStatics::PlaySoundAtLocation(this, EmptyGunSound, GetActorLocation());
		return false;
	}
	else
	{
		UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, GunMesh, TEXT("MuzzleFlashSocket"));
		UGameplayStatics::PlaySoundAtLocation(this, ShotSound, GetActorLocation());

		Ammo--;

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

		return true;
	}
}

int32 AGun::Reload(int32 AvailableAmmo)
{
	int32 Refill = FMath::Min(AvailableAmmo, AmmoCap - Ammo);
	Ammo += Refill;
	return AvailableAmmo - Refill;
}

int32 AGun::GetAmmoCount() const
{
	return Ammo;
}

