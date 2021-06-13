// Fill out your copyright notice in the Description page of Project Settings.

#include "BulletC.h"
#include "BulletEffectC.h"
#include "Engine.h"

// Sets default values
ABulletC::ABulletC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulletDamage = 1.6f;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SMSM(
		TEXT("StaticMesh'/Game/BulletStatic.BulletStatic'"));
	if (SMSM.Succeeded()) USM = SMSM.Object;

	BulletComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BULLET_CUBE"));

	BulletComponent->SetupAttachment(RootComponent);
	BulletComponent->SetStaticMesh(USM);

	// BulletComponent->SetRelativeScale3D(FVector(1.0f, 0.1f, 0.1f));

	BulletComponent->SetGenerateOverlapEvents(true);
	BulletComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	BulletComponent->SetCollisionObjectType(ECC_WorldStatic);

	BulletComponent->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	BulletComponent->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	BulletComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	BulletComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	BulletComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	BulletComponent->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Block);
	BulletComponent->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Block);
	BulletComponent->SetCollisionResponseToChannel(ECC_Destructible, ECR_Block);

	BulletComponent->CastShadow = false;
	BulletCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BULLET_COLLISION"));
	BulletCollision->SetupAttachment(BulletComponent);

	BulletCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BulletCollision->SetCollisionObjectType(ECC_WorldDynamic);
	BulletCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
	BulletCollision->SetBoxExtent(FVector(60.0f, 58.23f, 82.0f));

	SpawnParticleLocation = FVector(-75.0f, 0.0f, 0.0f);

	Tags.Add(FName(TEXT("Bullet")));
	BulletCollision->ComponentTags.Add(TEXT("WeaponArea"));

	BulletCollision->OnComponentBeginOverlap.AddDynamic(this, &ABulletC::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ABulletC::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ABulletC::BulletDestroy, 0.25f, false);
}

// Called every frame
void ABulletC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RootComponent->SetWorldLocation(GetActorForwardVector() * 75.0f + RootComponent->GetComponentLocation());
}

void ABulletC::BulletExplosionDestroy()
{
	GetWorld()->SpawnActor<ABulletEffectC>(ABulletEffectC::StaticClass(), RootComponent->GetComponentLocation() + GetActorForwardVector() * -75.0f, GetActorRotation());
	Destroy();
}

void ABulletC::BulletDestroy()
{
	Destroy();
}

void ABulletC::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Wall")) { BulletExplosionDestroy(); }
}

