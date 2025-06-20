// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AnimaCharacterBase.h"


AAnimaCharacterBase::AAnimaCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

}

UAbilitySystemComponent* AAnimaCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAnimaCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


