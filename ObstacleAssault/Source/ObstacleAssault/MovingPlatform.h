// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "MovingPlatform")
	FVector PlatformVelocity = FVector(10000, 0, 0);

	UPROPERTY(EditAnywhere, Category = "MovingPlatform")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "MovingPlatform")
	float MoveDistance = 200;

private:
	// move platform
	void MovePlatform(float DeltatTime);
	void RotatePlatform(float DeltaTime);
};
