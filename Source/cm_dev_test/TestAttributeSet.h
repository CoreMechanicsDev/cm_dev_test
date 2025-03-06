// Core Mechanics

#pragma once
 
#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "TestAttributeSet.generated.h"

// Macros to easily declare attributes.  This will appear in EVERY project
// That uses GAS.  
// Make sure that there are no typos here as they will not throw errors
 #define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class CM_DEV_TEST_API UTestAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	// Constructor declaration (needs corresponding implementation in cpp file)
	UTestAttributeSet();

	// Current Health (replicated using protected ufunction below)
	// It is being set up as a read only blueprint under the 'health' category
	// It  points to the protected 'OnRep_CurrentHealth' function to handle network replication
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_CurrentHealth)
	// Create the attribute data
	FGameplayAttributeData CurrentHealth;
	// Now call the macro defined above.  This will insert a bunch of boiler plate code that
	// Allows the GAS system to work for each attribute
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, CurrentHealth)

	// Max Health 
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, MaxHealth)

	// Manas
	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, Mana)
	
protected:
	// Replication Notifies
	// Calls function defined above
	// Tells server how much health, mana, etc we have
	UFUNCTION()
	virtual void OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	
	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);
	
};
