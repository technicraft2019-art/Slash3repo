// Copyright (c) 2026 Charles C. Poole Jr.   d/b/a CPTechnicraft Interactive Studio

#include "Pawns/Bird1.h"

ABird1::ABird1()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABird1::BeginPlay()
{
	Super::BeginPlay();
}

void ABird1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABird1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

