// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerArea.h"

// Sets default values for this component's properties
UTriggerArea::UTriggerArea()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTriggerArea::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UTriggerArea::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor* Actor = GetAcceptableActor();

    if (Mover != nullptr) { // 이거 안 해주면 실행 직후 바로 팅김
        if (Actor == nullptr) {
            Mover->SetShouldMove(false);
            GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("lock..."));
        }
        else {
            Mover->SetShouldMove(true);
            GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Unlock!!"));
        }
    }

}

AActor* UTriggerArea::GetAcceptableActor() const {
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

    for (int i = 0; i < Actors.Num(); i++) {
        if (Actors[i]->ActorHasTag(TriggerTag)) {
            return Actors[i];
        }
    }

    return nullptr;

}

void UTriggerArea::SetMover(UUpAndDownMover* NewMover) {
    Mover = NewMover;
}