// Core Mechanics

// Some includes are able to referred to without the path because we included
// the path in the Build.cs file
#include "TestPlayerCharacter.h"
#include "TestCharacterBase.h"
#include "Kismet/GameplayStatics.h"
#include "Serialization/MappedName.h"

// Sets default values
ATestPlayerCharacter::ATestPlayerCharacter()
{

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


// Called every frame
void ATestPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Draw sphere at every frame at actor location
	SPHERE_TICK(GetActorLocation());

	// Drawn line at every frame from actor to vector location
	LINE_TICK(GetActorLocation(), FVector(2200.f, 700.f, 150.f));
}

FString ATestPlayerCharacter::GetCurrentUsername()
{
	return FPlatformMisc::GetDefaultDeviceProfileName();

}

// Called when the game starts or when spawned
void ATestPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Testing Kaos LOG Macro 

	FString MyDummyString = "Hello World";
	int MyDummyInt = 666;
	FString MyPlatform = UGameplayStatics::GetPlatformName();

	LOG("String is {1}, Int is {2}, platform is {3} in function {4}.", MyDummyString, MyDummyInt, MyPlatform, __FUNCTION__);

	// New LOGFMT function example
	// UE_LOGFMT(LogCore, Warning, "Loading `{Name}` failed with error {Error}", "Deep", "DumbError");
	
	// Another Macro to also print the function / file from which the print call was made
	//PRINTARGS("Hello World From Function: %s", *FString(__FUNCTION__));

	// Set up a vector that serves as center location for sphere
	FVector TargetLocation(2200.f, 700.f, 150.f);

	// The following simplified debug draw calls use macros defined in the MyMacros.h file

	// Draw Sphere at target location
	SPHERE(TargetLocation);

	// Draw line from player to target location
	LINE(GetActorLocation(), TargetLocation);
	
}


