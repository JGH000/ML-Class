// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AutoMaticDoorC.h"
#include "MyAutoMaticDoorC_BossRoom001.generated.h"

/**
 * 
 */
UCLASS()
class UE_BPPRACTICE01_API AMyAutoMaticDoorC_BossRoom001 : public AAutoMaticDoorC
{
	GENERATED_BODY()
	
public:

	AMyAutoMaticDoorC_BossRoom001();

private:
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * CloseBox3;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent * CloseBox4;
	
	
};
