// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SRev_HUD.generated.h"

class USRev_UserWidget;

/**
 * 
 */
UCLASS()
class SKATEREVOLUTION_API ASRev_HUD : public AHUD
{
	GENERATED_BODY()


public:
	
	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf<USRev_UserWidget> LayoutWidgetClass;

	
	void DisplayWidgets(TSubclassOf<USRev_UserWidget> WidgetClass);
	void UpdateScore(float Score);
	void UpdateRecord(float Record);

protected:

	UPROPERTY()
	USRev_UserWidget* LayoutWidget;
	
	virtual void BeginPlay() override;

	
};
