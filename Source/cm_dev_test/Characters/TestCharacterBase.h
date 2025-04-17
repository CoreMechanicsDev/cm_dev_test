// Core Mechanics

#pragma once

// Macros to simplify code
#include "MyMacros.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include <iostream>
#include "TestCharacterBase.generated.h"

class UTestAbilitySystemComponent;
class UTestAttributeSet;

UCLASS()
class CM_DEV_TEST_API ATestCharacterBase : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestCharacterBase();
	
	// From Tutorial
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAbilitySystemComponent* MyAbilitySystem;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return MyAbilitySystem;
	}

	//From Tutorial - create attribute set which adds it to character
	UPROPERTY()
	class UTestAttributeSet* MyAttributeSet;

	// From Kai (probably does same as above)
	virtual UTestAttributeSet* GetAttributeSet() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Define function that will give character its default
	// Abilities specified by user
	void GiveDefaultAbilities();

	// ME - Try to give default attributes
	void GiveDefaultAttributes() const;
	

	//UPROPERTY()
	//TObjectPtr<UTestAttributeSet> MyAttributeSet;

	// From Kai - Add component as UPROPERTY (requires forward declaration) so ASC
	// Appears on Player Character in editor
	// UPROPERTY(BlueprintReadOnly)
	// TObjectPtr<UTestAbilitySystemComponent> AbilitySystem;

	// From Kai create default ability section in editor
	// So user can specify what abilities character starts with
	// ** THIS CREATES THE ENTRY IN THE PLAYER'S DETAILS PANEL **
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Ability")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "GAS|Ability")
	TSubclassOf<UGameplayEffect> DefaultAttributeEffect;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
