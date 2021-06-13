// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Monster004C.h"
#include "Anim_Monster004C.generated.h"

/**
 * 
 */
UCLASS()
class UE_BPPRACTICE01_API UAnim_Monster004C : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UAnim_Monster004C();

protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float CurrentSpeed;

private:
	UPROPERTY()
		class AMonster004C * Vampire;

	UPROPERTY()
		float Speed;

private:
	UFUNCTION()
		void AnimNotify_SlashStart();

	UFUNCTION()
		void  AnimNotify_SlashEnd();

	UFUNCTION()
		void AnimNotify_SlashNoAttackMode();

	UFUNCTION()
		void AnimNotify_MonsterDisappear();
};
