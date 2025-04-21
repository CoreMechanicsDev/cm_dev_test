// Core Mechanics

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/AC_SpinAndBob.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class CM_DEV_TEST_API ATestActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Define static mesh and make it appear as setting in editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	UStaticMeshComponent* Mesh;

	// Define Actor Component for SpinAndBob and make it appear as setting in editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	UAC_SpinAndBob* SpinAndBob;
};
