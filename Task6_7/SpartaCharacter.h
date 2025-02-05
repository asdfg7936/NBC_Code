#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpartaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;

UCLASS()
class PROJECT1_API ASpartaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	ASpartaCharacter();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Camera|Camera")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera|Camera")
	UCameraComponent* CameraComp;

protected:


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION() //����ϸ� �ּ��� �����ʿ��� �ش� �Լ��� �ľ��� �� �ִ�.
	void Move(const FInputActionValue& value); //����ü�� ���� ũ�� ������ ������ �������� ���� ���ɿ� �� ����.
	UFUNCTION()
	void StartJump(const FInputActionValue& value); //������ ������ ���� ������ ���� �ϱ� ���ؼ� ������ �ȴ�.
	UFUNCTION()
	void StopJump(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);
	UFUNCTION()
	void StartSprint(const FInputActionValue& value);
	UFUNCTION()
	void StopSprint(const FInputActionValue& value);

private :
	float NormalSpeed;
	float SprintSpeedMultiplier;
	float SprintSpeed;
};
