// Core Mechanics


#include "TestAttributeSet.h"
#include "GameplayEffectExtension.h"

// The scope resolution operator allows us to put all the constructor logic here
// instead of having to put it in the .h file

UTestAttributeSet::UTestAttributeSet()
	// Initialize Variables
	// Apparently these current values can just be set easily by using : and then a list
	// of default values
	// : Health(33.f), Speed(44.f), Magic(55.f)
	{
	}

// Pre Attribute Change Actions (requires GameplayEffectExtension.h)

void UTestAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	
	if(Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 2.f, GetMaxHealth());
	}

}

// Post Attribute Change Actions (requires GameplayEffectExtension.h)
// Note:  This is where in-game reactions should be placed
// and without this function, modifications to attributes seem
// to take place behind the scenes anyway (ie health will drop
// below min or above max)
// You can also access info about the instigator and target actor
// inside this function as well as their ASC, etc

void UTestAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if(Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
}
