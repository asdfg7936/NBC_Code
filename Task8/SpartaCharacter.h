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
		AActor* DamageCauser) override; //���� ��������, �������� ���� ����(EX �ҼӼ�, ���Ӽ� ���), �������� �� ���, �������� �߻���Ų ����
	
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

	void OnDeath();
	void UpdateOverheadHP();


private :
	float NormalSpeed;
	float SprintSpeedMultiplier;
	float SprintSpeed;
};
