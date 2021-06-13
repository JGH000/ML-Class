// Fill out your copyright notice in the Description page of Project Settings.

#include "Anim_Monster002C.h"
#include "Engine.h"

UAnim_Monster002C::UAnim_Monster002C()
{
	CurrentSpeed = 0.0f;
	Speed = 0.0f;
}

void UAnim_Monster002C::NativeUpdateAnimation(float DeltaSeconds)
{
	if (!IsValid(Brute)) Brute = Cast<AMonster002C>(TryGetPawnOwner());

	else {
		Speed = FVector(Brute->GetVelocity().X, Brute->GetVelocity().Y, 0.0f).Size();

		CurrentSpeed = FMath::FInterpTo(CurrentSpeed, Speed, DeltaSeconds, 10.0f);
	}
}

void UAnim_Monster002C::AnimNotify_AxSlashStart()
{
	Brute->AxSlashStart();
}

void UAnim_Monster002C::AnimNotify_AxSlashEnd()
{
	Brute->AxSlashEnd();
}

void UAnim_Monster002C::AnimNotify_AxSlashNoAttackMode()
{
	Brute->AxSlashNoAttackMode();
}

void UAnim_Monster002C::AnimNotify_MonsterDisappear()
{
	Brute->Disappear();
}
