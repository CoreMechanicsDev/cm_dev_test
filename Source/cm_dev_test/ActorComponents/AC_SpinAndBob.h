// Core Mechanics

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_SpinAndBob.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CM_DEV_TEST_API UAC_SpinAndBob : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAC_SpinAndBob();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// When this UPROPERTY command precedes a variable declaration it makes it appear in the Details panel in editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FRotator Spin;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FVector Bob;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float BobSpeedMultiplier;

private:
	FVector StartLocation;
};
