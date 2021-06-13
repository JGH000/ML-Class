// Fill out your copyright notice in the Description page of Project Settings.

#include "Anim_Monster001C.h"
#include "Engine.h"

UAnim_Monster001C::UAnim_Monster001C()
{
	CurrentSpeed = 0.0f;
	Speed = 0.0f;
}

void UAnim_Monster001C::NativeUpdateAnimation(float DeltaSeconds)
{
	if (!IsValid(Mutant)) Mutant = Cast<AMonster001C>(TryGetPawnOwner());

	else {
		Speed = FVector(Mutant->GetVelocity().X, Mutant->GetVelocity().Y, 0.0f).Size();

		CurrentSpeed = FMath::FInterpTo(CurrentSpeed, Speed, DeltaSeconds, 10.0f);
	}
}

void UAnim_Monster001C::AnimNotify_PunchStart()
{
	Mutant->PunchStart();
}

void UAnim_Monster001C::AnimNotify_PunchEnd()
{
	Mutant->PunchEnd();
}

void UAnim_Monster001C::AnimNotify_PunchNoAttackMode()
{
	Mutant->PunchNoAttackMode();
}

void UAnim_Monster001C::AnimNotify_SlashStart()
{
	Mutant->SlashStart();
}

void UAnim_Monster001C::AnimNotify_SpinAttackEnd()
{
	if (IsValid(Mutant)) Mutant->SlashEnd();
}

void UAnim_Monster001C::AnimNotify_SlashNoAttackMode()
{
	Mutant->SlashNoAttackMode();
}

void UAnim_Monster001C::AnimNotify_MonsterDisappear()
{
	Mutant->Disappear();
}
