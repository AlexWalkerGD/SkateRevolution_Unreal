// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SRev_ScoreComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SKATEREVOLUTION_API USRev_ScoreComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USRev_ScoreComponent();

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void IncreasePoints(int32 amount);
	virtual void GetRecord(int32 amount);

	UPROPERTY(EditAnywhere)
	int32 TotalScore = 0;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> SoundUpScore;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> SoundJump;

	UPROPERTY()
	class ASRev_HUD* revHUD;

private:
	
};
