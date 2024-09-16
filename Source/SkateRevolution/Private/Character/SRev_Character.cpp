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
	PrimaryActorTick.bCanEverTick = true;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	Capsule->SetupAttachment(GetRootComponent());

	SkateObject = CreateDefaultSubobject<USkeletalMeshComponent>("SkateObject");
	SkateObject->SetupAttachment(GetRootComponent());

	CollisionSkate = CreateDefaultSubobject<UCapsuleComponent>("CollisionSkate");
	CollisionSkate->SetupAttachment(GetRootComponent());

	BlockageDetector = CreateDefaultSubobject<UBoxComponent>("BlockageDetector");
	BlockageDetector->SetupAttachment(GetRootComponent());

	ScoreComponent = CreateDefaultSubobject<USRev_ScoreComponent>("ScoreComponent");

	
	bIsBoost = false;
	MaxBoostSpeed = 1500.0f;
	MinBoostSpeed = 100.0f;
	RunSpeed = 600.0f;
	CurrentFuel= 0.f;
	BoostAcceleration = 1000.0f;
	FuelConsumptionRate = 10.f;
	
	
}

void ASRev_Character::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->SetSimulatePhysics(false);
	
	Capsule->OnComponentBeginOverlap.AddDynamic(this, &ASRev_Character::OnOverlap);
	BlockageDetector->OnComponentBeginOverlap.AddDynamic(this, &ASRev_Character::OnHit);
	
}

void ASRev_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(CanChangeSpeed == true)
	{
		Accelerate();
	}
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
		
		if(OtherComp->ComponentHasTag("Blocker")) 
		{
			GetMesh()->SetCollisionProfileName("Ragdoll");
			GetMesh()->SetSimulatePhysics(true);

			OnDeath();
		}
	}	
}

void ASRev_Character::OnDeath()
{
	ASRev_PlayerController* PlayerController = Cast<ASRev_PlayerController>(GetController());
	PlayerController->UnPossess();
	SkateObject->SetSimulatePhysics(true);
	
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
}

void ASRev_Character::Accelerate()
{
	if (CurrentFuel > 0.0f)
	{
		bIsBoost = true;

		if (GetCharacterMovement()->MaxWalkSpeed < MaxBoostSpeed || GetCharacterMovement()->MaxWalkSpeed < MinBoostSpeed)
		{
			float NewSpeed = GetCharacterMovement()->MaxWalkSpeed + ((BoostAcceleration * FactorResult) * GetWorld()->GetDeltaSeconds());
			
			GetCharacterMovement()->MaxWalkSpeed = FMath::Clamp(NewSpeed, MinBoostSpeed, MaxBoostSpeed);
		}

		CurrentFuel = FMath::Max(CurrentFuel - (FuelConsumptionRate * GetWorld()->GetDeltaSeconds()), 0.0f);
	}
	else
	{
		Decelerate();
	}

}

void ASRev_Character::Decelerate()
{
	if (GetCharacterMovement()->MaxWalkSpeed > RunSpeed || GetCharacterMovement()->MaxWalkSpeed < RunSpeed)
	{
		float NewSpeed = GetCharacterMovement()->MaxWalkSpeed - ((BoostAcceleration * FactorResult) * GetWorld()->GetDeltaSeconds());

		GetCharacterMovement()->MaxWalkSpeed = FMath::Max(NewSpeed, RunSpeed);
	}

	if (GetCharacterMovement()->MaxWalkSpeed > 500.f)
	{
		bIsBoost = false;
	}
}

void ASRev_Character::JumpSkate()
{
	if(AnimSkate)
	SkateObject->PlayAnimation(AnimSkate, false);
}
	


