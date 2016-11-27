// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin play"))

	auto Tank = GetControlledTank();
	if (Tank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing %s"), *Tank->GetName())
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Not posessing a tank"))
	}
}

// Called every frame
void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	// AimTowardsCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("ticking"))

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

