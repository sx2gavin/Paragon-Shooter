// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Missile.generated.h"

UCLASS()
class PARAGONSHOOTER_API AMissile : public AActor
{
	GENERATED_BODY()

private:
	// Components
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCapsuleComponent* CapsuleCollider;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* MissileMesh;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UProjectileMovementComponent* ProjectileMovement;

private:
	// Properties
	UPROPERTY(EditAnywhere, Category = "Properties")
	float MissileSpeed = 2000.0f;
	
public:	
	// Sets default values for this actor's properties
	AMissile();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, 
		const FHitResult& Hit );
};
