// Copyright (c) 2026 Charles C. Poole Jr.   d/b/a CPTechnicraft Interactive Studio


#include "Item2.h"
#include "Slash3/DebugMacros.h"

// Sets default values
AItem2::AItem2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and register a UStaticMeshComponent default subobject and store its pointer in ItemMesh.
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	// Replaces the RootComponent with the component stored in ItemMesh.
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AItem2::BeginPlay()
{
	Super::BeginPlay();

	DRAW_COORD_SYS(FVector::ZeroVector, FRotator::ZeroRotator);
}

// Customized use of the Sin function
float AItem2::TransformedSin() const
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

//Customized use of the Cos function
float AItem2::TransformedCos() const
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItem2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	// float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();

	// AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	DRAW_SPHERE_SingleFrame(Location, FColor::Blue);
	DRAW_VECTOR_SingleFrame(Location, Location + Forward * 100.f, FColor::Blue);

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	DRAW_POINT_SingleFrame(AvgVector, FColor::Cyan);
}

