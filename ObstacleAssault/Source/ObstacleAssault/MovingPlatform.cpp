// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// 현재 위치에 속력 벡터 더해서 플랫폼 이동
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);

	// 시작점 기준 플랫폼이 이동한 거리 계산
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	// 제한 거리를 벗어나면 최대 제한 거리에 플랫폼을 위치 시킴
	if (DistanceMoved > MoveDistance) {
		SetActorLocation(StartLocation + PlatformVelocity.GetSafeNormal() * MoveDistance);
		PlatformVelocity *= -1;
	}
}

