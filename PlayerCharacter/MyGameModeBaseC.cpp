// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBaseC.h"
#include "PlayerCharacter/MyPlayerCharacterC.h"
#include "PlayerCharacter/MyPlayerControllerC.h"

AMyGameModeBaseC::AMyGameModeBaseC() {
	DefaultPawnClass = AMyPlayerCharacterC::StaticClass();
	PlayerControllerClass = AMyPlayerControllerC::StaticClass();

}


