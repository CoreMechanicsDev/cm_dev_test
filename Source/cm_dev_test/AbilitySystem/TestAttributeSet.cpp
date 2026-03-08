// Core Mechanics


#include "TestAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "MyMacros.h"

// The scope resolution operator allows us to put all the constructor logic here
// instead of having to put it in the .h file

UTestAttributeSet::UTestAttributeSet()
	// Initialize Variables - Now uses Gameplay Effect to apply, but can be
	// directly assigned here using format : Health(33.f), Speed(44.f), Magic(55.f)
	{
	}

// Pre Attribute Change Actions (requires GameplayEffectExtension.h)
// NOTE: No action / code should be put here if it needs to execute on an
// exact attribute value - use PostGameplayEffectExecute for that below
void UTestAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// Super::PreAttributeChange(Attribute, NewValue);

	// Clamp attribute to minimum of 2
	// if(Attribute == GetHealthAttribute())
	// {
	// 	NewValue = FMath::Clamp(NewValue, 2.f, GetMaxHealth());
	// }

}

// Post Attribute Change Actions (requires GameplayEffectExtension.h)
// NOTE:  This is where in-game reactions SHOULD be placed
// and without this function, modifications to attributes seem
// to take place behind the scenes anyway (ie health will drop
// below min or above max)
// You can also access info about the instigator and target actor
// inside this function as well as their ASC, etc

void UTestAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// Do this if it's the health attribute that has changed
	if(Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		// *** REMOVED - THIS WAS CAUSING HEALTH ATTRIBUTE TO REGISTER A SECOND CHANGE EVENT ***
		// Make sure health doesn't drop below MaxHealth
		//SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));

		// Print name of hit actor and its new health value
		FString LocalTarget = GetOwningActor()->GetActorNameOrLabel();
		LOG("Health on {1} is now {2}", LocalTarget, GetHealth());

		
		
		// TEST - Print to log if health is at 3
		if (GetHealth() == 0)
		{
			LOG("Target Should Be Dead - and new Git Test");
		}
	}
}
