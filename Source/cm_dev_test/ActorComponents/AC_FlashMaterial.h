// Core Mechanics

#pragma once

#include "MyMacros.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_FlashMaterial.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CM_DEV_TEST_API UAC_FlashMaterial : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties

	// Make this appear as BP node in editor
	// UFUNCTION(BlueprintPure, Category = "On Damage")
	UAC_FlashMaterial();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
