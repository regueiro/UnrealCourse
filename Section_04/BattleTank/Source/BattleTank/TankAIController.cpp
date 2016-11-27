// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AIController Begin play"))

	auto Tank = GetControlledTank();
	if (Tank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController posessing %s"), *Tank->GetName())
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Not posessing a tank"))
	}

	auto PlayerTank = GetPlayerTank();

	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Found player tank %s"), *PlayerTank->GetName())
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player tank not found"))
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	auto PlayerTank = Cast<ATank>(Player);
	
	return PlayerTank;
}
