// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AnimaAttributeSet.h"
#include "Net/UnrealNetwork.h"


UAnimaAttributeSet::UAnimaAttributeSet()
{
	InitHealth(100.f);
}

void UAnimaAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAnimaAttributeSet, Health, COND_None, REPNOTIFY_Always);

}

void UAnimaAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAnimaAttributeSet, Health, OldHealth);//OldHealth以防止回滚
}
