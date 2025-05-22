// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class DEMO_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	UPROPERTY(BlueprintReadOnly)
	float RunningTime = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sine Paramters")
	float Amplitude = 0.25f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sine Paramters")
	float TimeConstant = 5.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	float sinFunction(float value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
