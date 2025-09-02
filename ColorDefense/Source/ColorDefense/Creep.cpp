// Fill out your copyright notice in the Description page of Project Settings.


#include "Creep.h"
#include "AIController.h"

// Sets default values
ACreep::ACreep()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACreep::BeginPlay()
{
	Super::BeginPlay();

	MoveTo(-1780, 1780, 5);
	
}

// Called every frame
void ACreep::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACreep::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACreep::MoveTo(float x, float y, float z)
{
	AAIController* AIController = Cast<AAIController>(GetController());
	if (AIController)
	{
		FVector Destination = FVector(x, y, z);
		float AcceptanceRadius = 50.0f;
		bool bStopOnOverlap = true;
		bool bUsePathfinding = true;
		bool bProjectDestinationToNavigation = true;
		bool bCanStrafe = false;
		TSubclassOf<UNavigationQueryFilter> FilterClass = nullptr;
		bool bAllowPartialPath = true;

		EPathFollowingRequestResult::Type Result = AIController->MoveToLocation(
			Destination,
			AcceptanceRadius,
			bStopOnOverlap,
			bUsePathfinding,
			bProjectDestinationToNavigation,
			bCanStrafe,
			FilterClass,
			bAllowPartialPath
		);

		// if (Result == EPathFollowingRequestResult::Type::RequestSuccessful)
		// {
		// 	UE_LOG(LogTemp, Log, TEXT("MoveToLocation: 이동 요청이 성공적으로 시작되었습니다."));
		// }
		// else if (Result == EPathFollowingRequestResult::Type::AlreadyAtGoal)
		// {
		// 	UE_LOG(LogTemp, Log, TEXT("MoveToLocation: 이미 목적지에 있습니다."));
		// }
		// else // Failed
		// {
		// 	UE_LOG(LogTemp, Warning, TEXT("MoveToLocation: 경로 요청에 실패했습니다."));
		// }
	}
}