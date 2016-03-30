// Copyright 2016 Santiago Regueiro

#include "BuildingEscape.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Get player viewpoint
	FVector ViewPointLocation;
	FRotator ViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT ViewPointLocation, OUT ViewPointRotation);

	//UE_LOG(LogTemp, Warning, TEXT("Location %s, Rotation %s"), *ViewPointLocation.ToString(), *ViewPointRotation.ToString());

	// Draw a red trace in the world to visualise

	FVector LineTraceEnd = ViewPointLocation + ViewPointRotation.Vector()* Reach;

	DrawDebugLine(GetWorld(), ViewPointLocation, LineTraceEnd, FColor(255, 0, 0), false, 0 ,0, 10);

	// Ray-cast to reach distance
	FHitResult LineTraceHitResult;
	FCollisionQueryParams CollisionQueryParams(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(OUT LineTraceHitResult, ViewPointLocation, LineTraceEnd, FCollisionObjectQueryParams(
		ECC_PhysicsBody), CollisionQueryParams);
	// See what we hit
	auto ActorHit = LineTraceHitResult.GetActor();

	if (ActorHit) {
		UE_LOG(LogTemp, Warning, TEXT("Hit %s"), *(ActorHit->GetName()));
	}

	
}

