// Fill out your copyright notice in the Description page of Project Settings.

#include "Monster002C.h"
#include "Engine.h"

// Sets default values
AMonster002C::AMonster002C()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	GetCapsuleComponent()->SetCapsuleHalfHeight(112.329056f);
	GetCapsuleComponent()->SetCapsuleRadius(38.145153f);

	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->CanCharacterStepUpOn = ECB_No;

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Destructible, ECR_Block);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> PLAYER_BODY(
		TEXT("SkeletalMesh'/Game/Blueprints/Monster/Monster002/brute.brute'"));

	if (PLAYER_BODY.Succeeded()) {
		GetMesh()->SetSkeletalMesh(PLAYER_BODY.Object);
		GetMesh()->SetRelativeLocationAndRotation(
			FVector(-6.340454f, 0.0f, -104.55957f), FRotator(0.0f, -90.0f, 0.0f));
		GetMesh()->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	GetMesh()->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	GetMesh()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Destructible, ECR_Block);

    AxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("AX_BOX"));
    AxCollision->SetupAttachment(GetMesh(), TEXT("RightHand"));
    
    AxCollision->SetRelativeLocationAndRotation(FVector(-30.570389f, 2.660888f, 30.204039f), FRotator(0.0f, 90.0f, 15.000078f));
	AxCollision->SetBoxExtent(FVector(41.9674f, 31.746868f, 75.628433f));
    
    AxCollision->SetGenerateOverlapEvents(true);
    AxCollision->CanCharacterStepUpOn = ECB_No;
    
    AxCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    AxCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
    
    AxCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
    AxCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
    
    AxCollision->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
    AxCollision->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
    AxCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
    AxCollision->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
    AxCollision->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
    AxCollision->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);

	LeftCapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("LEFT_CAPSULE"));
	LeftCapsuleCollision->SetupAttachment(GetMesh(), TEXT("LeftHand"));
	
	LeftCapsuleCollision->SetRelativeLocationAndRotation(FVector(10.838737f, 3.838791f, 3.945109f), FRotator(0.0f, 90.0f, -90.0f));
	LeftCapsuleCollision->SetCapsuleHalfHeight(35.382725f);
	LeftCapsuleCollision->SetCapsuleRadius(12.974672f);
	
	LeftCapsuleCollision->SetGenerateOverlapEvents(true);
	LeftCapsuleCollision->CanCharacterStepUpOn = ECB_No;
	
	LeftCapsuleCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	LeftCapsuleCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	
	LeftCapsuleCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	LeftCapsuleCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	
	LeftCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	LeftCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	LeftCapsuleCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	LeftCapsuleCollision->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	LeftCapsuleCollision->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	LeftCapsuleCollision->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);

	LeftCapsuleCollision2 = CreateDefaultSubobject<UCapsuleComponent>(TEXT("LEFT_CAPSULE_2"));
	LeftCapsuleCollision2->SetupAttachment(GetMesh(), TEXT("LeftArm"));

	LeftCapsuleCollision2->SetRelativeLocationAndRotation(FVector(2.066884f, -6.533708f, -0.000134f), FRotator(0.0f, -184.999985f, -90.0f));
	LeftCapsuleCollision2->SetCapsuleHalfHeight(38.900658f);
	LeftCapsuleCollision2->SetCapsuleRadius(12.974672f);

	LeftCapsuleCollision2->SetGenerateOverlapEvents(true);
	LeftCapsuleCollision2->CanCharacterStepUpOn = ECB_No;

	LeftCapsuleCollision2->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	LeftCapsuleCollision2->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

	LeftCapsuleCollision2->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	LeftCapsuleCollision2->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	LeftCapsuleCollision2->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	LeftCapsuleCollision2->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	LeftCapsuleCollision2->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	LeftCapsuleCollision2->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	LeftCapsuleCollision2->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	LeftCapsuleCollision2->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);

	RightCapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RIGHT_CAPSULE"));
	RightCapsuleCollision->SetupAttachment(GetMesh(), TEXT("RightHand"));

	RightCapsuleCollision->SetRelativeLocationAndRotation(FVector(-1.309987f, 2.041284f, 1.502229f), FRotator(0.0f, 90.0f, -90.0f));
	RightCapsuleCollision->SetCapsuleHalfHeight(35.382725f);
	RightCapsuleCollision->SetCapsuleRadius(12.974672f);

	RightCapsuleCollision->SetGenerateOverlapEvents(true);
	RightCapsuleCollision->CanCharacterStepUpOn = ECB_No;

	RightCapsuleCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	RightCapsuleCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

	RightCapsuleCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	RightCapsuleCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	RightCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	RightCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	RightCapsuleCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RightCapsuleCollision->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	RightCapsuleCollision->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	RightCapsuleCollision->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);

	RightCapsuleCollision2 = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RIGHT_CAPSULE_2"));
	RightCapsuleCollision2->SetupAttachment(GetMesh(), TEXT("RightArm"));
						 
	RightCapsuleCollision2->SetRelativeLocationAndRotation(FVector(-0.990728f, -9.001226f, 1.941617f), FRotator(0.0f, 5.0f, 90.0f));
	RightCapsuleCollision2->SetCapsuleHalfHeight(35.382725f);
	RightCapsuleCollision2->SetCapsuleRadius(12.974672f);
						 
	RightCapsuleCollision2->SetGenerateOverlapEvents(true);
	RightCapsuleCollision2->CanCharacterStepUpOn = ECB_No;
						 
	RightCapsuleCollision2->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	RightCapsuleCollision2->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
						 
	RightCapsuleCollision2->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	RightCapsuleCollision2->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
						 
	RightCapsuleCollision2->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	RightCapsuleCollision2->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	RightCapsuleCollision2->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RightCapsuleCollision2->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	RightCapsuleCollision2->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	RightCapsuleCollision2->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);

	BodyCapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("BODY_CAPSULE"));
	BodyCapsuleCollision->SetupAttachment(GetMesh());

	BodyCapsuleCollision->SetRelativeLocationAndRotation(FVector(0.0f, 6.340453f, 104.55957f), FRotator(0.0f, -90.0f, 180.0f));
	BodyCapsuleCollision->SetCapsuleHalfHeight(112.329056f);
	BodyCapsuleCollision->SetCapsuleRadius(55.83889f);

	BodyCapsuleCollision->SetGenerateOverlapEvents(true);
	BodyCapsuleCollision->CanCharacterStepUpOn = ECB_No;

	BodyCapsuleCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BodyCapsuleCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

	BodyCapsuleCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	BodyCapsuleCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	BodyCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	BodyCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	BodyCapsuleCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	BodyCapsuleCollision->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	BodyCapsuleCollision->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	BodyCapsuleCollision->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);

	HitAreaCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("HIT_AREA_CAPSULE"));
	HitAreaCollision->SetupAttachment(GetMesh(), TEXT("Hips"));

	HitAreaCollision->SetRelativeLocationAndRotation(FVector(0.0f, 12.697135f, 3.519986f), FRotator(0.0f, 0.0f, -84.999931f));
	HitAreaCollision->SetCapsuleHalfHeight(105.993835f);
	HitAreaCollision->SetCapsuleRadius(38.145153f);

	HitAreaCollision->SetGenerateOverlapEvents(true);
	HitAreaCollision->CanCharacterStepUpOn = ECB_No;

	HitAreaCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	HitAreaCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

	HitAreaCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	HitAreaCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	HitAreaCollision->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	HitAreaCollision->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	HitAreaCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	HitAreaCollision->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	HitAreaCollision->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	HitAreaCollision->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);

	BulletSensorCollision = CreateDefaultSubobject<USphereComponent>(TEXT("BULLET_SENSOR_CAPSULE"));
	BulletSensorCollision->SetupAttachment(GetCapsuleComponent());

	BulletSensorCollision->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	BulletSensorCollision->SetSphereRadius(750.0f);

	BulletSensorCollision->SetGenerateOverlapEvents(true);
	BulletSensorCollision->CanCharacterStepUpOn = ECB_No;

	BulletSensorCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BulletSensorCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

	BulletSensorCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	BulletSensorCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Overlap);

	BulletSensorCollision->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	BulletSensorCollision->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	BulletSensorCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	BulletSensorCollision->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	BulletSensorCollision->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	BulletSensorCollision->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);

	BruteHorn001 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BRUTE_HORN_001"));

	BruteHorn002 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BRUTE_HORN_002"));

	BruteSphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BRUTE_SPHERE"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> HoRn(
		TEXT("StaticMesh'/Game/Blueprints/Monster/Monster002/HornAnd/BruteHorn.BruteHorn'"));

	if (HoRn.Succeeded()) {
		StaticMesh_Horn = HoRn.Object;
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BlAcKSpHeRe(
		TEXT("StaticMesh'/Game/Blueprints/Monster/Monster002/HornAnd/BruteSphere.BruteSphere'"));

	if (BlAcKSpHeRe.Succeeded()) {
		StaticMesh_BlackSphere = BlAcKSpHeRe.Object;
	}

	BruteHorn001->SetupAttachment(GetMesh(), TEXT("001"));
	BruteHorn001->SetStaticMesh(StaticMesh_Horn);
	BruteHorn001->SetRelativeLocationAndRotation(FVector(-1.352919f, -0.967125f, 4.615677f), FRotator(12.700019f, -15.579365f, -51.744377f));
	BruteHorn001->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.25f));

	BruteHorn002->SetupAttachment(GetMesh(), TEXT("002"));
	BruteHorn002->SetStaticMesh(StaticMesh_Horn);
	BruteHorn002->SetRelativeLocationAndRotation(FVector(2.269946f, -1.494833f, 3.905419f), FRotator(-24.404476f, 9.53348f, -57.267509f));
	BruteHorn002->SetRelativeScale3D(FVector(0.05f, 0.05f, 0.12f));

	BruteSphere->SetupAttachment(GetMesh(), TEXT("Spine2"));
	BruteSphere->SetStaticMesh(StaticMesh_BlackSphere);
	BruteSphere->SetRelativeLocationAndRotation(FVector(0.0f, -2.225969f, 2.527797f), FRotator(0.0f, 0.0f, 0.0f));
	BruteSphere->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));

	static ConstructorHelpers::FClassFinder<UAnim_Monster002C> BRUTE_ANIM_CLASS(
		TEXT("AnimBlueprint'/Game/Blueprints/Monster/Monster002/Monster002AnimC/Anim_Monster002ForC.Anim_Monster002ForC_C'"));
	if (BRUTE_ANIM_CLASS.Succeeded()) BruteAnimClass = BRUTE_ANIM_CLASS.Class;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> M_AS(
		TEXT("AnimMontage'/Game/Blueprints/Monster/Monster002/Monster002Anim/Brute_AxSlash.Brute_AxSlash'"));

	if (M_AS.Succeeded()) {
		Montage_AxSlash = M_AS.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> M_D(
		TEXT("AnimMontage'/Game/Blueprints/Monster/Monster002/Monster002Anim/Brute_Death.Brute_Death'"));

	if (M_D.Succeeded()) {
		Montage_Death = M_D.Object;
	}

	if (IsValid(GetMesh()->SkeletalMesh)) {
		GetMesh()->SetAnimInstanceClass(BruteAnimClass);
	}

	State = MONSTERENUM::MON_IDLE;
	DistanceToPlayer = 0.0f;
	HP = 50.0f;
	MonsterTargetRotation = FRotator(0.0f, 0.0f, 0.0f);
	MonsterCurrentRotation = FRotator(0.0f, 0.0f, 0.0f);
	IsAxSlash = false;
	IsAlive = true;
	SaveState = MONSTERENUM::MON_IDLE;
	IsSaveStateUseAble = false;
	DeathCheckAble = false;

	GetCapsuleComponent()->ComponentTags.Add("Monster");
	AxCollision->ComponentTags.Add("NoAttackMode");

	AxCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster002C::AxBoxBeginOverlap);
	LeftCapsuleCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster002C::LeftCapsuleBeginOverlap);
	LeftCapsuleCollision2->OnComponentBeginOverlap.AddDynamic(this, &AMonster002C::LeftCapsule2BeginOverlap);
	RightCapsuleCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster002C::RightCapsuleBeginOverlap);
	RightCapsuleCollision2->OnComponentBeginOverlap.AddDynamic(this, &AMonster002C::RightCapsule2BeginOverlap);
	BodyCapsuleCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster002C::BodyCapsuleBeginOverlap);
	BodyCapsuleCollision->OnComponentEndOverlap.AddDynamic(this, &AMonster002C::BodyCapsuleEndOverlap);
	HitAreaCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster002C::HitAreaCapsuleBeginOverlap);
	BulletSensorCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster002C::BulletSensorBeginOverlap);
}

// Called when the game starts or when spawned
void AMonster002C::BeginPlay()
{
	Super::BeginPlay();

	State = MONSTERENUM::MON_IDLE;

	FVector YYY = FVector(GetActorForwardVector().X, GetActorForwardVector().Y, 0.0f).GetSafeNormal(1.0f);

	MonsterCurrentRotation = FVector(YYY.X, YYY.Y, 0.0f).Rotation();

	if (MonsterCurrentRotation.Yaw < 0.0f) MonsterCurrentRotation.Yaw += 360.0f;

	SetActorRelativeRotation(MonsterCurrentRotation);

	Player = Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());
	// if (IsValid(Player)) GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Blue, TEXT("Complete!"));
}

// Called every frame
void AMonster002C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HP > 0.0f) {
		if (Player->GetCapsuleComponent()->ComponentHasTag("DeathPlayer")) {
			if (DeathCheckAble) {
				IsAxSlash = false;
				StopAnimMontage(Montage_AxSlash);
				AxCollision->ComponentTags[0] = "NoAttackMode";
				SaveState = State;
				IsSaveStateUseAble = true;
				State = MONSTERENUM::MON_IDLE;
				DeathCheckAble = false;
			}
		}
		else {
			DeathCheckAble = true;
			if (IsSaveStateUseAble) {
				State = SaveState;
				IsSaveStateUseAble = false;
			}
			else {}

			if (State == MONSTERENUM::MON_IDLE) {
				CheckDistance();
				Sequence000(DeltaTime);
			}
			else if (State == MONSTERENUM::MON_FOLLOW) {
				if (!IsAxSlash) {
					StopAnimMontage(Montage_AxSlash);
					CheckDirection();

					Sequence000(DeltaTime);
					Sequence001();
				}
			}

			else if (State == MONSTERENUM::MON_ATTACK) {
				if (IsAxSlash) CheckDirection();
				else {
						PlayAnimMontage(Montage_AxSlash, 1.0f);
						IsAxSlash = true;
						CheckDirection();
					}
				Sequence000(DeltaTime);
				Sequence001();
			}
		}
	}
	else {
		if (IsAlive) {
			IsAlive = false;
			GetCapsuleComponent()->ComponentTags[0] = "DeadMonster";
			AxSlashNoAttackMode();
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
			PlayAnimMontage(Montage_Death, 1.0f);
		}
	}
}

// Called to bind functionality to input
void AMonster002C::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMonster002C::Sequence000(float DDD)
{
	if (MonsterTargetRotation.Yaw <= 90.0f && MonsterCurrentRotation.Yaw >= 225.0f) {
		MonsterTargetRotation.Yaw += 360.0f;
		if (MonsterCurrentRotation.Yaw > 360.0f) {
			MonsterCurrentRotation.Yaw -= 360.0f;
		}
		else { MonsterCurrentRotation = FRotator(0.0f, FMath::FInterpTo(MonsterCurrentRotation.Yaw, MonsterTargetRotation.Yaw, DDD, 20.0f), 0.0f); }
	}
	else if (MonsterTargetRotation.Yaw >= 270.0f && MonsterCurrentRotation.Yaw <= 135.0f) {
		MonsterTargetRotation.Yaw -= 360.0f;
		if (MonsterCurrentRotation.Yaw < 0.0f) {
			MonsterCurrentRotation.Yaw += 360.0f;
		}
		else { MonsterCurrentRotation = FRotator(0.0f, FMath::FInterpTo(MonsterCurrentRotation.Yaw, MonsterTargetRotation.Yaw, DDD, 20.0f), 0.0f); }

	}
	else { MonsterCurrentRotation = FRotator(0.0f, FMath::FInterpTo(MonsterCurrentRotation.Yaw, MonsterTargetRotation.Yaw, DDD, 20.0f), 0.0f); }

	SetActorRotation(FRotator(0.0f, MonsterCurrentRotation.Yaw, 0.0f));
}

void AMonster002C::Sequence001()
{
	GetCharacterMovement()->MaxWalkSpeed = 1000.0f;
	if (!IsAxSlash) AddMovementInput(GetActorForwardVector(), 1.0f, false);
}

void AMonster002C::CheckDistance()
{
	if (HP < 50.0f) State = MONSTERENUM::MON_FOLLOW;
	else {
		DistanceToPlayer = (Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation() - GetActorLocation()).Size();
		if (DistanceToPlayer <= 1500.0f && State == MONSTERENUM::MON_IDLE) State = MONSTERENUM::MON_FOLLOW;

	}
}

void AMonster002C::CheckDirection()
{
	MonsterTargetRotation = (FVector(
		(((Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation()) - GetActorLocation()).GetSafeNormal()).X,
		(((Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation()) - GetActorLocation()).GetSafeNormal()).Y, 0.0f)).Rotation();

	if (MonsterTargetRotation.Yaw < 0.0f) MonsterTargetRotation.Yaw += 360.0f;
}

void AMonster002C::AxSlashStart()
{
	AxCollision->ComponentTags[0] = "AttackMode";
}

void AMonster002C::AxSlashEnd()
{
	IsAxSlash = false;
}

void AMonster002C::AxSlashNoAttackMode()
{
	AxCollision->ComponentTags[0] = "NoAttackMode";
}

void AMonster002C::Disappear()
{
	Destroy();
}

void AMonster002C::AxBoxBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) {

		if (AxCollision->ComponentHasTag("AttackMode")) {
			Player->MinusHP(20.0f);
			AxSlashNoAttackMode();
			if (Player->IsReloadMode) {
				Player->StopAnimMontage(Player->Montage_Reload);
				Player->ReloadModeCancel();
			}
		}
	}
}

void AMonster002C::LeftCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		class ABulletC * Bu = Cast<ABulletC>(OtherActor);
		HP -= Bu->BulletDamage;
		Bu->BulletExplosionDestroy();
		if (HP < 0.0f) HP = 0.0f;
	}
}

void AMonster002C::LeftCapsule2BeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		class ABulletC * Bu = Cast<ABulletC>(OtherActor);
		HP -= Bu->BulletDamage;
		Bu->BulletExplosionDestroy();
		if (HP < 0.0f) HP = 0.0f;
	}
}

void AMonster002C::RightCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		class ABulletC * Bu = Cast<ABulletC>(OtherActor);
		HP -= Bu->BulletDamage;
		Bu->BulletExplosionDestroy();
		if (HP < 0.0f) HP = 0.0f;
	}
}

void AMonster002C::RightCapsule2BeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		class ABulletC * Bu = Cast<ABulletC>(OtherActor);
		HP -= Bu->BulletDamage;
		Bu->BulletExplosionDestroy();
		if (HP < 0.0f) HP = 0.0f;
	}
}

void AMonster002C::BodyCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (IsValid(OtherActor)) {
		if (OtherComp->ComponentHasTag("Player")) State = MONSTERENUM::MON_ATTACK;
	}
}

void AMonster002C::BodyCapsuleEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (IsValid(OtherActor)) {
		if (OtherComp->ComponentHasTag("Player")) State = MONSTERENUM::MON_FOLLOW;
	}
}

void AMonster002C::HitAreaCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		class ABulletC * Bu = Cast<ABulletC>(OtherActor);
		HP -= Bu->BulletDamage;
		Bu->BulletExplosionDestroy();
		if (HP < 0.0f) HP = 0.0f;
	}
}

void AMonster002C::BulletSensorBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (State == MONSTERENUM::MON_IDLE) {
		if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) State = MONSTERENUM::MON_FOLLOW;

	}
}

