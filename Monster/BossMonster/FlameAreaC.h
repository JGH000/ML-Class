// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerCharacter/MyPlayerCharacterC.h"
#include "FlameAreaC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API AFlameAreaC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlameAreaC();

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
	
	UPROPERTY()
		class UCapsuleComponent * Capsule;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle_FlameDamage;

	UPROPERTY()
		FTimerHandle CountdownTimerHandle_DestroyFlame;

	UPROPERTY()
		class AMyPlayerCharacterC * Player;

private:
	void FlameDamage();
	void DestroyFlame();

	UFUNCTION()
		void CapsuleBeginOverlap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);

	UFUNCTION()
		void CapsuleEndOverlap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);
};
