// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAutoMaticDoorC_BossRoom001.h"
#include "Engine.h"

AMyAutoMaticDoorC_BossRoom001::AMyAutoMaticDoorC_BossRoom001() {

	CloseBox3 = CreateDefaultSubobject<UBoxComponent>(TEXT("CB3"));
	CloseBox4 = CreateDefaultSubobject<UBoxComponent>(TEXT("CB4"));

	CloseBox3->SetupAttachment(USC);
	CloseBox4->SetupAttachment(USC);

	CloseBox3->SetRelativeLocationAndRotation(FVector(729.0f, 503.0f, 655.0f), FRotator(0.0f, 90.0f, 0.0f));
	CloseBox3->SetWorldScale3D(FVector(20.0f, 1.0f, 20.0f));
	CloseBox3->SetBoxExtent(FVector(10.0f, 32.0f, 35.0f));

	CloseBox4->SetRelativeLocationAndRotation(FVector(-607.0f, 503.0f, 655.0f), FRotator(0.0f, 90.0f, 0.0f));
	CloseBox4->SetWorldScale3D(FVector(20.0f, 1.0f, 20.0f));
	CloseBox4->SetBoxExtent(FVector(35.0f, 32.0f, 35.0f));

	CloseBox3->OnComponentBeginOverlap.AddDynamic(this, &AAutoMaticDoorC::OnOverlapBegin2);
	CloseBox4->OnComponentBeginOverlap.AddDynamic(this, &AAutoMaticDoorC::OnOverlapBegin2);
}


