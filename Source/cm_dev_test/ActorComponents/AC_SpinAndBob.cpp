// Core Mechanics


#include "AC_SpinAndBob.h"


// Sets default values for this component's properties
UAC_SpinAndBob::UAC_SpinAndBob()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_SpinAndBob::BeginPlay()
{
	Super::BeginPlay();

	// Store the original location of the actor
	StartLocation = GetOwner()->GetActorLocation();
}


// Called every frame
void UAC_SpinAndBob::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Rotate the actor over time
	GetOwner()->AddActorWorldRotation(Spin * DeltaTime);

	// Bob the actor over time based on a sine wave

	// Store seconds as float how long since level started
	float time = GetOwner()->GetWorld()->GetRealTimeSeconds();

	// Use sine wave which calculates amount of time since level has loaded to bounce actor
	// Result will be value between -1 and +1
	float sine = FMath::Sin(time * BobSpeedMultiplier);
	GetOwner()->SetActorLocation(StartLocation + (Bob * sine));
	

	
	
}

