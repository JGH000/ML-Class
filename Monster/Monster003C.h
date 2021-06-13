// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterEnumC.h"
#include "PlayerCharacter/MyPlayerCharacterC.h"
#include "Anim_Monster003C.h"
#include "Monster003C.generated.h"

UCLASS()
class UE_BPPRACTICE01_API AMonster003C : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonster003C();

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
		class UCapsuleComponent * KickCapsuleCollision;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * HurricaneKickCapsuleCollision;

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
		bool IsHurricaneKickFunctionPlay; 

	UPROPERTY()
		uint32  RandomInt; 

	UPROPERTY()
		bool RandomDirectionIsLoading; 

	UPROPERTY()
		bool IsKick; 

	UPROPERTY()
		uint32 RandomInt2; 

	UPROPERTY()
		float HP; 

	UPROPERTY()
		bool IsAlive; 

	UPROPERTY()
		class AMyPlayerCharacterC * Player; 

	UPROPERTY()
		bool IsHurricaneKick; 

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
		FTimerHandle CountdownTimerHandle_RandomHurricaneKick;

private:
	UPROPERTY()
		TSubclassOf<class UAnim_Monster003C> ZombieAnimClass;

	UPROPERTY()
		UAnimMontage * Montage_HurricaneKick;

	UPROPERTY()
		UAnimMontage * Montage_Kick;

	UPROPERTY()
		UAnimMontage * Montage_Death;


private:
	void Sequence000(float DDD);
	void Sequence001();
	void CheckDistance();
	void CheckDirection();
	void RandomDirection();
	void RandomHurricaneKick();

public:
	void KickStart();
	void KickEnd();
	void KickNoAttackMode();
	void HurricaneKickAttackMode();
	void HurricaneKickNoAttackMode();
	void SetHurricaneKickFalse();
	void Disappear();

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
			void KickCapsuleBeginOverlap(
				UPrimitiveComponent* OverlappedComponent,
				AActor* OtherActor,
				UPrimitiveComponent* OtherComp,
				int32 OtherBodyIndex,
				bool bFromSweep,
				const FHitResult & SweepResult);

		UFUNCTION()
			void HurricaneKickCapsuleBeginOverlap(
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
