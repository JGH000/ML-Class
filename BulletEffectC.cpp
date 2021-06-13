// Fill out your copyright notice in the Description page of Project Settings.

#include "BulletEffectC.h"
#include "Engine.h"

// Sets default values
ABulletEffectC::ABulletEffectC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> PPP(
		TEXT("ParticleSystem'/Game/Particle/BulletExplosionParticle.BulletExplosionParticle'"));
	if (PPP.Succeeded()) UPS = PPP.Object;

	UPSC = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BULLET_EXPLOSION_PARTICLE"));

	UPSC->SetTemplate(UPS);
	UPSC->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABulletEffectC::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ABulletEffectC::ParticleDestroy, 1.2f, false);
}

// Called every frame
void ABulletEffectC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABulletEffectC::ParticleDestroy()
{
	Destroy();
}

