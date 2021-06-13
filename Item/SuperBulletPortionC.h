// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/PortionC.h"
#include "SuperBulletPortionC.generated.h"

/**
 * 
 */
UCLASS()
class UE_BPPRACTICE01_API ASuperBulletPortionC : public APortionC
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent * SM_Bottle;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent * SM_Cork;

public:
	ASuperBulletPortionC();

};
