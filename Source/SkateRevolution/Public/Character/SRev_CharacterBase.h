// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SRev_CharacterBase.generated.h"

UCLASS(Abstract)
class SKATEREVOLUTION_API ASRev_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ASRev_CharacterBase();

protected:
	virtual void BeginPlay() override;


};
