// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "Engine/World.h"
#include "ParagonShooter/Actors/Gun.h"
#include "ParagonShooter/GameModes/KillEmAllgameMode.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);

	for (TSubclassOf<AGun> GunType : GunTypes)
	{
		AGun* NewGun = GetWorld()->SpawnActor<AGun>(GunType);
		NewGun->SetOwner(this);
		NewGun->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("weapon_socket"));
		NewGun->SetActorHiddenInGame(true);
		Guns.Add(NewGun);
	}

	SwitchActiveGun(0);

	Health = MaxHealth;
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AShooterCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AShooterCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AShooterCharacter::LookRight);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AShooterCharacter::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &AShooterCharacter::LookRightRate);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AShooterCharacter::Fire);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Gun 1"), IE_Pressed, this, &AShooterCharacter::ActiveGun1);
	PlayerInputComponent->BindAction(TEXT("Gun 2"), IE_Pressed, this, &AShooterCharacter::ActiveGun2);
	PlayerInputComponent->BindAction(TEXT("Gun 3"), IE_Pressed, this, &AShooterCharacter::ActiveGun3);
	PlayerInputComponent->BindAction(TEXT("Gun 4"), IE_Pressed, this, &AShooterCharacter::ActiveGun4);
}

float AShooterCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	Health = FMath::Clamp(Health - DamageAmount, 0.f, MaxHealth);

	UE_LOG(LogTemp, Warning, TEXT("Current Health is %f"), Health);
	if (Health == 0)
	{
		HandleDeath();
	}

	return DamageAmount;
}

void AShooterCharacter::MoveForward(float AxisValue)
{
	FVector MoveDirection = GetActorForwardVector() * AxisValue;
	AddMovementInput(MoveDirection);
}

void AShooterCharacter::MoveRight(float AxisValue)
{
	FVector MoveDirection = GetActorRightVector() * AxisValue;
	AddMovementInput(MoveDirection);
}

void AShooterCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void AShooterCharacter::LookUpRate(float AxisValue)
{
	float RotateAmount = AxisValue * GetWorld()->DeltaTimeSeconds * TurnRate;
	AddControllerPitchInput(RotateAmount);
}

void AShooterCharacter::LookRight(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void AShooterCharacter::LookRightRate(float AxisValue)
{
	float RotateAmount = AxisValue * GetWorld()->DeltaTimeSeconds * TurnRate;
	AddControllerYawInput(RotateAmount);
}

void AShooterCharacter::ActiveGun1()
{
	SwitchActiveGun(0);
}

void AShooterCharacter::ActiveGun2()
{
	SwitchActiveGun(1);
}

void AShooterCharacter::ActiveGun3()
{
	SwitchActiveGun(2);
}

void AShooterCharacter::ActiveGun4()
{
	SwitchActiveGun(3);
}

void AShooterCharacter::HandleDeath()
{
	// Make this character die.
	bIsDead = true;

	AParagonShooterGameModeBase* CurrentGameMode = GetWorld()->GetAuthGameMode<AParagonShooterGameModeBase>();
	// Call Game mode's function to remove this actor from the game and calculate win state.
	CurrentGameMode->ActorDied(this);

	DetachFromControllerPendingDestroy();
	SetActorEnableCollision(false);
}

void AShooterCharacter::Fire()
{
	if (ActiveGun != nullptr)
	{
		ActiveGun->PullTrigger();
	}
}

bool AShooterCharacter::GetIsDead() const
{
	return bIsDead;
}

float AShooterCharacter::GetHealthPercent() const
{
	if (MaxHealth != 0)
	{
		return Health / MaxHealth;
	}

	return 0.0;
}

void AShooterCharacter::SwitchActiveGun(int GunOrder)
{
	if (Guns.Num() > GunOrder)
	{
		if (ActiveGun != nullptr)
		{
			ActiveGun->SetActorHiddenInGame(true);
		}
		ActiveGun = Guns[GunOrder];
		ActiveGun->SetActorHiddenInGame(false);
	}
}
