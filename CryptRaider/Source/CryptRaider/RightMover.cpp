// Fill out your copyright notice in the Description page of Project Settings.

#include "RightMover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
URightMover::URightMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URightMover::BeginPlay()
{
	Super::BeginPlay();
	
	AActor* Owner = GetOwner();
	FString Name = Owner->GetActorNameOrLabel();
	FVector OwnerLocation = Owner->GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("Right Mover : %s %s"), *Name, *OwnerLocation.ToCompactString());

}


// Called every frame
void URightMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

