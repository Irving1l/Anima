// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AnimaHUD.h"
#include "UI/Widget/AnimaUserWidget.h"



void AAnimaHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
