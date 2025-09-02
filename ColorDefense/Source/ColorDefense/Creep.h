// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Creep.generated.h"

UCLASS()
class COLORDEFENSE_API ACreep : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACreep();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveTo(float x, float y, float z);
};
