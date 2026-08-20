// Core Mechanics


#include "TestActor.h"


// Sets default values
ATestActor::ATestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create subobjects for actor
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpinAndBob = CreateDefaultSubobject<UAC_SpinAndBob>("SpinAndBob");
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Test comment from mac - REMOVE

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

