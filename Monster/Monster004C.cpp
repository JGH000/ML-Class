// Fill out your copyright notice in the Description page of Project Settings.

#include "Monster004C.h"
#include "Engine.h"

// Sets default values
AMonster004C::AMonster004C()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCapsuleHalfHeight(102.411263f);
	GetCapsuleComponent()->SetCapsuleRadius(41.416969f);

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
		TEXT("SkeletalMesh'/Game/Blueprints/Monster/Monster004/vampire_a_lusth.vampire_a_lusth'"));

	if (PLAYER_BODY.Succeeded()) {
		GetMesh()->SetSkeletalMesh(PLAYER_BODY.Object);
		GetMesh()->SetRelativeLocationAndRotation(
			FVector(0.0f, 0.0f, -100.430328f), FRotator(0.0f, -90.0f, 0.0f));
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

	Sword = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SWORD"));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SW(
		TEXT("SkeletalMesh'/Game/Blade_Fencer/SK_Blade_Fencer.SK_Blade_Fencer'"));

	if (SW.Succeeded()) {
		Sword->SetSkeletalMesh(SW.Object);
		Sword->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));
	}

	Sword->SetupAttachment(GetMesh(), TEXT("Sword"));
	
	Sword->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Sword->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);

	LongSwordCapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("SWORD_CAPSULE"));
	LongSwordCapsuleCollision->SetupAttachment(Sword);

	LongSwordCapsuleCollision->SetRelativeLocation(FVector(0.0f, 0.0f, 43.953171f));
	LongSwordCapsuleCollision->SetCapsuleHalfHeight(62.455208f);
	LongSwordCapsuleCollision->SetCapsuleRadius(13.620447f);
		
	LongSwordCapsuleCollision->SetGenerateOverlapEvents(true);
	LongSwordCapsuleCollision->CanCharacterStepUpOn = ECB_No;

	LongSwordCapsuleCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	LongSwordCapsuleCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

	LongSwordCapsuleCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	LongSwordCapsuleCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	LongSwordCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	LongSwordCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	LongSwordCapsuleCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	LongSwordCapsuleCollision->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	LongSwordCapsuleCollision->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	LongSwordCapsuleCollision->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);

	BodyCapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("BODY_CAPSULE"));
	BodyCapsuleCollision->SetupAttachment(GetCapsuleComponent());

	BodyCapsuleCollision->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
	BodyCapsuleCollision->SetCapsuleHalfHeight(120.900597f);
	BodyCapsuleCollision->SetCapsuleRadius(102.411263f);

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

	HitAreaCollision->SetRelativeLocationAndRotation(FVector(6.164087f, 16.914045f, 10.50234f), FRotator(0.0f, 0.0f, -85.0f));
	HitAreaCollision->SetCapsuleHalfHeight(103.217941f);
	HitAreaCollision->SetCapsuleRadius(45.851921f);

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

	static ConstructorHelpers::FClassFinder<UAnim_Monster004C> BRUTE_ANIM_CLASS(
		TEXT("AnimBlueprint'/Game/Blueprints/Monster/Monster004/Monster004AnimC/Anim_Monster004ForC.Anim_Monster004ForC_C'"));
	if (BRUTE_ANIM_CLASS.Succeeded()) VampireAnimClass = BRUTE_ANIM_CLASS.Class;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> M_S(
		TEXT("AnimMontage'/Game/Blueprints/Monster/Monster004/Monster004Anim/Vampire_Slash.Vampire_Slash'"));

	if (M_S.Succeeded()) {
		Montage_Slash = M_S.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> M_D(
		TEXT("AnimMontage'/Game/Blueprints/Monster/Monster004/Monster004Anim/Vampire_Death.Vampire_Death'"));

	if (M_D.Succeeded()) {
		Montage_Death = M_D.Object;
	}

	if (IsValid(GetMesh()->SkeletalMesh)) {
		GetMesh()->SetAnimInstanceClass(VampireAnimClass);
	}

	State = MONSTERENUM::MON_IDLE;
	DistanceToPlayer = 0.0f;
	HP = 50.0f;
	MonsterTargetRotation = FRotator(0.0f, 0.0f, 0.0f);
	MonsterCurrentRotation = FRotator(0.0f, 0.0f, 0.0f);
	IsLongSwordSlash = false;
	IsAlive = true;
	SaveState = MONSTERENUM::MON_IDLE;
	IsSaveStateUseAble = false;
	DeathCheckAble = false;

	GetCapsuleComponent()->ComponentTags.Add("Monster");
	LongSwordCapsuleCollision->ComponentTags.Add("NoAttackMode");

	LongSwordCapsuleCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster004C::LongSwordCapsuleBeginOverlap);
	BodyCapsuleCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster004C::BodyCapsuleBeginOverlap);
	BodyCapsuleCollision->OnComponentEndOverlap.AddDynamic(this, &AMonster004C::BodyCapsuleEndOverlap);
	HitAreaCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster004C::HitAreaCapsuleBeginOverlap);
	BulletSensorCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster004C::BulletSensorBeginOverlap);
}

// Called when the game starts or when spawned
void AMonster004C::BeginPlay()
{
	Super::BeginPlay();
	
	State = MONSTERENUM::MON_IDLE;

	FVector YYY = FVector(GetActorForwardVector().X, GetActorForwardVector().Y, 0.0f).GetSafeNormal(1.0f);

	MonsterCurrentRotation = FVector(YYY.X, YYY.Y, 0.0f).Rotation();

	if (MonsterCurrentRotation.Yaw < 0.0f) MonsterCurrentRotation.Yaw += 360.0f;

	SetActorRelativeRotation(MonsterCurrentRotation);

	Player = Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());
}

// Called every frame
void AMonster004C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HP > 0.0f) {
		if (Player->GetCapsuleComponent()->ComponentHasTag("DeathPlayer")) {
			if (DeathCheckAble) {
				IsLongSwordSlash = false;
				StopAnimMontage(Montage_Slash);
				LongSwordCapsuleCollision->ComponentTags[0] = "NoAttackMode";
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
				if (!IsLongSwordSlash) {
					StopAnimMontage(Montage_Slash);
					CheckDirection();

					Sequence000(DeltaTime);
					Sequence001();
				}
			}

			else if (State == MONSTERENUM::MON_ATTACK) {
				if (IsLongSwordSlash) CheckDirection();
				else {
					PlayAnimMontage(Montage_Slash, 1.0f);
					IsLongSwordSlash = true;
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
			LongSwordSlashNoAttackMode();
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
			PlayAnimMontage(Montage_Death, 1.0f);
		}
	}
}

// Called to bind functionality to input
void AMonster004C::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMonster004C::Sequence000(float DDD)
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

void AMonster004C::Sequence001()
{
	GetCharacterMovement()->MaxWalkSpeed = 1000.0f;
	if (!IsLongSwordSlash) AddMovementInput(GetActorForwardVector(), 1.0f, false);
}

void AMonster004C::CheckDistance()
{
	if (HP < 50.0f) State = MONSTERENUM::MON_FOLLOW;
	else {
		DistanceToPlayer = (Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation() - GetActorLocation()).Size();
		if (DistanceToPlayer <= 1500.0f && State == MONSTERENUM::MON_IDLE) State = MONSTERENUM::MON_FOLLOW;

	}
}

void AMonster004C::CheckDirection()
{
	MonsterTargetRotation = (FVector(
		(((Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation()) - GetActorLocation()).GetSafeNormal()).X,
		(((Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation()) - GetActorLocation()).GetSafeNormal()).Y, 0.0f)).Rotation();

	if (MonsterTargetRotation.Yaw < 0.0f) MonsterTargetRotation.Yaw += 360.0f;
}

void AMonster004C::LongSwordSlashStart()
{
	LongSwordCapsuleCollision->ComponentTags[0] = "AttackMode";
}

void AMonster004C::LongSwordSlashEnd()
{
	IsLongSwordSlash = false;
}

void AMonster004C::LongSwordSlashNoAttackMode()
{
	LongSwordCapsuleCollision->ComponentTags[0] = "NoAttackMode";
}

void AMonster004C::Disappear()
{
	Destroy();
}

void AMonster004C::LongSwordCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) {

		if (LongSwordCapsuleCollision->ComponentHasTag("AttackMode")) {
			Player->MinusHP(8.0f);
			LongSwordSlashNoAttackMode();
			if (Player->IsReloadMode) {
				Player->StopAnimMontage(Player->Montage_Reload);
				Player->ReloadModeCancel();
			}
		}
	}
}

void AMonster004C::BodyCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (IsValid(OtherActor)) {
		if (OtherComp->ComponentHasTag("Player")) State = MONSTERENUM::MON_ATTACK;
	}
}

void AMonster004C::BodyCapsuleEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (IsValid(OtherActor)) {
		if (OtherComp->ComponentHasTag("Player")) State = MONSTERENUM::MON_FOLLOW;
	}
}

void AMonster004C::HitAreaCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		class ABulletC * Bu = Cast<ABulletC>(OtherActor);
		HP -= Bu->BulletDamage;
		Bu->BulletExplosionDestroy();
		if (HP < 0.0f) HP = 0.0f;
	}
}

void AMonster004C::BulletSensorBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (State == MONSTERENUM::MON_IDLE) {
		if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) State = MONSTERENUM::MON_FOLLOW;

	}
}
