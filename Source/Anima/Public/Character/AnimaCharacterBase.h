// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AnimaCharacterBase.generated.h"

UCLASS()
class ANIMA_API AAnimaCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAnimaCharacterBase();

protected:
	virtual void BeginPlay() override;



};
