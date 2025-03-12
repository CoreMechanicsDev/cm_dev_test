// Core Mechanics

#pragma once

#include "MyMacros.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "TestCharacterBase.generated.h"

// Forward declarations
class UTestAbilitySystemComponent;
class UTestAttributeSet;
//class UGameplayEffect;
//class UGameplayAbility;

UCLASS()
class CM_DEV_TEST_API ATestCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	ATestCharacterBase();

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Add ability system component (what makes this whole thing work on an actor)
	UPROPERTY()
	TObjectPtr<UTestAbilitySystemComponent> AbilitySystemComponent;

	// Add attribute set to tell system what specific attributes to give
	// (all defined in TestAttributeSet file)
	UPROPERTY()
	TObjectPtr<UTestAttributeSet> AttributeSet;

public:
	
	// Allow access to AbilitySystemComponent
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Getter function for attribute set
	virtual UTestAttributeSet* GetAttributeSet() const
	{
		return AttributeSet;
	};
	
	// Assign attributes to character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	UTestAttributeSet* Attributes;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

};
