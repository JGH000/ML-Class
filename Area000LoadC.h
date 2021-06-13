// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Area000LoadC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API AArea000LoadC : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AArea000LoadC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * Box;

	UPROPERTY(EditAnywhere, Category = "true면 levelLoad, false면 levelUnLoad")
		bool IsLoadCollision;

	UPROPERTY(EditAnywhere)
		int32 AreaNumber;

protected:
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);
};
