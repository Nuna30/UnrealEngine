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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	virtual void Tick(float DeltaTime) override;

	void Fire();
	void LookAtTank();
	
	class ATank* Tank;

	UPROPERTY(EditAnywhere, Category = "Tower")
	float FireRange = 600;

};
