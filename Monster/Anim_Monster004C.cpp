// Fill out your copyright notice in the Description page of Project Settings.

#include "Anim_Monster004C.h"

UAnim_Monster004C::UAnim_Monster004C()
{
	CurrentSpeed = 0.0f;
	Speed = 0.0f;
}

void UAnim_Monster004C::NativeUpdateAnimation(float DeltaSeconds)
{
	 if (!IsValid(Vampire)) Vampire = Cast<AMonster004C>(TryGetPawnOwner());
	 
	 else {
	 	Speed = FVector(Vampire->GetVelocity().X, Vampire->GetVelocity().Y, 0.0f).Size();
	 
	 	CurrentSpeed = FMath::FInterpTo(CurrentSpeed, Speed, DeltaSeconds, 10.0f);
	 }
}

void UAnim_Monster004C::AnimNotify_SlashStart()
{
	Vampire->LongSwordSlashStart();
}

void UAnim_Monster004C::AnimNotify_SlashEnd()
{
	Vampire->LongSwordSlashEnd();
}

void UAnim_Monster004C::AnimNotify_SlashNoAttackMode()
{
	Vampire->LongSwordSlashNoAttackMode();
}

void UAnim_Monster004C::AnimNotify_MonsterDisappear()
{
	Vampire->Disappear();
}
