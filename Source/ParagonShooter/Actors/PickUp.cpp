// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Root Component"));
	SetRootComponent(DefaultRootComponent);

	TriggerCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger Collider"));
	TriggerCollider->SetupAttachment(DefaultRootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(DefaultRootComponent);

	RotatingComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("Rotating Component"));

}

FVector APickUp::GetColliderCenter()
{
	if (TriggerCollider)
	{
		return TriggerCollider->GetComponentLocation();
	}
	else
	{
		return GetActorLocation();
	}
}

bool APickUp::CheckPickUpCondition(AShooterCharacter* ActionCharacter)
{
	return true;
}

void APickUp::PerformPickUp(AShooterCharacter* ActionCharacter)
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PickUpEffect, GetActorLocation());
	UGameplayStatics::PlaySoundAtLocation(this, PickUpSFX, GetActorLocation());
	Destroy();
}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

