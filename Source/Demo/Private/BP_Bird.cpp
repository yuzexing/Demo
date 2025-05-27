// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ABP_Bird::ABP_Bird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);
	SetRootComponent(Capsule);
	SKMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SKMesh->SetupAttachment(GetRootComponent());
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300.f;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	AutoPossessPlayer = EAutoReceiveInput::Player0;
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

void ABP_Bird::MoveForward(float value) {
	if (value != 0 && Controller) {
		FVector v = GetActorForwardVector();
		AddMovementInput(v, value, false);
	}
}

void ABP_Bird::LookUp(float value) {
	AddControllerPitchInput(value);
}

void ABP_Bird::Turn(float value) {
	AddControllerYawInput(value);
}


// Called to bind functionality to input
void ABP_Bird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName(TEXT("MoveForward")), this, &ABP_Bird::MoveForward);
	PlayerInputComponent->BindAxis(FName(TEXT("Turn")), this, &ABP_Bird::Turn);
	PlayerInputComponent->BindAxis(FName(TEXT("LookUpAndDown")), this, &ABP_Bird::LookUp);
}

