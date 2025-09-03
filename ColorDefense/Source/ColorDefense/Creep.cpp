// Fill out your copyright notice in the Description page of Project Settings.


#include "Creep.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "WayPoint.h"

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

	// AIController 가져오기
	AIController = Cast<AAIController>(GetController());

	// 목적지에 도착했을 경우를 처리하는 OnMoveCompleted 콜백함수 연결
	AIController->ReceiveMoveCompleted.AddDynamic(this, &ACreep::OnMoveCompleted);

	// 출발
	MoveAlong();

	// 위에서 BP_Creep 보기
	if (ViewInGame) 
	{
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (PC)
		{
			PC->SetViewTarget(this);
		}	
	}
	
}

// Called every frame
void ACreep::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 현재 ai 상태 출력
	if (AIController)
	{
		FString StatusString = UEnum::GetValueAsString(AIController->GetMoveStatus());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, StatusString);
	}

}

// Called to bind functionality to input
void ACreep::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// 해당 좌표로 이동
void ACreep::MoveTo(float x, float y, float z)
{
	if (AIController)
	{
		FVector Destination = FVector(x, y, z);
		float AcceptanceRadius = VAcceptanceRadius;
		bool bStopOnOverlap = true;
		bool bUsePathfinding = true;
		bool bProjectDestinationToNavigation = false;
		bool bCanStrafe = false;
		TSubclassOf<UNavigationQueryFilter> FilterClass = nullptr;
		bool bAllowPartialPath = false;

		// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("MoveToLocation...")));

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

		// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("MoveToLocation completed")));
	}
	else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("No AIController")));
}

// 모든 waypoint들 얻어서 Waypoints 배열에 저장
void ACreep::GetAllWaypoints()
{
	TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWayPoint::StaticClass(), FoundActors);
	for (AActor* Actor : FoundActors)
	{
		AWayPoint* Waypoint = Cast<AWayPoint>(Actor);
		if (Waypoint)
		{
			// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Added.")));
			Waypoints.Add(Waypoint);
		}
		else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("No Waypoint")));
	}
}

// Wapoint 차례대로 이동
void ACreep::MoveAlong()
{
	GetAllWaypoints();
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Waypoints.Num() = %d"), Waypoints.Num()));
    if (Waypoints.Num() > 0)
	{
		FVector StartLocation = Waypoints[0]->GetActorLocation();
		MoveTo(StartLocation.X, StartLocation.Y, StartLocation.Z);
	}
	else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("No Waypoint in Waypoints")));
}

void ACreep::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("OnMoveCompleted...")));

    CurrentWaypointIndex++;
    if (Waypoints.IsValidIndex(CurrentWaypointIndex))
    {
        FVector NextLocation = Waypoints[CurrentWaypointIndex]->GetActorLocation();
        MoveTo(NextLocation.X, NextLocation.Y, NextLocation.Z);
    }
	else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("No Waypoints valid index")));

	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("OnMoveCompleted completed")));
}