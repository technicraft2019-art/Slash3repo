// Copyright (c) 2026 Charles C. Poole Jr.   d/b/a CPTechnicraft Interactive Studio


#include "Item2.h"
#include "Slash3/DebugMacros.h"

// Sets default values
AItem2::AItem2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItem2::BeginPlay()
{
	Super::BeginPlay();

	int32 AvgInt = Avg<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3: %d"), AvgInt);

	float AvgFloat = Avg<float>(3.45f, 7.86f);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 3.45 and 7.86: %f"), AvgFloat);

}

// Customized use of the Sin function
float AItem2::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

//Customized use of the Cos function
float AItem2::TransformedCos()
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
}

