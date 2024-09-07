// Copyright AlexWalkerGD


#include "Character/SRev_CharacterBase.h"

// Sets default values
ASRev_CharacterBase::ASRev_CharacterBase()
{
 	PrimaryActorTick.bCanEverTick = false;

	Skate = CreateDefaultSubobject<USkeletalMeshComponent>("Skate");
	

}

// Called when the game starts or when spawned
void ASRev_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


