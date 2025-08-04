// Irving's project is aimed at finding a job.


#include "Character/AnimaCharacterBase.h"


AAnimaCharacterBase::AAnimaCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	//Weapon = CreateDefaultSubobject<UStaticMeshComponent>("Weapon");
	//Weapon->SetupAttachment(GetMesh(), FName(TEXT("WeaponHandSocket")));
	//Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAnimaCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



