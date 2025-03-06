// Core Mechanics

#pragma once
 
#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "TestAttributeSet.generated.h"

// Macros to easily declare attributes
 #define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER((PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER((PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class CM_DEV_TEST_API UTestAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	// Constructor
//	UTestAttributeSet();

	// Current Health

	// Max Health
	
	
};
