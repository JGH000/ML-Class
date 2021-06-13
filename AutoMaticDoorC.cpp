// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoMaticDoorC.h"
#include "BulletC.h"
#include "Engine.h"

// Sets default values
AAutoMaticDoorC::AAutoMaticDoorC()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USC = CreateDefaultSubobject<USceneComponent>(TEXT("USC"));

	USC->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> WWW(
		TEXT("StaticMesh'/Game/Wall_AutoDoor.Wall_AutoDoor'"));
	if (WWW.Succeeded()) WallSM = WWW.Object;

	LeftWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LEFT_WALL"));
	LeftWallCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("LEFT_WALL_COLLISION"));
	RightWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RIGHT_WALL"));
	RightWallCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("RIGHT_WALL_COLLISION"));

	LeftWall->SetupAttachment(USC);
	LeftWallCollision->SetupAttachment(LeftWall);
	RightWall->SetupAttachment(USC);
	RightWallCollision->SetupAttachment(RightWall);

	LeftWall->SetStaticMesh(WallSM);
	RightWall->SetStaticMesh(WallSM);

	OpenBox = CreateDefaultSubobject<UBoxComponent>(TEXT("OB"));
	OpenBox2 = CreateDefaultSubobject<UBoxComponent>(TEXT("OB2"));
	CloseBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CB"));
	CloseBox2 = CreateDefaultSubobject<UBoxComponent>(TEXT("CB2"));

	OpenBox->SetupAttachment(USC);
	OpenBox2->SetupAttachment(USC);
	CloseBox->SetupAttachment(USC);
	CloseBox2->SetupAttachment(USC);

	LeftWall->SetRelativeLocation(FVector(420.0f, 181.0f, 0.0f));
	LeftWall->SetWorldScale3D(FVector(1.2f, 1.2f, 1.7f));

	LeftWallCollision->SetRelativeLocation(FVector(0.0f, 49.999996f, 386.470459f));
	LeftWallCollision->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	LeftWallCollision->SetBoxExtent(FVector(305.0f, 54.0f, 420.0f));

	RightWall->SetRelativeLocation(FVector(-300.0f, 181.0f, 0.0f));
	RightWall->SetWorldScale3D(FVector(1.2f, 1.2f, 1.7f));

    RightWallCollision->SetRelativeLocation(FVector(0.0f, 49.999996f, 386.470459f));
    RightWallCollision->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
    RightWallCollision->SetBoxExtent(FVector(305.0f, 54.0f, 420.0f));

	OpenBox->SetRelativeLocation(FVector(61.0f, 0.0f, 655.0f));
	OpenBox->SetWorldScale3D(FVector(20.0f, 1.0f, 20.0f));
	OpenBox->SetBoxExtent(FVector(35.0f, 32.0f, 35.0f));

	OpenBox2->SetRelativeLocation(FVector(61.0f, 240.0f, 655.0f));
	OpenBox2->SetWorldScale3D(FVector(20.0f, 1.0f, 20.0f));
	OpenBox2->SetBoxExtent(FVector(35.0f, 32.0f, 35.0f));

	CloseBox->SetRelativeLocation(FVector(61.0f, -320.0f, 655.0f));
	CloseBox->SetWorldScale3D(FVector(20.0f, 1.0f, 20.0f));
	CloseBox->SetBoxExtent(FVector(35.0f, 32.0f, 35.0f));

	CloseBox2->SetRelativeLocation(FVector(61.0f, 700.0f, 655.0f));
	CloseBox2->SetWorldScale3D(FVector(20.0f, 1.0f, 20.0f));
	CloseBox2->SetBoxExtent(FVector(35.0f, 32.0f, 35.0f));

	IsOpen = false;

	LeftWallCollision->OnComponentBeginOverlap.AddDynamic(this, &AAutoMaticDoorC::OnOverlapBegin_BulletCollision);
	RightWallCollision->OnComponentBeginOverlap.AddDynamic(this, &AAutoMaticDoorC::OnOverlapBegin_BulletCollision);

	OpenBox->OnComponentBeginOverlap.AddDynamic(this, &AAutoMaticDoorC::OnOverlapBegin);
	OpenBox2->OnComponentBeginOverlap.AddDynamic(this, &AAutoMaticDoorC::OnOverlapBegin);
    CloseBox->OnComponentBeginOverlap.AddDynamic(this, &AAutoMaticDoorC::OnOverlapBegin2);
    CloseBox2->OnComponentBeginOverlap.AddDynamic(this, &AAutoMaticDoorC::OnOverlapBegin2);

}

// Called when the game starts or when spawned
void AAutoMaticDoorC::BeginPlay()
{
	Super::BeginPlay();
	
	LeftWallFirstPosX = LeftWall->GetComponentLocation().X;
	RightWallFirstPosX = RightWall->GetComponentLocation().X;
}

// Called every frame
void AAutoMaticDoorC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	 if (IsOpen) {
	 	RightWall->SetWorldLocation(FVector
	 	(FMath::FInterpTo(RightWall->GetComponentLocation().X, RightWallFirstPosX - 500.0f, DeltaTime, 2.0f)
	 		, RightWall->GetComponentLocation().Y, RightWall->GetComponentLocation().Z));
	 
	 	LeftWall->SetWorldLocation(FVector
	 	(FMath::FInterpTo(LeftWall->GetComponentLocation().X, LeftWallFirstPosX + 500.0f, DeltaTime, 2.0f)
	 		, LeftWall->GetComponentLocation().Y, LeftWall->GetComponentLocation().Z));
	 }


	 else {
	 	RightWall->SetWorldLocation(FVector
	 	(FMath::FInterpTo(RightWall->GetComponentLocation().X, RightWallFirstPosX, DeltaTime, 2.0f)
	 		, RightWall->GetComponentLocation().Y, RightWall->GetComponentLocation().Z));
	 
	 	LeftWall->SetWorldLocation(FVector
	 	(FMath::FInterpTo(LeftWall->GetComponentLocation().X, LeftWallFirstPosX, DeltaTime, 2.0f)
	 		, LeftWall->GetComponentLocation().Y, LeftWall->GetComponentLocation().Z));
	 }

}

void AAutoMaticDoorC::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) { IsOpen = true; }
}

void AAutoMaticDoorC::OnOverlapBegin2(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) { IsOpen = false; }
}

void AAutoMaticDoorC::OnOverlapBegin_BulletCollision(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		ABulletC * aa = Cast<ABulletC>(OtherActor);

			aa->BulletExplosionDestroy();
	
	}
}
