// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	void ActorDied(AActor* DeadActor);
	
protected:
	
	virtual void BeginPlay() override;

	// 함수 바디는 .cpp이 아니라 블루프린트에서 구현할 거임
	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

private:
	
	class AToonTanksPlayerController* ToonTanksPlayerController;
	class ATank* Tank;

	// 게임 시작 전 3초 대기
	float StartDelay = 3;

	// 게임 시작 처리 함수
	void HandleGameStart();

};
