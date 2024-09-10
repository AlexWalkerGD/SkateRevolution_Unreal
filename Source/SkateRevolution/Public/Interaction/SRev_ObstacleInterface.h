// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SRev_ObstacleInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USRev_ObstacleInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SKATEREVOLUTION_API ISRev_ObstacleInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

    virtual void CompleteJump() = 0;

};
