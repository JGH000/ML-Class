// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAutoMaticDoorC_BossRoom002.h"
#include "Engine.h"

AMyAutoMaticDoorC_BossRoom002::AMyAutoMaticDoorC_BossRoom002() {

	OpenBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	OpenBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	OpenBox->SetRelativeScale3D(FVector(0.01f, 0.01f, 0.01f));

	CloseBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CloseBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CloseBox->SetRelativeScale3D(FVector(0.01f, 0.01f, 0.01f));

	Tags.Add("Boss001Door");
}

void AMyAutoMaticDoorC_BossRoom002::OoOpen()
{
	IsOpen = true;
}
