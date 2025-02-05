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
	
	UFUNCTION() //사용하면 최소한 엔진쪽에서 해당 함수를 파악할 수 있다.
	void Move(const FInputActionValue& value); //구조체는 값이 크기 때문에 참조로 가져오는 편이 성능에 더 좋다.
	UFUNCTION()
	void StartJump(const FInputActionValue& value); //누르는 순간과 때는 순간을 따로 하기 위해서 나눠도 된다.
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
