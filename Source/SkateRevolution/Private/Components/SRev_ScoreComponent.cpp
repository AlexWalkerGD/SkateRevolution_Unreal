// Copyright AlexWalkerGD


#include "Components/SRev_ScoreComponent.h"

USRev_ScoreComponent::USRev_ScoreComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void USRev_ScoreComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


// Called every frame
void USRev_ScoreComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void USRev_ScoreComponent::IncreasePoints(int32 amount)
{
	TotalScore = TotalScore + amount;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Total: ") + TotalScore);
}

	

