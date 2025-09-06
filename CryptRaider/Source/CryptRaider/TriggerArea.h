// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "UpAndDownMover.h"
#include "TriggerArea.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UTriggerArea : public UBoxComponent
{
	GENERATED_BODY()

public:
	UTriggerArea();	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	AActor* GetAcceptableActor() const;

    UFUNCTION(BlueprintCallable)
    void SetMover(UUpAndDownMover* Mover);

private:
	UPROPERTY(EditAnywhere, Category = "TriggerArea")
	FName TriggerTag;
    UUpAndDownMover* Mover;
};
