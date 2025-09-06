// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

<<<<<<< HEAD
=======
	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunMesh"));
>>>>>>> 853db79 ([ git 다시 연결함 ])
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

<<<<<<< HEAD
=======
	SyncWithGun();

}

void APlayerCharacter::SyncWithGun()
{
	if (GunMesh)
    {
        FRotator CharacterRotation = GetActorRotation(); 
        GunMesh->SetWorldRotation(CharacterRotation);
    }
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NO GunMesh initialized in APlayerCharcter::SyncWithGun()"));
	}
>>>>>>> 853db79 ([ git 다시 연결함 ])
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 키 바인딩 매핑
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APlayerCharacter::LookRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Jump);
}

void APlayerCharacter::MoveForward(float AxisValue)
{
	// 무브먼트 컴포넌트(Movement Component)에 이동 요청을 추가
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void APlayerCharacter::LookUp(float AxisValue)
{
	// 컨트롤러에 pitch 값 추가
	AddControllerPitchInput(AxisValue);
}

void APlayerCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void APlayerCharacter::LookRight(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void APlayerCharacter::Jump()
{
	ACharacter::Jump();
}