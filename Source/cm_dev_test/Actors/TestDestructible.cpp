// Core Mechanics


#include "TestDestructible.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/TestAbilitySystemComponent.h"
#include "AbilitySystem/TestAttributeSet.h"

// Sets default values
ATestDestructible::ATestDestructible()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create Static Mesh slot on actor	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	RootComponent = StaticMeshComp;

	// Create Ability System for actor
	MyAbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystem");

	// Create Attribute set for actor
	MyAttributeSet = CreateDefaultSubobject<UTestAttributeSet>("AttributeSet");
}


UTestAttributeSet* ATestDestructible::GetAttributeSet() const
{
	return MyAttributeSet;
}

// Called when the game starts or when spawned
void ATestDestructible::BeginPlay()
{
	Super::BeginPlay();
	
	// Sending the test event on begin play
	TestEvent();

	// Initialize abilities on actor
	MyAbilitySystem->InitAbilityActorInfo(this, this);

	// Give abilities and attributes
	GiveDefaultAbilities();
	GiveDefaultAttributes();

	// CREATE BLUEPRINT EVENT FOR HEALTH CHANGE
	// ******** From Youtube Create Health Change Event
	//UTestAttributeSet* MyAttributeSet = PS->MyAttributeSet;
	MyAbilitySystem->GetGameplayAttributeValueChangeDelegate(MyAttributeSet->GetHealthAttribute()).AddUObject(this, &ATestDestructible::OnHealthAttributeChanged);
	

}

// Grant default abilities at start
void ATestDestructible::GiveDefaultAbilities()
{

	// Iterate through default abilities and give them
	for(TSubclassOf<UGameplayAbility> MyAbilityClass : DefaultAbilities)
	{
		const FGameplayAbilitySpec MyAbilitySpec(MyAbilityClass, 1);
		MyAbilitySystem->GiveAbility(MyAbilitySpec);
	}
}

// Grant default attributes at start (using effect)
void ATestDestructible::GiveDefaultAttributes() const
{
	
	if(!MyAbilitySystem || !DefaultAttributeEffect)
	{
		PRINTERR("NO DEFAULT ATTRIBUTE SET");
		return;
	}

	// FIGURE OUT WHAT THIS DOES
	FGameplayEffectContextHandle EffectContext = MyAbilitySystem->MakeEffectContext();

	// FIGURE OUT WHAT THIS DOES
	EffectContext.AddSourceObject(this);

	// FIGURE OUT WHAT THIS DOES
	const FGameplayEffectSpecHandle SpecHandle = MyAbilitySystem->MakeOutgoingSpec(DefaultAttributeEffect, 1.f, EffectContext);

	// FIGURE OUT WHAT THIS DOES
	if(SpecHandle.IsValid())
	{
		MyAbilitySystem->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());			
	}
}


// Called every frame
void ATestDestructible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// CREATE BLUEPRINT EVENT FOR HEALTH CHANGE
void ATestDestructible::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
	LOG("OnHealthAttributeChanged Fired");
}

