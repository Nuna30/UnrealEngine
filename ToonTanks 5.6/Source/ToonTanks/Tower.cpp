// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);
    
    if (Tank)
    {
        float Distance = FVector::Dist(this->GetActorLocation(), Tank->GetActorLocation());

        if (Distance < FireRange) Super::RotateTurret(Tank->GetActorLocation());
    } 

}

void ATower::BeginPlay()
{
	Super::BeginPlay();
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
    if (FVector::Dist(Tank->GetActorLocation(), this->GetActorLocation()) < FireRange)
    {
        Super::Fire();        
    }
}

void ATower::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}