// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BirdPlayerController.h"
#include "EnhancedInputComponent.h" //增强映射的头文件
#include "EnhancedInputSubsystems.h" //增强子系统的头文件
#include "GameFramework/Controller.h" //输入控制器的头文件
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"


ABirdPlayerController::ABirdPlayerController()
{
	bReplicates = true;
}

void ABirdPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(BirdContext);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(BirdContext, 0);

	//bShowMouseCursor = true;
	//DefaultMouseCursor = EMouseCursor::Default;

	//FInputModeGameAndUI InputModeData;
	//InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	//InputModeData.SetHideCursorDuringCapture(false);
	//SetInputMode(InputModeData);
}

void ABirdPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABirdPlayerController::Move);
	//EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABirdPlayerController::Look);
	//EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ABirdPlayerController::Turn);
}

void ABirdPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void ABirdPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator PitchRotation(Rotation.Pitch, 0, 0);

	const FVector UpDirection = FRotationMatrix(PitchRotation).GetUnitAxis(EAxis::Z);
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(UpDirection, InputAxisVector.Y);
	}
}

void ABirdPlayerController::Turn(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
