// ============================================================
//  Copyright (c) 2026 Charles C. Poole Jr.
//  d/b/a CPTechnicraft Interactive Studio
//
//  All Rights Reserved.
//
//  This software and associated source files are the intellectual
//  property of Charles C. Poole Jr. Unauthorized copying,
//  modification, distribution, or use without permission is
//  prohibited except where expressly allowed.
//
//  Project: Slash3 (Unreal Engine)
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugDemo1.generated.h"

UCLASS()
class SLASH3_API ADebugDemo1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADebugDemo1();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
