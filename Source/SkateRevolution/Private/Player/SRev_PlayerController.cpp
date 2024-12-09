// Copyright AlexWalkerGD


#include "Player/SRev_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "FrameTypes.h"
#include "Character/SRev_Character.h"
#include "Kismet/KismetMathLibrary.h"


ASRev_PlayerController::ASRev_PlayerController()
{
    bReplicates = true;
}

void ASRev_PlayerController::BeginPlay()
{
    Super::BeginPlay();
    check(SRevContext);

    //Character = Cast<ACharacter>(GetCharacter());

    SCharacter = Cast<ASRev_Character>(GetCharacter());
    
    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    check(Subsystem);
    Subsystem->AddMappingContext(SRevContext, 0);    
}

void ASRev_PlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASRev_PlayerController::Move);
    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ASRev_PlayerController::StopRun);
    EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &ASRev_PlayerController::Rotate);
    EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ASRev_PlayerController::StartJump); 
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

void ASRev_PlayerController::Rotate(const FInputActionValue& InputActionValue)
{
    const FVector2d InputAxisValue = InputActionValue.Get<FVector2D>();
    
    if (APawn* ControlledPawn = GetPawn<APawn>())
    {
        ControlledPawn->AddControllerPitchInput(InputAxisValue.Y);
        ControlledPawn->AddControllerYawInput(InputAxisValue.X);
    }
    
}

void ASRev_PlayerController::StartJump()
{

    if(!SCharacter->bIsJumping)
    {
        SCharacter->bIsJumping = true;
        
        if(SCharacter->bIsJumping)
        {
            SCharacter->Jump();
            SCharacter->PlayAnimMontage(SCharacter->AnimFall);
            SCharacter->JumpSkate();

            FTimerHandle TimerHandle;
            GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
            {
                UE_LOG(LogTemp, Warning, TEXT("CanJump"));
                SCharacter->bIsJumping = false;
                 }, 1, false);
        }        
    }
}


void ASRev_PlayerController::StopRun()
{
    SCharacter->bStopMovementByCurve = true;
}



