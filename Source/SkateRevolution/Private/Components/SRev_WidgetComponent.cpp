// Copyright AlexWalkerGD


#include "Components/SRev_WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "Player/SRev_PlayerController.h"
#include "UI/SRev_UserWidget.h"

// Sets default values for this component's properties
USRev_WidgetComponent::USRev_WidgetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USRev_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void USRev_WidgetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USRev_WidgetComponent::Restart()
{
	//UUserWidget* RestartWidget = CreateWidget<UUserWidget>(this, ResWidget);
	//RestartWidget->AddToViewport();
}

