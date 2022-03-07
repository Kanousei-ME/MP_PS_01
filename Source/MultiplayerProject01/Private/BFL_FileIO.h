// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "Engine/Texture2d.h"
#include "Engine/SkeletalMesh.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <Runtime\Core\Public\Misc\FileHelper.h>
#include "BFL_FileIO.generated.h"


/**
 * 
 */
UCLASS()
class UBFL_FileIO : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "File I/O")
		static FString LoadFileToString(FString FileName);

	UFUNCTION(BlueprintCallable, Category = "File I/O")
		static TArray<FString> LoadFileToStringArray(FString FileName);

	UFUNCTION(BlueprintCallable, Category = "File I/O")
		static bool LoadText(FString FileName, FString& SaveTextA);

	UFUNCTION(BlueprintCallable, Category = "File I/O")
		static USkeletalMesh* TestLoadObjCharacter(FString& path);

};
