// Core Mechanics


#include "ActorComponents/AC_FlashMaterial.h"

// Sets default values for this component's properties
// UFUNCTION(BlueprintPure, Category = "On Damage")
UAC_FlashMaterial::UAC_FlashMaterial()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	return;
	// ...
}


// Called when the game starts
void UAC_FlashMaterial::BeginPlay()
{
	Super::BeginPlay();

	LOG("AC_FlashMaterial BeginPlay");
	// ...
	
}


// Called every frame
void UAC_FlashMaterial::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

