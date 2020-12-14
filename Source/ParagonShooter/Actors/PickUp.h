// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp.generated.h"


UCLASS()
class PARAGONSHOOTER_API APickUp : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* DefaultRootComponent;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* TriggerCollider;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	class URotatingMovementComponent* RotatingComponent;

	UPROPERTY(EditDefaultsOnly)
	class UParticleSystem* PickUpEffect;

	bool bCanAutoPickUp = false;

public:
	// Sets default values for this actor's properties
	APickUp();

	/// <summary>
	/// Get the center of the collider, use this to locate a good spot to display an HUD
	/// </summary>
	/// <returns></returns>
	FVector GetColliderCenter();

	/// <summary>
	/// Determine whether this item can be picked up.
	/// i.e. If health is full or ammo is full then no need to pick up.
	/// </summary>
	/// <param name="ActionCharacter"></param>
	/// <returns></returns>
	virtual bool CheckPickUpCondition(class AShooterCharacter* ActionCharacter);

	/// <summary>
	/// Perform the pick up and apply effect on the character.
	/// Then destroy this pick up actor.
	/// </summary>
	virtual void PerformPickUp(class AShooterCharacter* ActionCharacter);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
