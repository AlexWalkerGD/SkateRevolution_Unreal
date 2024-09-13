// Copyright AlexWalkerGD


#include "Components/SRev_ScoreComponent.h"

#include "Game/SRev_GameInstance.h"
#include "Game/SRev_HUD.h"
#include "GameFramework/GameSession.h"
#include "Kismet/GameplayStatics.h"
#include "Player/SRev_PlayerController.h"
#include "UObject/ConstructorHelpers.h"

USRev_ScoreComponent::USRev_ScoreComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void USRev_ScoreComponent::BeginPlay()
{
	Super::BeginPlay();

	revHUD = Cast<ASRev_HUD>(UGameplayStatics::GetPlayerController(this,0)->GetHUD());
}


// Called every frame
void USRev_ScoreComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void USRev_ScoreComponent::IncreasePoints(int32 amount)
{
	TotalScore = TotalScore + amount;

	//ASRev_HUD* revHUD = Cast<ASRev_HUD>(UGameplayStatics::GetPlayerController(this,0)->GetHUD());
	if (revHUD)
	{
		revHUD->UpdateScore(TotalScore);
		GetRecord(TotalScore);
	}
}

void USRev_ScoreComponent::GetRecord(int32 amount)
{
	USRev_GameInstance* revInstance = Cast<USRev_GameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	
	if(amount > revInstance->InstanceRecord)
	{
		revInstance->InstanceRecord = amount;
		revHUD->UpdateRecord(revInstance->InstanceRecord);
		
	}
}

	

