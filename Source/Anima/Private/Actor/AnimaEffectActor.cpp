// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/AnimaEffectActor.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/AnimaAttributeSet.h"



AAnimaEffectActor::AAnimaEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void AAnimaEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAnimaAttributeSet* AnimaAttributeSet = Cast<UAnimaAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAnimaAttributeSet::StaticClass()));
		UAnimaAttributeSet* MuAnimaAttributeSet = const_cast<UAnimaAttributeSet*>(AnimaAttributeSet);
		MuAnimaAttributeSet->SetHealth(AnimaAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void AAnimaEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AAnimaEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAnimaEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAnimaEffectActor::EndOverlap);

}


