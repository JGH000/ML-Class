// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerAnimBase.h"
#include "MyPlayerCharacterC.h"
#include "Engine.h"

UPlayerAnimBase::UPlayerAnimBase()
{
	TargetYawZ = 0.0f;
	YawZ = 0.0f;
	Move_NCheck = false;
	Move_NECheck = true;
	Move_ECheck = true;
	Move_SECheck = true;
	Move_SCheck = true;
	Move_SWCheck = true;
	Move_WCheck = true;
	Move_NWCheck = true;
	Speed = 0.0f;
	CurrentSpeed = 0.0f;
	Head02Roll = 0.0f;
	Head02Pitch = 0.0f;
	CurrentHead02Roll = 0.0f;
	CurrentHead02Pitch = 0.0f;
	IsCombatMode_Anim = false;
	ThighYaw = 0.0f;
	CurrentThighYaw = 0.0f;
	PlayRate_BattleMode = 1.0f;
	CurrentClavicleLRoll = 0.0f;
	CurrentClavicleLPitch = 0.0f;
	ClavicleLRoll = 0.0f;
	ClavicleLPitch = 0.0f;
	IsAlive_Anim = true;
	IsReload_Anim = false;
}

void UPlayerAnimBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!IsValid(Para))
	{
		//  > 애니메이션 클래스를 소유하고 있는 Pawn 을 가져와서
		//    APlayerCharacter 형태로 변환하여 참조시킵니다.
	    Para = Cast<AMyPlayerCharacterC>(TryGetPawnOwner());
		// return;
	}
	
	else {
		Sequence000(DeltaSeconds);
		Sequence001(DeltaSeconds);
		Sequence002(DeltaSeconds);
		Sequence003(DeltaSeconds);
	}

}

void UPlayerAnimBase::Sequence000(float DeltaSeconds)
{
	if (Para->CharacterLookDirection == "N") {
		Move_N();
		Move_NCheck = false; Move_NECheck = true; Move_ECheck = true; Move_SECheck = true;
		Move_SCheck = true;  Move_SWCheck = true; Move_WCheck = true; Move_NWCheck = true;
	}
	else if (Para->CharacterLookDirection == "NE") {
		Move_NE();
		Move_NCheck = true; Move_NECheck = false; Move_ECheck = true; Move_SECheck = true;
		Move_SCheck = true;  Move_SWCheck = true; Move_WCheck = true; Move_NWCheck = true;
	}
	else if (Para->CharacterLookDirection == "E") {
		Move_E();
		Move_NCheck = true; Move_NECheck =  true; Move_ECheck = false; Move_SECheck = true;
		Move_SCheck = true;  Move_SWCheck = true; Move_WCheck = true; Move_NWCheck = true;
	}
	else if (Para->CharacterLookDirection == "SE") {
		Move_SE();
		Move_NCheck = true;  Move_NECheck = true; Move_ECheck = true; Move_SECheck = false;
		Move_SCheck = true;  Move_SWCheck = true; Move_WCheck = true; Move_NWCheck = true;
	}
	else if (Para->CharacterLookDirection == "S") {
		Move_S();
		Move_NCheck = true;  Move_NECheck = true; Move_ECheck = true; Move_SECheck = true;
		Move_SCheck = false;  Move_SWCheck = true; Move_WCheck = true; Move_NWCheck = true;
	}
	else if (Para->CharacterLookDirection == "SW") {
		Move_SW();
		Move_NCheck = true;  Move_NECheck = true; Move_ECheck = true; Move_SECheck = true;
		Move_SCheck = true;  Move_SWCheck = false; Move_WCheck = true; Move_NWCheck = true;
	}
	else if (Para->CharacterLookDirection == "W") {
		Move_W();
		Move_NCheck = true;  Move_NECheck = true; Move_ECheck = true; Move_SECheck = true;
		Move_SCheck = true;  Move_SWCheck = true; Move_WCheck = false; Move_NWCheck = true;
	}
	else  {
		Move_NW();
		Move_NCheck = true;  Move_NECheck = true; Move_ECheck = true; Move_SECheck = true;
		Move_SCheck = true;  Move_SWCheck = true; Move_WCheck = true; Move_NWCheck = false;
	}
}

void UPlayerAnimBase::Sequence001(float DeltaSeconds)
{
	// Size이 VectorLength 말하는것이다.
	Speed = FVector(Para->GetVelocity().X, Para->GetVelocity().Y, 0.0f).Size();
	CurrentSpeed = FMath::FInterpTo(CurrentSpeed, Speed, DeltaSeconds, 10.0f);

	Rotate_Head();

	CurrentHead02Roll = FMath::FInterpTo(CurrentHead02Roll, Head02Roll, DeltaSeconds, 60.0f);
	CurrentHead02Pitch = FMath::FInterpTo(CurrentHead02Pitch, Head02Pitch, DeltaSeconds, 60.0f);

	if (IsCombatMode_Anim) {
		ClavicleLRoll = Head02Roll;
		ClavicleLPitch = Head02Pitch;
		if (IsAlive_Anim) {
			if (IsReload_Anim) {
				CurrentClavicleLRoll = 0.0f;
				CurrentClavicleLPitch = 0.0f;
			}
			else {}
		}
		else {
			CurrentClavicleLRoll = 0.0f;
			CurrentClavicleLPitch = 0.0f;
		}
		Rotate_Thigh();
	}
	else { 
		ClavicleLRoll = 0.0f;
		ClavicleLPitch = 0.0f;
		ThighYaw = 0.0f;
		PlayRate_BattleMode = 1.0f;
	}

	CurrentClavicleLRoll = FMath::FInterpTo(CurrentClavicleLRoll, ClavicleLRoll, DeltaSeconds, 60.0f);
	CurrentClavicleLPitch = FMath::FInterpTo(CurrentClavicleLPitch, ClavicleLPitch, DeltaSeconds, 60.0f);
	CurrentThighYaw = FMath::FInterpTo(CurrentThighYaw, ThighYaw, DeltaSeconds, 10.0f);
}

void UPlayerAnimBase::Sequence002(float DeltaSeconds)
{
	YawZ = FMath::FInterpTo(YawZ, TargetYawZ, DeltaSeconds, 10.0f);

	if (YawZ >= 360.0f) {
		YawZ -= 360.0f;
		TargetYawZ -= 360.0f;
	}

	else {
		if (YawZ <= -360.0f) {
			YawZ += 360.0f;
			TargetYawZ += 360.0f;
		}
	}
}

void UPlayerAnimBase::Sequence003(float DeltaSeconds)
{
	if (IsCombatMode_Anim) {
	
		if (YawZ > 359.0f || (YawZ < 1.0f && YawZ > -1.0f) || YawZ < -359.0f) {
			Para->IsShotable_Rotate = true;
		}
		else Para->IsShotable_Rotate = false;
	}
}

void UPlayerAnimBase::Move_N()
{
	if (Move_NCheck) {
		     if (Para->PreviousCharacterLookDirection == "NE") TargetYawZ -=  45.0f;
		else if (Para->PreviousCharacterLookDirection == "E" ) TargetYawZ -=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "SE") TargetYawZ -= 135.0f;
		else if (Para->PreviousCharacterLookDirection == "S" ) TargetYawZ += 180.0f;
		else if (Para->PreviousCharacterLookDirection == "SW") TargetYawZ += 135.0f;
		else if (Para->PreviousCharacterLookDirection == "W" ) TargetYawZ +=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "NW") TargetYawZ +=  45.0f;
	}
}

void UPlayerAnimBase::Move_NE()
{
	if (Move_NECheck) {
		     if (Para->PreviousCharacterLookDirection == "E" )  TargetYawZ -=  45.0f;
		else if (Para->PreviousCharacterLookDirection == "SE")  TargetYawZ -=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "S" )  TargetYawZ -= 135.0f;
		else if (Para->PreviousCharacterLookDirection == "SW")  TargetYawZ += 180.0f;
		else if (Para->PreviousCharacterLookDirection == "W" )  TargetYawZ += 135.0f;
		else if (Para->PreviousCharacterLookDirection == "NW")  TargetYawZ +=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "N" )  TargetYawZ +=  45.0f;
	}
}

void UPlayerAnimBase::Move_E()
{
	if (Move_ECheck) {
		     if (Para->PreviousCharacterLookDirection == "SE")  TargetYawZ -=  45.0f;
		else if (Para->PreviousCharacterLookDirection == "S" )  TargetYawZ -=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "SW")  TargetYawZ -= 135.0f;
		else if (Para->PreviousCharacterLookDirection == "W" )  TargetYawZ += 180.0f;
		else if (Para->PreviousCharacterLookDirection == "NW")  TargetYawZ += 135.0f;
		else if (Para->PreviousCharacterLookDirection == "N" )  TargetYawZ +=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "NE")  TargetYawZ +=  45.0f;
	}
}

void UPlayerAnimBase::Move_SE()
{
	if (Move_SECheck) {
		     if (Para->PreviousCharacterLookDirection == "S" )  TargetYawZ -=  45.0f;
		else if (Para->PreviousCharacterLookDirection == "SW")  TargetYawZ -=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "W" )  TargetYawZ -= 135.0f;
		else if (Para->PreviousCharacterLookDirection == "NW")  TargetYawZ += 180.0f;
		else if (Para->PreviousCharacterLookDirection == "N" )  TargetYawZ += 135.0f;
		else if (Para->PreviousCharacterLookDirection == "NE")  TargetYawZ +=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "E" )  TargetYawZ +=  45.0f;
	}
}

void UPlayerAnimBase::Move_S()
{
	if (Move_SCheck) {
		     if (Para->PreviousCharacterLookDirection == "SW")  TargetYawZ -=  45.0f;
		else if (Para->PreviousCharacterLookDirection == "W" )  TargetYawZ -=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "NW")  TargetYawZ -= 135.0f;
		else if (Para->PreviousCharacterLookDirection == "N" )  TargetYawZ += 180.0f;
		else if (Para->PreviousCharacterLookDirection == "NE")  TargetYawZ += 135.0f;
		else if (Para->PreviousCharacterLookDirection == "E" )  TargetYawZ +=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "SE")  TargetYawZ +=  45.0f;
	}
}

void UPlayerAnimBase::Move_SW()
{
	if (Move_SWCheck) {
		     if (Para->PreviousCharacterLookDirection == "W" )  TargetYawZ -=  45.0f;
		else if (Para->PreviousCharacterLookDirection == "NW")  TargetYawZ -=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "N" )  TargetYawZ -= 135.0f;
		else if (Para->PreviousCharacterLookDirection == "NE")  TargetYawZ += 180.0f;
		else if (Para->PreviousCharacterLookDirection == "E" )  TargetYawZ += 135.0f;
		else if (Para->PreviousCharacterLookDirection == "SE")  TargetYawZ +=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "S" )  TargetYawZ +=  45.0f;
	}
}

void UPlayerAnimBase::Move_W()
{
	if (Move_WCheck) {
		     if (Para->PreviousCharacterLookDirection == "NW")  TargetYawZ -=  45.0f;
		else if (Para->PreviousCharacterLookDirection == "N" )  TargetYawZ -=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "NE")  TargetYawZ -= 135.0f;
		else if (Para->PreviousCharacterLookDirection == "E" )  TargetYawZ += 180.0f;
		else if (Para->PreviousCharacterLookDirection == "SE")  TargetYawZ += 135.0f;
		else if (Para->PreviousCharacterLookDirection == "S" )  TargetYawZ +=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "SW")  TargetYawZ +=  45.0f;
	}
}

void UPlayerAnimBase::Move_NW()
{
	if (Move_NWCheck) {
		     if (Para->PreviousCharacterLookDirection == "N" )  TargetYawZ -=  45.0f;
		else if (Para->PreviousCharacterLookDirection == "NE")  TargetYawZ -=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "E" )  TargetYawZ -= 135.0f;
		else if (Para->PreviousCharacterLookDirection == "SE")  TargetYawZ += 180.0f;
		else if (Para->PreviousCharacterLookDirection == "S" )  TargetYawZ += 135.0f;
		else if (Para->PreviousCharacterLookDirection == "SW")  TargetYawZ +=  90.0f;
		else if (Para->PreviousCharacterLookDirection == "W" )  TargetYawZ +=  45.0f;
	}
}

void UPlayerAnimBase::Rotate_Head()
{
	if (Para->GetSpringArm() != nullptr) {
		if (IsAlive_Anim) {
			if (IsReload_Anim) {
				CurrentHead02Roll = 0.0f; CurrentHead02Pitch = 0.0f; Head02Roll = 0.0f; Head02Pitch = 0.0f;
			}
			else {
				Head02Roll = Para->SpringArmRotation().Pitch; Head02Pitch = Para->SpringArmRotation().Pitch;
				if (!Move_NCheck) Head02Pitch = 0.0f;
				else if (!Move_NECheck) {}
				else if (!Move_ECheck) Head02Roll = 0.0f;
				else if (!Move_SECheck) Head02Roll *= -1.0f;
				else if (!Move_SCheck) {
					Head02Roll *= -1.0f;
					Head02Pitch = 0.0f;
				}
				else if (!Move_SWCheck) {
					Head02Roll *= -1.0f;
					Head02Pitch *= -1.0f;
				}
				else if (!Move_WCheck) {
					Head02Roll = 0.0f;
					Head02Pitch *= -1.0f;
				}
				else if (!Move_NWCheck) Head02Pitch *= -1.0f;
			}
		}

		else {
			CurrentHead02Roll = 0.0f;
			CurrentHead02Pitch = 0.0f;
			Head02Roll = 0.0f;
			Head02Pitch = 0.0f;
		}

	}
}

void UPlayerAnimBase::Rotate_Thigh()
{
	if (IsAlive_Anim) {
		if (IsReload_Anim) {
			ThighYaw = 0.0f;
			CurrentThighYaw = 0.0f;
		}
		else {
			     if (Para->BattleFootDirection == "N")  { ThighYaw = 0.0f;   PlayRate_BattleMode = 1.0f;  }
			else if (Para->BattleFootDirection == "NE") { ThighYaw = 7.5f;   PlayRate_BattleMode = 1.0f;  }
			else if (Para->BattleFootDirection == "E")  { ThighYaw = 15.0f;  PlayRate_BattleMode = 1.0f;  }
			else if (Para->BattleFootDirection == "SE") { ThighYaw = -7.5f;  PlayRate_BattleMode = -1.0f; }
			else if (Para->BattleFootDirection == "S")  { ThighYaw = 0.0f;   PlayRate_BattleMode = -1.0f; }
			else if (Para->BattleFootDirection == "SW") { ThighYaw = 7.5f;   PlayRate_BattleMode = -1.0f; }
			else if (Para->BattleFootDirection == "W")  { ThighYaw = -15.0f; PlayRate_BattleMode = 1.0f;  }
			else if (Para->BattleFootDirection == "NW") { ThighYaw = -7.5f;  PlayRate_BattleMode = 1.0f;  }
		}
	}
	else {
	ThighYaw = 0.0f;
	CurrentThighYaw = 0.0f;
	}
}

void UPlayerAnimBase::AnimNotify_Change_CombatMode()
{
	if (IsCombatMode_Anim) IsCombatMode_Anim = false;
	else IsCombatMode_Anim = true;
}

void UPlayerAnimBase::AnimNotify_Change_CombatMode2()
{
	Para->ChangeCombatMode();
}

void UPlayerAnimBase::AnimNotify_Change_CombatMode3()
{
	Para->ChangeMontageEnd();
}

void UPlayerAnimBase::AnimNotify_ShotAble()
{
	Para->JumpShotable();
}

void UPlayerAnimBase::AnimNotify_ReloadStart()
{
	// if (GEngine)
	// 	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
	IsReload_Anim = true;
}

void UPlayerAnimBase::AnimNotify_ReloadEnd()
{
	IsReload_Anim = false;
}

void UPlayerAnimBase::AnimNotify_ReloadEnd2()
{
	Para->ChangeReloadModeEnd();
}

void UPlayerAnimBase::AnimNotify_AnimDeath()
{
	IsAlive_Anim = false;
}

void UPlayerAnimBase::AnimNotify_LightOffandRebirthable()
{
	Para->LightOffAndRebirthAble();
}

void UPlayerAnimBase::AnimNotify_Anim_Rebirth()
{
	IsAlive_Anim = true;
	IsCombatMode_Anim = false;
	IsReload_Anim = false;
	// 함수 하나 더 넣어야 함
	Para->Rebirth();
}
