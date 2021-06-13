// Fill out your copyright notice in the Description page of Project Settings.

#include "DestroySmokeC.h"
#include "Engine.h"

// Sets default values
ADestroySmokeC::ADestroySmokeC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> PPP(
		TEXT("ParticleSystem'/Game/Particle/DestroySmoke.DestroySmoke'"));
	if (PPP.Succeeded()) UPS = PPP.Object;

	UPSC = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BOX_DESTROY_SMOKE_PARTICLE"));

	UPSC->SetTemplate(UPS);
	UPSC->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADestroySmokeC::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ADestroySmokeC::ParticleDestroy, 1.2f, false);
}

// Called every frame
void ADestroySmokeC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADestroySmokeC::ParticleDestroy()
{
	Destroy();
}

