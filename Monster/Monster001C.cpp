// Fill out your copyright notice in the Description page of Project Settings.

#include "Monster001C.h"
#include "Engine.h"

// Sets default values
AMonster001C::AMonster001C()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCapsuleHalfHeight(81.466438f);
	GetCapsuleComponent()->SetCapsuleRadius(41.720497f);

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
		TEXT("SkeletalMesh'/Game/Blueprints/Monster/Monster001/mutant.mutant'"));

	if (PLAYER_BODY.Succeeded()) {
		GetMesh()->SetSkeletalMesh(PLAYER_BODY.Object);
		GetMesh()->SetRelativeLocationAndRotation(
			FVector(-20.084154f, 0.0f, -81.104202f), FRotator(0.0f, -90.0f, 0.0f));
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

	BodyCapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("BODY_CAPSULE"));
	BodyCapsuleCollision->SetupAttachment(GetMesh());

	BodyCapsuleCollision->SetRelativeLocationAndRotation(FVector(0.000031f, 20.095373f, 84.142708f), FRotator(0.0f, 90.0f, 0.0f));
	BodyCapsuleCollision->SetCapsuleHalfHeight(84.26609f);
	BodyCapsuleCollision->SetCapsuleRadius(45.470879f);

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

	SwordCapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("SWORD_CAPSULE"));
	SwordCapsuleCollision->SetupAttachment(GetMesh(), TEXT("LeftHand"));

	SwordCapsuleCollision->SetRelativeLocationAndRotation(FVector(10.838737f, 3.838791f, 3.945109f), FRotator(110.000107f, 0.0f, 0.0f));
	SwordCapsuleCollision->SetCapsuleHalfHeight(65.501297f);
	SwordCapsuleCollision->SetCapsuleRadius(43.469524f);

	SwordCapsuleCollision->SetGenerateOverlapEvents(true);
	SwordCapsuleCollision->CanCharacterStepUpOn = ECB_No;

	SwordCapsuleCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SwordCapsuleCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

	SwordCapsuleCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	SwordCapsuleCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	SwordCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	SwordCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	SwordCapsuleCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SwordCapsuleCollision->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	SwordCapsuleCollision->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	SwordCapsuleCollision->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);

	RightCapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RIGHT_CAPSULE"));
	RightCapsuleCollision->SetupAttachment(GetMesh(), TEXT("RightHand"));

	RightCapsuleCollision->SetRelativeLocationAndRotation(FVector(3.774367f, 7.287223f, 0.0f), FRotator(-90.0f, 0.0f, 0.0f));
	RightCapsuleCollision->SetCapsuleHalfHeight(48.099056f);
	RightCapsuleCollision->SetCapsuleRadius(24.097807f);

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

	LeftCapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("LEFT_CAPSULE"));
	LeftCapsuleCollision->SetupAttachment(GetMesh(), TEXT("LeftHand"));

	LeftCapsuleCollision->SetRelativeLocationAndRotation(FVector(9.272405f, 1.718739f, 3.37501f), FRotator(110.0f, 0.0f, 0.0f));
	LeftCapsuleCollision->SetCapsuleHalfHeight(59.155064f);
	LeftCapsuleCollision->SetCapsuleRadius(16.073225f);

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

	HitAreaCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("HIT_AREA_CAPSULE"));
	HitAreaCollision->SetupAttachment(GetMesh(), TEXT("Hips"));

	HitAreaCollision->SetRelativeLocationAndRotation(FVector(-2.237053f, 0.0f, 24.802921f), FRotator(0.0f, 0.0f, -90.0f));
	HitAreaCollision->SetCapsuleHalfHeight(81.466438f);
	HitAreaCollision->SetCapsuleRadius(41.720497f);

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

	static ConstructorHelpers::FClassFinder<UAnim_Monster001C> MUTANT_ANIM_CLASS(
		TEXT("AnimBlueprint'/Game/Blueprints/Monster/Monster001/Monster001AnimC/Anim_Monster001ForC.Anim_Monster001ForC_C'"));
	if (MUTANT_ANIM_CLASS.Succeeded()) MutantAnimClass = MUTANT_ANIM_CLASS.Class;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> M_SA(
		TEXT("AnimMontage'/Game/Blueprints/Monster/Monster001/Monster001Anim/Mutant_SpinAttack.Mutant_SpinAttack'"));

	if (M_SA.Succeeded()) {
		Montage_SpinAttack = M_SA.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> M_P(
		TEXT("AnimMontage'/Game/Blueprints/Monster/Monster001/Monster001Anim/Mutant_PunchMontage.Mutant_PunchMontage'"));

	if (M_P.Succeeded()) {
		Montage_Punch = M_P.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> M_D(
		TEXT("AnimMontage'/Game/Blueprints/Monster/Monster001/Monster001Anim/Mutant_Death.Mutant_Death'"));

	if (M_D.Succeeded()) {
		Montage_Death = M_D.Object;
	}

	 if (IsValid(GetMesh()->SkeletalMesh)) {
	 	GetMesh()->SetAnimInstanceClass(MutantAnimClass);
	 }

	MonsterTargetRotation = FRotator(0.0f, 0.0f, 0.0f);
	State = MONSTERENUM::MON_IDLE;
	DistanceToPlayer = 0.0f;
	MonsterCurrentRotation = FRotator(0.0f, 0.0f, 0.0f);
	IsSpinAttack = false;
	RandomInt = 0;
	RandomDirectionIsLoading = false;
	IsPunch = false;
	RandomInt2 = 0;
	HP = 50.0f;
	IsAlive = true;
	IsSpinAttackFunctionPlay = false;
	SaveState = MONSTERENUM::MON_IDLE;
	IsSaveStateUseAble = false;
	DeathCheckAble = false;
	
	GetCapsuleComponent()->ComponentTags.Add("Monster");
	SwordCapsuleCollision->ComponentTags.Add("NoAttackMode");
	RightCapsuleCollision->ComponentTags.Add("NoAttackMode");

	BodyCapsuleCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster001C::BodyCapsuleBeginOverlap);
	BodyCapsuleCollision->OnComponentEndOverlap.AddDynamic(this, &AMonster001C::BodyCapsuleEndOverlap);
	SwordCapsuleCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster001C::SwordCapsuleBeginOverlap);
	RightCapsuleCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster001C::RightCapsuleBeginOverlap);
	LeftCapsuleCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster001C::LeftCapsuleBeginOverlap);
	HitAreaCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster001C::HitAreaCapsuleBeginOverlap);
	BulletSensorCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster001C::BulletSensorBeginOverlap);
	
}

// Called when the game starts or when spawned
void AMonster001C::BeginPlay()
{
	Super::BeginPlay();
	
	State = MONSTERENUM::MON_IDLE;

	FVector YYY = FVector(GetActorForwardVector().X, GetActorForwardVector().Y , 0.0f).GetSafeNormal(1.0f);

	MonsterCurrentRotation = FVector(YYY.X, YYY.Y, 0.0f).Rotation();

	if (MonsterCurrentRotation.Yaw < 0.0f) MonsterCurrentRotation.Yaw += 360.0f;



	SetActorRelativeRotation(MonsterCurrentRotation);

	Player = Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());
	// if (IsValid(Player)) GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Blue, TEXT("Complete!"));
}

// Called every frame
void AMonster001C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HP > 0.0f) {
		if (Player->GetCapsuleComponent()->ComponentHasTag("DeathPlayer")) {
			if (DeathCheckAble) {
				IsPunch = false;
				StopAnimMontage(Montage_Punch);
				RightCapsuleCollision->ComponentTags[0] = "NoAttackMode";
				SwordCapsuleCollision->ComponentTags[0] = "NoAttackMode";
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
				if (RandomDirectionIsLoading) {}
				else {
					GetWorldTimerManager().SetTimer(CountdownTimerHandle_RandomDirection, this, &AMonster001C::RandomDirection, 2.0f, false);
					RandomDirectionIsLoading = true;
				}
				Sequence000(DeltaTime);
			}
			else if (State == MONSTERENUM::MON_FOLLOW) {
				if (!IsPunch) {
					StopAnimMontage(Montage_Punch);
					CheckDirection();

					if (!IsSpinAttackFunctionPlay) {
						GetWorldTimerManager().SetTimer(CountdownTimerHandle_RandomSpinAttack, this, &AMonster001C::RandomSpinAttack, 2.0f, false);
						IsSpinAttackFunctionPlay = true;
					}

					Sequence000(DeltaTime);
					Sequence001();
				}
			}

			else if (State == MONSTERENUM::MON_ATTACK) {
				if (IsSpinAttack) CheckDirection();
				else {
					if (IsPunch) return;
					else {
						PlayAnimMontage(Montage_Punch, 1.0f);
						IsPunch = true;
						CheckDirection();
					}
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
			PunchNoAttackMode();
			SlashNoAttackMode();
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
			PlayAnimMontage(Montage_Death, 1.0f);
		}
	}
}

// Called to bind functionality to input
void AMonster001C::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMonster001C::Sequence000(float DDD)
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

void AMonster001C::Sequence001()
{
	if (IsSpinAttack) {
		GetCharacterMovement()->MaxWalkSpeed = 3000.0f;
		AddMovementInput(GetActorForwardVector(), 1.0f, false);
	}
	else {
		GetCharacterMovement()->MaxWalkSpeed = 1000.0f;
		if (!IsPunch) AddMovementInput(GetActorForwardVector(), 1.0f, false);
	}
}

void AMonster001C::CheckDistance()
{
	if (HP < 50.0f) State = MONSTERENUM::MON_FOLLOW;
	else {
		DistanceToPlayer = (Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation() - GetActorLocation()).Size();
		if (DistanceToPlayer <= 1500.0f && State == MONSTERENUM::MON_IDLE) State = MONSTERENUM::MON_FOLLOW;
	
	}
}

void AMonster001C::CheckDirection()
{
	MonsterTargetRotation = (FVector(
		(((Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation()) - GetActorLocation()).GetSafeNormal()).X,
		(((Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation()) - GetActorLocation()).GetSafeNormal()).Y, 0.0f)).Rotation();

	if (MonsterTargetRotation.Yaw < 0.0f) MonsterTargetRotation.Yaw += 360.0f;
}

void AMonster001C::RandomDirection()
{
	if (State == MONSTERENUM::MON_IDLE) {
		if (IsAlive) {
			RandomInt = FMath::RandRange(0, 3);
			if (RandomInt == 0) MonsterTargetRotation = FRotator(0.0f, 0.0f, 0.0f);
			else if (RandomInt == 1)  MonsterTargetRotation = FRotator(0.0f, 90.0f, 0.0f);
			else if (RandomInt == 2)  MonsterTargetRotation = FRotator(0.0f, 180.0f, 0.0f);
			else if (RandomInt == 3)  MonsterTargetRotation = FRotator(0.0f, 270.0f, 0.0f);
		}
	}

	RandomDirectionIsLoading = false;
}

void AMonster001C::RandomSpinAttack()
{
	if (State == MONSTERENUM::MON_FOLLOW) {
		if (IsAlive && !IsPunch && !IsSpinAttack) {
			RandomInt2 = FMath::RandRange(0, 3);
			if (RandomInt2 == 0) {
				IsSpinAttack = true;
				PlayAnimMontage(Montage_SpinAttack, 1.0f);
				return;
			}
		}
	}
	
	IsSpinAttackFunctionPlay = false;
}

void AMonster001C::SlashEnd()
{
	IsSpinAttack = false;
	IsPunch = false;
	IsSpinAttackFunctionPlay = false;
}

void AMonster001C::PunchStart()
{
	RightCapsuleCollision->ComponentTags[0] = "AttackMode";
}

void AMonster001C::PunchEnd()
{
	IsPunch = false;
}

void AMonster001C::SlashStart()
{
	SwordCapsuleCollision->ComponentTags[0] = "AttackMode";
}

void AMonster001C::SlashNoAttackMode()
{
	SwordCapsuleCollision->ComponentTags[0] = "NoAttackMode";
}

void AMonster001C::Disappear()
{
	Destroy();
}

void AMonster001C::PunchNoAttackMode()
{
	RightCapsuleCollision->ComponentTags[0] = "NoAttackMode";
}

void AMonster001C::BodyCapsuleBeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{

	if (IsValid(OtherActor)) {
		if (OtherComp->ComponentHasTag("Player")) State = MONSTERENUM::MON_ATTACK;
	}
}

void AMonster001C::BodyCapsuleEndOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex)
{
	if (IsValid(OtherActor)) {
		if (OtherComp->ComponentHasTag("Player")) State = MONSTERENUM::MON_FOLLOW;
	}
}

void AMonster001C::SwordCapsuleBeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) {

		if (SwordCapsuleCollision->ComponentHasTag("AttackMode")) {
			Player->MinusHP(20.0f);
			SlashNoAttackMode();
			if (Player->IsReloadMode) {
				Player->StopAnimMontage(Player->Montage_Reload);
				Player->ReloadModeCancel();
			}
		}
	}
}

void AMonster001C::RightCapsuleBeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) {
		if (RightCapsuleCollision->ComponentHasTag("AttackMode")) {
			Player->MinusHP(12.0f);
			PunchNoAttackMode();
			if (Player->IsReloadMode) {
				Player->StopAnimMontage(Player->Montage_Reload);
				Player->ReloadModeCancel();
			}
		}
	}
	else {
		if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
			class ABulletC * Bu = Cast<ABulletC>(OtherActor);
			HP -= Bu->BulletDamage;
			Bu->BulletExplosionDestroy();
			if (HP < 0.0f) HP = 0.0f;
		}
	}
}

void AMonster001C::LeftCapsuleBeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		class ABulletC * Bu = Cast<ABulletC>(OtherActor);
		HP -= Bu->BulletDamage;
		Bu->BulletExplosionDestroy();
		if (HP < 0.0f) HP = 0.0f;
	}
}

void AMonster001C::HitAreaCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		class ABulletC * Bu = Cast<ABulletC>(OtherActor);
		HP -= Bu->BulletDamage;
		Bu->BulletExplosionDestroy();
		if (HP < 0.0f) HP = 0.0f;
	}
}

void AMonster001C::BulletSensorBeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (State == MONSTERENUM::MON_IDLE) {
		if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) State = MONSTERENUM::MON_FOLLOW;
	
	}
}

