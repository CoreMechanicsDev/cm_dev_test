// Core Mechanics


#include "TestEnemyCharacter.h"

// Sets default values
ATestEnemyCharacter::ATestEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ATestEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATestEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

