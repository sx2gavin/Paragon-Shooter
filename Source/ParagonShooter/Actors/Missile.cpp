// Fill out your copyright notice in the Description page of Project Settings.


#include "Missile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "ParagonShooter/Actors/Launcher.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ParagonShooter/Characters/ShooterCharacter.h"

// Sets default values
AMissile::AMissile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleCollider = CreateDefaultSubobject<UCapsuleComponent>("CapsuleCollider");
	RootComponent = CapsuleCollider;

	MissileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Missile Mesh"));
	MissileMesh->SetupAttachment(RootComponent);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
}

// Called when the game starts or when spawned
void AMissile::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMovement->InitialSpeed = MissileSpeed;
	ProjectileMovement->MaxSpeed = MissileSpeed;

	CapsuleCollider->OnComponentHit.AddDynamic(this, &AMissile::OnHit);
}

// Called every frame
void AMissile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMissile::OnHit(UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, 
		const FHitResult& Hit)
{
	if (OtherActor == GetOwner())
	{
		return;
	}

	ALauncher* OwnerLauncher = Cast<ALauncher>(GetOwner());

	if (OwnerLauncher)
	{
		DrawDebugSphere(GetWorld(), Hit.Location, OwnerLauncher->GetExplosionRadius(), 10, FColor::Red, false, 3);

		TArray<AActor*> HitActors;
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

		UKismetSystemLibrary::SphereOverlapActors(GetWorld(),
			Hit.Location,
			OwnerLauncher->GetExplosionRadius(),
			ObjectTypes,
			TSubclassOf<AShooterCharacter>(),
			TArray < AActor* >(),
			HitActors);

		FRadialDamageEvent RadialDamage;

		ACharacter* Character = Cast<ACharacter>(OwnerLauncher->GetOwner());

		if (Character != nullptr)
		{
			AController* Controller = Character->GetController();
			
			for (AActor* HitActor : HitActors)
			{
				HitActor->TakeDamage(OwnerLauncher->GetDamage(), RadialDamage, Controller, OwnerLauncher);
			}
		}
	}

	Destroy();
}