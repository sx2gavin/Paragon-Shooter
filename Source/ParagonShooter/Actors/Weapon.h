// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class PARAGONSHOOTER_API AWeapon : public AActor
{
	GENERATED_BODY()

protected:
	// Components
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USkeletalMeshComponent* WeaponMesh;

	// Customize Fields
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	int32 AmmoCap = 30;

	UPROPERTY(EditDefaultsOnly, Category = "Particle Effects")
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* ShotSound;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* EmptyGunSound;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* ReloadGunSound;
	
	// Properties
	int32 Ammo = 30;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float Damage = 30;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void FireEmptyWeapon();
	virtual void FireLoadedWeapon();

public:	
	// Sets default values for this actor's properties
	AWeapon();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/// <summary>
	/// Pull the weapon trigger, different weapons have different effects, they should be extended in child classes.
	/// </summary>
	/// <returns>Whether this weapon has ammo left or not.</returns>
	virtual bool PullTrigger();

	/// <summary>
	/// Reload this gun, returns remaining ammos. 
	/// </summary>
	/// <param name="AvailableAmmo">All the ammo count that the character has at the moment</param>
	/// <returns>Remaining ammo</returns>
	int32 Reload(int32 AvailableAmmo);

	int32 GetAmmoCount() const;

	float GetDamage();
};
