// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API ABulletC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
		class UStaticMesh * USM;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent * BulletComponent;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * BulletCollision;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle;

	UPROPERTY(VisibleAnywhere)
		FVector SpawnParticleLocation;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float BulletDamage;

	UFUNCTION(BlueprintCallable)
		void BulletExplosionDestroy();

protected:
	UFUNCTION()
		void BulletDestroy();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);
	
};
