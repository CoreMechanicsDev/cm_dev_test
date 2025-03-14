// Core Mechanics

#pragma once

#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "TestAttributeSet.generated.h"

// Helper Macros From Tutorial
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

	// Initialize Values For Attributes
	UTestAttributeSet();
	
	// From Tutorial - Contains Health attribute
	UPROPERTY()
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, Health);

	UPROPERTY()
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, Speed);

	UPROPERTY()
	FGameplayAttributeData Magic;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, Magic);
};
