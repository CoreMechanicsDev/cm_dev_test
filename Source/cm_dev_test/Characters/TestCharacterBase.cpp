// Core Mechanics


#include "TestCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/TestAbilitySystemComponent.h"
#include "AbilitySystem/TestAttributeSet.h"

// Sets default values
ATestCharacterBase::ATestCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// From Kai - Initialize ASC
	// AbilitySystemComponent = CreateDefaultSubobject<UTestAbilitySystemComponent>("TestAbilitySystemComponent");

	// From tutorial 
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystem");

	// From tutorial - create and attach attributes  to character
	AttributeSet = CreateDefaultSubobject<UTestAttributeSet>("AttributeSet");
}

// From Kai - Getter for ASC
// UAbilitySystemComponent* ATestCharacterBase::GetAbilitySystemComponent() const
// {
// 	return AbilitySystemComponent;
// }

// UFabAttributeSet* ATestCharacterBase::GetAttributeSet() const
// {
// 	return AttributeSet;
// 	
// }

// Called when the game starts or when spawned
void ATestCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	// From Kai - Initialize ASC on owner and avatar (ie Player)
	// AbilitySystemComponent->InitAbilityActorInfo(this, this);

	// From tutorial
	AbilitySystem->InitAbilityActorInfo(this, this);

	// From Kai - Give default abilities
	GiveDefaultAbilities();

	
	// From tutorial - hack to set initial values
	// Notice how these functions were never declared anywhere
	// This is because they are created by the macros as defined
	// In SimpleGasAttribubteSet.h

	// Set initial values
	// AttributeSet->SetHealth(10);
	// AttributeSet->SetMagic(5);
	//
	auto Attribute = AttributeSet->GetHealthAttribute();
	auto& Delegate = AbilitySystem->GetGameplayAttributeValueChangeDelegate(Attribute);
	Delegate.AddWeakLambda(this, [this](auto)
	{
		if (AttributeSet->GetHealth() <= 0)
			Destroy();
	});
}

void ATestCharacterBase::GiveDefaultAbilities()
{
	// From Kai
	// Now assign all default abiliites
	for(TSubclassOf<UGameplayAbility> AbilityClass : DefaultAbilities)
	{
		const FGameplayAbilitySpec AbilitySpec(AbilityClass, 1);
		AbilitySystem->GiveAbility(AbilitySpec);
	}
	
}

// Called every frame
void ATestCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATestCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

