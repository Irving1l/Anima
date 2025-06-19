// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AnimaPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"



AAnimaPlayerController::AAnimaPlayerController()
{
	bReplicates = true;
}

void AAnimaPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AnimaContext);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AnimaContext, 0);
}

void AAnimaPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAnimaPlayerController::Move);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAnimaPlayerController::Look);

}

void AAnimaPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAnimaPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	if (InputAxisVector.IsNearlyZero())
	{
		return;
	}

	FRotator NewControlRotation = GetControlRotation();

	NewControlRotation.Yaw += InputAxisVector.X * 2.f;
	NewControlRotation.Pitch = FMath::Clamp(NewControlRotation.Pitch - InputAxisVector.Y * 2.f, -80.f, 80.f);

	SetControlRotation(NewControlRotation);
}
