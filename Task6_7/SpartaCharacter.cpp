// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASpartaCharacter::ASpartaCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent); // 루트 컴포넌트 밑에 부착
	SpringArmComp->TargetArmLength = 300.0f; // 캐릭터와의 거리 입력
	SpringArmComp->bUsePawnControlRotation = true; //시점 회전시 카메라도 같이 이동하는 것

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);// 스프링 암 컴포넌트의 가장 마지막 부분에 추가 USpringArmComponent::SocketName-> 가장 마지막 부분
	CameraComp->bUsePawnControlRotation = false; //같이 움직이면 시점이 난해해짐

	NormalSpeed = 600.0f;
	SprintSpeedMultiplier = 1.7f;
	SprintSpeed = NormalSpeed * SprintSpeedMultiplier;

	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
}

// Called to bind functionality to input
void ASpartaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)//입력처리 컴포넌트
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent)) { //다른 이전 방식들로 처리가능하니 인헨스드인풋컴포넌트로 캐스팅해서 변환
		if (ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetController())) {
			if (PlayerController->MoveAction) {
				EnhancedInput->BindAction(
					PlayerController->MoveAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::Move
				);
			}
			if (PlayerController->JumpAction) {
				EnhancedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::StartJump
				);
			}
			if (PlayerController->JumpAction) {
				EnhancedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Completed,
					this,
					&ASpartaCharacter::StopJump
				);
			}
			if (PlayerController->LookAction) {
				EnhancedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::Look
				);
			}
			if (PlayerController->SprintAction) {
				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::StartSprint
				);
			}
			if (PlayerController->SprintAction) {
				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Completed,
					this,
					&ASpartaCharacter::StopSprint
				);
			}
		}
	}

}

void ASpartaCharacter::Move(const FInputActionValue& value) {
	if (!Controller) return;

	const FVector2D MoveInput = value.Get<FVector2D>();

	if (!FMath::IsNearlyZero(MoveInput.X)) {
		AddMovementInput(GetActorForwardVector(), MoveInput.X);
	}
	if (!FMath::IsNearlyZero(MoveInput.Y)) {
		AddMovementInput(GetActorRightVector(), MoveInput.Y);
	}
}

void ASpartaCharacter::StartJump(const FInputActionValue& value) {
	if (value.Get<bool>())
		Jump();

}

void ASpartaCharacter::StopJump(const FInputActionValue& value) {
	if (value.Get<bool>())
		StopJumping();
}

void ASpartaCharacter::Look(const FInputActionValue& value) {
	FVector2D LookInput = value.Get<FVector2D>();
	AddControllerYawInput(LookInput.X);
	AddControllerPitchInput(LookInput.Y);
	// pitch , yaw, roll은 각각 y축 , z축, x축
}

void ASpartaCharacter::StartSprint(const FInputActionValue& value) {
	if (GetCharacterMovement())
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;

}

void ASpartaCharacter::StopSprint(const FInputActionValue& value) {
	if (GetCharacterMovement())
		GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
}