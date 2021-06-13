// Fill out your copyright notice in the Description page of Project Settings.

#include "Area000LoadC.h"
#include "Engine.h"

// Sets default values
AArea000LoadC::AArea000LoadC()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("AREA001LOAD_COLLISION"));
	// Box->SetupAttachment(RootComponent);

	Box->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Box->SetCollisionObjectType(ECC_WorldDynamic);
	Box->SetCollisionResponseToAllChannels(ECR_Overlap);
	Box->SetBoxExtent(FVector(52.176094f, 4.908602f, 81.255386f));

	Box->OnComponentBeginOverlap.AddDynamic(this, &AArea000LoadC::OnOverlapBegin);

	// AreaNumber = 0;
}

// Called when the game starts or when spawned
void AArea000LoadC::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AArea000LoadC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArea000LoadC::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{


	if (OtherComp->ComponentHasTag("Player")) {
		if (AreaNumber == 1) {
			if (IsLoadCollision) UGameplayStatics::LoadStreamLevel(this, "Area001", true, true, FLatentActionInfo());
			else UGameplayStatics::UnloadStreamLevel(this, "Area001", FLatentActionInfo(), true);
		}

		if (AreaNumber == 2) {
			if (IsLoadCollision) UGameplayStatics::LoadStreamLevel(this, "Area002", true, true, FLatentActionInfo());
			else UGameplayStatics::UnloadStreamLevel(this, "Area002", FLatentActionInfo(), true);
		}

		if (AreaNumber == 3) {
			if (IsLoadCollision) UGameplayStatics::LoadStreamLevel(this, "Area003", true, true, FLatentActionInfo());
			else UGameplayStatics::UnloadStreamLevel(this, "Area003", FLatentActionInfo(), true);
		}

		if (AreaNumber == 4) {
			if (IsLoadCollision) UGameplayStatics::LoadStreamLevel(this, "Area004", true, true, FLatentActionInfo());
			else UGameplayStatics::UnloadStreamLevel(this, "Area004", FLatentActionInfo(), true);
		}
	}

}


