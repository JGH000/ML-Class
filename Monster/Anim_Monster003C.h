// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Monster003C.h"
#include "Anim_Monster003C.generated.h"

/**
 * 
 */
UCLASS()
class UE_BPPRACTICE01_API UAnim_Monster003C : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UAnim_Monster003C();
	
protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float CurrentSpeed;

private:
	UPROPERTY()
		class AMonster003C * Zombie;

	UPROPERTY()
		float Speed;

private:
	UFUNCTION()
		void AnimNotify_HurricaneKickStart();

	UFUNCTION()
		void  AnimNotify_HurricaneKickEnd();

	UFUNCTION()
		void AnimNotify_KickStart();

	UFUNCTION()
		void  AnimNotify_KickEnd();

	UFUNCTION()
		void AnimNotify_IsKickNoAttackMode();

	UFUNCTION()
		void AnimNotify_MonsterDisappear();
};
