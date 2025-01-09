// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "CoreMinimal.h"
#include <iostream>

// Sets default values
AMyActor::AMyActor()
    : MoveCount(0)
    , Timer(0.f)
    , EventCount(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
    GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "MyActor Spawned.");
    UE_LOG(LogTemp, Log, TEXT("MyActor Spawned."));
	
}


// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (MoveCount < 10)
    {
        if (Timer < 1.f)
        {
            Timer += DeltaTime;
        }
        else
        {
            move();
            Timer = 0.f;
        }
    }

}

void AMyActor::move()
{
    int Scale = 100.f;

    int DeltaX = step() * Scale;
    int DeltaY = step() * Scale;
    int DirectionX = createEvent();
    int DirectionY = createEvent();

    start = GetActorLocation();
    int32 Event_temp = createEvent();
    float NewPosX = (DeltaX * DirectionX) + start.X;
    float NewPosY = (DeltaY * DirectionY) + start.Y;
    FVector NewPos = FVector(NewPosX, NewPosY, start.Z);
    SetActorLocation(NewPos);
    ++MoveCount;

    if (Event_temp == 1) {
        UE_LOG(LogTemp, Log, TEXT("happen Event"));
        EventCount++;
    }
    FString Print_MoveCnt = FString::Printf(TEXT("MoveCnt = %d"), MoveCount);
    GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Print_MoveCnt);
    UE_LOG(LogTemp, Log, TEXT("MoveCnt = %d"), MoveCount);

    distance(start / Scale, NewPos / Scale);

    if (MoveCount == 10)
    {
        UE_LOG(LogTemp, Log, TEXT("EventCount: %d"), EventCount);
    }
}
void AMyActor::distance(FVector first, FVector second)
{
    float distance = FMath::Sqrt(
        FMath::Pow(static_cast<float>(second.X - first.X), 2.0f) +
        FMath::Pow(static_cast<float>(second.Y - first.Y), 2.0f)
    );
    UE_LOG(LogTemp, Log, TEXT("%d_Move Distance : %f"),MoveCount, distance);
}
int32 AMyActor::createEvent() {
    return FMath::RandBool() ? 1 : (-1);
}

int32_t AMyActor::step()
{
    bool bRandomBoolean = FMath::RandBool();
    return bRandomBoolean ? 1 : 0;
}
