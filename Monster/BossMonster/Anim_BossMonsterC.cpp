// Fill out your copyright notice in the Description page of Project Settings.

#include "Anim_BossMonsterC.h"
#include "Engine.h"

// Sets default values
UAnim_BossMonsterC::UAnim_BossMonsterC() {
	CurrentSpeed = 0.0f;
	Speed = 0.0f;
}

void UAnim_BossMonsterC::NativeUpdateAnimation(float DeltaSeconds)
{
	if (!IsValid(Boss)) Boss = Cast<ABossMonsterC>(TryGetPawnOwner());

	else {
		Speed = FVector(Boss->GetVelocity().X, Boss->GetVelocity().Y, 0.0f).Size();

		CurrentSpeed = FMath::FInterpTo(CurrentSpeed, Speed, DeltaSeconds, 10.0f);
	}
}

void UAnim_BossMonsterC::AnimNotify_StandUpOnlyOneEnd()
{
	Boss->StandUpOnlyOneFalse();
}

void UAnim_BossMonsterC::AnimNotify_MonsterDisappear()
{
	Boss->MonsterDisappear();
}

void UAnim_BossMonsterC::AnimNotify_FireBall()
{
	Boss->FireBall();
}

void UAnim_BossMonsterC::AnimNotify_AttackEnd()
{
	Boss->AttackEnd();
}

void UAnim_BossMonsterC::AnimNotify_FireFromGround()
{
	Boss->FireGroundSpawn();
}

void UAnim_BossMonsterC::AnimNotify_FlameSet()
{
	Boss->FlameAreaSpawn();
}
