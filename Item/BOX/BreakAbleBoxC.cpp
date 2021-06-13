// Fill out your copyright notice in the Description page of Project Settings.

#include "BreakAbleBoxC.h"
#include "Engine.h"

// Sets default values
ABreakAbleBoxC::ABreakAbleBoxC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BOX"));

	BoxBox->SetupAttachment(RootComponent);

	BoxHitArea = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX_HIT_AREA"));

	BoxHitArea->SetupAttachment(BoxBox);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> LoadStaticMesh(
		TEXT("StaticMesh'/Game/InfinityBladeGrassLands/Environments/Breakables/StaticMesh/Box/SM_Env_Breakables_Box1.SM_Env_Breakables_Box1'"));

	if (LoadStaticMesh.Succeeded()) {
		SM = LoadStaticMesh.Object;
	}

	BoxBox->SetStaticMesh(SM);
	BoxBox->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	BoxBox->SetWorldScale3D(FVector(2.5f, 2.5f, 2.5f));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> AAA(
		TEXT("StaticMesh'/Game/InfinityBladeGrassLands/Environments/Breakables/StaticMesh/Box/SM_Env_Breakables_Box1_destroyed.SM_Env_Breakables_Box1_destroyed'"));

	if (AAA.Succeeded()) {
		SM = AAA.Object;
	}

	BoxHitArea->SetRelativeLocation(FVector(0.25f, 2.5f, 13.75f));
	BoxHitArea->SetBoxExtent(FVector(26.0f, 28.0f, 14.0f));
	
	BoxHitArea->OnComponentBeginOverlap.AddDynamic(this, &ABreakAbleBoxC::OnOverlapBegin);

	OnlyOne = true;
}

// Called when the game starts or when spawned
void ABreakAbleBoxC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABreakAbleBoxC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABreakAbleBoxC::BoxDestroy()
{
	Destroy();
}

void ABreakAbleBoxC::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		if (OnlyOne) {
			OnlyOne = false;

			Cast<ABulletC>(OtherActor)->BulletExplosionDestroy();

			// 연기 생성하는 코드
			GetWorld()->SpawnActor<ADestroySmokeC>(ADestroySmokeC::StaticClass(), FTransform(
				BoxBox->GetComponentRotation(), BoxBox->GetComponentLocation(), BoxBox->GetComponentScale() * 2.0f));

			BoxBox->SetStaticMesh(SM);

			R = FMath::RandRange(0, 9);

			if (R < 3) {
				// HP포션 생성하는 코드
				GetWorld()->SpawnActor<AHPPortionC>(AHPPortionC::StaticClass(), FTransform(
					FRotator(0.0f, 0.0f, 0.0f), FVector(BoxBox->GetComponentLocation().X, BoxBox->GetComponentLocation().Y, BoxBox->GetComponentLocation().Z + 20.0f), FVector(1.0f, 1.0f, 1.0f)));
			}
			else if (R < 4) {
				// 노데미지포션 생성하는 코드
				GetWorld()->SpawnActor<ANoDamagePortionC>(ANoDamagePortionC::StaticClass(), FTransform(
					FRotator(0.0f, 0.0f, 0.0f), FVector(BoxBox->GetComponentLocation().X, BoxBox->GetComponentLocation().Y, BoxBox->GetComponentLocation().Z + 20.0f), FVector(1.0f, 1.0f, 1.0f)));
			}
			else if (R < 5) {
				// 슈퍼불렛포션 생성하는 코드
				GetWorld()->SpawnActor<ASuperBulletPortionC>(ASuperBulletPortionC::StaticClass(), FTransform(
					FRotator(0.0f, 0.0f, 0.0f), FVector(BoxBox->GetComponentLocation().X, BoxBox->GetComponentLocation().Y, BoxBox->GetComponentLocation().Z + 45.0f), FVector(1.0f, 1.0f, 1.0f)));
			}

			GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ABreakAbleBoxC::BoxDestroy, 0.85f, false);
		}
	}

}

