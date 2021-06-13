// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterEnumC.h"
#include "PlayerCharacter/MyPlayerCharacterC.h"
#include "Anim_Monster002C.h"
#include "Monster002C.generated.h"

UCLASS()
class UE_BPPRACTICE01_API AMonster002C : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonster002C();

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
		class UBoxComponent * AxCollision;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * LeftCapsuleCollision;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * LeftCapsuleCollision2;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * RightCapsuleCollision;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * RightCapsuleCollision2;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * BodyCapsuleCollision;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * HitAreaCollision;

	UPROPERTY(VisibleAnywhere)
		class USphereComponent * BulletSensorCollision;

private:
	UPROPERTY()
		class UStaticMesh * StaticMesh_Horn;

	UPROPERTY()
		class UStaticMeshComponent * BruteHorn001;

	UPROPERTY()
		class UStaticMeshComponent * BruteHorn002;

	UPROPERTY()
		class UStaticMesh * StaticMesh_BlackSphere;

	UPROPERTY()
		class UStaticMeshComponent * BruteSphere;

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
		bool IsAxSlash;

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
		TSubclassOf<class UAnim_Monster002C> BruteAnimClass;

	UPROPERTY()
		UAnimMontage * Montage_AxSlash;

	UPROPERTY()
		UAnimMontage * Montage_Death;

private:
	void Sequence000(float DDD);
	void Sequence001();
	void CheckDistance();
	void CheckDirection();

public:
	void AxSlashStart();
	void AxSlashEnd();
	void AxSlashNoAttackMode();
	void Disappear();

	private:
		UFUNCTION()
			void AxBoxBeginOverlap(
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
			void LeftCapsule2BeginOverlap(
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
			void RightCapsule2BeginOverlap(
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
