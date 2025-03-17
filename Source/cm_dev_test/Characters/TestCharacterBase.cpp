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
	MyAbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystem");

	// From tutorial - create and attach attributes  to character
	MyAttributeSet = CreateDefaultSubobject<UTestAttributeSet>("AttributeSet");
}

// From Kai - Getter for ASC
// UAbilitySystemComponent* ATestCharacterBase::GetAbilitySystemComponent() const
// {
// 	return AbilitySystemComponent;
// }

UTestAttributeSet* ATestCharacterBase::GetAttributeSet() const
{
	return MyAttributeSet;
}

// Called when the game starts or when spawned
void ATestCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	// From Kai - Initialize ASC on owner and avatar (ie Player)
	// AbilitySystemComponent->InitAbilityActorInfo(this, this);

	// From tutorial
	MyAbilitySystem->InitAbilityActorInfo(this, this);

	// From Kai - Give default abilities
	GiveDefaultAbilities();
	GiveDefaultAttributes();

	// From me - Try giving default attributes
	//GiveDefaultAttributes();
	
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
	// Delegate.AddWeakLambda(this, [this](auto)
	// {
	// 	if (MyAttributeSet->GetHealth() <= 0)
	// 		Destroy();
	// });
}

// Grant default abilities at start
void ATestCharacterBase::GiveDefaultAbilities()
{
	PRINT("Initializing Abilities");
	
	for(TSubclassOf<UGameplayAbility> MyAbilityClass : DefaultAbilities)
	{
		const FGameplayAbilitySpec MyAbilitySpec(MyAbilityClass, 1);
		MyAbilitySystem->GiveAbility(MyAbilitySpec);
	}
}

// Grant default attributes at start (using effect)
// CLEAN THIS UP
void ATestCharacterBase::GiveDefaultAttributes() const
{
	UE_LOG(LogTemp, Warning, TEXT("Initializing Attributes"));

	PRINT("Initializing Attributes");

	if(!MyAbilitySystem || !DefaultAttributeEffect)
	{
		PRINTERR("NO DEFAULT ATTRIBUTE SET");
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Define EffectContext"));
	FGameplayEffectContextHandle EffectContext = MyAbilitySystem->MakeEffectContext();

	UE_LOG(LogTemp, Warning, TEXT("AddSourceObject"));
	EffectContext.AddSourceObject(this);

	// Declare SpecHandle Variable
	
	UE_LOG(LogTemp, Warning, TEXT("Define SpecHandle"));
	const FGameplayEffectSpecHandle SpecHandle = MyAbilitySystem->MakeOutgoingSpec(DefaultAttributeEffect, 1.f, EffectContext);

	if(SpecHandle.IsValid())
	{
		PRINT("Applying Effects To Character");
		UE_LOG(LogTemp, Warning, TEXT("ApplyGameplayEffectSpecToSelf"));

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

