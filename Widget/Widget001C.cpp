// Fill out your copyright notice in the Description page of Project Settings.

#include "Widget001C.h"
#include "PlayerCharacter/MyPlayerCharacterC.h"
#include "Engine.h"

void UWidget001C::NativeConstruct() {
	Super::NativeConstruct();

	Player = Cast<AMyPlayerCharacterC>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());

	FullBullet_Text = FText::FromString(FString::FromInt(Player->BulletFull));
	Bullet_Text = FText::FromString(FString::FromInt(Player->Bullet));

	IsCensorVisible = false;
	IsMonsterRecognized_FromCharacter = false;
	IsAlive_FromCharacter = true;
}

void UWidget001C::NativeTick(const FGeometry & MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	Bullet_Text = FText::FromString(FString::FromInt(Player->Bullet));

	HPBar_Percent = Player->HP * 0.01f;

	RunGaugeBar_Percent = Player->RunGauge * 0.01f;

	Sequence000_First();
	Sequence000_Second();
	Sequence000_Third();

	ItemSlot001_Image = Player->ItemSlot[0].ItemSlotImage;
	ItemSlot002_Image = Player->ItemSlot[1].ItemSlotImage;
	ItemSlot003_Image = Player->ItemSlot[2].ItemSlotImage;
	ItemSlot004_Image = Player->ItemSlot[3].ItemSlotImage;

	if (Player->ItemSlot[0].TheNumberOfItem == 0) {
		ItemSlot001_TheNumberOfItem = FText::FromString("");
		ItemSlot001_Color = FLinearColor(1.0f, 1.0f, 1.0f, 0.0f);
	}
	else {
		ItemSlot001_TheNumberOfItem = FText::FromString(FString::FromInt(Player->ItemSlot[0].TheNumberOfItem));
		ItemSlot001_Color = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);
	}

	if (Player->ItemSlot[1].TheNumberOfItem == 0) {
		ItemSlot002_TheNumberOfItem = FText::FromString("");
		ItemSlot002_Color = FLinearColor(1.0f, 1.0f, 1.0f, 0.0f);
	}
	else {
		ItemSlot002_TheNumberOfItem = FText::FromString(FString::FromInt(Player->ItemSlot[1].TheNumberOfItem));
		ItemSlot002_Color = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);
	}

	if (Player->ItemSlot[2].TheNumberOfItem == 0) {
		ItemSlot003_TheNumberOfItem = FText::FromString("");
		ItemSlot003_Color = FLinearColor(1.0f, 1.0f, 1.0f, 0.0f);
	}
	else {
		ItemSlot003_TheNumberOfItem = FText::FromString(FString::FromInt(Player->ItemSlot[2].TheNumberOfItem));
		ItemSlot003_Color = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);
	}

	if (Player->ItemSlot[3].TheNumberOfItem == 0) {
		ItemSlot004_TheNumberOfItem = FText::FromString("");
		ItemSlot004_Color = FLinearColor(1.0f, 1.0f, 1.0f, 0.0f);
	}
	else {
		ItemSlot004_TheNumberOfItem = FText::FromString(FString::FromInt(Player->ItemSlot[3].TheNumberOfItem));
		ItemSlot004_Color = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);
	}

	Sequence001();

	IsMonsterRecognized_FromCharacter = Player->IsMonsterRecognized;
	IsAlive_FromCharacter = !(Player->IsRebirthAble);
}

void UWidget001C::Sequence000_First()
{
	if (Player->IsNoDamageTimerStart) {
		Gauge001_Percent = Player->NoDamageModeTimer * 0.5f;
		Gauge001_TextColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);

		if (
			(Gauge002_Percent == 0.0f && Gauge003_Percent == 0.0f)
			|| (Gauge002_Percent == 0.0f && Gauge002_TransformY == 0.0f && Gauge003_Percent != 0.0f && Gauge003_TransformY != 0.0f && Gauge001_TransformY == -60.0f)
			|| (Gauge002_Percent != 0.0f && Gauge002_TransformY != 0.0f && Gauge003_Percent == 0.0f && Gauge003_TransformY == 0.0f && Gauge001_TransformY == -60.0f)
			) Gauge001_TransformY = 0.0f;

		else if (Gauge002_Percent != 0.0f && Gauge002_TransformY != -120.0f
			&& Gauge003_Percent != 0.0f && Gauge003_TransformY != -120.f
			) Gauge001_TransformY = -120.0f;

		else if ((Gauge002_Percent != 0.0f && Gauge002_TransformY == 0.0f)
			|| (Gauge003_Percent != 0.0f && Gauge003_TransformY == 0.0f)
			) Gauge001_TransformY = -60.0f;
	}
	else {
	   Gauge001_Percent = 0.0f; 
	   Gauge001_TextColor = FLinearColor(1.0f, 1.0f, 1.0f, 0.0f);
	}
}

void UWidget001C::Sequence000_Second()
{
	if (Player->IsSuperBulletMode) {
		Gauge002_Percent = Player->IsSuperBulletModeTimer * 0.2f;
		Gauge002_TextColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);

		if (
			(Gauge001_Percent == 0.0f && Gauge003_Percent == 0.0f)
			|| (Gauge001_Percent == 0.0f && Gauge001_TransformY == 0.0f && Gauge003_Percent != 0.0f && Gauge003_TransformY != 0.0f && Gauge002_TransformY == -60.0f)
			|| (Gauge001_Percent != 0.0f && Gauge001_TransformY != 0.0f && Gauge003_Percent == 0.0f && Gauge003_TransformY == 0.0f && Gauge002_TransformY == -60.0f)
			) Gauge002_TransformY = 0.0f;

		else if (Gauge001_Percent != 0.0f && Gauge001_TransformY != -120.0f
			&& Gauge003_Percent != 0.0f && Gauge003_TransformY != -120.f
			) Gauge002_TransformY = -120.0f;

		else if ((Gauge001_Percent != 0.0f && Gauge001_TransformY == 0.0f)
			|| (Gauge003_Percent != 0.0f && Gauge003_TransformY == 0.0f)
			) Gauge002_TransformY = -60.0f;
	}
	else {
		Gauge002_Percent = 0.0f;
		Gauge002_TextColor = FLinearColor(1.0f, 1.0f, 1.0f, 0.0f);
	}
}

void UWidget001C::Sequence000_Third()
{
	if (Player->IsTest003Mode) {
		Gauge003_Percent = Player->IsSuperBulletModeTimer * 0.3334f;
		Gauge003_TextColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);

		if (
			(Gauge001_Percent == 0.0f && Gauge002_Percent == 0.0f)
			|| (Gauge001_Percent == 0.0f && Gauge001_TransformY == 0.0f && Gauge002_Percent != 0.0f && Gauge002_TransformY != 0.0f && Gauge003_TransformY == -60.0f)
			|| (Gauge001_Percent != 0.0f && Gauge001_TransformY != 0.0f && Gauge002_Percent == 0.0f && Gauge002_TransformY == 0.0f && Gauge003_TransformY == -60.0f)
			) Gauge003_TransformY = 0.0f;

		else if (Gauge001_Percent != 0.0f && Gauge001_TransformY != -120.0f
			&& Gauge002_Percent != 0.0f && Gauge002_TransformY != -120.f
			) Gauge003_TransformY = -120.0f;

		else if ((Gauge001_Percent != 0.0f && Gauge001_TransformY == 0.0f)
			|| (Gauge002_Percent != 0.0f && Gauge002_TransformY == 0.0f)
			) Gauge003_TransformY = -60.0f;
	}
	else {
		Gauge003_Percent = 0.0f;
		Gauge003_TextColor = FLinearColor(1.0f, 1.0f, 1.0f, 0.0f);
	}
}

void UWidget001C::Sequence001()
{
	if (Player->IsRebirthAble) {
		GameoverScreenColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.75f);
		GameoverTextColor = FLinearColor(0.984375f, 0.046143f, 0.046143f, 1.0f);
	}

	else {
		GameoverScreenColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f);
		GameoverTextColor = FLinearColor(0.984375f, 0.046143f, 0.046143f, 0.0f);
	}
}

void UWidget001C::Sequence002()
{
	if (Player->IsMonsterRecognized) {
		GameoverScreenColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.75f);
		GameoverTextColor = FLinearColor(0.984375f, 0.046143f, 0.046143f, 1.0f);
	}

	else {
		GameoverScreenColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f);
		GameoverTextColor = FLinearColor(0.984375f, 0.046143f, 0.046143f, 0.0f);
	}
}
