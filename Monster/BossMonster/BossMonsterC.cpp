// Fill out your copyright notice in the Description page of Project Settings.

#include "BossMonsterC.h"
#include "Engine.h"

// Sets default values
ABossMonsterC::ABossMonsterC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCapsuleHalfHeight(100.0f);
	GetCapsuleComponent()->SetCapsuleRadius(34.0f);

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
		TEXT("SkeletalMesh'/Game/Blueprints/Monster/BossMonster/maw_j_laygo.maw_j_laygo'"));

	if (PLAYER_BODY.Succeeded()) {
		GetMesh()->SetSkeletalMesh(PLAYER_BODY.Object);
		GetMesh()->SetRelativeLocationAndRotation(
			FVector(0.0f, 0.0f, -99.0f), FRotator(0.0f, -90.0f, 0.0f));
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

	 static ConstructorHelpers::FObjectFinder<UParticleSystem> PPP(
	 	TEXT("ParticleSystem'/Game/AAA.AAA'"));
	 if (PPP.Succeeded()) UPS = PPP.Object;
	 
	 for (int i = 0; i < 8; i++) {
		 FString PartiStr = "PARTICLE_";
		 PartiStr.Append(FString::FromInt(i+1));
		 UPSC[i] = CreateDefaultSubobject<UParticleSystemComponent>(FName(*PartiStr));
		 UPSC[i]->SetupAttachment(GetMesh());
	 }

	 // UPSC->SetTemplate(UPS);

	 UPSC[0]->SetRelativeLocation(FVector(50.0f, 50.0f, -4.0f));
	 UPSC[0]->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	 UPSC[1]->SetRelativeLocation(FVector(0.0f, 70.0f, -4.0f));
	 UPSC[1]->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	 UPSC[2]->SetRelativeLocation(FVector(-50.0f, 50.0f, -4.0f));
	 UPSC[2]->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	 UPSC[3]->SetRelativeLocation(FVector(70.0f, 0.0f, -4.0f));
	 UPSC[3]->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	 UPSC[4]->SetRelativeLocation(FVector(-70.0f, 0.0f, -4.0f));
	 UPSC[4]->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	 UPSC[5]->SetRelativeLocation(FVector(50.0f, -50.0f, -4.0f));
	 UPSC[5]->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	 UPSC[6]->SetRelativeLocation(FVector(0.0f, -70.0f, -4.0f));
	 UPSC[6]->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	 UPSC[7]->SetRelativeLocation(FVector(-50.0f, -50.0f, -4.0f));
	 UPSC[7]->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	 HitAreaCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("HIT_AREA_CAPSULE"));
	 HitAreaCollision->SetupAttachment(GetMesh(), TEXT("Hips"));

	 HitAreaCollision->SetRelativeLocationAndRotation(FVector(4.0f, -13.0f, 10.908442f), FRotator(0.0f, 0.0f, -95.0f));
	 HitAreaCollision->SetCapsuleHalfHeight(90.0f);
	 HitAreaCollision->SetCapsuleRadius(42.0f);

	 HitAreaCollision->SetGenerateOverlapEvents(true);
	 HitAreaCollision->CanCharacterStepUpOn = ECB_No;

	 HitAreaCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	 HitAreaCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

	 HitAreaCollision->SetCollisionResponseToAllChannels(ECR_Overlap);

	 FireCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("FIRE_COLLISION"));
	 FireCollision->SetupAttachment(GetCapsuleComponent());

	 FireCollision->SetRelativeLocation(FVector(0.0f, 0.0f, -68.0f));
	 FireCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	 FireCollision->SetCollisionObjectType(ECC_WorldDynamic);
	 FireCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
	 FireCollision->SetBoxExtent(FVector(85.0f, 85.0f, 32.0f));

	 StopExitCheckCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("STOP_EXIT_CHECK_COLLISION"));
	 StopExitCheckCollision->SetupAttachment(GetCapsuleComponent());

	 StopExitCheckCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	 StopExitCheckCollision->SetCollisionObjectType(ECC_WorldDynamic);
	 StopExitCheckCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
	 StopExitCheckCollision->SetBoxExtent(FVector(90.0f, 90.0f, 100.0f));

	 StopEnterCheckCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("STOP_ENTER_CHECK_COLLISION"));
	 StopEnterCheckCollision->SetupAttachment(GetCapsuleComponent());

	 StopEnterCheckCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	 StopEnterCheckCollision->SetCollisionObjectType(ECC_WorldDynamic);
	 StopEnterCheckCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
	 StopEnterCheckCollision->SetBoxExtent(FVector(75.0f, 75.0f, 100.0f));

	 PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("POINT_LIGHT"));

	 PointLight->SetupAttachment(GetMesh());
	 PointLight->SetRelativeLocation(FVector(0.0f, 0.0f, 127.0f));
	 PointLight->SetIntensity(2500.0f);

	 PointLight->SetLightColor(FLinearColor(1.0f, 0.14996f, 0.0f), true);

	 PointLight->SetAttenuationRadius(0.0f);
	 PointLight->SetCastShadows(false);

	 static ConstructorHelpers::FClassFinder<UAnim_BossMonsterC> BOSS_ANIM_CLASS(
		 TEXT("AnimBlueprint'/Game/Blueprints/Monster/BossMonster/BossMonsterAnimC/Anim_BossMonsterForC.Anim_BossMonsterForC_C'"));
	 if (BOSS_ANIM_CLASS.Succeeded()) BossAnimClass = BOSS_ANIM_CLASS.Class;

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_FB(
		 TEXT("AnimMontage'/Game/Blueprints/Monster/BossMonster/BossMonsterAnim/Boss_FireBall.Boss_FireBall'"));

	 if (M_FB.Succeeded()) {
		 Montage_FireBall = M_FB.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_HW(
		 TEXT("AnimMontage'/Game/Blueprints/Monster/BossMonster/BossMonsterAnim/Boss_Howling.Boss_Howling'"));

	 if (M_HW.Succeeded()) {
		 Montage_Howling = M_HW.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_RR(
		 TEXT("AnimMontage'/Game/Blueprints/Monster/BossMonster/BossMonsterAnim/Boss_Roar.Boss_Roar'"));

	 if (M_RR.Succeeded()) {
		 Montage_Roar = M_RR.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_SIT(
		 TEXT("AnimMontage'/Game/Blueprints/Monster/BossMonster/BossMonsterAnim/Boss_Sit.Boss_Sit'"));

	 if (M_SIT.Succeeded()) {
		 Montage_Sit = M_SIT.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_STAND(
		 TEXT("AnimMontage'/Game/Blueprints/Monster/BossMonster/BossMonsterAnim/Boss_StandUp.Boss_StandUp'"));

	 if (M_STAND.Succeeded()) {
		 Montage_StandUp = M_STAND.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_D(
		 TEXT("AnimMontage'/Game/Blueprints/Monster/BossMonster/BossMonsterAnim/Boss_Death.Boss_Death'"));

	 if (M_D.Succeeded()) {
		 Montage_Death = M_D.Object;
	 }

	 if (IsValid(GetMesh()->SkeletalMesh)) {
		 GetMesh()->SetAnimInstanceClass(BossAnimClass);
	 }

	IsSit = true;
	IsStandUpMontagePlay = false;
	MonsterTargetRotation = FRotator(0.0f, 0.0f, 0.0f);
	MonsterCurrentRotation = FRotator(0.0f, 0.0f, 0.0f);
	State = MONSTERENUM::MON_IDLE;
	StandUpOnlyOne = true;
	HP = 600.0f;
	IsDead = false;
	OnlyOne = false;
	IsAlive = true;
	IsStop = false;
	IsFireBall = false;
	IsDirectionCheck = false;
	IsAttackModeFunctionCheckStart = false;
	AttackCheckOnlyOne = true;
	DeathCheckAble = false;
	IsSaveStateUseAble = false;
	AttackRandomInt = 0;
	FlameGroundCount = 0;
	SaveState = MONSTERENUM::MON_IDLE;

	GetCapsuleComponent()->ComponentTags.Add("Monster");
	Tags.Add("Boss001");

	HitAreaCollision->OnComponentBeginOverlap.AddDynamic(this, &ABossMonsterC::HitAreaCapsuleBeginOverlap);
	FireCollision->OnComponentBeginOverlap.AddDynamic(this, &ABossMonsterC::FireBoxBeginOverlap);
	FireCollision->OnComponentEndOverlap.AddDynamic(this, &ABossMonsterC::FireBoxEndOverlap);
	StopExitCheckCollision->OnComponentEndOverlap.AddDynamic(this, &ABossMonsterC::StopExitCheckCollisionEndOverlap);
	StopEnterCheckCollision->OnComponentBeginOverlap.AddDynamic(this, &ABossMonsterC::StopEnterCheckCollisionBeginOverlap);
}

// Called when the game starts or when spawned
void ABossMonsterC::BeginPlay()
{
	Super::BeginPlay();
	
	State = MONSTERENUM::MON_IDLE;

	MonsterCurrentRotation = FRotator(0.0f, 270.0f, 0.0f);

	if (MonsterCurrentRotation.Yaw < 0.0f) MonsterCurrentRotation.Yaw += 360.0f;



	SetActorRelativeRotation(MonsterCurrentRotation);

	Player = Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());

	PlayAnimMontage(Montage_Sit);

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyAutoMaticDoorC_BossRoom002::StaticClass(), FoundActors);

	for (int i = 0; i < FoundActors.Num(); i++) {
		if (FoundActors[i]->ActorHasTag("Boss001Door")) {
			AutoDoor = Cast<AMyAutoMaticDoorC_BossRoom002>(FoundActors[i]);
			break;
		}
	}
}

// Called every frame
void ABossMonsterC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (HP > 0.0f) {
		if (Player->GetCapsuleComponent()->ComponentHasTag("DeathPlayer")) {
			if (DeathCheckAble) {
				StopAnimMontage();
				AttackCheckOnlyOne = true;
				IsSaveStateUseAble = true;
				if (State == MONSTERENUM::MON_IDLE) { SaveState = MONSTERENUM::MON_IDLE; }
				else { SaveState = MONSTERENUM::MON_FOLLOW; }
				State = MONSTERENUM::MON_IDLE;
				DeathCheckAble = false;

				if (StandUpOnlyOne && SaveState == MONSTERENUM::MON_FOLLOW) PlayAnimMontage(Montage_Sit, 1.0f);

			}
		}
		else {
			DeathCheckAble = true;
			if (IsSaveStateUseAble) {
				State = SaveState;
				IsSaveStateUseAble = false;
			}

			if (State == MONSTERENUM::MON_FOLLOW) {
				if (StandUpOnlyOne) {
					if (!IsStandUpMontagePlay) {
						PlayAnimMontage(Montage_StandUp, 1.0f);
						IsStandUpMontagePlay = true;
					}
				}
				else {
					if (!IsAttackModeFunctionCheckStart) {
						GetWorldTimerManager().SetTimer(CountdownTimerHandle_SetAttackMode, this, &ABossMonsterC::SetAttackMode, FMath::RandRange(1.0f, 3.15f), false);
						IsAttackModeFunctionCheckStart = true;
					}
					CheckDirection();
					Sequence000(DeltaTime);
					Sequence001();
				}
			}

			else if (State == MONSTERENUM::MON_ATTACK) {
				if (AttackCheckOnlyOne) {
					AttackCheckOnlyOne = false;
					AttackRandomInt = FMath::RandRange(0, 2);

					if (AttackRandomInt == 0) FireBallStart();
					else if (AttackRandomInt == 1) FireGroundStart();
					else if (AttackRandomInt == 2) {
						if (FlameGroundCount < 2) FlameAreaSetStart();
						else {
							AttackRandomInt = FMath::RandRange(0,1);
							if (AttackRandomInt == 0) FireBallStart();
							else if (AttackRandomInt == 1) FireGroundStart();
						}
					
					}
				}
			}
		}
	}
	else {
		if (IsAlive) {
			IsAlive = false;
			GetCapsuleComponent()->ComponentTags[0] = "DeadMonster";
			AutoDoor->OoOpen();
			BossEffect->Destroy();
			GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
			PlayAnimMontage(Montage_Death, 1.0f);
		}
	}
}

// Called to bind functionality to input
void ABossMonsterC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABossMonsterC::Sequence000(float DDD)
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

void ABossMonsterC::Sequence001()
{
	GetCharacterMovement()->MaxWalkSpeed = 500.0f;
	if (!IsStop) AddMovementInput(GetActorForwardVector(), 1.0f, false);
}

void ABossMonsterC::CheckDirection()
{
	MonsterTargetRotation = (FVector(
		(((Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation()) - GetActorLocation()).GetSafeNormal()).X,
		(((Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation()) - GetActorLocation()).GetSafeNormal()).Y, 0.0f)).Rotation();

	if (MonsterTargetRotation.Yaw < 0.0f) MonsterTargetRotation.Yaw += 360.0f;
}

void ABossMonsterC::BossEffectSpawn()
{
	BossEffect = GetWorld()->SpawnActor<ABossEffectC>(ABossEffectC::StaticClass(), FVector(454.0f, 33997.0f, -6877.0f), FRotator(0.0f, 0.0f, 0.0f));
}

void ABossMonsterC::FlameSetUp()
{
	for (int i = 0; i < 8; i++) {
		UPSC[i]->SetTemplate(UPS);
	}
}

void ABossMonsterC::FlameSetOff()
{
	for (int i = 0; i < 8; i++) {
		UPSC[i]->SetTemplate(nullptr);
	}
}

void ABossMonsterC::FlameDamage()
{
	if (Player->IsAlive) Player->MinusHP(4.0f);
}

void ABossMonsterC::FireBallStart()
{
	PlayAnimMontage(Montage_FireBall);
}

void ABossMonsterC::SetAttackMode()
{
	if (DeathCheckAble) { State = MONSTERENUM::MON_ATTACK; }
	IsAttackModeFunctionCheckStart = false;
}

void ABossMonsterC::FireGroundStart()
{
	PlayAnimMontage(Montage_Howling);
}

void ABossMonsterC::FlameAreaSetStart()
{
	PlayAnimMontage(Montage_Roar);
	PointLight->Intensity = 5000.0f;
}

void ABossMonsterC::StandUpOnlyOneFalse()
{
	StandUpOnlyOne = false;
	BossEffectSpawn();
	FlameSetUp();
}

void ABossMonsterC::MonsterDisappear()
{
	Destroy();
}

void ABossMonsterC::FireBall()
{
	GetWorld()->SpawnActor<AFBC>(AFBC::StaticClass(), GetMesh()->GetSocketLocation(TEXT("FireBall_Socket")), GetMesh()->GetSocketRotation(TEXT("FireBall_Socket")));
}

void ABossMonsterC::AttackEnd()
{
	if (PointLight->Intensity == 5000) {
		PointLight->Intensity = 0.0f;
		FlameGroundCount += 1;
	}
	else {
		if (FlameGroundCount > 0) FlameGroundCount -= 1;
	}
	AttackCheckOnlyOne = true;
	State = MONSTERENUM::MON_FOLLOW;
}

void ABossMonsterC::FireGroundSpawn()
{
	GetWorld()->SpawnActor<AFireFromGroundC>(AFireFromGroundC::StaticClass(), FVector(Player->GetActorLocation().X, Player->GetActorLocation().Y, -7194.0f), FRotator(0.0f, 0.0f, 0.0f));
}

void ABossMonsterC::FlameAreaSpawn()
{
	int Cc = 0;

	while (Cc < 5) {
		GetWorld()->SpawnActor<AFlameAreaC>(AFlameAreaC::StaticClass(), FVector(FMath::RandRange(-2720.100098f, 3624.100098f), FMath::RandRange(31865.900391f, 38201.101562f), -7194.0f), FRotator(0.0f, 0.0f, 0.0f))->SetActorScale3D(FVector(5.0f, 5.0f, 5.0f));
		Cc++;
	}
}

void ABossMonsterC::MonsterEnumIsNowFollow()
{
	State = MONSTERENUM::MON_FOLLOW;
}

void ABossMonsterC::HitAreaCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		class ABulletC * Bu = Cast<ABulletC>(OtherActor);
		if (PointLight->Intensity == 50000.0) { HP -= Bu->BulletDamage * 0.5f; }
		else { HP -= Bu->BulletDamage; }
		Bu->BulletExplosionDestroy();
		if (HP < 0.0f) HP = 0.0f;
	}
}

void ABossMonsterC::FireBoxBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) GetWorldTimerManager().SetTimer(CountdownTimerHandle_FlameDamage, this, &ABossMonsterC::FlameDamage, 0.4f, true);
}

void ABossMonsterC::FireBoxEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (OtherComp->ComponentHasTag("Player")) GetWorldTimerManager().ClearTimer(CountdownTimerHandle_FlameDamage);
}

void ABossMonsterC::StopExitCheckCollisionEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (OtherComp->ComponentHasTag("Player")) IsStop = false;
}

void ABossMonsterC::StopEnterCheckCollisionBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) IsStop = true;
}
