// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaGameMode.h"
#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"

ASpartaGameMode::ASpartaGameMode()
{
	DefaultPawnClass = ASpartaCharacter::StaticClass(); //클래스 이름을 통해 출력, StaticClass()는 정적으로 반환해주는 것
	PlayerControllerClass = ASpartaPlayerController::StaticClass();

}