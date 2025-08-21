// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

ATank::ATank() 
{
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
    SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
    PlayerController = Cast<APlayerController>(GetController());
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    LookAtCursor();
}

void ATank::LookAtCursor()
{
    if (PlayerController)
        {
            FHitResult HitResult;
            PlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);
            Super::RotateTurret(HitResult.ImpactPoint);
            DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 25.f, 12, FColor::Red, false, -1);
        }
}

void ATank::Move(float Value)
{
    UE_LOG(LogTemp, Display, TEXT("Value : %f"), Value);

    float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

    FVector DeltaLocation = FVector(0.f);
    DeltaLocation.X = Value * Speed * DeltaTime;

    AddActorLocalOffset(DeltaLocation, true);
}

void ATank::Turn(float Value)
{
    float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

    FRotator DeltaRotation = FRotator(0.f);
    DeltaRotation.Yaw = Value * TurnRate * DeltaTime;

    AddActorLocalRotation(DeltaRotation, true);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    // 프로젝트 세팅에서 설정한 axi mappings group 이름과 같아야 한다.
    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
}
