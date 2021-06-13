// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Item/ItemStructC.h"
#include "BulletC.h"
#include "MyPlayerCharacterC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API AMyPlayerCharacterC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayerCharacterC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Landed(const FHitResult& Hit) override;

private:
	UPROPERTY(VisibleAnywhere)
		TSubclassOf<class UPlayerAnimBase> PlayerAnimClass;
	
	// > 아이템 슬롯 Widget 을 로드하여 참조할 변수
	// UPROPERTY()
	//	TSubclassOf<class UItemSlotDisplayBase> ItemSlotWidget;

    // > 아이템 슬롯 인스턴스를 참조할 변수
	//    UPROPERTY()
	//    	class UItemSlotDisplayBase * ItemSlotWidgetInstance;

	UPROPERTY(VisibleAnywhere)
		class UPointLightComponent * PointLight;

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent * Camera;

	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent * SpringArm;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * MonsterRecognitionCensor;

public:
	UPROPERTY()
		FString CharacterLookDirection;

	UPROPERTY()
		FString PreviousCharacterLookDirection;

	UPROPERTY()
		bool IsShotable_Rotate;

	UPROPERTY()
		FString BattleFootDirection;

	UPROPERTY()
		bool IsNoDamageTimerStart;

	UPROPERTY()
		bool IsSuperBulletMode;

	UPROPERTY()
		bool IsRebirthAble;

	UPROPERTY()
		bool IsTest003Mode;

	UPROPERTY()
		bool IsAlive;

	UPROPERTY()
		bool IsReloadMode;

	UPROPERTY()
		int32 Bullet;

	UPROPERTY()
		int32 BulletFull;

	UPROPERTY()
		float HP;

	UPROPERTY()
		float NoDamageModeTimer;

	UPROPERTY()
		float IsSuperBulletModeTimer;

	UPROPERTY()
		float IsTest003Timer;

	UPROPERTY()
		float RunGauge;

	UPROPERTY()
		TArray<FItemC> ItemSlot;

	UPROPERTY()
		bool IsMonsterRecognized;
private:
	UPROPERTY()
		int32 VerticalInt;

	UPROPERTY()
		int32 HorizontalInt;

	UPROPERTY()
		bool IsRunning;

	UPROPERTY()
		bool IsCombatMode;

	UPROPERTY()
		bool IsChanging;

	UPROPERTY()
		bool IsMoveAble;

	UPROPERTY()
		bool IsJumping;

	UPROPERTY()
		bool IsShotButtonPressed;

	UPROPERTY()
		bool IsShotable;

	UPROPERTY()
		bool IsRebirthing;

	UPROPERTY()
		bool IsFalling;

	UPROPERTY()
		bool IsNoDamageMode;

	UPROPERTY()
		bool IsSuperBulletTimerStart;

	UPROPERTY()
		bool IsTest003TimerStart;

	UPROPERTY()
		bool IsRunGaugeMinusStart;

	UPROPERTY()
		bool IsRunGaugePlusStart;

	UPROPERTY()
		float PitchCameraVelocity;

	UPROPERTY()
		float JumpFloat;

	UPROPERTY()
		float MKS;

	UPROPERTY()
		float MKS_RUN;

	UPROPERTY()
		FItemC NullItemSlot;

	UPROPERTY()
		int32 MonsterRecognitionCount;
public:
	UFUNCTION()
		void ChangeCombatMode();

	UFUNCTION()
		void ChangeMontageEnd();

	UFUNCTION()
		void JumpShotable();

	UFUNCTION()
		void ChangeReloadModeEnd();

	UFUNCTION()
		void Rebirth();

	UFUNCTION()
		void ReloadModeCancel();

	UFUNCTION()
		void MinusHP(float Damage);

	UFUNCTION()
		void LightOffAndRebirthAble();

	UFUNCTION()
		class USpringArmComponent * GetSpringArm();

	UFUNCTION()
		FRotator SpringArmRotation();

private:
	 UFUNCTION()
		 void BulletShot();

	 UFUNCTION()
		 void BattleModeFootYaw();

	UFUNCTION()
		 void NoDamageModeEnd();

	UFUNCTION()
		 bool UseItem(int32 ItemCode);

	 UFUNCTION()
		 void FiveBulletModeEnd();

	 UFUNCTION()
		 void Test003End();

	 UFUNCTION()
		 void RunGaugeMinus();

	 UFUNCTION()
		 void RunGaugePlus();

private:
	UPROPERTY()
		FTimerHandle CountdownTimerHandle_BulletShot;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle_NoDamageModeEnd;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle_FiveBulletModeEnd;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle_Test003End;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle_RunGaugeMinus;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle_RunGaugePlus;

public:
	UPROPERTY()
		UAnimMontage * Montage_Reload;

private:
	UPROPERTY()
		UAnimMontage * Montage_Jump_AttackMode;

	UPROPERTY()
		UAnimMontage * Montage_Jump_NoAttackMode;

	UPROPERTY()
		UAnimMontage * Montage_JumpEnd_AttackMode;

	UPROPERTY()
		UAnimMontage * Montage_JumpEnd_NoAttackMode;

	UPROPERTY()
		UAnimMontage * Montage_Rebirth;

	UPROPERTY()
		UAnimMontage * Montage_ChangeAttackMode;

	UPROPERTY()
		UAnimMontage * Montage_ChangeAttackMode_2;

	UPROPERTY()
		UAnimMontage * Montage_Death;

	UPROPERTY()
		UAnimMontage * Montage_Falling_AttackMode;

	UPROPERTY()
		UAnimMontage * Montage_Falling_NoAttackMode;

private:
	// > 아이템 슬롯 Widget 을 로드하여 참조할 변수
	UPROPERTY()
		TSubclassOf<class UWidget001C> CharacterWidget;

	// > 아이템 슬롯 인스턴스를 참조할 변수
	UPROPERTY()
		class UWidget001C * ItemSlotWidgetInstance;

	void Sequence000();
	void Sequence001();
	void Sequence002();
	void Sequence003();
	void Sequence004();
	void Sequence005();
	void Sequence006();
	void Sequence007();

	void InputHorizontal(float NewAxisValue);
	void InputVertical(float NewAxisValue);
	void MouseX(float NewAxisValue);
	void MouseY(float NewAxisValue);
	void ShotShot(float NewAxisValue);

	void InputRun_Pressed();
	void InputRun_Released();

	void JumpKey();
	void ShotKey();
	void ChangeKey();
	void ReloadKey();
	void RebirthKey();
	void ItemKey001();
	void ItemKey002();
	void ItemKey003();
	void ItemKey004();

private:
	UFUNCTION()
		void MonsterRecognitionCensorBeginOverlap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);

	UFUNCTION()
		void MonsterRecognitionCensorEndOverlap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);
};
