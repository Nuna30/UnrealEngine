// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UpAndDownMover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UUpAndDownMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUpAndDownMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Go(float DeltaTime);
	void Return(float DeltaTime);
	void SetShouldMove(bool ShouldMove);

private:
	UPROPERTY(EditAnywhere, Category = "Moving")
	FVector MoveOffset;

	UPROPERTY(EditAnywhere, Category = "Moving")
	float MoveTime;

	FVector OriginalLocation;
	FVector TargetLocation;
	float speed;
	bool ShouldMove;
		
};
