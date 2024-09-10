// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SRev_Obstacles.generated.h"

UCLASS()
class SKATEREVOLUTION_API ASRev_Obstacles : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASRev_Obstacles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
