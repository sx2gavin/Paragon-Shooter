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
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	class USphereComponent* TriggerCollider;
	
public:	
	// Sets default values for this actor's properties
	APickUp();

	/// <summary>
	/// Get the center of the collider, use this to locate a good spot to display an HUD
	/// </summary>
	/// <returns></returns>
	FVector GetColliderCenter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
