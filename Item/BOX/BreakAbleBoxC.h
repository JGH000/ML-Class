// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletC.h"
#include "Item/HPPortionC.h"
#include "Item/NoDamagePortionC.h"
#include "Item/SuperBulletPortionC.h"
#include "Item/Box/DestroySmokeC.h"
#include "BreakAbleBoxC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API ABreakAbleBoxC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABreakAbleBoxC();

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
		class UStaticMeshComponent * BoxBox;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * BoxHitArea;

private:
	UPROPERTY(VisibleAnywhere)
		bool OnlyOne;

	UPROPERTY(VisibleAnywhere)
		int32 R;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle;

protected:
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
