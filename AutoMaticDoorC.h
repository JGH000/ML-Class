// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AutoMaticDoorC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API AAutoMaticDoorC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAutoMaticDoorC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere)
		class USceneComponent * USC;

	UPROPERTY(VisibleAnywhere)
		class UStaticMesh * WallSM;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent * LeftWall;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * LeftWallCollision;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent * RightWall;
	
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * RightWallCollision;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * OpenBox;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * OpenBox2;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * CloseBox;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * CloseBox2;


	UPROPERTY(VisibleAnywhere)
		float LeftWallFirstPosX;

	UPROPERTY(VisibleAnywhere)
		float RightWallFirstPosX;

	UPROPERTY(VisibleAnywhere)
		bool IsOpen;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);

public:
	UFUNCTION()
	void OnOverlapBegin2(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult & SweepResult);

private:
	UFUNCTION()
		void OnOverlapBegin_BulletCollision(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);
};