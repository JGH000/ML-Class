// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimBase.generated.h"

/**
 * 
 */
UCLASS()
class UE_BPPRACTICE01_API UPlayerAnimBase : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UPlayerAnimBase();
	
protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY()
		class AMyPlayerCharacterC * Para;

private:
	UPROPERTY()
		float TargetYawZ;

	UPROPERTY()
		float YawZ;
	
	UPROPERTY()
		bool Move_NCheck;

	UPROPERTY()
		bool Move_NECheck;

	UPROPERTY()
		bool Move_ECheck;

	UPROPERTY()
		bool Move_SECheck;

	UPROPERTY()
		bool Move_SCheck;

	UPROPERTY()
		bool Move_SWCheck;

	UPROPERTY()
		bool Move_WCheck;

	UPROPERTY()
		bool Move_NWCheck;

	UPROPERTY()
		bool IsCombatMode_Anim;

	UPROPERTY()
		bool IsAlive_Anim;

	UPROPERTY()
		bool IsReload_Anim;

	UPROPERTY()
		float Speed;

	UPROPERTY()
		float CurrentSpeed;

	UPROPERTY()
		float Head02Roll;

	UPROPERTY()
		float Head02Pitch;

	UPROPERTY()
		float CurrentHead02Roll;

	UPROPERTY()
		float CurrentHead02Pitch;

	UPROPERTY()
		float ThighYaw;

	UPROPERTY()
		float CurrentThighYaw;

	UPROPERTY()
		float CurrentClavicleLRoll;							   
															   
	UPROPERTY()
		float CurrentClavicleLPitch;						   
															   
	UPROPERTY()
		float ClavicleLRoll;								   
															   
	UPROPERTY()
		float ClavicleLPitch;

	UPROPERTY()
		float PlayRate_BattleMode;

private:
	UFUNCTION()
		void Sequence000(float DeltaSeconds);

	UFUNCTION()
		void Sequence001(float DeltaSeconds);

	UFUNCTION()
		void Sequence002(float DeltaSeconds);

	UFUNCTION()
		void Sequence003(float DeltaSeconds);

	UFUNCTION()
		void Move_N();

	UFUNCTION()
		void Move_NE();

	UFUNCTION()
		void Move_E();

	UFUNCTION()
		void Move_SE();

	UFUNCTION()
		void Move_S();

	UFUNCTION()
		void Move_SW();

	UFUNCTION()
		void Move_W();

	UFUNCTION()
		void Move_NW();


	UFUNCTION()
		void Rotate_Head();

	UFUNCTION()
		void Rotate_Thigh();

    UFUNCTION()
		void AnimNotify_Change_CombatMode();

	UFUNCTION()
		void AnimNotify_Change_CombatMode2();

	UFUNCTION()
		void AnimNotify_Change_CombatMode3();

	UFUNCTION()
		void AnimNotify_ShotAble();

	UFUNCTION()
		void AnimNotify_ReloadStart();

	UFUNCTION()
		void AnimNotify_ReloadEnd();

	UFUNCTION()
		void AnimNotify_ReloadEnd2();

	UFUNCTION()
		void AnimNotify_AnimDeath();

	UFUNCTION()
		void AnimNotify_LightOffandRebirthable();

	UFUNCTION()
		void AnimNotify_Anim_Rebirth();
};
