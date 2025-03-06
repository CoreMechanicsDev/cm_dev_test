// Core Mechanics
  
#pragma once

#include "CoreMinimal.h"
#include "MyCharacterBase.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class CM_DEV_TEST_API AEnemyCharacter : public AMyCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
