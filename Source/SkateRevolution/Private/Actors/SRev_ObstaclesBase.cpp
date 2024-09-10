// Copyright AlexWalkerGD


#include "Actors/SRev_ObstaclesBase.h"
#include "Components/BoxComponent.h"

// Sets default values
ASRev_ObstaclesBase::ASRev_ObstaclesBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	Box->SetupAttachment(GetRootComponent());
	
	

}

void ASRev_ObstaclesBase::CompleteJump()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

// Called when the game starts or when spawned
void ASRev_ObstaclesBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASRev_ObstaclesBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

