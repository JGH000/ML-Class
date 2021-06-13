// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BossMonsterC.h"
#include "Anim_BossMonsterC.generated.h"

/**
 * 
 */
UCLASS()
class UE_BPPRACTICE01_API UAnim_BossMonsterC : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	UAnim_BossMonsterC();
	
protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float CurrentSpeed;

private:
	UPROPERTY()
		class ABossMonsterC * Boss;

	UPROPERTY()
		float Speed;

private:
	UFUNCTION()
		void AnimNotify_StandUpOnlyOneEnd();

	UFUNCTION()
		void AnimNotify_MonsterDisappear();

	UFUNCTION()
		void AnimNotify_FireBall();

	UFUNCTION()
		void AnimNotify_AttackEnd();

	UFUNCTION()
		void AnimNotify_FireFromGround();

	UFUNCTION()
		void AnimNotify_FlameSet();
};
