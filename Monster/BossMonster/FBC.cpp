// Fill out your copyright notice in the Description page of Project Settings.

#include "FBC.h"
#include "FB_HitParticleC.h"
#include "Engine.h"

// Sets default values
AFBC::AFBC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RScene = CreateDefaultSubobject<USceneComponent>(TEXT("R_SCENE"));

	RScene->SetupAttachment(RootComponent);

	RScene->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	static ConstructorHelpers::FObjectFinder<UParticleSystem> PPP(
		TEXT("ParticleSystem'/Game/ParagonRevenant/FX/Particles/Revenant/Abilities/Mark/FX/P_Revenant_Mark_Trail.P_Revenant_Mark_Trail'"));
	if (PPP.Succeeded()) UPS = PPP.Object;

	UPSC = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FB_PARTICLE"));
	UPSC->SetTemplate(UPS);
	UPSC->SetupAttachment(RScene);
	UPSC->SetRelativeLocation(FVector(28.0f, 0.0f, 0.0f));
	UPSC->SetRelativeScale3D(FVector(4.0f, 4.0f, 4.0f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> AAA(
		TEXT("StaticMesh'/Game/Blueprints/Monster/BossMonster/FireBallSphere/FBSphere.FBSphere'"));
	if (AAA.Succeeded()) USM = AAA.Object;

	USMC = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FB_SPHERE"));

	USMC->SetupAttachment(UPSC);
	USMC->SetStaticMesh(USM);
	USMC->SetRelativeLocation(FVector(-10.75f, 0.0f, 0.0f));
	USMC->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));

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
	Capsule->SetupAttachment(UPSC);

	Capsule->SetRelativeLocationAndRotation(FVector(-18.75f, 0.0f, 0.0f), FRotator(-90.0f, 0.0f, 0.0f));
	Capsule->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));
	Capsule->SetCapsuleHalfHeight(80.504478f);
	Capsule->SetCapsuleRadius(44.0f);

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

	Capsule->OnComponentBeginOverlap.AddDynamic(this, &AFBC::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AFBC::BeginPlay()
{
	Super::BeginPlay();
	
	Player = Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());

	GetWorldTimerManager().SetTimer(CountdownTimerHandle_FBDestroy, this, &AFBC::FBDestroy, 0.75f, false);

}

// Called every frame
void AFBC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RScene->SetWorldLocation(GetActorForwardVector() * 30.0f + RScene->GetComponentLocation());
}

void AFBC::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) {
		Player->MinusHP(20.0f);
		if (Player->IsReloadMode) {
			Player->StopAnimMontage(Player->Montage_Reload);
			Player->ReloadModeCancel();
		}
		FBExplosionDestroy();
	}
}

void AFBC::FBDestroy()
{
	Destroy();
}

void AFBC::FBExplosionDestroy()
{
	GetWorld()->SpawnActor<AFB_HitParticleC>(AFB_HitParticleC::StaticClass(), RootComponent->GetComponentLocation(), GetActorRotation())->SetActorScale3D(FVector(4.0f, 4.0f, 4.0f));
	Destroy();
}

