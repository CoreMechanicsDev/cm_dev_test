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

void ATestCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	MyAbilitySystem->InitAbilityActorInfo(this, this);

	GiveDefaultAbilities();
	GiveDefaultAttributes();
	
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

// Grant default   attributes at start (using effect)
void ATestCharacterBase::GiveDefaultAttributes() const
{

	LOG("Initializing Attributes in {1}", FString(__FUNCTION__));

	if(!MyAbilitySystem || !DefaultAttributeEffect)
	{

		// Check for valid owning actor and print warning if no default attribute set found
		AActor* OwningActor = GetOwner();
		if (OwningActor)
		{
			FString LocalTarget = this->GetActorNameOrLabel();
			PRINTARGS("GAS: No default attributes for %s", *LocalTarget);
		}

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

