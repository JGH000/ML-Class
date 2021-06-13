// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerCharacter/MyPlayerCharacterC.h"
#include "Item/ItemStructC.h"
#include "PortionC.generated.h"

UCLASS()
class UE_BPPRACTICE01_API APortionC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortionC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(VisibleAnywhere)
		class UStaticMesh * SM;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent * StaticMesh;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent * Capsule;

	UPROPERTY(VisibleAnywhere)
		class URotatingMovementComponent * RotatingMovement;


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class AMyPlayerCharacterC * Player;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FItemC NowItemSlot;

protected:
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);
};
