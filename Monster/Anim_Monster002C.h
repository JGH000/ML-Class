// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Monster002C.h"
#include "Anim_Monster002C.generated.h"

/**
 * 
 */
UCLASS()
class UE_BPPRACTICE01_API UAnim_Monster002C : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UAnim_Monster002C();

protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float CurrentSpeed;

private:
	UPROPERTY()
		class AMonster002C * Brute;

	UPROPERTY()
		float Speed;
	
private:
	UFUNCTION()
		void AnimNotify_AxSlashStart();

	UFUNCTION()
		void AnimNotify_AxSlashEnd();

	UFUNCTION()
		void AnimNotify_AxSlashNoAttackMode();

	UFUNCTION()
		void AnimNotify_MonsterDisappear();
	
};
