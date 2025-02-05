// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveItem.h"

// Sets default values
AMoveItem::AMoveItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	MeshComponent->SetupAttachment(SceneRoot);
	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = 60.0f;
	MaxRange = 200.0f;
	start_x = GetActorLocation();
	y_n = true;
}

// Called when the game starts or when spawned
void AMoveItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	currentLocation = GetActorLocation();
	if (y_n == true) {
		Move(DeltaTime);
		if (currentLocation.X >= start_x.X + MaxRange) {
			MoveSpeed *= -1.0f;
			y_n = false;
		}
	}
	else if (y_n == false) {
		Move(DeltaTime);
		if (currentLocation.X <= start_x.X - MaxRange) {
			MoveSpeed *= -1.0f;
			y_n = true;
		}
	}

}

void AMoveItem::Move(float DeltaTime)
{
	AddActorLocalOffset(FVector(MoveSpeed*DeltaTime, 0.0f,0.0f));

}

