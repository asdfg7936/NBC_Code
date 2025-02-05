// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaPlayerController.h"
#include "EnhancedInputSubsystems.h"

ASpartaPlayerController::ASpartaPlayerController()
	:InputMappingContext(nullptr),
	MoveAction(nullptr),
	JumpAction(nullptr),
	LookAction(nullptr),
	SprintAction(nullptr)
{

}

void ASpartaPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (ULocalPlayer* LoaclPlayer = GetLocalPlayer()) { // 로컬 플레이어 가져오기
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem = LoaclPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()) { // 인헨스트 인풋 시스템 관리하는 서브 시스템 가져오기
			if (InputMappingContext) { // 객체 확인
				SubSystem->AddMappingContext(InputMappingContext, 0);//우선 순위 0으로 현재 맵핑 컨텍트를 연결하라
			}
		}
	}
}