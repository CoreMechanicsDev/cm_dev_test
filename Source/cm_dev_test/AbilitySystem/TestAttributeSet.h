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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChange, float, Health);

UCLASS()
class CM_DEV_TEST_API UTestAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	// Initialize Values For Attributes
	UTestAttributeSet();


	
	// Define methods for clamping attribute values and actions resulting from attribute changes
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	// Original
	//UPROPERTY(BlueprintReadOnly)
	// From Reddit
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, Health);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, MaxHealth);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, Speed);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Magic;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, Magic);


};
