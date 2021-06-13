// Fill out your copyright notice in the Description page of Project Settings.

#include "Anim_Monster003C.h"
#include "Engine.h"

UAnim_Monster003C::UAnim_Monster003C()
{
	CurrentSpeed = 0.0f;
	Speed = 0.0f;
}

void UAnim_Monster003C::NativeUpdateAnimation(float DeltaSeconds)
{
	if (!IsValid(Zombie)) Zombie = Cast<AMonster003C>(TryGetPawnOwner());

	else {
		Speed = FVector(Zombie->GetVelocity().X, Zombie->GetVelocity().Y, 0.0f).Size();

		CurrentSpeed = FMath::FInterpTo(CurrentSpeed, Speed, DeltaSeconds, 10.0f);
	}
}

void UAnim_Monster003C::AnimNotify_HurricaneKickStart()
{
	Zombie->HurricaneKickAttackMode();
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("HURRI!"));
}

void UAnim_Monster003C::AnimNotify_HurricaneKickEnd()
{
	Zombie->SetHurricaneKickFalse();
}

void UAnim_Monster003C::AnimNotify_KickStart()
{
	Zombie->KickStart();
}

void UAnim_Monster003C::AnimNotify_KickEnd()
{
	Zombie->KickEnd();
}

void UAnim_Monster003C::AnimNotify_IsKickNoAttackMode()
{
	Zombie->KickNoAttackMode();
}

void UAnim_Monster003C::AnimNotify_MonsterDisappear()
{
	Zombie->Disappear();
}
