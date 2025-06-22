// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AnimaHUD.generated.h"

class UAnimaUserWidget;

/**
 * 
 */
UCLASS()
class ANIMA_API AAnimaHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	TObjectPtr<UAnimaUserWidget> OverlayWidget;


protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAnimaUserWidget> OverlayWidgetClass;

	
};
