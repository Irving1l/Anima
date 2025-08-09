// Irving's project is aimed at finding a job.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Inv_Highlightable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)//添加这个后，确保编译器正确生成了必要的类导出符号。
class UInv_Highlightable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INVENTORY_API IInv_Highlightable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, Category = "Inventory")
	void Highlight();

	UFUNCTION(BlueprintNativeEvent, Category = "Inventory")
	void UnHighlight();
	
};
