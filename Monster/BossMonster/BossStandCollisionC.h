// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BossMonsterC.h"
#include "BossStandCollisionC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API ABossStandCollisionC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABossStandCollisionC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
		class USceneComponent * RScene;

	UPROPERTY()
		class UBoxComponent * Box001;

	UPROPERTY()
		class UBoxComponent * Box002;

	UPROPERTY()
		class UBoxComponent * Box003;

private:
	UPROPERTY()
		class ABossMonsterC * BB;

private:
	UFUNCTION()
		void OnOverlapBegin_Box001(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);

private:
	UFUNCTION()
		void OnOverlapBegin_Box002(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);

private:
	UFUNCTION()
		void OnOverlapBegin_Box003(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);
	
};
