// Core Mechanics

#pragma once

#include "MyMacros.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "TestDestructible.generated.h"


class UTestAbilitySystemComponent;
class UTestAttributeSet;

UCLASS()
class CM_DEV_TEST_API ATestDestructible : public AActor , public IAbilitySystemInterface
{
	GENERATED_BODY()
	
	// Allow static mesh to be added to actor in editor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= Mesh, meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* StaticMeshComp;

public:
	// Sets default values for this actor's properties
	ATestDestructible();
	
	// Show Ability System Item In Editor Details
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	UAbilitySystemComponent* MyAbilitySystem;

	// Creates Ability System 	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return MyAbilitySystem;
	}

	// Creates Attribute Set
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	class UTestAttributeSet* MyAttributeSet;

	// From Kai (probably does same as above)
	virtual UTestAttributeSet* GetAttributeSet() const;

	// Hit Bounce Variables
	float BounceStartTime = -1.0f;
	float BounceDuration = 0.5f;
	FVector TargetLocation;
	FVector StartLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Define function to bounce mesh
	void BounceMesh(float StartTime, bool ShouldBounce);
	
	// Define functions to give abilities and attribiutes
	void GiveDefaultAbilities();
	void GiveDefaultAttributes() const;

	// Create Default Abilities parameter in editor
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Ability")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	// Create Default Effects parameter in editor
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Ability")
	TSubclassOf<UGameplayEffect> DefaultAttributeEffect;

	// CREATE BLUEPRINT EVENT FOR HEALTH CHANGE
	virtual void OnHealthAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnHealthChanged(float OldValue, float NewValue);
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Create Test Event
	UFUNCTION(BlueprintImplementableEvent)
	void TestEvent();
	
	// When this UPROPERTY command precedes a variable declaration it makes it appear in the Details panel in editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FRotator Spin;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FVector Bob;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float BobSpeedMultiplier;
	
};



