// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Heroine.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GroomComponent.h"

// Sets default values
AHeroine::AHeroine()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300.f;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 700.f, 0.f);

	Hair = CreateDefaultSubobject<UGroomComponent>(TEXT("Hair"));
	Hair->SetupAttachment(GetMesh());
	Hair->AttachmentName = TEXT("Head");

	Eyebrows = CreateDefaultSubobject<UGroomComponent>(TEXT("Eyebrows"));
	Eyebrows->SetupAttachment(GetMesh());
	Eyebrows->AttachmentName = TEXT("Head");
}

// Called when the game starts or when spawned
void AHeroine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHeroine::MoveForward(float value) {
	if (Controller && value) {
		FRotator ControlRotator = GetControlRotation();
		FRotator YawRotator(0.f, ControlRotator.Yaw, 0.f);
		FVector Direction = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}
void AHeroine::Turn(float value) {
	AddControllerYawInput(value);
}
void AHeroine::LookUpAndDown(float value) {
	AddControllerPitchInput(value);
}

void AHeroine::TurnRight(float value) {
	if (Controller && value) {
		FRotator ControlRotator = GetControlRotation();
		FRotator YawRotator(0.f, ControlRotator.Yaw, 0.f);
		FVector Direction = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}
// Called to bind functionality to input
void AHeroine::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName(TEXT("MoveForward")), this, &AHeroine::MoveForward);
	PlayerInputComponent->BindAxis(FName(TEXT("Turn")), this, &AHeroine::Turn);
	PlayerInputComponent->BindAxis(FName(TEXT("LookUpAndDown")), this, &AHeroine::LookUpAndDown);
	PlayerInputComponent->BindAxis(FName(TEXT("TurnRight")), this, &AHeroine::TurnRight);
}

