// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Monster/MonsterEnumC.h"
#include "PlayerCharacter/MyPlayerCharacterC.h"
#include "Anim_BossMonsterC.h"
#include "BossEffectC.h"
#include "FBC.h"
#include "FireFromGroundC.h"
#include "FlameAreaC.h"
#include "MyAutoMaticDoorC_BossRoom002.h"
#include "BossMonsterC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API ABossMonsterC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABossMonsterC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere)
		class UParticleSystem * UPS;

	UPROPERTY(VisibleAnywhere)
		class UParticleSystemComponent * UPSC[8];

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * HitAreaCollision;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * FireCollision;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * StopEnterCheckCollision;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * StopExitCheckCollision;

	UPROPERTY(VisibleAnywhere)
		class UPointLightComponent * PointLight;

private:
	UPROPERTY()
		bool IsSit;

	UPROPERTY()
		bool IsStandUpMontagePlay;

	UPROPERTY()
		FRotator MonsterTargetRotation;

	UPROPERTY()
		FRotator MonsterCurrentRotation;

	UPROPERTY()
		MONSTERENUM State;

	UPROPERTY()
		bool StandUpOnlyOne;

	UPROPERTY()
		class AMyPlayerCharacterC * Player;

	UPROPERTY()
		class ABossEffectC * BossEffect;

	UPROPERTY()
		float HP;

	UPROPERTY()
		bool IsDead;

	UPROPERTY()
		class AMyAutoMaticDoorC_BossRoom002 * AutoDoor;

	UPROPERTY()
		bool OnlyOne;

	UPROPERTY()
		bool IsAlive;

	UPROPERTY()
		bool IsStop;

	UPROPERTY()
		bool IsFireBall;

	UPROPERTY()
		bool IsDirectionCheck;

	UPROPERTY()
		bool IsAttackModeFunctionCheckStart;

	UPROPERTY()
		bool AttackCheckOnlyOne;

	UPROPERTY()
		bool DeathCheckAble;

	UPROPERTY()
		bool IsSaveStateUseAble;

	UPROPERTY()
		int32 AttackRandomInt;

	UPROPERTY()
		int32 FlameGroundCount;

	UPROPERTY()
		MONSTERENUM SaveState;

private:
	UPROPERTY()
		FTimerHandle CountdownTimerHandle_SetAttackMode;

		UPROPERTY()
			FTimerHandle CountdownTimerHandle_FlameDamage;

private:
	UPROPERTY()
		TSubclassOf<class UAnim_BossMonsterC> BossAnimClass;

	UPROPERTY()
		UAnimMontage * Montage_Death;

	UPROPERTY()
		UAnimMontage * Montage_FireBall;

	UPROPERTY()
		UAnimMontage * Montage_Howling;

	UPROPERTY()
		UAnimMontage * Montage_Roar;

	UPROPERTY()
		UAnimMontage * Montage_Sit;

	UPROPERTY()
		UAnimMontage * Montage_StandUp;
	
private:
	void Sequence000(float DDD);
	void Sequence001();
	void CheckDirection(); 
	void BossEffectSpawn();
	void FlameSetUp();
	void FlameSetOff();
	void FlameDamage();
	void FireBallStart();
	void SetAttackMode();
	void FireGroundStart();
	void FlameAreaSetStart();

public:
	void StandUpOnlyOneFalse(); 
	void MonsterDisappear(); 
	void FireBall(); 
	void AttackEnd(); 
	void FireGroundSpawn(); 
	void FlameAreaSpawn(); 
	void MonsterEnumIsNowFollow();

private:
	UFUNCTION()
		void HitAreaCapsuleBeginOverlap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);

			UFUNCTION()
				void FireBoxBeginOverlap(
					UPrimitiveComponent* OverlappedComponent,
					AActor* OtherActor,
					UPrimitiveComponent* OtherComp,
					int32 OtherBodyIndex,
					bool bFromSweep,
					const FHitResult & SweepResult);

			UFUNCTION()
				void FireBoxEndOverlap(
					UPrimitiveComponent* OverlappedComponent,
					AActor* OtherActor,
					UPrimitiveComponent* OtherComp,
					int32 OtherBodyIndex);

			UFUNCTION()
				void StopExitCheckCollisionEndOverlap(
					UPrimitiveComponent* OverlappedComponent,
					AActor* OtherActor,
					UPrimitiveComponent* OtherComp,
					int32 OtherBodyIndex
				    );

			UFUNCTION()
				void StopEnterCheckCollisionBeginOverlap(
					UPrimitiveComponent* OverlappedComponent,
					AActor* OtherActor,
					UPrimitiveComponent* OtherComp,
					int32 OtherBodyIndex,
					bool bFromSweep,
					const FHitResult & SweepResult);
};
