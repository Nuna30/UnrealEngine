// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_Rotator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UAC_Rotator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_Rotator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FRotator OriginalRotation;
	FRotator RotationSpeed;

	void DoRotate(float DeltaTime);
	void DoReturn(float DeltaTime);
	float CalcRotationDiff(FRotator fr1, FRotator fr2);

private:
	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator RotationOffset;
	
	UPROPERTY(EditAnywhere, Category = "Rotation")
	float RotationTime;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	bool Rotate;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	bool Clockwise;
};
