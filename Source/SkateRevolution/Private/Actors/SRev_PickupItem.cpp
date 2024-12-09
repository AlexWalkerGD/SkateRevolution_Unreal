// Copyright AlexWalkerGD


#include "Actors/SRev_PickupItem.h"
#include "Components/AudioComponent.h"
#include "Character/SRev_Character.h"
#include "Kismet/GameplayStatics.h"


ASRev_PickupItem::ASRev_PickupItem()
{	
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>("Capsule");
	SetRootComponent(Sphere);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(GetRootComponent());

	SoundPickup = CreateDefaultSubobject<USoundBase>(TEXT("Sound"));
}

void ASRev_PickupItem::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ASRev_PickupItem::OnOverlap);
	
}

void ASRev_PickupItem::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SwepResult)
{
		if(ASRev_Character* Character = Cast<ASRev_Character>(OtherActor))
		{
			UGameplayStatics::PlaySound2D(GetWorld(), SoundPickup, 1,1,0, NULL, nullptr, true);
			Character->CurrentFuel = Fuel;
			Character->FactorResult = NumberFactor;
			Character->CanChangeSpeed = true;
			this->K2_DestroyActor();
		}
}




