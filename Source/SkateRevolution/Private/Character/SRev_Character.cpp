// Copyright AlexWalkerGD


#include "Character/SRev_Character.h"

#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SRev_ScoreComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"

#include "Interaction/SRev_ObstacleInterface.h"
#include "Player/SRev_PlayerController.h"
#include "UI/SRev_UserWidget.h"



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
	SSkate->SetupAttachment(GetRootComponent());
	SSkate->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	Capsule->SetupAttachment(GetRootComponent());

	CollisionSkate = CreateDefaultSubobject<UCapsuleComponent>("CollisionSkate");
	CollisionSkate->SetupAttachment(GetRootComponent());

	BlockageDetector = CreateDefaultSubobject<UBoxComponent>("BlockageDetector");
	BlockageDetector->SetupAttachment(GetRootComponent());

	ScoreComponent = CreateDefaultSubobject<USRev_ScoreComponent>("ScoreComponent");
	
	
}

void ASRev_Character::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->SetSimulatePhysics(false);
	
	Capsule->OnComponentBeginOverlap.AddDynamic(this, &ASRev_Character::OnOverlap);
	BlockageDetector->OnComponentBeginOverlap.AddDynamic(this, &ASRev_Character::OnHit);
	
}

void ASRev_Character::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SwepResult)
{
	if(ISRev_ObstacleInterface* ObsInterface = Cast<ISRev_ObstacleInterface>(OtherActor))
	{
		ObsInterface->CompleteJump();
		ScoreComponent->IncreasePoints(10);
		
	}
}

void ASRev_Character::OnHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
							UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SwepResult)
{
	if(ISRev_ObstacleInterface* ObsInterface = Cast<ISRev_ObstacleInterface>(OtherActor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Tem Interface"));
		
		if(OtherComp->ComponentHasTag("Blocker")) 
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Tem Tag"));
			GetMesh()->SetCollisionProfileName("Ragdoll");
			GetMesh()->SetSimulatePhysics(true);

			OnDeath();
		}
	}	
}

void ASRev_Character::OnDeath()
{
	if(AnimFall)
	{
		//PlayAnimMontage(AnimFall);
	}

	ASRev_PlayerController* PlayerController = Cast<ASRev_PlayerController>(GetController());
	PlayerController->UnPossess();
	
	if(IsValid(ResWidget))
	{
		RUserWidget = CreateWidget<USRev_UserWidget>(PlayerController, ResWidget);
		if(RUserWidget != nullptr)
		{
			RUserWidget->AddToViewport();
			FInputModeUIOnly Mode;
			Mode.SetWidgetToFocus(RUserWidget->GetCachedWidget());
			PlayerController->SetInputMode(Mode);
			PlayerController->bShowMouseCursor = true;	
		}
	}

	RestartGame();
	
}

void ASRev_Character::RestartGame()
{
	if(IsValid(ResWidget))
	{
	}
	
}
	


