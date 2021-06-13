// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MonsterEnumC.generated.h"

UENUM(BlueprintType)
enum class MONSTERENUM : uint8
{
	MON_IDLE UMETA(DisplayName = "IDLE"),
	MON_FOLLOW UMETA(DisplayName = "FOLLOW"),
	MON_ATTACK UMETA(DisplayName = "ATTACK")
}
;

UCLASS()
class UE_BPPRACTICE01_API AMonsterEnumC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonsterEnumC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
