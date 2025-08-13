// Fill out your copyright notice in the Description page of Project Settings.


#include "UpAndDownMover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UUpAndDownMover::UUpAndDownMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUpAndDownMover::BeginPlay()
{
	Super::BeginPlay();
	
	OriginalLocation = GetOwner()->GetActorLocation();
	TargetLocation = OriginalLocation + MoveOffset;
	speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;
}


// Called every frame
void UUpAndDownMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
		
	if (move) Go(DeltaTime);
	else Return(DeltaTime);
}

void UUpAndDownMover::Go(float DeltaTime)
{
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, speed);
	GetOwner()->SetActorLocation(NewLocation);
}

void UUpAndDownMover::Return(float DeltaTime)
{
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, OriginalLocation, DeltaTime, speed);
	GetOwner()->SetActorLocation(NewLocation);
}