// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SRev_CharacterBase.generated.h"

UCLASS()
class SKATEREVOLUTION_API ASRev_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASRev_CharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
