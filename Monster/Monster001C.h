// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterEnumC.h"
#include "PlayerCharacter/MyPlayerCharacterC.h"
#include "Anim_Monster001C.h"
#include "Monster001C.generated.h"

UCLASS()
class UE_BPPRACTICE01_API AMonster001C : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonster001C();

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
		class UCapsuleComponent * BodyCapsuleCollision;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * SwordCapsuleCollision;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * RightCapsuleCollision;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * LeftCapsuleCollision;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * HitAreaCollision;

	UPROPERTY(VisibleAnywhere)
		class USphereComponent * BulletSensorCollision;

private:
	UPROPERTY()
		FRotator MonsterTargetRotation;

	UPROPERTY()
		MONSTERENUM State;

	UPROPERTY()
		float DistanceToPlayer;

	UPROPERTY()
		FRotator MonsterCurrentRotation;

	UPROPERTY()
		bool IsSpinAttack;

	UPROPERTY()
		uint32  RandomInt;

	UPROPERTY()
		bool RandomDirectionIsLoading;

	UPROPERTY()
		bool IsPunch;

	UPROPERTY()
		uint32 RandomInt2;

	UPROPERTY()
		float HP;

	UPROPERTY()
		bool IsAlive;

	UPROPERTY()
		class AMyPlayerCharacterC * Player;

	UPROPERTY()
		bool IsSpinAttackFunctionPlay;

	UPROPERTY()
		MONSTERENUM SaveState;

	UPROPERTY()
		bool IsSaveStateUseAble;

	UPROPERTY()
		bool DeathCheckAble;

private:
	UPROPERTY()
		FTimerHandle CountdownTimerHandle_RandomDirection;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle_RandomSpinAttack;

private:
	UPROPERTY()
		TSubclassOf<class UAnim_Monster001C> MutantAnimClass;

	UPROPERTY()
		UAnimMontage * Montage_SpinAttack;

	UPROPERTY()
		UAnimMontage * Montage_Punch;

	UPROPERTY()
		UAnimMontage * Montage_Death;

private:
	void Sequence000(float DDD);
	void Sequence001();
	void CheckDistance();
	void CheckDirection();
	void RandomDirection();
	void RandomSpinAttack();

public:
	void SlashEnd();
	void PunchStart();
	void PunchEnd();
	void SlashStart();
	void SlashNoAttackMode();
	void Disappear();
	void PunchNoAttackMode();

private:
	UFUNCTION()
	void BodyCapsuleBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult & SweepResult);

	UFUNCTION()
	void BodyCapsuleEndOverlap(
		    UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	UFUNCTION()
	void SwordCapsuleBeginOverlap(
		    UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);

	UFUNCTION()
	void RightCapsuleBeginOverlap(
	        UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);

	UFUNCTION()
	void LeftCapsuleBeginOverlap(
		    UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);

	UFUNCTION()
	void HitAreaCapsuleBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult & SweepResult);

	UFUNCTION()
	void BulletSensorBeginOverlap(
		    UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);
};
