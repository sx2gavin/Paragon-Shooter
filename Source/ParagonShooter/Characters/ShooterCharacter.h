// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AWeapon;
class APickUp;

UCLASS()
class PARAGONSHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	// Properties
	UPROPERTY(EditAnywhere, Category = "Combat")
	int32 MaxAmmo = 300;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AWeapon>> WeaponTypes;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<APickUp>> DropsOnDeath;

	UPROPERTY(EditDefaultsOnly)
	float TurnRate = 100;

	UPROPERTY(EditAnywhere)
	float MaxHealth = 100;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UCameraShake> FireCameraShake;

	float Health;

	int32 Ammo;

	bool bIsDead = false;
	bool bIsSwitchingWeapon = false;
	bool bIsFiring = false;
	bool bIsReloading = false;

	UPROPERTY()
	TArray<AWeapon*> Weapons;

	UPROPERTY()
	AWeapon* ActiveWeapon;

	UPROPERTY()
	AWeapon* LastActiveWeapon;

	UPROPERTY()
	APickUp* OverlappedPickUp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this character's properties
	AShooterCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator,
		AActor* DamageCauser) override;
	bool IsFullHealth();

	bool RestockAmmo(int32 Amount);
	bool IsFullAmmo();

	void Fire();
	
	UFUNCTION(BlueprintPure)
	bool GetIsDead() const;

	UFUNCTION(BlueprintPure)
	bool GetSwitchWeapon() const;

	UFUNCTION(BlueprintCallable)
	void SetSwitchWeapon(bool bSwitchingWeapon);

	UFUNCTION(BlueprintPure)
	bool GetIsFiring() const;
	
	UFUNCTION(BlueprintCallable)
	void SetIsFiring(bool bNewIsFiring);
	
	UFUNCTION(BlueprintPure)
	bool GetIsReloading() const;
	
	UFUNCTION(BlueprintCallable)
	void SetIsReloading(bool bNewIsReloading);

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	UFUNCTION(BlueprintCallable)
	FString GetAmmoCountString() const;

	APickUp* GetOverlappedPickUp() const;

	void SwitchActiveWeapon(int WeaponIndex);

	/// <summary>
	/// Adds a new gun to your gun stash.
	/// </summary>
	/// <param name="GunType"></param>
	/// <returns>The index for this new gun as a integer</returns>
	int32 AddWeapon(TSubclassOf<AWeapon> WeaponType);

	UFUNCTION(BlueprintCallable)
	void UpdateActiveGunVisibility();

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	void LookUp(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRight(float AxisValue);
	void LookRightRate(float AxisValue);

	void ActiveWeapon1();
	void ActiveWeapon2();
	void ActiveWeapon3();
	void ActiveWeapon4();

	void Reload();
	void Action();

	void HandleDeath();

	UFUNCTION()
	void OnComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
