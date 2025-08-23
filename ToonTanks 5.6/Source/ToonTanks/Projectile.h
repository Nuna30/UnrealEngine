// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Projectile")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	// HitComp : 부딪히는 컴포넌트 (발사체)
	// OtherActor : 충돌 당하는 액터
	// NormalImpulse : 충돌 직후 임펄스
	// Hit : 충돌 시 FHitResult에서 정보를 얻기 위해 넘겨줌
	// delegate에 바인딩 하기 위해 UFUNCTION 사용 (콜백 함수로 작동하기 위해선 필수)
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	float Damage = 50.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
