// Irving's project is aimed at finding a job.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AnimaCharacterBase.generated.h"

UCLASS(Abstract)//对于不用实例化的类，可以使用这个声明
class ANIMA_API AAnimaCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAnimaCharacterBase();

protected:
	virtual void BeginPlay() override;

	//UPROPERTY(EditAnywhere, Category = "Combat")
	//TObjectPtr<UStaticMeshComponent> Weapon;

};
