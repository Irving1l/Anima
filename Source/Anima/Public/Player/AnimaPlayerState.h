// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AnimaPlayerState.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class ANIMA_API AAnimaPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	AAnimaPlayerState();

	
protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;


};
