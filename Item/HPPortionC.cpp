// Fill out your copyright notice in the Description page of Project Settings.

#include "HPPortionC.h"
#include "Engine.h"

AHPPortionC::AHPPortionC()
{
	PrimaryActorTick.bCanEverTick = true;

	NowItemSlot.TheNumberOfItem = 0;

	static ConstructorHelpers::FObjectFinder<UTexture2D> LoadItemImage(
		TEXT("Texture2D'/Game/HPPotion.HPPotion'"));

	if (LoadItemImage.Succeeded()) {
		NowItemSlot.ItemSlotImage = LoadItemImage.Object;
	}

	NowItemSlot.ItemName = "HPPortion";
	NowItemSlot.ItemCode = 1001;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> LoadStaticMesh(
		TEXT("StaticMesh'/Game/MultistoryDungeons/Meshes/Props/Potion_03.Potion_03'"));

	if (LoadStaticMesh.Succeeded()) {
		SM = LoadStaticMesh.Object;
	}

	StaticMesh->SetStaticMesh(SM);

	StaticMesh->SetWorldScale3D(FVector(1.5f, 1.5f, 1.5f));

	StaticMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	StaticMesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StaticMesh->SetCollisionObjectType(ECC_WorldStatic);



	Capsule->SetRelativeLocation(FVector(0.0f, 0.0f, 16.666668f));
	Capsule->SetCapsuleHalfHeight(21.0f);
	Capsule->SetCapsuleRadius(12.5f);


}


