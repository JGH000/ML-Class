// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BossEffectC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API ABossEffectC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABossEffectC();

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
		class UParticleSystem * UPS_1;

	UPROPERTY()
		class UParticleSystemComponent * UPSC_1;

	UPROPERTY()
		class UParticleSystem * UPS_2;

	UPROPERTY()
		class UParticleSystemComponent * UPSC_2;

	UPROPERTY()
		class UParticleSystem * UPS_3;

	UPROPERTY()
		class UParticleSystemComponent * UPSC_3;
};
