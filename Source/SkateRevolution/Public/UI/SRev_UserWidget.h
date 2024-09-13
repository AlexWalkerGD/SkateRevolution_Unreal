// Copyright AlexWalkerGD

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SRev_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class SKATEREVOLUTION_API USRev_UserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:


	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* txtScore;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* txtRecord;
	
	void SetScore(float Score);

	void SetRecord(float Record);
	
protected:

    void NativeConstruct() override;
	
};
