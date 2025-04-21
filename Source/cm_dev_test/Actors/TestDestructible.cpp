// Core Mechanics


#include "TestDestructible.h"
#include "Kismet/GameplayStatics.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/TestAbilitySystemComponent.h"
#include "AbilitySystem/TestAttributeSet.h"

// bool ShouldAnimate = false;
// float AnimationStartTime = 0.0f;
// FVector AnimationStartLocation;
// float AnimationDuration;

// Sets default values
ATestDestructible::ATestDestructible()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create Static Mesh slot on actor	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	RootComponent = StaticMeshComp;

	// Create Ability System for actor
	MyAbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystem");

	// Create Attribute set for actor
	MyAttributeSet = CreateDefaultSubobject<UTestAttributeSet>("AttributeSet");
	
}

// Get default attributes
UTestAttributeSet* ATestDestructible::GetAttributeSet() const
{
	return MyAttributeSet;
}

// Called when the game starts or when spawned
void ATestDestructible::BeginPlay()
{
	Super::BeginPlay();


	// BounceMesh(DeltaTime);
	
	// Sending the test event on begin play
	TestEvent();

	// Initialize abilities on actor
	MyAbilitySystem->InitAbilityActorInfo(this, this);

	// Give abilities and attributes
	GiveDefaultAbilities();
	GiveDefaultAttributes();

	// CREATE BLUEPRINT EVENT FOR HEALTH CHANGE
	// ******** From Youtube Create Health Change Event
	//UTestAttributeSet* MyAttributeSet = PS->MyAttributeSet;
	MyAbilitySystem->GetGameplayAttributeValueChangeDelegate(MyAttributeSet->GetHealthAttribute()).AddUObject(this, &ATestDestructible::OnHealthAttributeChanged);
	
	// Store original mesh location (for spin and bob functionality)
	//AnimationStartLocation = this->GetActorLocation();

}

// Grant default abilities at start
void ATestDestructible::GiveDefaultAbilities()
{

	// Iterate through default abilities and give them
	for(TSubclassOf<UGameplayAbility> MyAbilityClass : DefaultAbilities)
	{
		const FGameplayAbilitySpec MyAbilitySpec(MyAbilityClass, 1);
		MyAbilitySystem->GiveAbility(MyAbilitySpec);
	}
}

// Grant default attributes at start (using effect)
void ATestDestructible::GiveDefaultAttributes() const
{
	
	if(!MyAbilitySystem || !DefaultAttributeEffect)
	{
		PRINTERR("NO DEFAULT ATTRIBUTE SET");
		return;
	}

	// FIGURE OUT WHAT THIS DOES
	FGameplayEffectContextHandle EffectContext = MyAbilitySystem->MakeEffectContext();

	// FIGURE OUT WHAT THIS DOES
	EffectContext.AddSourceObject(this);

	// FIGURE OUT WHAT THIS DOES
	const FGameplayEffectSpecHandle SpecHandle = MyAbilitySystem->MakeOutgoingSpec(DefaultAttributeEffect, 1.f, EffectContext);

	// FIGURE OUT WHAT THIS DOES
	if(SpecHandle.IsValid())
	{
		MyAbilitySystem->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());			
	}
}

// Called every frame
void ATestDestructible::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);

	// BOUNCE - Store actor's current location
	FVector NewLocation = GetActorLocation();

	// BOUNCE - Sin generates value between -1 to 1 which cycles up and down
	// We use that value to move / create the new height each frame
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

	// BOUNCE - This creates the new location towards the desired vector (in this case, Z) and multiply it by another
	// Number which will be the scale / speed of the movement
	NewLocation.Z += DeltaHeight * 10.0f;

	// BOUNCE - DeltaTime is a parameter passed to the tick function
	RunningTime += DeltaTime;

	// BOUNCE - Finally, Set the actor's location to the newly calculated location
	SetActorLocation(NewLocation);
	
	//if (ShouldAnimate)
	//{
		// Call bounce mesh function and send current time
		//BounceMesh(UGameplayStatics::GetTimeSeconds(GetWorld()), true);
        
		// Use sine wave which calculates amount of time since level has loaded to bounce actor
		// Result will be value between -1 and +1
		// float sine = FMath::Sin(AnimationStartTime * BobSpeedMultiplier);
		// this->AddActorWorldRotation(Spin * AnimationStartTime);
		// this->SetActorLocation(StartLocation + (Bob * sine));
		
	//	this->AddActorWorldRotation(Spin * .5);

	//}
		
}


// CREATES BLUEPRINT EVENT FOR HEALTH CHANGE
void ATestDestructible::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
	LOG("OnHealthAttributeChanged Fired");

	// Store start time in global variable for tick animation and set ShouldAnimate to true
	// AnimationStartTime = this->GetWorld()->GetRealTimeSeconds();
	// ShouldAnimate = true;
	
	// Do Simple Material Flash (as defined in Material Function)
	FCustomPrimitiveData CPD = StaticMeshComp->GetCustomPrimitiveData();
	
	// When health changes, flash material
	// Iterate through all static mesh subobjects and adjust material
	// Get all components of this actor
	for (UActorComponent* CompItr : this->GetComponents())
	{
		// If the currently iterated component is a mesh, cast it to a mesh component
		if (UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(CompItr))
		{

			// Print  Mesh Name
			LOG("FOUND MESH {1}", this->GetActorNameOrLabel());

			// Call Custom Primitive Data in Material Function (MF_Flash) and pass Game time for SINE math
			Mesh->SetCustomPrimitiveDataFloat(0,UGameplayStatics::GetTimeSeconds(GetWorld()));
			
			// Make an array of materials (in case there are multiple)
			TArray<class UMaterialInterface*> materials = Mesh->GetMaterials();

			// Iterate through each material - up to materials.Num() 
			for (int i = 0; i < materials.Num(); i++)
			{
				LOG("FOUND MATERIAL {1}", materials[i]->GetName());
			}
		}
	
	}
}

void ATestDestructible::BounceMesh(float StartTime, bool ShouldBounce)
{

	LOG("BounceMesh called with starting time of {1}", StartTime);
	
	// Rotate the actor over time
	// 

	// Bob the actor over time based on a sine wave

	if (ShouldBounce)
	{
	
	}


}
