// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Mesh"));
	WeaponMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	Ammo = AmmoCap;
}

void AWeapon::FireEmptyWeapon()
{
	UGameplayStatics::PlaySoundAtLocation(this, EmptyGunSound, GetActorLocation());
}

void AWeapon::FireLoadedWeapon()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, WeaponMesh, TEXT("MuzzleFlashSocket"));
	UGameplayStatics::PlaySoundAtLocation(this, ShotSound, GetActorLocation());
	Ammo--;
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AWeapon::PullTrigger()
{
	if (Ammo == 0)
	{
		FireEmptyWeapon();
		return false;
	}
	else
	{
		FireLoadedWeapon();
		return true;
	}
}

int32 AWeapon::Reload(int32 AvailableAmmo)
{
	int32 Refill = FMath::Min(AvailableAmmo, AmmoCap - Ammo);
	Ammo += Refill;

	if (Refill != 0 && ReloadGunSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ReloadGunSound, GetActorLocation());
	}
	return AvailableAmmo - Refill;
}

int32 AWeapon::GetAmmoCount() const
{
	return Ammo;
}

