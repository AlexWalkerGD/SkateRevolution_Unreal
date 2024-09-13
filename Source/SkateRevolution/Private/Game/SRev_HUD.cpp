// Copyright AlexWalkerGD


#include "Game/SRev_HUD.h"
#include "UI/SRev_UserWidget.h"
#include "Blueprint/UserWidget.h"
#include "Game/SRev_GameInstance.h"
#include "Kismet/GameplayStatics.h"


void ASRev_HUD::BeginPlay()
{
	Super::BeginPlay();
	
	DisplayWidgets(LayoutWidgetClass);
	
}

void ASRev_HUD::DisplayWidgets(TSubclassOf<USRev_UserWidget> WidgetClass)
{
	if(WidgetClass)
	{
		LayoutWidget = CreateWidget<USRev_UserWidget>(GetWorld(),WidgetClass);
		LayoutWidget->AddToViewport();
		UpdateScore(0);

		USRev_GameInstance* revInstance = Cast<USRev_GameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
		UpdateRecord(revInstance->InstanceRecord);
	}
}

void ASRev_HUD::UpdateScore(float Score)
{
	if(LayoutWidget)
	LayoutWidget->SetScore(Score);
}
 
void ASRev_HUD::UpdateRecord(float Record)
{
	if(LayoutWidget)
	LayoutWidget->SetRecord(Record);
}

