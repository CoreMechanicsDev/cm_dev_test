// Core Mechanics


#include "PlayerCharacter.h"
// This include is able to referred to without the path because we included
// the path in the Build.cs file
#include "MyMacros.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Hello World"));

	//	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Hello Screen"));
	// Replaced the above long command with a macro contained in MyMacros.h
	// Now printing is much easier
	
	PRINT("Hello Macro World!");
	
	// Another Macro to also print the function from which the print call was made
	PRINTARGS("Hello From Function: %s", *FString(__FUNCTION__));

	// Set up a vector that serves as center location for sphere
	FVector TargetLocation(2200.f, 700.f, 150.f);

	// The following simplified debug draw calls use macros defined in the MyMacros.h file

	// Draw Sphere at target location
	SPHERE(TargetLocation);

	// Draw line from player to target location
	LINE(GetActorLocation(), TargetLocation);
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Draw sphere at every frame at actor location
	SPHERE_TICK(GetActorLocation());

	// Drawn line at every frame from actor to vector location
	LINE_TICK(GetActorLocation(), FVector(2200.f, 700.f, 150.f));
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

