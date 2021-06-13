// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Monster001C.h"
#include "Anim_Monster001C.generated.h"

/**
 * 
 */
UCLASS()
class UE_BPPRACTICE01_API UAnim_Monster001C : public UAnimInstance
{
	GENERATED_BODY()

public:
	UAnim_Monster001C();

protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float CurrentSpeed;

private:
	UPROPERTY()
		class AMonster001C * Mutant;
	
	UPROPERTY()
		float Speed;

private:
	UFUNCTION()
		void AnimNotify_PunchStart();

	UFUNCTION()
		void AnimNotify_PunchEnd();

	UFUNCTION()
		void AnimNotify_PunchNoAttackMode();

	UFUNCTION()
		void AnimNotify_SlashStart();

	UFUNCTION()
		void AnimNotify_SpinAttackEnd();

	UFUNCTION()
		void AnimNotify_SlashNoAttackMode();

	UFUNCTION()
		void AnimNotify_MonsterDisappear();
};
