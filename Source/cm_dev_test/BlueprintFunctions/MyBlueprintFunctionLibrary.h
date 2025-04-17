// Core Mechanics

#pragma once

#include "MyMacros.h"

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CM_DEV_TEST_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "CM_DEV_Functions")
	static void GenerateRandomInt(int ValueMin, int ValueMax, int& ValueResult);

	UFUNCTION(BlueprintCallable, Category = "CM_DEV_Functions")
	static void SpinMesh(UStaticMeshComponent* MyMesh, float SpinRate);

	UFUNCTION(BlueprintCallable, Category = "CM_DEV_Functions")
	static void CM_LogPrint(FString MyString);
	
	
};
