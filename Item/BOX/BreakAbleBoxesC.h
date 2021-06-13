// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletC.h"
#include "Item/HPPortionC.h"
#include "Item/NoDamagePortionC.h"
#include "Item/SuperBulletPortionC.h"
#include "Item/Box/DestroySmokeC.h"
#include "BreakAbleBoxesC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API ABreakAbleBoxesC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABreakAbleBoxesC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(VisibleAnywhere)
		class UStaticMesh * SM;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent * BoxesBoxes;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * BoxesHitArea;

	UPROPERTY(VisibleAnywhere)
		class USceneComponent * RootSceneComponent;

	UPROPERTY(VisibleAnywhere)
		class USceneComponent * Sp0;

	UPROPERTY(VisibleAnywhere)
		class USceneComponent * Sp1;

	UPROPERTY(VisibleAnywhere)
		class USceneComponent * Sp2;

	UPROPERTY(VisibleAnywhere)
		class USceneComponent * Sp3;

	UPROPERTY(VisibleAnywhere)
		class USceneComponent * Sp4;

	UPROPERTY(VisibleAnywhere)
		class USceneComponent * Sp5;

	UPROPERTY(VisibleAnywhere)
		class USceneComponent * Sp6;
private:
	UPROPERTY(VisibleAnywhere)
		bool OnlyOne;

	UPROPERTY(VisibleAnywhere)
		TArray<int32> R;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle;

private:
	UFUNCTION()
		void PortionSpawnFunction(int32 I,float XX,float YY,float ZZ);

	UFUNCTION()
		void BoxDestroy();
	
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);
};
