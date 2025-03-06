// Core Mechanics


#include "TestAttributeSet.h"
#include "Net/UnrealNetwork.h"

// The scope resolution operator allows us to put all the constructor logic here
// instead of having to put it in the .h file

UTestAttributeSet::UTestAttributeSet()
	// Initialize Variables
	// Apparently these current values can just be set easily by using : and then a list
	// of default values
	: CurrentHealth(100.f), MaxHealth(100.f), Mana(100.f)
{
}

// Handle REP_NOTIFY message for each variable
// Insures that all clients receive current values of stats
void UTestAttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTestAttributeSet, CurrentHealth, OldCurrentHealth)
}

void UTestAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTestAttributeSet,MaxHealth, OldMaxHealth)
}

void UTestAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTestAttributeSet, Mana, OldMana)
}

// Now, actually SEND the stats to the network
void UTestAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UTestAttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UTestAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UTestAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	
}