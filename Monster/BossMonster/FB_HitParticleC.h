// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FB_HitParticleC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API AFB_HitParticleC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFB_HitParticleC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
		class UParticleSystem * UPS;

	UPROPERTY()
		class UParticleSystemComponent * UPSC;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle;
	
	UFUNCTION()
	    void ParticleDestroy();
	
};
