// Fill out your copyright notice in the Description page of Project Settings.

#include "FB_HitParticleC.h"
#include "Engine.h"

// Sets default values
AFB_HitParticleC::AFB_HitParticleC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> PPP(
		TEXT("ParticleSystem'/Game/ParagonRevenant/FX/Particles/Revenant/Abilities/Ultimate/FX/P_Revenant_Ultimate_Exit.P_Revenant_Ultimate_Exit'"));
	if (PPP.Succeeded()) UPS = PPP.Object;

	UPSC = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FB_EXPLOSION_PARTICLE"));

	UPSC->SetTemplate(UPS);
	UPSC->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AFB_HitParticleC::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AFB_HitParticleC::ParticleDestroy, 0.9f, false);
}

// Called every frame
void AFB_HitParticleC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFB_HitParticleC::ParticleDestroy()
{
	Destroy();
}

