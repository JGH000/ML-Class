// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterEnumC.h"
#include "PlayerCharacter/MyPlayerCharacterC.h"
#include "Anim_Monster004C.h"
#include "Monster004C.generated.h"

UCLASS()
class UE_BPPRACTICE01_API AMonster004C : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonster004C();

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
		class UCapsuleComponent * LongSwordCapsuleCollision;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * BodyCapsuleCollision;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * HitAreaCollision;

	UPROPERTY(VisibleAnywhere)
		class USphereComponent * BulletSensorCollision;

private:
	UPROPERTY()
		class USkeletalMeshComponent * Sword;

private:
	UPROPERTY()
		MONSTERENUM State;

	UPROPERTY()
		float DistanceToPlayer;

	UPROPERTY()
		float HP;

	UPROPERTY()
		FRotator MonsterTargetRotation;

	UPROPERTY()
		FRotator MonsterCurrentRotation;

	UPROPERTY()
		bool IsLongSwordSlash;

	UPROPERTY()
		bool IsAlive;

	UPROPERTY()
		class AMyPlayerCharacterC * Player;

	UPROPERTY()
		MONSTERENUM SaveState;

	UPROPERTY()
		bool IsSaveStateUseAble;

	UPROPERTY()
		bool DeathCheckAble;

protected:
	UPROPERTY()
		TSubclassOf<class UAnim_Monster004C> VampireAnimClass;

	UPROPERTY()
		UAnimMontage * Montage_Slash;

	UPROPERTY()
		UAnimMontage * Montage_Death;

private:
	void Sequence000(float DDD);
	void Sequence001();
	void CheckDistance();
	void CheckDirection();

public:
	void LongSwordSlashStart();
	void LongSwordSlashEnd();
	void LongSwordSlashNoAttackMode();
	void Disappear();
	
private:
	UFUNCTION()
		void LongSwordCapsuleBeginOverlap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);

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
