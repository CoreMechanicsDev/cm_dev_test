// Core Mechanics

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "TestAbilitySystemComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CM_DEV_TEST_API UTestAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UTestAbilitySystemComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
