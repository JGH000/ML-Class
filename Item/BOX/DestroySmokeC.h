// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestroySmokeC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API ADestroySmokeC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestroySmokeC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
		class UParticleSystem * UPS;

	UPROPERTY(VisibleAnywhere)
		class UParticleSystemComponent * UPSC;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle;

private:
	UFUNCTION()
		void ParticleDestroy();
	
};
