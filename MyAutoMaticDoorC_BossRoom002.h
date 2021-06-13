// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AutoMaticDoorC.h"
#include "MyAutoMaticDoorC_BossRoom002.generated.h"

/**
 * 
 */
UCLASS()
class UE_BPPRACTICE01_API AMyAutoMaticDoorC_BossRoom002 : public AAutoMaticDoorC
{
	GENERATED_BODY()
	
public:
	AMyAutoMaticDoorC_BossRoom002();
	
public:
	void OoOpen();
	
};
