// Copyright (c) 2026 Charles C. Poole Jr.   d/b/a CPTechnicraft Interactive Studio

#include "Pawns/Bird1.h"
#include "Components/CapsuleComponent.h"

ABird1::ABird1()
{
	PrimaryActorTick.bCanEverTick = true;

	// Setting up the Capsule Collision Component.
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);
	SetRootComponent(Capsule);
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