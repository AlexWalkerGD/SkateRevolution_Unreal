// Copyright AlexWalkerGD


#include "SRev_CharacterBase.h"

// Sets default values
ASRev_CharacterBase::ASRev_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASRev_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASRev_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASRev_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

