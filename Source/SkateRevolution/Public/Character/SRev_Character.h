// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "Character/SRev_CharacterBase.h"
#include "Components/SRev_ScoreComponent.h"
#include "Animation/AnimMontage.h"
#include "Game/SRev_HUD.h"
#include "SRev_Character.generated.h"

/**
 * 
 */

class UCapsuleComponent;
class USceneComponent;
class UBoxComponent;
class USoundBase;
class ASRev_PlayerController;
class ASRev_HUD;

UCLASS()
class SKATEREVOLUTION_API ASRev_Character : public ASRev_CharacterBase
{
	GENERATED_BODY()

public:
	ASRev_Character();

	//////////// Functions Default of player ////////////

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	

	//////////// Functions Collision of player ////////////

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SwepResult);

	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SwepResult);

	//UFUNCTION()
	//virtual void OnGround(USceneComponent* Component);
	
	//////////// Functions of events during the game ////////////
	
	UFUNCTION()
	virtual void OnDeath();

	UFUNCTION()
	virtual void Accelerate();

	UFUNCTION()
	virtual void Decelerate();

	UFUNCTION()
	virtual void JumpSkate();

	//UFUNCTION()
	//virtual void StopRun();
	
	//////////// Variables of Widgets of player ////////////
	
	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf<class USRev_UserWidget> ResWidget;

	UPROPERTY(VisibleInstanceOnly, Category="Widgets")
	USRev_UserWidget* RUserWidget;


	//////////// Variables of Components of player ////////////

	UPROPERTY(EditAnywhere,Category="Components")
	TObjectPtr<UCapsuleComponent> Capsule;

	UPROPERTY(EditAnywhere,Category="Components")
	TObjectPtr<UCapsuleComponent> CollisionSkate;

	UPROPERTY(EditAnywhere,Category="Components")
	TObjectPtr<UBoxComponent> BlockageDetector;

	UPROPERTY(EditAnywhere,Category="Components")
	TObjectPtr<USRev_ScoreComponent> ScoreComponent;

	UPROPERTY(EditAnywhere,Category="Components")
	TObjectPtr<USkeletalMeshComponent> SkateObject;

	//////////// Variables of animations of player ////////////
	
	UPROPERTY(EditAnywhere,Category="Anim")
	TObjectPtr<UAnimMontage> AnimFall;

	UPROPERTY(EditAnywhere,Category="Anim|Skate")
	UAnimationAsset* AnimSkate;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Anim")
	bool bIsJumping;

	//////////// Variables of sounds on death ////////////

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> Sound1;
	
	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> Sound2;
	
	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> Sound3;
	
	//////////// Variables of movement of player ////////////

	UPROPERTY(EditAnywhere,Category="Movement")
	bool CanChangeSpeed = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Movement")
	bool bIsBoost = false;

	UPROPERTY(EditAnywhere,Category="Movement")
	float MaxBoostSpeed;

	UPROPERTY(EditAnywhere,Category="Movement")
	float MinBoostSpeed;

	UPROPERTY(EditAnywhere,Category="Movement")
	float FactorResult;

	UPROPERTY(EditAnywhere,Category="Movement")
	float RunSpeed;

	UPROPERTY(EditAnywhere,Category="Movement")
	float CurrentFuel;
	
	UPROPERTY(EditAnywhere,Category="Movement")
	float BoostAcceleration;

	UPROPERTY(EditAnywhere,Category="Movement")
	float FuelConsumptionRate;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Curve")
	UCurveFloat* Curve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Curve")
	bool bStopMovementByCurve;
	
};
