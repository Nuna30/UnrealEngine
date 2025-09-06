// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorGun.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AColorGun::AColorGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 컴포넌트 생성 및 hierarchy 구축
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AColorGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColorGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

