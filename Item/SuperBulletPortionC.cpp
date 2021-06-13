// Fill out your copyright notice in the Description page of Project Settings.

#include "SuperBulletPortionC.h"
#include "Engine.h"

ASuperBulletPortionC::ASuperBulletPortionC() {
	PrimaryActorTick.bCanEverTick = true;

	NowItemSlot.TheNumberOfItem = 0;

	static ConstructorHelpers::FObjectFinder<UTexture2D> LoadItemImage(
		TEXT("Texture2D'/Game/FiveBulletPotion.FiveBulletPotion'"));

	if (LoadItemImage.Succeeded()) {
		NowItemSlot.ItemSlotImage = LoadItemImage.Object;
	}

	NowItemSlot.ItemName = "SuperBulletPortion";
	NowItemSlot.ItemCode = 1003;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> LoadStaticMesh(
		TEXT("StaticMesh'/Game/Unity/GPVFX_POTION_B_GPVFX_Bottle_B.GPVFX_POTION_B_GPVFX_Bottle_B'"));

	if (LoadStaticMesh.Succeeded()) {
		SM = LoadStaticMesh.Object;
	}

	StaticMesh->SetStaticMesh(SM);

	StaticMesh->SetWorldScale3D(FVector(0.25f, 0.25f, 0.25f));

	StaticMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	StaticMesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StaticMesh->SetCollisionObjectType(ECC_WorldStatic);



	Capsule->SetRelativeLocation(FVector(0.0f, 0.0f, -8.0f));
	Capsule->SetCapsuleHalfHeight(102.5f);
	Capsule->SetCapsuleRadius(93.0f);

	SM_Bottle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BOTTLE"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> LoadStaticMesh001(
		TEXT("StaticMesh'/Game/Unity/GPVFX_POTION_B_GPVFX_Botle_B_Fill.GPVFX_POTION_B_GPVFX_Botle_B_Fill'"));

	if (LoadStaticMesh001.Succeeded()) {
		SM = LoadStaticMesh001.Object;
	}

	SM_Bottle->SetStaticMesh(SM);
	SM_Bottle->SetupAttachment(StaticMesh);

	SM_Cork = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CORK"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> LoadStaticMesh002(
		TEXT("StaticMesh'/Game/Unity/GPVFX_POTION_B_GPVFX_Cork_GPVFX_Corks.GPVFX_POTION_B_GPVFX_Cork_GPVFX_Corks'"));

	if (LoadStaticMesh002.Succeeded()) {
		SM = LoadStaticMesh002.Object;
	}

	SM_Cork->SetStaticMesh(SM);
	SM_Cork->SetupAttachment(StaticMesh);
}


