// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "Character/SRev_CharacterBase.h"
#include "SRev_Character.generated.h"

/**
 * 
 */

class UCapsuleComponent;

UCLASS()
class SKATEREVOLUTION_API ASRev_Character : public ASRev_CharacterBase
{
	GENERATED_BODY()

public:
	ASRev_Character();

	virtual void BeginPlay() override;


	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SwepResult);
	

	UPROPERTY(EditAnywhere,Category="Components")
	TObjectPtr<USkeletalMeshComponent> SSkate;

	UPROPERTY(EditAnywhere,Category="Components")
	TObjectPtr<UCapsuleComponent> Capsule;
	
};
