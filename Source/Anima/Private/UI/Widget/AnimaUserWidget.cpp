// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/AnimaUserWidget.h"

void UAnimaUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
