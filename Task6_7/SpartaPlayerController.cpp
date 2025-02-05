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
	if (ULocalPlayer* LoaclPlayer = GetLocalPlayer()) { // ���� �÷��̾� ��������
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem = LoaclPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()) { // ���Ʈ ��ǲ �ý��� �����ϴ� ���� �ý��� ��������
			if (InputMappingContext) { // ��ü Ȯ��
				SubSystem->AddMappingContext(InputMappingContext, 0);//�켱 ���� 0���� ���� ���� ����Ʈ�� �����϶�
			}
		}
	}
}