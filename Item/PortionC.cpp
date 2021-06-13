// Fill out your copyright notice in the Description page of Project Settings.

#include "PortionC.h"
#include "Engine.h"

// Sets default values
APortionC::APortionC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ITEM_MESH"));

	StaticMesh->SetupAttachment(RootComponent);

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE_COLLISION"));

	Capsule->SetupAttachment(StaticMesh);

	Capsule->OnComponentBeginOverlap.AddDynamic(this, &APortionC::OnOverlapBegin);

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("ROTATION"));

	RotatingMovement->RotationRate = FRotator(0.0f, 180.0f, 0.0f);

}

// Called when the game starts or when spawned
void APortionC::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());


}

// Called every frame
void APortionC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void APortionC::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) {
	
		if (
			(
			 ((Player->ItemSlot[1].TheNumberOfItem == 5 && Player->ItemSlot[1].ItemCode == NowItemSlot.ItemCode) || Player->ItemSlot[1].ItemCode != NowItemSlot.ItemCode) &&
			 ((Player->ItemSlot[2].TheNumberOfItem == 5 && Player->ItemSlot[2].ItemCode == NowItemSlot.ItemCode) || Player->ItemSlot[2].ItemCode != NowItemSlot.ItemCode) &&
			 ((Player->ItemSlot[3].TheNumberOfItem == 5 && Player->ItemSlot[3].ItemCode == NowItemSlot.ItemCode) || Player->ItemSlot[3].ItemCode != NowItemSlot.ItemCode) &&
			 Player->ItemSlot[0].TheNumberOfItem == 0
			)
			||
			(
			 Player->ItemSlot[0].TheNumberOfItem < 5 && Player->ItemSlot[0].ItemCode == NowItemSlot.ItemCode
			)
		   ) {
			Player->ItemSlot[0].TheNumberOfItem += 1;
			Player->ItemSlot[0].ItemSlotImage = NowItemSlot.ItemSlotImage;
			Player->ItemSlot[0].ItemName = NowItemSlot.ItemName;
			Player->ItemSlot[0].ItemCode = NowItemSlot.ItemCode;
			Destroy();
		}

		else if (
			(
			 ((Player->ItemSlot[2].TheNumberOfItem == 5 && Player->ItemSlot[2].ItemCode == NowItemSlot.ItemCode) || Player->ItemSlot[2].ItemCode != NowItemSlot.ItemCode) &&
			 ((Player->ItemSlot[3].TheNumberOfItem == 5 && Player->ItemSlot[3].ItemCode == NowItemSlot.ItemCode) || Player->ItemSlot[3].ItemCode != NowItemSlot.ItemCode) &&
			 Player->ItemSlot[1].TheNumberOfItem == 0
			)
			||
			(
			 Player->ItemSlot[1].TheNumberOfItem < 5 && Player->ItemSlot[1].ItemCode == NowItemSlot.ItemCode
			)
		   ) {
			Player->ItemSlot[1].TheNumberOfItem += 1;
			Player->ItemSlot[1].ItemSlotImage = NowItemSlot.ItemSlotImage;
			Player->ItemSlot[1].ItemName = NowItemSlot.ItemName;
			Player->ItemSlot[1].ItemCode = NowItemSlot.ItemCode;
			Destroy();
		}

		else if (
			(
			 ((Player->ItemSlot[3].TheNumberOfItem == 5 && Player->ItemSlot[3].ItemCode == NowItemSlot.ItemCode) || Player->ItemSlot[3].ItemCode != NowItemSlot.ItemCode) &&
			 Player->ItemSlot[2].TheNumberOfItem == 0
			)
			||
			(
			 Player->ItemSlot[2].TheNumberOfItem < 5 && Player->ItemSlot[2].ItemCode == NowItemSlot.ItemCode
			)
		   ) {
			Player->ItemSlot[2].TheNumberOfItem += 1;
			Player->ItemSlot[2].ItemSlotImage = NowItemSlot.ItemSlotImage;
			Player->ItemSlot[2].ItemName = NowItemSlot.ItemName;
			Player->ItemSlot[2].ItemCode = NowItemSlot.ItemCode;
			Destroy();
		}

		else if (
			(
			 Player->ItemSlot[3].TheNumberOfItem == 0
			)
			||
			(
			 Player->ItemSlot[3].TheNumberOfItem < 5 && Player->ItemSlot[3].ItemCode == NowItemSlot.ItemCode
			)
		   ) {
			Player->ItemSlot[3].TheNumberOfItem += 1;
			Player->ItemSlot[3].ItemSlotImage = NowItemSlot.ItemSlotImage;
			Player->ItemSlot[3].ItemName = NowItemSlot.ItemName;
			Player->ItemSlot[3].ItemCode = NowItemSlot.ItemCode;
			Destroy();
		}
	}

}

