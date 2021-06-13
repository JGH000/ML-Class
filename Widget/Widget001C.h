// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "Widget001C.generated.h"

/**
 * 
 */
UCLASS()
class UE_BPPRACTICE01_API UWidget001C : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:
	UPROPERTY(BlueprintReadOnly,  Category = "MyPlayerCharacter")
		class AMyPlayerCharacterC * Player;

	UPROPERTY(BlueprintReadOnly, Category = "BulletAndFullBullet")
		FText Bullet_Text;

	UPROPERTY(BlueprintReadOnly, Category = "BulletAndFullBullet")
		FText FullBullet_Text;
	
	UPROPERTY(BlueprintReadOnly, Category = "Percent")
		float HPBar_Percent;

	UPROPERTY(BlueprintReadOnly, Category = "Percent")
		float RunGaugeBar_Percent;

	//////////////////////////////////////

	UPROPERTY(BlueprintReadOnly, Category = "Gauge001")
		float Gauge001_Percent;

	UPROPERTY(BlueprintReadOnly, Category = "Gauge001")
		float Gauge001_TransformY;

	UPROPERTY(BlueprintReadOnly, Category = "Gauge001")
		FLinearColor Gauge001_TextColor;

	//////////////////////////////////////

	UPROPERTY(BlueprintReadOnly, Category = "Gauge002")
		float Gauge002_Percent;

	UPROPERTY(BlueprintReadOnly, Category = "Gauge002")
		float Gauge002_TransformY;

	UPROPERTY(BlueprintReadOnly, Category = "Gauge002")
		FLinearColor Gauge002_TextColor;

	//////////////////////////////////////

	UPROPERTY(BlueprintReadOnly, Category = "Gauge003")
		float Gauge003_Percent;

	UPROPERTY(BlueprintReadOnly, Category = "Gauge003")
		float Gauge003_TransformY;

	UPROPERTY(BlueprintReadOnly, Category = "Gauge003")
		FLinearColor Gauge003_TextColor;

	//////////////////////////////////////

	 UPROPERTY(BlueprintReadOnly, Category = "ItemSlot")
	 	UTexture2D * ItemSlot001_Image;
	 
	 UPROPERTY(BlueprintReadOnly, Category = "ItemSlot")
		 FLinearColor ItemSlot001_Color;

	 UPROPERTY(BlueprintReadOnly, Category = "ItemSlot")
		FText ItemSlot001_TheNumberOfItem;

	 UPROPERTY(BlueprintReadOnly, Category = "ItemSlot")
	 	UTexture2D * ItemSlot002_Image;
	 
	 UPROPERTY(BlueprintReadOnly, Category = "ItemSlot")
		 FLinearColor ItemSlot002_Color;

	 UPROPERTY(BlueprintReadOnly, Category = "ItemSlot")
		 FText ItemSlot002_TheNumberOfItem;

	 UPROPERTY(BlueprintReadOnly, Category = "ItemSlot")
	 	UTexture2D * ItemSlot003_Image;
	 
	 UPROPERTY(BlueprintReadOnly, Category = "ItemSlot")
		 FLinearColor ItemSlot003_Color;

	 UPROPERTY(BlueprintReadOnly, Category = "ItemSlot")
		 FText ItemSlot003_TheNumberOfItem;

	 UPROPERTY(BlueprintReadOnly, Category = "ItemSlot")
	 	UTexture2D * ItemSlot004_Image;
	 
	 UPROPERTY(BlueprintReadOnly, Category = "ItemSlot")
		 FLinearColor ItemSlot004_Color;

	 UPROPERTY(BlueprintReadOnly, Category = "ItemSlot")
		 FText ItemSlot004_TheNumberOfItem;

	 //
	 UPROPERTY(BlueprintReadOnly, Category = "GameOverScreenImageAndText")
	 	FLinearColor GameoverScreenColor;
	 
	 UPROPERTY(BlueprintReadOnly, Category = "GameOverScreenImageAndText")
	 	FLinearColor GameoverTextColor;

	 //
	 UPROPERTY(BlueprintReadOnly, Category = "Censor")
		 bool IsCensorVisible;

	 UPROPERTY(BlueprintReadOnly, Category = "Censor")
		 bool IsMonsterRecognized_FromCharacter;

	 UPROPERTY(BlueprintReadOnly, Category = "Censor")
		 bool IsAlive_FromCharacter;

 private:
	 UFUNCTION()
		 void Sequence000_First();

	 UFUNCTION()
		 void Sequence000_Second();

	 UFUNCTION()
		 void Sequence000_Third();

 	UFUNCTION()
 		void Sequence001();

	UFUNCTION()
		void Sequence002();
};
