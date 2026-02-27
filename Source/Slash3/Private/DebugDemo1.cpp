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

#include "DebugDemo1.h"
#include "Slash3/DebugMacros.h"

// Sets default values
ADebugDemo1::ADebugDemo1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADebugDemo1::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADebugDemo1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float MovementSpeed = 50.f;
	float RotationRate = 45.f;
	AddActorWorldOffset(FVector(MovementSpeed * DeltaTime, 0.f, 0.f));
	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
	DRAW_SPHERE_SingleFrame(GetActorLocation(), FColor::Cyan);
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f, FColor::Green);
}

