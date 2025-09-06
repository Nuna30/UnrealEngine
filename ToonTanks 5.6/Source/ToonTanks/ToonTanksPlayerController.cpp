// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksPlayerController.h"
#include "GameFramework/Pawn.h"

void AToonTanksPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
    // 컨트롤러가 소유한 폰에 접근한 다음 인풋 활성화/비활성화
    if (bPlayerEnabled)
    {
        GetPawn()->EnableInput(this);
    }
    else 
    {
        GetPawn()->DisableInput(this);
    }
    bShowMouseCursor = bPlayerEnabled;
}