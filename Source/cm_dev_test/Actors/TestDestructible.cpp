// Core Mechanics
// Aaron McClay 2025


#include "TestDestructible.h"
#include "Kismet/GameplayStatics.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/TestAbilitySystemComponent.h"
#include "AbilitySystem/TestAttributeSet.h"

// Constructor - Set default values here
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

	// Create Sound Subobject
	BounceSound = CreateDefaultSubobject<USoundBase>("Bounce Sound");

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

	StartLocation = GetActorLocation();
	 BounceSoundPlayed = false;
	
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
	
		if (BounceStartTime != -1.0f) // Check if bounce should happen (happens every frame)
		{
			// Calculate the time passed since the bounce started
			float ElapsedTime = GetWorld()->GetTimeSeconds() - BounceStartTime;

			float LerpFactor = FMath::Clamp(ElapsedTime / BounceDuration, 0.0f, 1.0f);
			float QuadraticBounceFactor = 4.0f * LerpFactor * (LerpFactor - 1.0f);

			// Apply LERP to Z-axis position (example)
			FVector NewLocation = FVector(GetActorLocation().X, GetActorLocation().Y, FMath::Lerp(StartLocation.Z, TargetLocation.Z, QuadraticBounceFactor));
			SetActorLocation(NewLocation);
			// LOG("CURRENT BOUNCE LOCATION: {1}", NewLocation.Z);

			// Check if Lerp bounce position and if sound hasn't already played, play bounce sound
			if (LerpFactor > .5f && !BounceSoundPlayed)
			{
				
				// Play bounce sound
				UGameplayStatics::PlaySound2D(GetWorld(), BounceSound, .5, 1, 0, NULL, this, true);
				BounceSoundPlayed = true;
			}
				// If LerpFactor hits 1, we are done with the bounce.  Reset Start Time so we can bounce again.
				if (LerpFactor == 1.0f)
				{
					// Bounce completed
					BounceStartTime = -1.0f;

					//Optional: Trigger other events at end of bounce
					// Do Stuff
					BounceSoundPlayed = false;

				}
		}
}


// CREATES BLUEPRINT EVENT FOR HEALTH CHANGE
void ATestDestructible::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
	// LOG("OnHealthAttributeChanged Fired");

	// Test change for PC Commit - REMOVE
	s
	// Set Bounce Start Time (this will allow jump animation in tick function to begin)
	BounceStartTime = GetWorld()->GetTimeSeconds();
	LOG("\nBounce Data:\nStart Time: {1}\nDuration: {2}\nStart Height: {3}", BounceStartTime, BounceDuration, StartLocation.Z);

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
			// LOG("FOUND MESH {1}", this->GetActorNameOrLabel());

			// Call Custom Primitive Data in Material Function (MF_Flash) and pass Game time for SINE math
			Mesh->SetCustomPrimitiveDataFloat(0,UGameplayStatics::GetTimeSeconds(GetWorld()));
			
			// Make an array of materials (in case there are multiple)
			TArray<class UMaterialInterface*> materials = Mesh->GetMaterials();

			// Iterate through each material - up to materials.Num() 
			for (int i = 0; i < materials.Num(); i++)
			{
				// LOG("FOUND MATERIAL {1}", materials[i]->GetName());
			}
		}
	
	}
}