// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	void HandleDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	virtual void Tick(float DeltaTime) override;

	void LookAtTank();
	
	class ATank* Tank;

	UPROPERTY(EditAnywhere, Category = "Tower")
	float FireRange = 600;

	FTimerHandle FireRateTimerHandle;
	float FireRate = 2;
	void CheckFireCondition();

};
