// Fill out your copyright notice in the Description page of Project Settings.

#include "MonsterDestroyCollisionC.h"
#include "Engine.h"

// Sets default values
AMonsterDestroyCollisionC::AMonsterDestroyCollisionC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RScene = CreateDefaultSubobject<USceneComponent>(TEXT("R_SCENE"));

	RScene->SetupAttachment(RootComponent);

	DestroyBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BULLET_COLLISION"));
	DestroyBox->SetupAttachment(RScene);

	DestroyBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	DestroyBox->SetCollisionObjectType(ECC_WorldDynamic);
	DestroyBox->SetCollisionResponseToAllChannels(ECR_Overlap);
	DestroyBox->SetBoxExtent(FVector(60.0f, 58.23f, 82.0f));

	DestroyBox->OnComponentBeginOverlap.AddDynamic(this, &AMonsterDestroyCollisionC::DestroyBeginOverlap);
}

// Called when the game starts or when spawned
void AMonsterDestroyCollisionC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonsterDestroyCollisionC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMonsterDestroyCollisionC::DestroyBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Monster")) {
		OtherActor->Destroy();
	}
}

