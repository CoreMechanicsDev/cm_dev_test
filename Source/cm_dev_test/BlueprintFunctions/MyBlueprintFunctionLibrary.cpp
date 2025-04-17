// Core Mechanics


#include "MyBlueprintFunctionLibrary.h"

void UMyBlueprintFunctionLibrary::GenerateRandomInt(int ValueMin, int ValueMax, int& ValueResult)
{
	ValueResult = FMath::RandRange(ValueMin, ValueMax);
}

void UMyBlueprintFunctionLibrary::SpinMesh(UStaticMeshComponent* MyMesh, float SpinRate)
{
	LOG("SPIN CODE EXECUTING WITH SPIN RATE OF {1}", SpinRate);
}

void UMyBlueprintFunctionLibrary::CM_LogPrint(FString MyString)
{
	LOG("{1}", MyString);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, MyString);
}
