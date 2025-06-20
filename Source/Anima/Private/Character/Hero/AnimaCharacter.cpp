// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Hero/AnimaCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "Kismet/KismetMathLibrary.h"
#include "Player/AnimaPlayerState.h"
#include "AbilitySystemComponent.h"


AAnimaCharacter::AAnimaCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 10.f;
	SpringArm->bDoCollisionTest = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArm);
}

void AAnimaCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();
}

void AAnimaCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AAnimaCharacter::InitAbilityActorInfo()
{
	AAnimaPlayerState* AnimaPlayerState = GetPlayerState<AAnimaPlayerState>();
	check(AnimaPlayerState);
	AnimaPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AnimaPlayerState, this);
	AbilitySystemComponent = AnimaPlayerState->GetAbilitySystemComponent();
	AttributeSet = AnimaPlayerState->GetAttributeSet();
}
