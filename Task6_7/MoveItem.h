// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveItem.generated.h"

UCLASS()
class PROJECT1_API AMoveItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveItem();

protected:
	
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "MoveItem|Component")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveItem|Component")
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveItem|Properties")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveItem|Properties")
	float MaxRange;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "MoveItem|Properties")
	FVector currentLocation;

	FVector start_x;
	bool y_n;
	void Move(float DeltaTime);
	
	//UFUNCTION(BlueprintCallable, Category = "MoveItem|Properties")
	//void PrintMoveSpeed();

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
