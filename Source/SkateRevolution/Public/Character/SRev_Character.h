// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "Character/SRev_CharacterBase.h"
#include "Components/SRev_ScoreComponent.h"
#include "Components/SRev_WidgetComponent.h"
#include "Animation/AnimMontage.h"
#include "Game/SRev_HUD.h"
#include "SRev_Character.generated.h"

/**
 * 
 */

class UCapsuleComponent;
class UBoxComponent;
class ASRev_PlayerController;
class ASRev_HUD;

UCLASS()
class SKATEREVOLUTION_API ASRev_Character : public ASRev_CharacterBase
{
	GENERATED_BODY()

public:
	ASRev_Character();

	virtual void BeginPlay() override;


	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SwepResult);

	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SwepResult);

	UFUNCTION()
	virtual void OnDeath();

	UFUNCTION()
	virtual void RestartGame();


	

	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf<class USRev_UserWidget> ResWidget;

	UPROPERTY(VisibleInstanceOnly, Category="Widgets")
	USRev_UserWidget* RUserWidget;
	
	UPROPERTY(EditAnywhere,Category="Components")
	TObjectPtr<USkeletalMeshComponent> SSkate;

	UPROPERTY(EditAnywhere,Category="Components")
	TObjectPtr<UCapsuleComponent> Capsule;

	UPROPERTY(EditAnywhere,Category="Components")
	TObjectPtr<UCapsuleComponent> CollisionSkate;

	UPROPERTY(EditAnywhere,Category="Components")
	TObjectPtr<UBoxComponent> BlockageDetector;

	UPROPERTY(EditAnywhere,Category="Components")
	TObjectPtr<USRev_ScoreComponent> ScoreComponent;

	UPROPERTY(EditAnywhere,Category="Anim")
	TObjectPtr<UAnimMontage> AnimFall;

	
	
};
