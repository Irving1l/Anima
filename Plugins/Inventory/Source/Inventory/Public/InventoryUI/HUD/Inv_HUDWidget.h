// Irving's project is aimed at finding a job.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_HUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UInv_HUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void ShowPickupMessage(const FString& Message);//使用引用是为了避免拷贝，直接传递值会创建一个副本

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void HidePickupMessage();
};
