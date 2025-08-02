// Irving's project is aimed at finding a job.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AnimaCharacterBase.generated.h"

UCLASS()
class ANIMA_API AAnimaCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAnimaCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
