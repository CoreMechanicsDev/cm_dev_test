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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS|Health")
	// Create the attribute data
	FGameplayAttributeData CurrentHealth;
	// Now call the macro defined above.  This will insert a bunch of boilerplate code that
	// Allows the GAS system to work for each attribute
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, CurrentHealth)

	// Max Health 
	UPROPERTY(BlueprintReadOnly, Category = "GAS|Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, MaxHealth)

	// Magic
	UPROPERTY(BlueprintReadOnly, Category = "GAS|Magic")
	FGameplayAttributeData Magic;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, Magic)

	// Speed
	UPROPERTY(BlueprintReadOnly, Category = "GAS|Speed")
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, Speed)
	
	// BLANK
	// UPROPERTY(BlueprintReadOnly, Category = "BLANK", ReplicatedUsing = OnRep_BLANK)
	// FGameplayAttributeData BLANK;
	// ATTRIBUTE_ACCESSORS(UTestAttributeSet, BLANK)
};