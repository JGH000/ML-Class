// Fill out your copyright notice in the Description page of Project Settings.

#include "Monster003C.h"
#include "Engine.h"

// Sets default values
AMonster003C::AMonster003C()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    GetCapsuleComponent()->SetCapsuleHalfHeight(105.98349f);
    GetCapsuleComponent()->SetCapsuleRadius(38.083759f);
    
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
	 	TEXT("SkeletalMesh'/Game/Blueprints/Monster/Monster003/skeletonzombie_t_avelange.skeletonzombie_t_avelange'"));
	 
	 if (PLAYER_BODY.Succeeded()) {
	 	GetMesh()->SetSkeletalMesh(PLAYER_BODY.Object);
	 	GetMesh()->SetRelativeLocationAndRotation(
	 		FVector(0.0f, 0.0f, -104.288879f), FRotator(0.0f, -90.0f, 0.0f));
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
     
     BodyCapsuleCollision->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 104.288879f), FRotator(0.0f, 90.0f, 0.0f));
     BodyCapsuleCollision->SetCapsuleHalfHeight(104.451721f);
     BodyCapsuleCollision->SetCapsuleRadius(41.865437f);
     
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

     KickCapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("KICK_CAPSULE"));
     KickCapsuleCollision->SetupAttachment(GetMesh(), TEXT("RightFoot"));
     
     KickCapsuleCollision->SetRelativeLocationAndRotation(FVector(-3.28337f, -32.477856f, 8.803828f), FRotator(0.0f, 0.0f, 90.0f));
     KickCapsuleCollision->SetCapsuleHalfHeight(51.205631f);
     KickCapsuleCollision->SetCapsuleRadius(33.699913f);
     
     KickCapsuleCollision->SetGenerateOverlapEvents(true);
     KickCapsuleCollision->CanCharacterStepUpOn = ECB_No;
     
     KickCapsuleCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
     KickCapsuleCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
     
     KickCapsuleCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
     KickCapsuleCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
     
     KickCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
     KickCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
     KickCapsuleCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
     KickCapsuleCollision->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
     KickCapsuleCollision->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
     KickCapsuleCollision->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);
     
	 HurricaneKickCapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("HURRICANE_KICK_CAPSULE"));
	 HurricaneKickCapsuleCollision->SetupAttachment(GetMesh(), TEXT("LeftFoot"));
	 
	 HurricaneKickCapsuleCollision->SetRelativeLocationAndRotation(FVector(0.373955f, -32.477856f, 2.465425f), FRotator(0.0f, 0.0f, -90.0f));
	 HurricaneKickCapsuleCollision->SetCapsuleHalfHeight(51.205631f);
	 HurricaneKickCapsuleCollision->SetCapsuleRadius(33.699913f);
	 
	 HurricaneKickCapsuleCollision->SetGenerateOverlapEvents(true);
	 HurricaneKickCapsuleCollision->CanCharacterStepUpOn = ECB_No;
	 
	 HurricaneKickCapsuleCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	 HurricaneKickCapsuleCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	 
	 HurricaneKickCapsuleCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	 HurricaneKickCapsuleCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	 
	 HurricaneKickCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	 HurricaneKickCapsuleCollision->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	 HurricaneKickCapsuleCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	 HurricaneKickCapsuleCollision->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	 HurricaneKickCapsuleCollision->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	 HurricaneKickCapsuleCollision->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);
	 
	 HitAreaCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("HIT_AREA_CAPSULE"));
	 HitAreaCollision->SetupAttachment(GetMesh(), TEXT("Hips"));
	 
	 HitAreaCollision->SetRelativeLocationAndRotation(FVector(0.0f, 8.351363f, 4.132733f), FRotator(0.0f, 0.0f, -90.0f));
	 HitAreaCollision->SetCapsuleHalfHeight(95.305992f);
	 HitAreaCollision->SetCapsuleRadius(55.163376f);
	 
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
	    
	 static ConstructorHelpers::FClassFinder<UAnim_Monster003C> ZOMBIE_ANIM_CLASS(
		 TEXT("AnimBlueprint'/Game/Blueprints/Monster/Monster003/Monster003AnimC/Anim_Monster003ForC.Anim_Monster003ForC_C'"));
	 if (ZOMBIE_ANIM_CLASS.Succeeded()) ZombieAnimClass = ZOMBIE_ANIM_CLASS.Class;

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_HK(
		 TEXT("AnimMontage'/Game/Blueprints/Monster/Monster003/Monster003Anim/Zombie_HurricaneKick.Zombie_HurricaneKick'"));

	 if (M_HK.Succeeded()) {
		 Montage_HurricaneKick = M_HK.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_K(
		 TEXT("AnimMontage'/Game/Blueprints/Monster/Monster003/Monster003Anim/Zombie_Kick.Zombie_Kick'"));

	 if (M_K.Succeeded()) {
		 Montage_Kick = M_K.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_D(
		 TEXT("AnimMontage'/Game/Blueprints/Monster/Monster003/Monster003Anim/Zombie_Death.Zombie_Death'"));

	 if (M_D.Succeeded()) {
		 Montage_Death = M_D.Object;
	 }

	 if (IsValid(GetMesh()->SkeletalMesh)) {
		 GetMesh()->SetAnimInstanceClass(ZombieAnimClass);
	 }

	    MonsterTargetRotation = FRotator(0.0f, 0.0f, 0.0f);
	    State = MONSTERENUM::MON_IDLE;
	    DistanceToPlayer = 0.0f;
	    MonsterCurrentRotation = FRotator(0.0f, 0.0f, 0.0f);
	    IsHurricaneKickFunctionPlay = false;
	    RandomInt = 0;
	    RandomDirectionIsLoading = false;
	    IsKick = false;
	    RandomInt2 = 0;
	    HP = 50.0f;
	    IsAlive = true;
	    IsHurricaneKick = false;
	    SaveState = MONSTERENUM::MON_IDLE;
	    IsSaveStateUseAble = false;
	    DeathCheckAble = false;
	  
		GetCapsuleComponent()->ComponentTags.Add("Monster");
	    KickCapsuleCollision->ComponentTags.Add("NoAttackMode");
	    HurricaneKickCapsuleCollision->ComponentTags.Add("NoAttackMode");
	   
	   BodyCapsuleCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster003C::BodyCapsuleBeginOverlap);
	   BodyCapsuleCollision->OnComponentEndOverlap.AddDynamic(this, &AMonster003C::BodyCapsuleEndOverlap);
	   KickCapsuleCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster003C::KickCapsuleBeginOverlap);
	   HurricaneKickCapsuleCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster003C::HurricaneKickCapsuleBeginOverlap);
	   HitAreaCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster003C::HitAreaCapsuleBeginOverlap);
	   BulletSensorCollision->OnComponentBeginOverlap.AddDynamic(this, &AMonster003C::BulletSensorBeginOverlap);
}

// Called when the game starts or when spawned
void AMonster003C::BeginPlay()
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
void AMonster003C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	 if (HP > 0.0f) {
	 	if (Player->GetCapsuleComponent()->ComponentHasTag("DeathPlayer")) {
	 		if (DeathCheckAble) {
	 			IsKick = false;
	 			StopAnimMontage(Montage_Kick);
	 			KickCapsuleCollision->ComponentTags[0] = "NoAttackMode";
	 			HurricaneKickCapsuleCollision->ComponentTags[0] = "NoAttackMode";
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
	 				GetWorldTimerManager().SetTimer(CountdownTimerHandle_RandomDirection, this, &AMonster003C::RandomDirection, 2.0f, false);
	 				RandomDirectionIsLoading = true;
	 			}
	 			Sequence000(DeltaTime);
	 		}
	 		else if (State == MONSTERENUM::MON_FOLLOW) {
	 			if (!IsKick) {
	 				StopAnimMontage(Montage_Kick);
	 				CheckDirection();
	 
	 				if (!IsHurricaneKickFunctionPlay) {
	 					GetWorldTimerManager().SetTimer(CountdownTimerHandle_RandomHurricaneKick, this, &AMonster003C::RandomHurricaneKick, 2.0f, false);
	 					IsHurricaneKickFunctionPlay = true;
	 				}
	 
	 				Sequence000(DeltaTime);
	 				Sequence001();
	 			}
	 		}
	 
	 		else if (State == MONSTERENUM::MON_ATTACK) {
	 			if (IsHurricaneKick) CheckDirection();
	 			else {
	 				if (IsKick) return;
	 				else {
	 					PlayAnimMontage(Montage_Kick, 1.0f);
	 					IsKick = true;
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
	 		KickNoAttackMode();
	 		HurricaneKickNoAttackMode();
	 		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	 		PlayAnimMontage(Montage_Death, 1.0f);
	 	}
	 }
}

// Called to bind functionality to input
void AMonster003C::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMonster003C::Sequence000(float DDD)
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

void AMonster003C::Sequence001()
{
	 if (IsHurricaneKick) {
	 	GetCharacterMovement()->MaxWalkSpeed = 2000.0f;
	 	AddMovementInput(GetActorForwardVector(), 1.0f, false);
	 }
	 else {
	 	GetCharacterMovement()->MaxWalkSpeed = 1000.0f;
	 	if (!IsKick) AddMovementInput(GetActorForwardVector(), 1.0f, false);
	 }
}

void AMonster003C::CheckDistance()
{
	 if (HP < 50.0f) State = MONSTERENUM::MON_FOLLOW;
	 else {
	 	DistanceToPlayer = (Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation() - GetActorLocation()).Size();
	 	if (DistanceToPlayer <= 1500.0f && State == MONSTERENUM::MON_IDLE) State = MONSTERENUM::MON_FOLLOW;
	 
	 }
}

void AMonster003C::CheckDirection()
{
	 MonsterTargetRotation = (FVector(
	 	(((Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation()) - GetActorLocation()).GetSafeNormal()).X,
	 	(((Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->GetActorLocation()) - GetActorLocation()).GetSafeNormal()).Y, 0.0f)).Rotation();
	 
	 if (MonsterTargetRotation.Yaw < 0.0f) MonsterTargetRotation.Yaw += 360.0f;
}

void AMonster003C::RandomDirection()
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

void AMonster003C::RandomHurricaneKick()
{
	 if (State == MONSTERENUM::MON_FOLLOW) {
	 	if (IsAlive && !IsKick && !IsHurricaneKick) {
	 		RandomInt2 = FMath::RandRange(0, 3);
	 		if (RandomInt2 == 0) {
	 			IsHurricaneKick = true;
	 			PlayAnimMontage(Montage_HurricaneKick, 1.0f);
	 			return;
	 		}
	 	}
	 }
	 
	 IsHurricaneKickFunctionPlay = false;
}

void AMonster003C::KickStart()
{
	 KickCapsuleCollision->ComponentTags[0] = "AttackMode";
}

void AMonster003C::KickEnd()
{
	 IsKick = false;
}

void AMonster003C::KickNoAttackMode()
{
	KickCapsuleCollision->ComponentTags[0] = "NoAttackMode";
}

void AMonster003C::HurricaneKickAttackMode()
{
	 HurricaneKickCapsuleCollision->ComponentTags[0] = "AttackMode";
}

void AMonster003C::HurricaneKickNoAttackMode()
{
	HurricaneKickCapsuleCollision->ComponentTags[0] = "NoAttackMode";
}

void AMonster003C::SetHurricaneKickFalse()
{
 	IsHurricaneKick = false;
 	IsKick = false;
 	IsHurricaneKickFunctionPlay = false;
 	HurricaneKickNoAttackMode();
}

void AMonster003C::Disappear()
{
	 Destroy();
}

void AMonster003C::BodyCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
 	if (IsValid(OtherActor)) {
 		if (OtherComp->ComponentHasTag("Player")) State = MONSTERENUM::MON_ATTACK;
 	}
}

void AMonster003C::BodyCapsuleEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
 	if (IsValid(OtherActor)) {
 		if (OtherComp->ComponentHasTag("Player")) State = MONSTERENUM::MON_FOLLOW;
 	}
}

void AMonster003C::KickCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) {

		if (KickCapsuleCollision->ComponentHasTag("AttackMode")) {
			Player->MinusHP(13.0f);
			KickNoAttackMode();
			if (Player->IsReloadMode) {
				Player->StopAnimMontage(Player->Montage_Reload);
				Player->ReloadModeCancel();
			}
		}
	}
}

void AMonster003C::HurricaneKickCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Player")) {

		if (HurricaneKickCapsuleCollision->ComponentHasTag("AttackMode")) {
			Player->MinusHP(8.0f);
			HurricaneKickNoAttackMode();
			if (Player->IsReloadMode) {
				Player->StopAnimMontage(Player->Montage_Reload);
				Player->ReloadModeCancel();
			}
		}
	}
}

void AMonster003C::HitAreaCapsuleBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) {
		class ABulletC * Bu = Cast<ABulletC>(OtherActor);
		HP -= Bu->BulletDamage;
		Bu->BulletExplosionDestroy();
		if (HP < 0.0f) HP = 0.0f;
	}
}

void AMonster003C::BulletSensorBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (State == MONSTERENUM::MON_IDLE) {
		if (OtherActor->ActorHasTag("Bullet") && OtherComp->ComponentHasTag("WeaponArea")) State = MONSTERENUM::MON_FOLLOW;

	}
}
