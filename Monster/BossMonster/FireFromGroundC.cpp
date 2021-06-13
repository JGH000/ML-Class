// Fill out your copyright notice in the Description page of Project Settings.

#include "FireFromGroundC.h"
#include "Engine.h"

// Sets default values
AFireFromGroundC::AFireFromGroundC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RScene = CreateDefaultSubobject<USceneComponent>(TEXT("R_SCENE"));

	RScene->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> PPP(
		TEXT("ParticleSystem'/Game/ParagonRevenant/FX/Particles/Revenant/Abilities/Primary/FX/P_Revenant_Primary_HitWorld.P_Revenant_Primary_HitWorld'"));
	if (PPP.Succeeded()) UPS = PPP.Object;

	UPSC = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FLAME_PARTICLE"));
	UPSC->SetupAttachment(RScene);
	UPSC->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	UPSC->SetRelativeScale3D(FVector(3.0f, 5.0f, 5.0f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> XYZ(
		TEXT("StaticMesh'/Game/Blueprints/Monster/BossMonster/FlameSpawnFloor/AllDarkRedComponent.AllDarkRedComponent'"));
	if (XYZ.Succeeded()) USM = XYZ.Object;

	USMC = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FLAME_SPAWN_GROUND"));

	USMC->SetupAttachment(RScene);
	USMC->SetStaticMesh(USM);
	USMC->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	USMC->SetRelativeScale3D(FVector(0.15f, 3.0f, 3.0f));

	USMC->SetGenerateOverlapEvents(true);
	USMC->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	USMC->SetCollisionObjectType(ECC_WorldStatic);

	USMC->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	USMC->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	USMC->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	USMC->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	USMC->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	USMC->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Block);
	USMC->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Block);
	USMC->SetCollisionResponseToChannel(ECC_Destructible, ECR_Block);

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("HIT_AREA_CAPSULE"));
	Capsule->SetupAttachment(USMC);

	Capsule->SetRelativeLocationAndRotation(FVector(-7699.994629f, 0.0f, 0.0f), FRotator(90.0f, 0.0f, 0.0f));
	Capsule->SetCapsuleHalfHeight(169.0f);
	Capsule->SetCapsuleRadius(39.77f);

	Capsule->SetGenerateOverlapEvents(true);
	Capsule->CanCharacterStepUpOn = ECB_No;

	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Capsule->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

	Capsule->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	Capsule->SetCollisionResponseToChannel(ECC_Camera, ECR_Overlap);

	Capsule->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	Capsule->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	Capsule->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	Capsule->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	Capsule->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	Capsule->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);

	Capsule->ComponentTags.Add("NoAttackMode");

	Capsule->OnComponentBeginOverlap.AddDynamic(this, &AFireFromGroundC::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AFireFromGroundC::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());

	GetWorldTimerManager().SetTimer(CountdownTimerHandle_FlameStart, this, &AFireFromGroundC::FlameStart, 0.75f, false);
}

// Called every frame
void AFireFromGroundC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFireFromGroundC::FlameStart()
{
	USMC->SetStaticMesh(nullptr);
	UPSC->SetTemplate(UPS);
	Capsule->ComponentTags[0] = "AttackMode";
	Capsule->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	GetWorldTimerManager().SetTimer(CountdownTimerHandle_FlameEnd, this, &AFireFromGroundC::FlameEnd, 0.25f, false);
}

void AFireFromGroundC::FlameEnd()
{
	Capsule->ComponentTags[0] = "NoAttackMode";
	GetWorldTimerManager().SetTimer(CountdownTimerHandle_FlameDestroy, this, &AFireFromGroundC::FlameDestroy, 1.2f, false);
}

void AFireFromGroundC::FlameDestroy()
{
	Destroy();
}

void AFireFromGroundC::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Player") && Capsule->ComponentHasTag("AttackMode")) {
		Player->MinusHP(20.0f);
		if (Player->IsReloadMode) {
			Player->StopAnimMontage(Player->Montage_Reload);
			Player->ReloadModeCancel();
		}
	}
}

