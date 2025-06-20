// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AnimaPlayerState.h"
#include "AbilitySystem/AnimaAbilitySystemComponent.h"
#include "AbilitySystem/AnimaAttributeSet.h"

AAnimaPlayerState::AAnimaPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAnimaAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UAnimaAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AAnimaPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
