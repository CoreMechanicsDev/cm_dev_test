// Core Mechanics

#pragma once

#include "CoreMinimal.h"
#include "HAL/PlatformMisc.h"
//#include "Misc/DateTime.h"
#include "TestCharacterBase.h"
#include "TestPlayerCharacter.generated.h"

UCLASS()
class CM_DEV_TEST_API ATestPlayerCharacter : public ATestCharacterBase

{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	ATestPlayerCharacter();

	FString GetCurrentUsername();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
