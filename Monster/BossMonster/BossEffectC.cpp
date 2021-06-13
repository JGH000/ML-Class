// Fill out your copyright notice in the Description page of Project Settings.

#include "BossEffectC.h"
#include "Engine.h"

// Sets default values
ABossEffectC::ABossEffectC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RScene = CreateDefaultSubobject<USceneComponent>(TEXT("R_SCENE"));

	RScene->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> AAA(
		TEXT("ParticleSystem'/Game/ParagonRevenant/FX/Particles/Revenant/Abilities/Ultimate/FX/P_Revenant_Ultimate_Sky_Streaks_Close.P_Revenant_Ultimate_Sky_Streaks_Close'"));
	if (AAA.Succeeded()) UPS_1 = AAA.Object;

	UPSC_1 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BOSS_EFFECT_PARTICLE_001"));

	UPSC_1->SetTemplate(UPS_1);
	UPSC_1->SetupAttachment(RScene);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> BBB(
		TEXT("ParticleSystem'/Game/ParagonRevenant/FX/Particles/Revenant/Abilities/Ultimate/FX/P_Revenant_Ultimate_Sky_Portal.P_Revenant_Ultimate_Sky_Portal'"));
	if (BBB.Succeeded()) UPS_2 = BBB.Object;

	UPSC_2 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BOSS_EFFECT_PARTICLE_002"));

	UPSC_2->SetTemplate(UPS_2);
	UPSC_2->SetupAttachment(RScene);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> CCC(
		TEXT("ParticleSystem'/Game/ParagonRevenant/FX/Particles/Revenant/Abilities/Ultimate/FX/P_Revenant_Ultimate_Sky_Streaks.P_Revenant_Ultimate_Sky_Streaks'"));
	if (CCC.Succeeded()) UPS_3 = CCC.Object;

	UPSC_3 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BOSS_EFFECT_PARTICLE_003"));

	UPSC_3->SetTemplate(UPS_3);
	UPSC_3->SetupAttachment(RScene);
}

// Called when the game starts or when spawned
void ABossEffectC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABossEffectC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

