// Copyright 2016 Santiago Regueiro

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UPROPERTY(BlueprintAssignable)
	FOnDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
	FOnDoorEvent OnClose;
		
private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float TriggerMass;

	AActor* Owner = nullptr;

	float GetTotalMassOfActorsOnPlate();
};
