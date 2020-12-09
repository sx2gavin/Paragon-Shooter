// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;
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
	TArray<TSubclassOf<AGun>> GunTypes;

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
	TArray<AGun*> Guns;

	UPROPERTY()
	AGun* ActiveGun;

	UPROPERTY()
	AGun* LastActiveGun;

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

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	bool RestockAmmo(int32 Amount);

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

	void SwitchActiveGun(int GunOrder);

	UFUNCTION(BlueprintCallable)
	void UpdateActiveGunVisibility();

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	void LookUp(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRight(float AxisValue);
	void LookRightRate(float AxisValue);

	void ActiveGun1();
	void ActiveGun2();
	void ActiveGun3();
	void ActiveGun4();

	void Reload();
	void Action();

	void HandleDeath();

	UFUNCTION()
	void OnComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
