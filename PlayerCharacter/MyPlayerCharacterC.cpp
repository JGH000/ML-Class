// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerCharacterC.h"
#include "PlayerCharacter/PlayerAnimBase.h"
#include "Widget/Widget001C.h"
#include "Engine.h"

// Sets default values
AMyPlayerCharacterC::AMyPlayerCharacterC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCapsuleHalfHeight(88.0f);
	GetCapsuleComponent()->SetCapsuleRadius(34.0f);
	GetCapsuleComponent()->ComponentTags.Add("Player");

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> PLAYER_BODY(
	TEXT("SkeletalMesh'/Game/ParagonRevenant/Characters/Heroes/Revenant/Skins/RavenQuill/Meshes/Revenant_RavenQuill.Revenant_RavenQuill'"));

	if (PLAYER_BODY.Succeeded()) {
		GetMesh()->SetSkeletalMesh(PLAYER_BODY.Object);
		GetMesh()->SetRelativeLocationAndRotation(
			FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0, 0.0f));
		GetMesh()->SetRelativeScale3D(FVector(0.8f, 0.8f, 0.8f));
	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRING_ARM"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 90.0f));
	SpringArm->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = true;
	SpringArm->bInheritRoll = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	Camera->SetupAttachment(SpringArm);

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("POINT_LIGHT"));

	PointLight->SetupAttachment(GetMesh());
	PointLight->SetRelativeLocation(FVector(0.0f, 0.0f, 127.0f));
	PointLight->SetIntensity(2500.0f);

	PointLight->SetLightColor(FLinearColor(1.0f, 0.527115f, 1.0f), true);

	PointLight->SetAttenuationRadius(511.387878f);
	PointLight->SetCastShadows(false);

	MonsterRecognitionCensor = CreateDefaultSubobject<UBoxComponent>(TEXT("MONSTER_CENSOR"));
	MonsterRecognitionCensor->SetupAttachment(GetCapsuleComponent());

	MonsterRecognitionCensor->SetRelativeLocationAndRotation(FVector(-756.0f, 0.0f, -66.0f), FRotator(0.0f, 0.0f, 0.0f));
	MonsterRecognitionCensor->SetBoxExtent(FVector(500.0f, 750.0f, 22.0f));

	MonsterRecognitionCensor->SetGenerateOverlapEvents(true);
	MonsterRecognitionCensor->CanCharacterStepUpOn = ECB_No;

	MonsterRecognitionCensor->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MonsterRecognitionCensor->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

	MonsterRecognitionCensor->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	MonsterRecognitionCensor->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	MonsterRecognitionCensor->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	MonsterRecognitionCensor->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	MonsterRecognitionCensor->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	MonsterRecognitionCensor->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	MonsterRecognitionCensor->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	MonsterRecognitionCensor->SetCollisionResponseToChannel(ECC_Destructible, ECR_Overlap);

	NullItemSlot.TheNumberOfItem = 0;
	NullItemSlot.ItemName = "Null";
	NullItemSlot.ItemCode = 0;
	
	ItemSlot.Init(NullItemSlot, 4);

	// Tags.Add(FName(TEXT("Player")));

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_J_AM(
	 	TEXT("AnimMontage'/Game/Blueprints/CharaAnim/Montage_Jump_AttackMode.Montage_Jump_AttackMode'"));

	 if (M_J_AM.Succeeded()) {
	 	Montage_Jump_AttackMode = M_J_AM.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_J_NAM(
		 TEXT("AnimMontage'/Game/Blueprints/CharaAnim/Montage_Jump_NoAttackMode.Montage_Jump_NoAttackMode'"));

	 if (M_J_NAM.Succeeded()) {
		 Montage_Jump_NoAttackMode = M_J_NAM.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_JE_AM(
		 TEXT("AnimMontage'/Game/Blueprints/CharaAnim/Montage_JumpEnd_AttackMode.Montage_JumpEnd_AttackMode'"));

	 if (M_JE_AM.Succeeded()) {
		 Montage_JumpEnd_AttackMode = M_JE_AM.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_JE_NAM(
		 TEXT("AnimMontage'/Game/Blueprints/CharaAnim/Montage_JumpEnd_NoAttackMode.Montage_JumpEnd_NoAttackMode'"));

	 if (M_JE_NAM.Succeeded()) {
		 Montage_JumpEnd_NoAttackMode = M_JE_NAM.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_R(
		 TEXT("AnimMontage'/Game/Blueprints/CharaAnim/Montage_Rebirth.Montage_Rebirth'"));

	 if (M_R.Succeeded()) {
		 Montage_Rebirth = M_R.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_Re(
		 TEXT("AnimMontage'/Game/Blueprints/CharaAnim/Montage_Reload.Montage_Reload'"));

	 if (M_Re.Succeeded()) {
		 Montage_Reload = M_Re.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_CAM(
		 TEXT("AnimMontage'/Game/Blueprints/CharaAnim/Montage_ChangeAttackMode.Montage_ChangeAttackMode'"));

	 if (M_CAM.Succeeded()) {
		 Montage_ChangeAttackMode = M_CAM.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_CAM2(
		 TEXT("AnimMontage'/Game/Blueprints/CharaAnim/Montage_ChangeAttackMode_2.Montage_ChangeAttackMode_2'"));

	 if (M_CAM2.Succeeded()) {
		 Montage_ChangeAttackMode_2 = M_CAM2.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_D(
		 TEXT("AnimMontage'/Game/Blueprints/CharaAnim/Montage_Death.Montage_Death'"));

	 if (M_D.Succeeded()) {
		 Montage_Death = M_D.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_F_AM(
		 TEXT("AnimMontage'/Game/Blueprints/CharaAnim/Montage_Falling_AttackMode.Montage_Falling_AttackMode'"));

	 if (M_F_AM.Succeeded()) {
		 Montage_Falling_AttackMode = M_F_AM.Object;
	 }

	 static ConstructorHelpers::FObjectFinder<UAnimMontage> M_F_NAM(
		 TEXT("AnimMontage'/Game/Blueprints/CharaAnim/Montage_Falling_NoAttackMode.Montage_Falling_NoAttackMode'"));

	 if (M_F_NAM.Succeeded()) {
		 Montage_Falling_NoAttackMode = M_F_NAM.Object;
	 }

	 static ConstructorHelpers::FClassFinder<UPlayerAnimBase> PLAYER_ANIM_CLASS(
	 	TEXT("AnimBlueprint'/Game/Anim_C/Paragon_Anim_C.Paragon_Anim_C_C'"));
	 if (PLAYER_ANIM_CLASS.Succeeded()) PlayerAnimClass = PLAYER_ANIM_CLASS.Class;
	 
	 // 그 뭐시기냐... UserWidget 넣을 때 필요한 부분
	 // static ConstructorHelpers::FClassFinder<UItemSlotDisplayBase> ITEM_SLOT_WIDGET(TEXT("WidgetBlueprint'/Game/HUD/WidgetBP_ItemSlot.WidgetBP_ItemSlot_C'"));
	 // if (ITEM_SLOT_WIDGET.Succeeded()) ItemSlotWidget = ITEM_SLOT_WIDGET.Class;

	 // if (ItemSlotWidget != nullptr) {
	//	  ItemSlotWidgetInstance = CreateWidget<UItemSlotDisplayBase>(GetWorld(), ItemSlotWidget);
	//	  ItemSlotWidgetInstance->AddToViewport();
	 // }

	  if (IsValid(GetMesh()->SkeletalMesh)) {
	  	GetMesh()->SetAnimInstanceClass(PlayerAnimClass);
	  }

	 GetCharacterMovement()->JumpZVelocity = 800.0f;
	 GetCharacterMovement()->GravityScale = 2.5f;
	 GetCharacterMovement()->MaxWalkSpeed = 300.0f;

	JumpMaxCount = 1;
	JumpCurrentCount = 0;
	VerticalInt = 0;
	HorizontalInt = 0;
	CharacterLookDirection = "N";
	PreviousCharacterLookDirection = "N";
	IsRunning = false;
	IsAlive = true;
	PitchCameraVelocity = 1.5f;
	JumpFloat = 1000.0f;
	IsShotable_Rotate = false;
	IsCombatMode = false;
	IsChanging = false;
	IsMoveAble = true;
	IsJumping = false;
	IsShotButtonPressed = false;
	BattleFootDirection = "N";
	IsReloadMode = false;
	IsShotable = true;
	BulletFull = 100;
	Bullet = BulletFull;
	MKS = 300.0f;
	MKS_RUN = 800.0f;
	IsRebirthing = false;
	IsFalling = false;
	HP = 100.0f;
	IsNoDamageMode = false;
	IsRebirthAble = false;
	ItemSlot[0].ItemName = "Null";
	ItemSlot[1].ItemName = "Null";
	ItemSlot[2].ItemName = "Null";
	ItemSlot[3].ItemName = "Null";
	NullItemSlot.ItemName = "Null";
	IsNoDamageTimerStart = false;
	NoDamageModeTimer = 0.0f;
	IsSuperBulletMode = false;
	IsSuperBulletTimerStart = false;
	IsSuperBulletModeTimer = 0.0f;
	IsTest003Mode = false;
	IsTest003TimerStart = false;
	IsTest003Timer = 0.0f;
	RunGauge = 100.0f;
	IsRunGaugeMinusStart = false;
	IsRunGaugePlusStart = false;

	MonsterRecognitionCount = 0;
	IsMonsterRecognized = false;

	static ConstructorHelpers::FClassFinder<UWidget001C> ITEM_SLOT_WIDGET(TEXT("WidgetBlueprint'/Game/TestWidget001_C.TestWidget001_C_C'"));
	if (ITEM_SLOT_WIDGET.Succeeded()) CharacterWidget = ITEM_SLOT_WIDGET.Class;

	MonsterRecognitionCensor->OnComponentBeginOverlap.AddDynamic(this, &AMyPlayerCharacterC::MonsterRecognitionCensorBeginOverlap);
	MonsterRecognitionCensor->OnComponentEndOverlap.AddDynamic(this, &AMyPlayerCharacterC::MonsterRecognitionCensorEndOverlap);
}

// Called when the game starts or when spawned
void AMyPlayerCharacterC::BeginPlay()
{
	Super::BeginPlay();
	
	if (CharacterWidget != nullptr) {
		ItemSlotWidgetInstance = CreateWidget<UWidget001C>(GetWorld(), CharacterWidget);
		ItemSlotWidgetInstance->AddToViewport();
	}
}

// Called every frame
void AMyPlayerCharacterC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Sequence000();
	Sequence001();
	Sequence002();
	Sequence003();
	Sequence004();
	Sequence005();
	Sequence006();
	Sequence007();

	// GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, CharacterLookDirection);
	// GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, PreviousCharacterLookDirection);
	// GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, FString::SanitizeFloat(HorizontalInt));
	// GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::SanitizeFloat(VerticalInt));
}

// Called to bind functionality to input
void AMyPlayerCharacterC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("InputHorizontal"), this, &AMyPlayerCharacterC::InputHorizontal);
	PlayerInputComponent->BindAxis(TEXT("InputVertical"), this, &AMyPlayerCharacterC::InputVertical);
	PlayerInputComponent->BindAxis(TEXT("MouseX"), this, &AMyPlayerCharacterC::MouseX);
	PlayerInputComponent->BindAxis(TEXT("MouseY"), this, &AMyPlayerCharacterC::MouseY);
	PlayerInputComponent->BindAxis(TEXT("ShotShot"), this, &AMyPlayerCharacterC::ShotShot);

	PlayerInputComponent->BindAction(TEXT("InputRun"), EInputEvent::IE_Pressed ,this, &AMyPlayerCharacterC::InputRun_Pressed);
	PlayerInputComponent->BindAction(TEXT("InputRun"), EInputEvent::IE_Released, this, &AMyPlayerCharacterC::InputRun_Released);

	PlayerInputComponent->BindAction(TEXT("JumpKey"), EInputEvent::IE_Pressed ,this, &AMyPlayerCharacterC::JumpKey);
	PlayerInputComponent->BindAction(TEXT("ShotKey"), EInputEvent::IE_Pressed ,this, &AMyPlayerCharacterC::ShotKey);
	PlayerInputComponent->BindAction(TEXT("ChangeKey"), EInputEvent::IE_Pressed ,this, &AMyPlayerCharacterC::ChangeKey);
	PlayerInputComponent->BindAction(TEXT("ReloadKey"), EInputEvent::IE_Pressed ,this, &AMyPlayerCharacterC::ReloadKey);
	PlayerInputComponent->BindAction(TEXT("RebirthKey"), EInputEvent::IE_Pressed ,this, &AMyPlayerCharacterC::RebirthKey);
	PlayerInputComponent->BindAction(TEXT("ItemKey001"), EInputEvent::IE_Pressed ,this, &AMyPlayerCharacterC::ItemKey001);
	PlayerInputComponent->BindAction(TEXT("ItemKey002"), EInputEvent::IE_Pressed ,this, &AMyPlayerCharacterC::ItemKey002);
	PlayerInputComponent->BindAction(TEXT("ItemKey003"), EInputEvent::IE_Pressed ,this, &AMyPlayerCharacterC::ItemKey003);
	PlayerInputComponent->BindAction(TEXT("ItemKey004"), EInputEvent::IE_Pressed ,this, &AMyPlayerCharacterC::ItemKey004);
}

   void AMyPlayerCharacterC::Landed(const FHitResult & Hit)
   {
	   IsJumping = false;
	   IsFalling = false;
	   
	   if (IsAlive) {
		   if (IsCombatMode) PlayAnimMontage(Montage_JumpEnd_AttackMode, 1.0f);
		   else PlayAnimMontage(Montage_JumpEnd_NoAttackMode, 1.0f);
	   }
   }


void AMyPlayerCharacterC::ChangeCombatMode()
{
	if (IsCombatMode) IsCombatMode = false;
	else IsCombatMode = true;
}

void AMyPlayerCharacterC::ChangeMontageEnd()
{
	IsChanging = false;
	IsMoveAble = true;
}

void AMyPlayerCharacterC::BulletShot()
{


	GetWorld()->SpawnActor<ABulletC>(ABulletC::StaticClass(), FTransform(
		GetMesh()->GetSocketRotation("BulletStart"), GetMesh()->GetSocketLocation("BulletStart"), FVector(1.0f, 0.1f, 0.1f)));

	if (IsSuperBulletMode) {
		GetWorld()->SpawnActor<ABulletC>(ABulletC::StaticClass(), FTransform(
			GetMesh()->GetSocketRotation("SubBulletStart_1"), GetMesh()->GetSocketLocation("SubBulletStart_1"), FVector(1.0f, 0.1f, 0.1f)));
		GetWorld()->SpawnActor<ABulletC>(ABulletC::StaticClass(), FTransform(
			GetMesh()->GetSocketRotation("SubBulletStart_2"), GetMesh()->GetSocketLocation("SubBulletStart_2"), FVector(1.0f, 0.1f, 0.1f)));
		GetWorld()->SpawnActor<ABulletC>(ABulletC::StaticClass(), FTransform(
			GetMesh()->GetSocketRotation("SubBulletStart_3"), GetMesh()->GetSocketLocation("SubBulletStart_3"), FVector(1.0f, 0.1f, 0.1f)));
		GetWorld()->SpawnActor<ABulletC>(ABulletC::StaticClass(), FTransform(
			GetMesh()->GetSocketRotation("SubBulletStart_4"), GetMesh()->GetSocketLocation("SubBulletStart_4"), FVector(1.0f, 0.1f, 0.1f)));
	}
	else { Bullet -= 1; }
	
}

void AMyPlayerCharacterC::BattleModeFootYaw()
{
	if (HorizontalInt == 1) {
		if (VerticalInt == 1) BattleFootDirection = "NE";
		else if (VerticalInt == -1) BattleFootDirection = "NW";
		else BattleFootDirection = "N";
	}
	else if (HorizontalInt == -1) {
		if (VerticalInt == 1) BattleFootDirection = "SE";
		else if (VerticalInt == -1) BattleFootDirection = "SW";
		else BattleFootDirection = "S";
	} 
	else if (VerticalInt == 1) BattleFootDirection = "E";
	else if (VerticalInt == -1) BattleFootDirection = "W";
}

void AMyPlayerCharacterC::JumpShotable()
{
	if (IsShotable) {}
	else IsShotable = true;

	if (IsShotButtonPressed) IsShotButtonPressed = false;
}

void AMyPlayerCharacterC::ChangeReloadModeEnd()
{
	IsMoveAble = true;
	IsReloadMode = false;

	if (IsShotable) {}
	else IsShotable = true;

	Bullet = BulletFull;

	if (IsShotButtonPressed) IsShotButtonPressed = false;
}

void AMyPlayerCharacterC::Rebirth()
{
	IsAlive = true;
	IsShotable_Rotate = false;
	IsChanging = false;
	IsCombatMode = false;
	IsMoveAble = true;
	IsReloadMode = false;
	IsShotable = true;
	IsShotButtonPressed = false;

	HP = 100.0f;
	RunGauge = 100.0f;
	MKS = 400.0f;
	MKS_RUN = 800.0f;

	if (IsRunning) GetCharacterMovement()->MaxWalkSpeed = MKS_RUN;
	else           GetCharacterMovement()->MaxWalkSpeed = MKS;

	Bullet = BulletFull;

	GetCapsuleComponent()->ComponentTags[0] = "Player";
	IsRebirthing = false;
	IsNoDamageMode = true;

	PointLight->SetLightColor(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f) ,true);
}

void AMyPlayerCharacterC::ReloadModeCancel()
{
	IsMoveAble = true;
	IsReloadMode = false;

	if (IsShotable) {}
	else IsShotable = true;

	if (IsShotButtonPressed) IsShotButtonPressed = false;
}

void AMyPlayerCharacterC::MinusHP(float Damage)
{
	if (!IsNoDamageMode) {
		// GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, TEXT("UMBAERA!!!!!"));
		if ((HP - Damage) < 0.0f) HP = 0.0f;
		else HP = HP - Damage;
	}
}

void AMyPlayerCharacterC::NoDamageModeEnd()
{
	IsNoDamageMode = false;
	IsNoDamageTimerStart = false;
	PointLight->SetLightColor(FLinearColor(1.0f, 0.527115f, 1.0f, 1.0f), true);
}

void AMyPlayerCharacterC::LightOffAndRebirthAble()
{
	NoDamageModeEnd();
	FiveBulletModeEnd();
	PointLight->SetLightColor(FLinearColor(0.0f, 0.0f, 0.0f, 0.0f), true);
	GetCapsuleComponent()->ComponentTags[0] = "DeathPlayer";
	IsRebirthAble = true;
}

bool AMyPlayerCharacterC::UseItem(int32 ItemCode)
{
	if (ItemCode == 1001) {
		if (HP + 15.0f > 100.0f) HP = 100.0f;
		else HP = HP + 15.0f;
		return true;
	}
	else if (ItemCode == 1002) {
		IsNoDamageMode = true;
		IsNoDamageTimerStart = false;
		PointLight->SetLightColor(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), true);
		return true;
	}
	else if (ItemCode == 1003) {
		IsSuperBulletMode = true;
		IsSuperBulletTimerStart = false;
		Bullet = BulletFull;
		return true;
	}
	else if (ItemCode == 1004) {
		IsTest003Mode = true;
		IsTest003TimerStart = false;
		return true;
	}
	else return false;
}

void AMyPlayerCharacterC::FiveBulletModeEnd()
{
	IsSuperBulletMode = false;
	IsSuperBulletModeTimer = false;
}

void AMyPlayerCharacterC::Test003End()
{
	IsTest003Mode = false;
	IsTest003TimerStart = false;
}

void AMyPlayerCharacterC::RunGaugeMinus()
{
	IsRunGaugeMinusStart = false;
	RunGauge -= 0.75f;
}

void AMyPlayerCharacterC::RunGaugePlus()
{
	IsRunGaugePlusStart = false;
	RunGauge += 0.25f;
}

USpringArmComponent * AMyPlayerCharacterC::GetSpringArm()
{
	return SpringArm;
}

FRotator AMyPlayerCharacterC::SpringArmRotation()
{
	return SpringArm->GetComponentRotation();
}

void AMyPlayerCharacterC::Sequence000()
{
	if (IsCombatMode) {
		if (CharacterLookDirection != "N") PreviousCharacterLookDirection = CharacterLookDirection;
		else {}
		CharacterLookDirection = "N";
		BattleModeFootYaw();
	}
	else {
		if (HorizontalInt == 1) {
			if (VerticalInt == 1) {
				if (CharacterLookDirection != "NE") PreviousCharacterLookDirection = CharacterLookDirection;
				else {}
				CharacterLookDirection = "NE";
			}
			else if (VerticalInt == -1) {
				if (CharacterLookDirection != "NW") PreviousCharacterLookDirection = CharacterLookDirection;
				else {}
				CharacterLookDirection = "NW";
			}
			else {
				if (CharacterLookDirection != "N") PreviousCharacterLookDirection = CharacterLookDirection;
				else {}
				CharacterLookDirection = "N";
			}
		}
		else if (HorizontalInt == -1) {
			if (VerticalInt == 1) {
				if (CharacterLookDirection != "SE") PreviousCharacterLookDirection = CharacterLookDirection;
				else {}
				CharacterLookDirection = "SE";
			}
			else if (VerticalInt == -1) {
				if (CharacterLookDirection != "SW") PreviousCharacterLookDirection = CharacterLookDirection;
				else {}
				CharacterLookDirection = "SW";
			}
			else {
				if (CharacterLookDirection != "S") PreviousCharacterLookDirection = CharacterLookDirection;
				else {}
				CharacterLookDirection = "S";
			}
		}

		else if (VerticalInt == 1) {
			if (CharacterLookDirection != "E") PreviousCharacterLookDirection = CharacterLookDirection;
			else {}
			CharacterLookDirection = "E";
		}

		else if (VerticalInt == -1) {
			if (CharacterLookDirection != "W") PreviousCharacterLookDirection = CharacterLookDirection;
			else {}
			CharacterLookDirection = "W";
		}
	}
}

void AMyPlayerCharacterC::Sequence001()
{
	if (GetVelocity().Z < 0.0f && IsAlive && IsMoveAble && !IsJumping && !IsFalling) {
		IsFalling = false;
		if (IsCombatMode) PlayAnimMontage(Montage_Falling_AttackMode, 1.0f);
		else  PlayAnimMontage(Montage_Falling_NoAttackMode, 1.0f);
	}
}

void AMyPlayerCharacterC::Sequence002()
{
	if (HP <= 0.0f && IsAlive) {
		PlayAnimMontage(Montage_Death, 1.0f);
		IsAlive = false;
	}
}

void AMyPlayerCharacterC::Sequence003()
{
	if (IsAlive) {
		if (IsRunning) {
			if (FVector(GetVelocity().X, GetVelocity().Y, 0.0f).Size() == 0.0f) {
				if (RunGauge < 100.0f && !IsRunGaugePlusStart) {
					GetWorldTimerManager().SetTimer(CountdownTimerHandle_RunGaugePlus, this, &AMyPlayerCharacterC::RunGaugePlus, 0.005f, false);
					IsRunGaugePlusStart = true;
				}
			}
			else {
				if (RunGauge > 0.0f) {
					if (!IsRunGaugeMinusStart) {
						GetWorldTimerManager().SetTimer(CountdownTimerHandle_RunGaugeMinus, this, &AMyPlayerCharacterC::RunGaugeMinus, 0.005f, false);
						IsRunGaugeMinusStart = true;
					}
				}
				else {
					GetCharacterMovement()->MaxWalkSpeed = MKS;
				}
			}
		}
		else {
			if (RunGauge < 100.0f && !IsRunGaugePlusStart) {
				GetWorldTimerManager().SetTimer(CountdownTimerHandle_RunGaugePlus, this, &AMyPlayerCharacterC::RunGaugePlus, 0.005f, false);
				IsRunGaugePlusStart = true;
			}
		}
	}
	else {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle_RunGaugeMinus);
		IsRunGaugeMinusStart = false;
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle_RunGaugePlus);
		IsRunGaugePlusStart = false;
		RunGauge = 0.0f;
	}
}

void AMyPlayerCharacterC::Sequence004()
{
	if (IsNoDamageMode) {
		if (IsNoDamageTimerStart) {
			NoDamageModeTimer = GetWorldTimerManager().GetTimerRemaining(CountdownTimerHandle_NoDamageModeEnd);
		}
		else {
			GetWorldTimerManager().SetTimer(CountdownTimerHandle_NoDamageModeEnd, this, &AMyPlayerCharacterC::NoDamageModeEnd, 2.0f, false);
			IsNoDamageTimerStart = true;
		}
	}
}

void AMyPlayerCharacterC::Sequence005()
{
	if (IsSuperBulletMode) {
		if (IsSuperBulletTimerStart) {
			IsSuperBulletModeTimer = GetWorldTimerManager().GetTimerRemaining(CountdownTimerHandle_FiveBulletModeEnd);
		}
		else {
			GetWorldTimerManager().SetTimer(CountdownTimerHandle_FiveBulletModeEnd, this, &AMyPlayerCharacterC::FiveBulletModeEnd, 5.0f, false);
			IsSuperBulletTimerStart = true;
		}
	}
}

void AMyPlayerCharacterC::Sequence006()
{
	if (IsTest003Mode) {
		if (IsTest003TimerStart) {
			IsTest003Timer = GetWorldTimerManager().GetTimerRemaining(CountdownTimerHandle_Test003End);
		}
		else {
			GetWorldTimerManager().SetTimer(CountdownTimerHandle_Test003End, this, &AMyPlayerCharacterC::Test003End, 3.0f, false);
			IsTest003TimerStart = true;
		}
		
	}
}

void AMyPlayerCharacterC::Sequence007()
{
	if (MonsterRecognitionCount > 0) IsMonsterRecognized = true;
	else                             IsMonsterRecognized = false;
}

void AMyPlayerCharacterC::InputHorizontal(float NewAxisValue)
{
	if (IsAlive && IsMoveAble) {
		AddMovementInput(GetActorForwardVector(), NewAxisValue);
		if (NewAxisValue == 1.0f) HorizontalInt = 1;
		else if (NewAxisValue == -1.0f) HorizontalInt = -1;
		else HorizontalInt = 0;
	}
}

void AMyPlayerCharacterC::InputVertical(float NewAxisValue)
{
	if (IsAlive && IsMoveAble) {
		AddMovementInput(GetActorRightVector(), NewAxisValue);
		if (NewAxisValue == 1.0f) VerticalInt = 1;
		else if (NewAxisValue == -1.0f) VerticalInt = -1;
		else VerticalInt = 0;
	}
}

void AMyPlayerCharacterC::MouseX(float NewAxisValue)
{
	if (IsAlive) AddControllerYawInput(NewAxisValue * 0.25f);
}

void AMyPlayerCharacterC::MouseY(float NewAxisValue)
{
	if (IsAlive) {
		SpringArm->SetWorldRotation(FRotator(NewAxisValue * PitchCameraVelocity * 0.25f + SpringArm->GetComponentRotation().Pitch,0.0f, 0.0f));
		if (SpringArm->GetComponentRotation().Pitch >= 25.0f) SpringArm->SetWorldRotation(FRotator(25.0f, 0.0f, 0.0f));
		else if (SpringArm->GetComponentRotation().Pitch <= -40.0f) SpringArm->SetWorldRotation(FRotator(-40.0f, 0.0f, 0.0f));
	}
}

void AMyPlayerCharacterC::ShotShot(float NewAxisValue)
{
	if (IsAlive && NewAxisValue > 0.01f && IsCombatMode) {
		if (IsShotable_Rotate && IsShotable) {
			  if (Bullet > 0) {
				 if (!IsShotButtonPressed) {
					 GetWorldTimerManager().SetTimer(CountdownTimerHandle_BulletShot, this, &AMyPlayerCharacterC::BulletShot, 0.1f, true);
					 IsShotButtonPressed = true;
				 }
			 }
			 else GetWorldTimerManager().ClearTimer(CountdownTimerHandle_BulletShot);
		}
	}
	else {
	    GetWorldTimerManager().ClearTimer(CountdownTimerHandle_BulletShot);
		IsShotButtonPressed = false;
	}
}

void AMyPlayerCharacterC::InputRun_Pressed()
{
	IsRunning = true;

	if (RunGauge > 0.0f) GetCharacterMovement()->MaxWalkSpeed = MKS_RUN;
	else GetCharacterMovement()->MaxWalkSpeed = MKS;
}

void AMyPlayerCharacterC::InputRun_Released()
{
	IsRunning = false;
	GetCharacterMovement()->MaxWalkSpeed = MKS;
}
void AMyPlayerCharacterC::JumpKey()
{
	if (IsAlive && IsMoveAble && JumpCurrentCount < JumpMaxCount) {
		Jump();
		IsJumping = true;
		if (IsCombatMode) {
			GetWorldTimerManager().ClearTimer(CountdownTimerHandle_BulletShot);
			IsShotable = false;
			PlayAnimMontage(Montage_Jump_AttackMode, 1.0f);
		}
		else PlayAnimMontage(Montage_Jump_NoAttackMode, 1.0f);
	}
}

void AMyPlayerCharacterC::ShotKey()
{
}

void AMyPlayerCharacterC::ChangeKey()
{
	if (IsAlive && !IsChanging && !IsReloadMode && !IsJumping && !IsFalling) {
		IsMoveAble = false;
		IsChanging = true;
		if (IsCombatMode) {
			MKS = 300.0f;
			MKS_RUN = 800.0;
			if (IsRunning) GetCharacterMovement()->MaxWalkSpeed = MKS_RUN;
			else GetCharacterMovement()->MaxWalkSpeed = MKS;
			PlayAnimMontage(Montage_ChangeAttackMode_2, 1.0f);
		}
		else {
			MKS = 250.0f;
			MKS_RUN = 600.0;
			if (IsRunning) GetCharacterMovement()->MaxWalkSpeed = MKS_RUN;
			else GetCharacterMovement()->MaxWalkSpeed = MKS;
			PlayAnimMontage(Montage_ChangeAttackMode, 1.0f);
		}
	}
}

void AMyPlayerCharacterC::ReloadKey()
{
	if (IsAlive && IsMoveAble && !IsJumping && !IsFalling && !IsReloadMode) {
		if (IsCombatMode) GetWorldTimerManager().ClearTimer(CountdownTimerHandle_BulletShot);
		else {}

		IsMoveAble = false;
		IsShotable = false;
		IsReloadMode = true;
		PlayAnimMontage(Montage_Reload, 1.0f);
	}
}

void AMyPlayerCharacterC::RebirthKey()
{
	if (IsRebirthAble && !IsAlive && !IsRebirthing) {
		IsRebirthAble = false; 
		PlayAnimMontage(Montage_Rebirth, 1.0f);
		IsRebirthing = true;
	}
}

void AMyPlayerCharacterC::ItemKey001()
{
	if (IsAlive) {
		if (ItemSlot[0].TheNumberOfItem != 0) {
			if (UseItem(ItemSlot[0].ItemCode)) {
				ItemSlot[0].TheNumberOfItem -= 1;
				if (ItemSlot[0].TheNumberOfItem == 0) {
					ItemSlot[0] = NullItemSlot;
				}
			}
		}
	}
}

void AMyPlayerCharacterC::ItemKey002()
{
	if (IsAlive) {
		if (ItemSlot[1].TheNumberOfItem != 0) {
			if (UseItem(ItemSlot[1].ItemCode)) {
				ItemSlot[1].TheNumberOfItem -= 1;
				if (ItemSlot[1].TheNumberOfItem == 0) {
					ItemSlot[1] = NullItemSlot;
				}
			}
		}
	}
}

void AMyPlayerCharacterC::ItemKey003()
{
	if (IsAlive) {
		if (ItemSlot[2].TheNumberOfItem != 0) {
			if (UseItem(ItemSlot[2].ItemCode)) {
				ItemSlot[2].TheNumberOfItem -= 1;
				if (ItemSlot[2].TheNumberOfItem == 0) {
					ItemSlot[2] = NullItemSlot;
				}
			}
		}
	}
}

void AMyPlayerCharacterC::ItemKey004()
{
	if (IsAlive) {
		if (ItemSlot[3].TheNumberOfItem != 0) {
			if (UseItem(ItemSlot[3].ItemCode)) {
				ItemSlot[3].TheNumberOfItem -= 1;
				if (ItemSlot[3].TheNumberOfItem == 0) {
					ItemSlot[3] = NullItemSlot;
				}
			}
		}
	}
}

void AMyPlayerCharacterC::MonsterRecognitionCensorBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherComp->ComponentHasTag("Monster")) {
		MonsterRecognitionCount += 1;
	}
}

void AMyPlayerCharacterC::MonsterRecognitionCensorEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (OtherComp->ComponentHasTag("Monster")) {
		MonsterRecognitionCount -= 1;
	}
}


