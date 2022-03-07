// Fill out your copyright notice in the Description page of Project Settings.


#include "BFL_FileIO.h"
#include <Runtime\Core\Public\Misc\Paths.h>
#include <Runtime\Core\Public\HAL\PlatformFilemanager.h>


FString UBFL_FileIO::LoadFileToString(FString FileName)
{
	FString directory = FPaths::RootDir();
	FString result;
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	FString myFile;

	if (file.CreateDirectory(*directory))
	{
		myFile = directory + FileName;
		FFileHelper::LoadFileToString(result, *myFile);

		//Debug messages
		//if (GEngine)	
		GEngine->AddOnScreenDebugMessage(0, 20, FColor::Black, (myFile),true);

		

		if (FPaths::FileExists(myFile))
		{
			//if (GEngine)
				GEngine->AddOnScreenDebugMessage(1, 20, FColor::Red, (myFile),true);
		}

		

	}
	
	
	return result;

}

TArray<FString> UBFL_FileIO::LoadFileToStringArray(FString FileName)
{
	FString directory = FPaths::ProjectDir();
	TArray<FString> result;
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*directory))
	{
		FString myFile = directory + "/" + FileName;
		FFileHelper::LoadFileToStringArray(result, *myFile);
	}

	return result;
}

bool UBFL_FileIO::LoadText(FString FileName, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDevelopersDir() + FileName));
}



USkeletalMesh* UBFL_FileIO::TestLoadObjCharacter(FString& path)
{
	USkeletalMesh* meshClass;
	FString dirPath = FPaths::RootDir() + "Database/";
	

	meshClass = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, *(path)));

	return meshClass;

}

