// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "Interaction/SRev_ObstacleInterface.h"
#include "GameFramework/Actor.h"
#include "SRev_ObstaclesBase.generated.h"

class UBoxComponent;

UCLASS()
class SKATEREVOLUTION_API ASRev_ObstaclesBase : public AActor, public ISRev_ObstacleInterface
{
	GENERATED_BODY()
	
public:
	
	ASRev_ObstaclesBase();

	virtual void Tick(float DeltaTime) override;
	
	virtual void CompleteJump() override;

protected:
	
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent> Box;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
};
