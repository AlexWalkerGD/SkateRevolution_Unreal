// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SRev_ObstacleComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SKATEREVOLUTION_API USRev_ObstacleComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USRev_ObstacleComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
