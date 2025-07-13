// Core Mechanics

#pragma once

#include "CoreMinimal.h"
#include "TestCharacterBase.h"
#include "TestEnemyCharacter.generated.h"

UCLASS()
class CM_DEV_TEST_API ATestEnemyCharacter : public ATestCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
