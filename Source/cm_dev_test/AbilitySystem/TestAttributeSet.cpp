// Core Mechanics


#include "TestAttributeSet.h"

// The scope resolution operator allows us to put all the constructor logic here
// instead of having to put it in the .h file

UTestAttributeSet::UTestAttributeSet()
	// Initialize Variables
	// Apparently these current values can just be set easily by using : and then a list
	// of default values
	: Health(33.f), Speed(44.f), Magic(55.f)
	{
	}
