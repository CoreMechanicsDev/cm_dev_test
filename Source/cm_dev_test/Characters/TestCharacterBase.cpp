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
	
	// From tutorial 
	MyAbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystem");

	// From tutorial - create and attach attributes  to character
	MyAttributeSet = CreateDefaultSubobject<UTestAttributeSet>("AttributeSet");
}


UTestAttributeSet* ATestCharacterBase::GetAttributeSet() const
{
	return MyAttributeSet;
}

// Called when the game starts or when spawned
void ATestCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	// From tutorial
	MyAbilitySystem->InitAbilityActorInfo(this, this);

	// From Kai - Give default abilities
	GiveDefaultAbilities();
	GiveDefaultAttributes();
	
	// From tutorial - hack to set initial values
	// Notice how these functions were never declared anywhere
	// This is because they are created by the macros as defined
	// In SimpleGasAttribubteSet.h

	// Set initial values
	// AttributeSet->SetHealth(10);
	// AttributeSet->SetMagic(5);
	//
	// auto Attribute = MyAttributeSet->GetHealthAttribute();
	// auto& Delegate = MyAbilitySystem->GetGameplayAttributeValueChangeDelegate(Attribute);

	// TODO:  Try integrating this 'destroy' into new attribute setup
	// Delegate.AddWeakLambda(this, [this](auto)
	// {
	// 	if (MyAttributeSet->GetHealth() <= 0)
	// 		Destroy();
	// });
}

// Grant default abilities at start
void ATestCharacterBase::GiveDefaultAbilities()
{
	LOG("Initializing Abilities in {1}",FString(__FILE__));
	
	for(TSubclassOf<UGameplayAbility> MyAbilityClass : DefaultAbilities)
	{
		const FGameplayAbilitySpec MyAbilitySpec(MyAbilityClass, 1);
		MyAbilitySystem->GiveAbility(MyAbilitySpec);
	}
}

// Grant default attributes at start (using effect)
void ATestCharacterBase::GiveDefaultAttributes() const
{

	LOG("Initializing Attributes in {1}", FString(__FUNCTION__));

	if(!MyAbilitySystem || !DefaultAttributeEffect)
	{
		PRINTERR("NO DEFAULT ATTRIBUTE SET");
		return;
	}

	LOG("Define EffectContext in {1}", FString(__FILE__));
	FGameplayEffectContextHandle EffectContext = MyAbilitySystem->MakeEffectContext();

	LOG("Add Source Object in {1}", FString(__FILE__));
	EffectContext.AddSourceObject(this);

	// Declare SpecHandle Variable
	
	LOG("Define SpecHandle in {1}", FString(__FILE__));
	const FGameplayEffectSpecHandle SpecHandle = MyAbilitySystem->MakeOutgoingSpec(DefaultAttributeEffect, 1.f, EffectContext);

	if(SpecHandle.IsValid())
	{
		LOG("Applying Effects To Character in {1}", FString(__FILE__));

		MyAbilitySystem->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());			

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

