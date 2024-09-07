// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SRev_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
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
   	
   	private:

	UPROPERTY(EditAnywhere, Category= "Input");
   	TObjectPtr<UInputMappingContext> SRevContext;

	UPROPERTY(EditAnywhere, Category= "Input");
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
};
