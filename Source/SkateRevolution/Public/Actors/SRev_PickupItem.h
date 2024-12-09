// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "Character/SRev_Character.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "SRev_PickupItem.generated.h"

class USoundBase;

UCLASS()
class SKATEREVOLUTION_API ASRev_PickupItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ASRev_PickupItem();

	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> SoundPickup;

	UPROPERTY(EditAnywhere, Category="Boost")
	float Fuel;
	
	UPROPERTY(EditAnywhere, Category="Boost")
	float NumberFactor;

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SwepResult);


protected:
	
	virtual void BeginPlay() override;

};
