// Irving's project is aimed at finding a job.


#include "Character/AnimaCharacterBase.h"

// Sets default values
AAnimaCharacterBase::AAnimaCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAnimaCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnimaCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAnimaCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

