// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SRev_PlayerController.generated.h"

class UAnimMontage;
class UInputMappingContext;
class UInputAction;
class ACharacter;

struct FInputActionValue;

/**
 * 
 */
UCLASS()
class SKATEREVOLUTION_API ASRev_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
    	

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
    
public:
    	
   	ASRev_PlayerController();	
	
	TObjectPtr<ACharacter> Character;

	UPROPERTY(EditAnywhere, Category= "Input");
   	TObjectPtr<UInputMappingContext> SRevContext;

	UPROPERTY(EditAnywhere, Category= "Input");
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category= "Input");
	TObjectPtr<UInputAction> RotateAction;

	UPROPERTY(EditAnywhere, Category= "Input");
	TObjectPtr<UInputAction> JumpAction;
	

	void Move(const FInputActionValue& InputActionValue);
	void Rotate(const FInputActionValue& InputActionValue);
	void StartJump();
	void StopJump();
};
