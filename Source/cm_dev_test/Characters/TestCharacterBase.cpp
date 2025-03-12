// Core Mechanics


#include "TestCharacterBase.h"
#include "AbilitySystem/TestAbilitySystemComponent.h"
#include "AbilitySystem/TestAttributeSet.h"

// Sets default values
ATestCharacterBase::ATestCharacterBase()
{
	// Super::BeginPlay();

	PrimaryActorTick.bCanEverTick = true;
	
	// Create the ability system
	AbilitySystemComponent = CreateDefaultSubobject<UTestAbilitySystemComponent>("AbilitySystemComponent");
	
	// Create the attribute set
	AttributeSet = CreateDefaultSubobject<UTestAttributeSet>("AttributeSet");
	
}

// Implementation of ability system component (just returns)
UAbilitySystemComponent* ATestCharacterBase::GetAbilitySystemComponent() const
{
		return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ATestCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	PRINT("Hello From MyCharacterBase.cpp");

	// Specify owner and avatar of component
	// The owner is the entity which 'owns' this component which can be many things
	// We want the owner to be a pawn in this case
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

// Called every frame
void ATestCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


