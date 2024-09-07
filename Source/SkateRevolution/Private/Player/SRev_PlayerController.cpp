// Copyright AlexWalkerGD


#include "Player/SRev_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

ASRev_PlayerController::ASRev_PlayerController()
{
    bReplicates = true;
}

void ASRev_PlayerController::BeginPlay()
{
    Super::BeginPlay();
    check(SRevContext);
    
    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    check(Subsystem);
    Subsystem->AddMappingContext(SRevContext, 0);
    
    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;
    
    FInputModeGameAndUI InputModeData;
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    InputModeData.SetHideCursorDuringCapture(false);
    SetInputMode(InputModeData);
}

void ASRev_PlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASRev_PlayerController::Move);
    
}

void ASRev_PlayerController::Move(const FInputActionValue& InputActionValue)
{
    const FVector2d InputAxisValue = InputActionValue.Get<FVector2D>();
    const FRotator Rotation = GetControlRotation();
    const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    if (APawn* ControlledPawn = GetPawn<APawn>())
    {
        ControlledPawn->AddMovementInput(ForwardDirection, InputAxisValue.Y);
        ControlledPawn->AddMovementInput(RightDirection, InputAxisValue.X);
    }
    
}
