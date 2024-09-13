// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SRev_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SKATEREVOLUTION_API USRev_GameInstance : public UGameInstance
{
	GENERATED_BODY()

	public:
	int32 InstanceRecord = 0;
	
};
