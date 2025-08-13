// Fill out your copyright notice in the Description page of Project Settings.

#include "LeftMover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
ULeftMover::ULeftMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULeftMover::BeginPlay()
{
	Super::BeginPlay();

	OriginalLocation = GetOwner()->GetActorLocation();
	TargetLocation = OriginalLocation - MoveOffset;
	speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;
}


// Called every frame
void ULeftMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (move) Go(DeltaTime);
	else Return(DeltaTime);

}

void ULeftMover::Go(float DeltaTime)
{
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, speed);
	GetOwner()->SetActorLocation(NewLocation);
}

void ULeftMover::Return(float DeltaTime)
{
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, OriginalLocation, DeltaTime, speed);
	GetOwner()->SetActorLocation(NewLocation);
}