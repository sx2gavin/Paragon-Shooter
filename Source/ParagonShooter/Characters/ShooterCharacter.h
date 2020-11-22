// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class PARAGONSHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

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

	void Fire();

	UFUNCTION(BlueprintPure)
	bool GetIsDead() const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	void SwitchActiveGun(int GunOrder);

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

	void HandleDeath();

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AGun>> GunTypes;

	UPROPERTY(EditDefaultsOnly)
	float TurnRate = 100;

	UPROPERTY(EditAnywhere)
	float MaxHealth = 100;

	float Health;

	bool bIsDead = false;

	UPROPERTY()
	TArray<AGun*> Guns;

	UPROPERTY()
	AGun* ActiveGun;

};
