// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	void HandleDestruction();

	APlayerController* GetTankPlayerController() const {return TankPlayerController;}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* CameraComp;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArmComp;
		
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class APlayerController* TankPlayerController;

	UPROPERTY(EditAnywhere, Category = "Tank")
	float Speed = 400;
	
	UPROPERTY(EditAnywhere, Category = "Tank")
	float TurnRate = 90;

	
	void Move(float Value);
	void Turn(float Value);
	void LookAtCursor();
public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
