// Irving's project is aimed at finding a job.


#include "Player/AnimaPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Character/AnimaPlayerCharacter.h"
#include "InventoryUI/HUD/Inv_HUDWidget.h"
#include "Item/Component/Inv_Highlightable.h"
#include "Item/Component/Inv_ItemComponent.h"
#include "Kismet/GameplayStatics.h"


AAnimaPlayerController::AAnimaPlayerController()
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
	TraceLength = 500.0;
	ItemTraceChannel = ECC_GameTraceChannel1;
}

void AAnimaPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TraceForItem();
}

void AAnimaPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AnimaContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(AnimaContext, 0);
	}
	CreateHUDWidget();
}

void AAnimaPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAnimaPlayerController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAnimaPlayerController::Look);
	EnhancedInputComponent->BindAction(PrimaryInteractAction, ETriggerEvent::Started, this, &AAnimaPlayerController::PrimaryInteract);
}

void AAnimaPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D InputAxisVector = Value.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAnimaPlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D InputAxisVector = Value.Get<FVector2D>();
	
	if (ACharacter* ControlledCharacter = GetCharacter())
	{
		ControlledCharacter->AddControllerYawInput(InputAxisVector.X);
		ControlledCharacter->AddControllerPitchInput(InputAxisVector.Y);
	}
}

void AAnimaPlayerController::PrimaryInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Primary Interact"));
}

void AAnimaPlayerController::CreateHUDWidget()
{
	if (!IsLocalPlayerController()) return;

	Inv_HUDWidget = CreateWidget<UInv_HUDWidget>(this, Inv_HUDWidgetClass);
	if (IsValid(Inv_HUDWidget))
	{
		Inv_HUDWidget->AddToViewport();
	}
}

void AAnimaPlayerController::TraceForItem()
{
	if (!IsValid(GEngine) && !IsValid(GEngine->GameViewport)) return;
	FVector2D ViewportSize;
	GEngine->GameViewport->GetViewportSize(ViewportSize);
	const FVector2D ViewportCenter = ViewportSize / 2.f;
	FVector TraceStart;
	FVector TraceForward;//未返回，则TraceStart、TraceForward有效
	if (!UGameplayStatics::DeprojectScreenToWorld(this, ViewportCenter, TraceStart, TraceForward)) return;
	
	const FVector TraceEnd = TraceStart + TraceForward * TraceLength;
	FHitResult HitResult;

	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ItemTraceChannel);

	LastActor = ThisActor;
	ThisActor = HitResult.GetActor();

	if (!ThisActor.IsValid())
	{
		if (IsValid(Inv_HUDWidget)) Inv_HUDWidget->HidePickupMessage();
	}
	
	if (ThisActor == LastActor) return;
	if (ThisActor.IsValid())
	{
		if (UActorComponent* Hightlightable = ThisActor->FindComponentByInterface(UInv_Highlightable::StaticClass()); IsValid(Hightlightable))//如果该组件实现了接口，就调用函数
		{
			IInv_Highlightable::Execute_Highlight(Hightlightable);
		}
		
		UInv_ItemComponent* ItemComponent = ThisActor->FindComponentByClass<UInv_ItemComponent>();
		if (!IsValid(ItemComponent)) return;

		if (IsValid(Inv_HUDWidget)) Inv_HUDWidget->ShowPickupMessage(ItemComponent->GetPickupMessage());
	}
	if (LastActor.IsValid())
	{
		if (UActorComponent* Hightlightable = LastActor->FindComponentByInterface(UInv_Highlightable::StaticClass()); IsValid(Hightlightable))
		{
			IInv_Highlightable::Execute_UnHighlight(Hightlightable);
		}
	}
}



