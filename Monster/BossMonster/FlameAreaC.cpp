// Fill out your copyright notice in the Description page of Project Settings.

#include "FlameAreaC.h"
#include "Engine.h"

// Sets default values
AFlameAreaC::AFlameAreaC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RScene = CreateDefaultSubobject<USceneComponent>(TEXT("R_SCENE"));

	RScene->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UParticleSystem> PPP(
		TEXT("ParticleSystem'/Game/AAA.AAA'"));
	if (PPP.Succeeded()) UPS = PPP.Object;

	UPSC = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FLAME_AREA_PARTICLE"));

	UPSC->SetTemplate(UPS);
	UPSC->SetupAttachment(RScene);

	UPSC->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CSP"));

	Capsule->SetupAttachment(UPSC);

	Capsule->SetCapsuleHalfHeight(19.309204f);
	Capsule->SetCapsuleRadius(12.604055f);

	Capsule->SetGenerateOverlapEvents(true);
	Capsule->CanCharacterStepUpOn = ECB_No;

	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Capsule->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

	Capsule->SetCollisionResponseToChannels(ECR_Overlap);

	Capsule->OnComponentBeginOverlap.AddDynamic(this, &AFlameAreaC::CapsuleBeginOverlap);
	Capsule->OnComponentEndOverlap.AddDynamic(this, &AFlameAreaC::CapsuleEndOverlap);
}

// Called when the game starts or when spawned
void AFlameAreaC::BeginPlay()
{
	Super::BeginPlay();
	
	Player = Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());
	GetWorldTimerManager().SetTimer(CountdownTimerHandle_DestroyFlame, this, &AFlameAreaC::DestroyFlame, 12.0f, false);
}

// Called every frame
void AFlameAreaC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFlameAreaC::FlameDamage()
{
	if (Player->IsAlive) Player->MinusHP(5.0f);
}

void AFlameAreaC::DestroyFlame()
{
	Destroy();
}

void AFlameAreaC::CapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) GetWorldTimerManager().SetTimer(CountdownTimerHandle_FlameDamage, this, &AFlameAreaC::FlameDamage, 0.4f, true);
}


void AFlameAreaC::CapsuleEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (OtherComp->ComponentHasTag("Player")) GetWorldTimerManager().ClearTimer(CountdownTimerHandle_FlameDamage);
}

