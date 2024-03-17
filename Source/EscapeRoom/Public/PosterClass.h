// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Materials/MaterialInterface.h" // 包含材质接口的头文件
#include "Engine/Texture2D.h"
#include "Engine/Texture.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/TextureRenderTarget.h"
#include "Engine/TextureCube.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Components/PrimitiveComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PosterClass.generated.h"

UCLASS()
class ESCAPEROOM_API APosterClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APosterClass();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FFilePath Path;

	// Function to load a PNG image from the specified file path and convert it to a texture
	UFUNCTION(BlueprintCallable, Category = "Custom")
	UTexture2D* LoadTextureFromPath(const FString& FilePath);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInterface* MaterialTemplate; // Material Template pointer, initialized in child

};

