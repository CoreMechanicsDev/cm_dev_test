// Core Mechanics


#include "TestAbilitySystemComponent.h"


// Sets default values
UTestAbilitySystemComponent::UTestAbilitySystemComponent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);

}

// Called when the game starts or when spawned
void UTestAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// Sending the test GAS event on begin play
	GASTestEvent();
	
}

