// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class PARAGONSHOOTER_API AGun : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	class USceneComponent* Root;

	UPROPERTY(EditAnywhere)
	class USkeletalMeshComponent* GunMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRange = 2000;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float Damage = 30;

	UPROPERTY(EditDefaultsOnly)
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditDefaultsOnly)
	UParticleSystem* ImpactFlash;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* ShotSound;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* ImpactSound;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AGun();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PullTrigger();

};
