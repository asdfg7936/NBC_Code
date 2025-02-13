#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpartaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UWidgetComponent;
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

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "UI")
	UWidgetComponent* OverheadWidget;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float Amount);

protected:

	void BeginPlay() override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Health")
	float Health;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, 
		struct FDamageEvent const& DamageEvent, 
		AController* EventInstigator, 
		AActor* DamageCauser) override; //각각 데미지량, 데미지를 받은 유형(EX 불속성, 물속성 등등), 데미지를 준 상대, 데미지를 발생시킨 액터
	
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

	void OnDeath();
	void UpdateOverheadHP();


private :
	float NormalSpeed;
	float SprintSpeedMultiplier;
	float SprintSpeed;
};
