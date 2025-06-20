// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Enemy/AnimaEnemy.h"
#include "AbilitySystem/AnimaAbilitySystemComponent.h"
#include "AbilitySystem/AnimaAttributeSet.h"


AAnimaEnemy::AAnimaEnemy()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAnimaAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAnimaAttributeSet>("AttributeSet");
}

void AAnimaEnemy::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
