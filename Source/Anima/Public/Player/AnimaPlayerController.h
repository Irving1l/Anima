// Irving's project is aimed at finding a job.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AnimaPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UInv_HUDWidget;

/**
 * 
 */
UCLASS()
class ANIMA_API AAnimaPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAnimaPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void PrimaryInteract();
	void CreateHUDWidget();
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> AnimaContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> PrimaryInteractAction;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TSubclassOf<UInv_HUDWidget> Inv_HUDWidgetClass;

	UPROPERTY()
	TObjectPtr<UInv_HUDWidget> Inv_HUDWidget;
	
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	
};
