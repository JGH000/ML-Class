// Fill out your copyright notice in the Description page of Project Settings.

#include "BossStandCollisionC.h"
#include "Engine.h"

// Sets default values
ABossStandCollisionC::ABossStandCollisionC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RScene = CreateDefaultSubobject<USceneComponent>(TEXT("R_SCENE"));

	RScene->SetupAttachment(RootComponent);

	Box001 = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX001"));
	Box001->SetupAttachment(RScene);

	Box001->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Box001->SetCollisionObjectType(ECC_WorldDynamic);
	Box001->SetCollisionResponseToAllChannels(ECR_Overlap);
	Box001->SetRelativeLocation(FVector(-17.0f, 0.0f, -15.0f));
	Box001->SetRelativeScale3D(FVector(23.4f, 0.75f, 21.0f));

	Box002 = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX002"));
	Box002->SetupAttachment(RScene);

	Box002->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Box002->SetCollisionObjectType(ECC_WorldDynamic);
	Box002->SetCollisionResponseToAllChannels(ECR_Overlap);
	Box002->SetRelativeLocation(FVector(-744.0f, -376.0f, 0.0f));
	Box002->SetRelativeScale3D(FVector(0.75f, 12.5f, 20.0f));

	Box003 = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX003"));
	Box003->SetupAttachment(RScene);

	Box003->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Box003->SetCollisionObjectType(ECC_WorldDynamic);
	Box003->SetCollisionResponseToAllChannels(ECR_Overlap);
	Box003->SetRelativeLocation(FVector(708.0f, -377.0f, 0.0f));
	Box003->SetRelativeScale3D(FVector(0.75f, 12.5f, 20.0f));

	Box001->OnComponentBeginOverlap.AddDynamic(this, &ABossStandCollisionC::OnOverlapBegin_Box001);
	Box002->OnComponentBeginOverlap.AddDynamic(this, &ABossStandCollisionC::OnOverlapBegin_Box002);
	Box003->OnComponentBeginOverlap.AddDynamic(this, &ABossStandCollisionC::OnOverlapBegin_Box003);
}

// Called when the game starts or when spawned
void ABossStandCollisionC::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABossMonsterC::StaticClass(), FoundActors);

	for (int i = 0; i < FoundActors.Num(); i++) {
		if (FoundActors[i]->ActorHasTag("Boss001")) {
			BB = Cast<ABossMonsterC>(FoundActors[i]);
			break;
		}
	}
}

// Called every frame
void ABossStandCollisionC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABossStandCollisionC::OnOverlapBegin_Box001(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
		if (OtherComp->ComponentHasTag("Player")) {
			if (IsValid(BB)) BB->MonsterEnumIsNowFollow();
			else GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("BossMonster001IsNull!"));
			Destroy();
		}
}

void ABossStandCollisionC::OnOverlapBegin_Box002(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
		if (OtherComp->ComponentHasTag("Player")) {
			if (IsValid(BB)) BB->MonsterEnumIsNowFollow();
			else GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("BossMonster001IsNull!"));
			Destroy();
		}
}

void ABossStandCollisionC::OnOverlapBegin_Box003(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
		if (OtherComp->ComponentHasTag("Player")) {
			if (IsValid(BB)) BB->MonsterEnumIsNowFollow();
			else GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("BossMonster001IsNull!"));
			Destroy();
		}
}

