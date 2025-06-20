// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AnimaCharacterBase.h"
#include "AnimaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class ANIMA_API AAnimaCharacter : public AAnimaCharacterBase
{
	GENERATED_BODY()
	
public:
	AAnimaCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UCameraComponent> CameraComponent;


	void InitAbilityActorInfo();

};
