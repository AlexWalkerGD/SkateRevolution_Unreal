// Copyright AlexWalkerGD


#include "UI/SRev_UserWidget.h"
#include "Components/TextBlock.h"

void USRev_UserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void USRev_UserWidget::SetScore(float Score)
{
	if (txtScore != nullptr)
	txtScore->SetText(FText::AsNumber(Score));
}

void USRev_UserWidget::SetRecord(float Record)
{
	if (txtScore != nullptr)	
	txtRecord->SetText(FText::AsNumber(Record));
}




