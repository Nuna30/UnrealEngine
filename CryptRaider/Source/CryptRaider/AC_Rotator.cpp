// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_Rotator.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UAC_Rotator::UAC_Rotator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_Rotator::BeginPlay()
{
	Super::BeginPlay();

	OriginalRotation = GetOwner()->GetActorRotation();
	RotationSpeed = (OriginalRotation - RotationOffset) * (1 / RotationTime);
}


// Called every frame
void UAC_Rotator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Rotate) DoRotate(DeltaTime);
	else DoReturn(DeltaTime);
	
}

void UAC_Rotator::DoRotate(float DeltaTime)
{
	FRotator CurrentRotation = GetOwner()->GetActorRotation();

	float diff = CalcRotationDiff(CurrentRotation, RotationOffset);

	if (CalcRotationDiff(CurrentRotation, RotationOffset) <= 1.0f) GetOwner()->SetActorRotation(RotationOffset);
	else {
		if (Clockwise) GetOwner()->AddActorLocalRotation(RotationSpeed * DeltaTime);
		else GetOwner()->AddActorLocalRotation(RotationSpeed * DeltaTime * -1);
	}
}

void UAC_Rotator::DoReturn(float DeltaTime)
{
	FRotator CurrentRotation = GetOwner()->GetActorRotation();

	float diff = CalcRotationDiff(CurrentRotation, OriginalRotation);

	if (CalcRotationDiff(CurrentRotation, OriginalRotation) <= 1.0f) GetOwner()->SetActorRotation(OriginalRotation);
		else {
		if (!Clockwise) GetOwner()->AddActorLocalRotation(RotationSpeed * DeltaTime);
		else GetOwner()->AddActorLocalRotation(RotationSpeed * DeltaTime * -1);
	}
}

float UAC_Rotator::CalcRotationDiff(FRotator fr1, FRotator fr2) {
	FRotator diff = fr1 - fr2;
	return FMath::Sqrt(diff.Pitch * diff.Pitch + diff.Yaw * diff.Yaw + diff.Roll * diff.Roll);
}