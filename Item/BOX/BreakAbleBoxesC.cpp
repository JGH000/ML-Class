// Fill out your copyright notice in the Description page of Project Settings.

#include "BreakAbleBoxesC.h"
#include "Engine.h"

// Sets default values
ABreakAbleBoxesC::ABreakAbleBoxesC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ROOTSCENE"));

	RootSceneComponent->SetupAttachment(RootComponent);

	BoxesBoxes = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BOXES"));

	BoxesBoxes->SetupAttachment(RootSceneComponent);

	BoxesHitArea = CreateDefaultSubobject<UBoxComponent>(TEXT("BOXES_HIT_AREA"));

	BoxesHitArea->SetupAttachment(RootSceneComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> LoadStaticMesh(
		TEXT("StaticMesh'/Game/InfinityBladeGrassLands/Environments/Breakables/StaticMesh/Box/SM_Env_Breakables_Boxes.SM_Env_Breakables_Boxes'"));

	if (LoadStaticMesh.Succeeded()) {
		SM = LoadStaticMesh.Object;
	}

	RootSceneComponent->SetWorldScale3D(FVector(1.9f, 1.9f, 1.9f));

	BoxesBoxes->SetStaticMesh(SM);
	BoxesBoxes->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> AAA(
		TEXT("StaticMesh'/Game/InfinityBladeGrassLands/Environments/Breakables/StaticMesh/Box/SM_Env_Breakables_BoxesBITS.SM_Env_Breakables_BoxesBITS'"));

	if (AAA.Succeeded()) {
		SM = AAA.Object;
	}

	BoxesHitArea->SetRelativeLocation(FVector(-3.0f, 0.0f, 48.0f));
	BoxesHitArea->SetBoxExtent(FVector(105.0f, 100.0f, 48.0f));

	BoxesHitArea->OnComponentBeginOverlap.AddDynamic(this, &ABreakAbleBoxesC::OnOverlapBegin);

	Sp0 = CreateDefaultSubobject<USceneComponent>(TEXT("SCENE_COMPONENT_000"));
	Sp1 = CreateDefaultSubobject<USceneComponent>(TEXT("SCENE_COMPONENT_001"));
	Sp2 = CreateDefaultSubobject<USceneComponent>(TEXT("SCENE_COMPONENT_002"));
	Sp3 = CreateDefaultSubobject<USceneComponent>(TEXT("SCENE_COMPONENT_003"));
	Sp4 = CreateDefaultSubobject<USceneComponent>(TEXT("SCENE_COMPONENT_004"));
	Sp5 = CreateDefaultSubobject<USceneComponent>(TEXT("SCENE_COMPONENT_005"));
	Sp6 = CreateDefaultSubobject<USceneComponent>(TEXT("SCENE_COMPONENT_006"));

	Sp0->SetupAttachment(RootSceneComponent);
	Sp1->SetupAttachment(RootSceneComponent);
	Sp2->SetupAttachment(RootSceneComponent);
	Sp3->SetupAttachment(RootSceneComponent);
	Sp4->SetupAttachment(RootSceneComponent);
	Sp5->SetupAttachment(RootSceneComponent);
	Sp6->SetupAttachment(RootSceneComponent);

	Sp0->SetRelativeLocation(FVector( 65.0f,  -12.0f, 0.0f));
	Sp1->SetRelativeLocation(FVector( -8.0f,  -70.0f, 0.0f));
	Sp2->SetRelativeLocation(FVector(-42.0f, -106.0f, 0.0f));
	Sp3->SetRelativeLocation(FVector(-83.0f,  -41.0f, 0.0f));
	Sp4->SetRelativeLocation(FVector(-48.0f,    0.0f, 0.0f));
	Sp5->SetRelativeLocation(FVector( 10.0f,   48.0f, 0.0f));
	Sp6->SetRelativeLocation(FVector(-90.0f,  109.0f, 0.0f));

	OnlyOne = true;

	R.Init(0,7);
}

// Called when the game starts or when spawned
void ABreakAbleBoxesC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABreakAbleBoxesC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABreakAbleBoxesC::PortionSpawnFunction(int32 I, float XX, float YY, float ZZ)
{
	if (I < 3) {
		// HP포션 생성하는 코드
		GetWorld()->SpawnActor<AHPPortionC>(AHPPortionC::StaticClass(), FTransform(
			FRotator(0.0f, 0.0f, 0.0f), FVector(XX, YY, ZZ + 20.0f), FVector(1.0f, 1.0f, 1.0f)));
	}
	else if (I < 4) {
		// 노데미지포션 생성하는 코드
		GetWorld()->SpawnActor<ANoDamagePortionC>(ANoDamagePortionC::StaticClass(), FTransform(
			FRotator(0.0f, 0.0f, 0.0f), FVector(XX, YY, ZZ + 20.0f), FVector(1.0f, 1.0f, 1.0f)));
	}
	else if (I < 5) {
		// 슈퍼불렛포션 생성하는 코드
		GetWorld()->SpawnActor<ASuperBulletPortionC>(ASuperBulletPortionC::StaticClass(), FTransform(
			FRotator(0.0f, 0.0f, 0.0f), FVector(XX, YY, ZZ + 45.0f), FVector(1.0f, 1.0f, 1.0f)));
	}
}

void ABreakAbleBoxesC::BoxDestroy()
{
	Destroy();
}

void ABreakAbleBoxesC::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) {
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		if (OnlyOne) {
			OnlyOne = false;

			Cast<ABulletC>(OtherActor)->BulletExplosionDestroy();

			// 연기 생성하는 코드
			GetWorld()->SpawnActor<ADestroySmokeC>(ADestroySmokeC::StaticClass(), FTransform(
				BoxesBoxes->GetComponentRotation(), BoxesBoxes->GetComponentLocation(), BoxesBoxes->GetComponentScale() * 3.0f));


			BoxesBoxes->SetRelativeLocation(FVector(32.0f, 16.0f, 0.0f));


			BoxesBoxes->SetStaticMesh(SM);

			for (int i = 0; i < 7; i++) {
				R[i] = FMath::RandRange(0, 9);
				     if (i == 0) PortionSpawnFunction(R[i], Sp0->GetComponentLocation().X, Sp0->GetComponentLocation().Y, Sp0->GetComponentLocation().Z);
				else if (i == 1) PortionSpawnFunction(R[i], Sp1->GetComponentLocation().X, Sp1->GetComponentLocation().Y, Sp1->GetComponentLocation().Z);
				else if (i == 2) PortionSpawnFunction(R[i], Sp2->GetComponentLocation().X, Sp2->GetComponentLocation().Y, Sp2->GetComponentLocation().Z);
				else if (i == 3) PortionSpawnFunction(R[i], Sp3->GetComponentLocation().X, Sp3->GetComponentLocation().Y, Sp3->GetComponentLocation().Z);
				else if (i == 4) PortionSpawnFunction(R[i], Sp4->GetComponentLocation().X, Sp4->GetComponentLocation().Y, Sp4->GetComponentLocation().Z);
				else if (i == 5) PortionSpawnFunction(R[i], Sp5->GetComponentLocation().X, Sp5->GetComponentLocation().Y, Sp5->GetComponentLocation().Z);
				else if (i == 6) PortionSpawnFunction(R[i], Sp6->GetComponentLocation().X, Sp6->GetComponentLocation().Y, Sp6->GetComponentLocation().Z);
			}

			GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ABreakAbleBoxesC::BoxDestroy, 0.85f, false);
		}
	}
}

