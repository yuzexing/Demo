// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "DrawDebugHelpers.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begine Tick Called: %f"), 1.f);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(32, 5, FColor::Blue, FString(TEXT("my test")));
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	RunningTime += DeltaTime;
}

float AItem::sinFunction(float value) {
	return FMath::Sin(value * TimeConstant) * Amplitude;
}
