// Copyright AlexWalkerGD


#include "Character/SRev_Character.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interaction/SRev_ObstacleInterface.h"


ASRev_Character::ASRev_Character()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	SSkate = CreateDefaultSubobject<USkeletalMeshComponent>("Skate");
	SSkate->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	Capsule->SetupAttachment(GetRootComponent());
	
	
}

void ASRev_Character::BeginPlay()
{
	Super::BeginPlay();
	Capsule->OnComponentBeginOverlap.AddDynamic(this, &ASRev_Character::OnOverlap);
}

void ASRev_Character::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SwepResult)
{
	if(ISRev_ObstacleInterface* ObsInterface = Cast<ISRev_ObstacleInterface>(OtherActor))
	{
		ObsInterface->CompleteJump();
	}
}
