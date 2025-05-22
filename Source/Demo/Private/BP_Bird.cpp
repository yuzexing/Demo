// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Bird.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABP_Bird::ABP_Bird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);
	SetRootComponent(Capsule);
}

// Called when the game starts or when spawned
void ABP_Bird::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_Bird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABP_Bird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

