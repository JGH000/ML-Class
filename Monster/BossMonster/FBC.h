// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerCharacter/MyPlayerCharacterC.h"
#include "FBC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API AFBC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFBC();

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
		class UParticleSystem * UPS;

	UPROPERTY()
		class UParticleSystemComponent * UPSC;

	UPROPERTY(VisibleAnywhere)
		class UStaticMesh * USM;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent * USMC;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * Capsule;

private:
	UPROPERTY()
		class AMyPlayerCharacterC * Player;

private:
	UPROPERTY()
		FTimerHandle CountdownTimerHandle_FBDestroy;

private:
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);

	UFUNCTION()
		void FBDestroy();
	
	UFUNCTION()
		void FBExplosionDestroy();
};
