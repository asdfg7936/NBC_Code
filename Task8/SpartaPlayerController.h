// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpartaPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class PROJECT1_API ASpartaPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ASpartaPlayerController();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SprintAction;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<UUserWidget> HUDwidgetClass;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "HUD")
	UUserWidget* HUDwidgetInstance;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Menu")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Menu")
	UUserWidget* MainMenuWidgetInstance;

	UFUNCTION(BlueprintPure, Category = "HUD")
	UUserWidget* GetHUDwidget() const;
	UFUNCTION(BlueprintCallable, Category = "HUD")
	void ShowGameHUD();
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowMainMenu(bool bIsRestart);
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void StartGame();

protected:
	virtual void BeginPlay() override;

};
