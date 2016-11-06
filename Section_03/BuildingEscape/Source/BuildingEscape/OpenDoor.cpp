// Copyright 2016 Santiago Regueiro

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	Owner = GetOwner();
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if(GetTotalMassOfActorsOnPlate() > TriggerMass) {
		OnOpen.Broadcast();
	} else {
		OnClose.Broadcast();
	}
}

float UOpenDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;

	TArray<AActor*> OverlappingActors;

	if (!PressurePlate) { return 0.f; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	for (const auto& Actor : OverlappingActors) {
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	return TotalMass;
}

