// Fill out your copyright notice in the Description page of Project Settings.
#include "Item.h"
#include "Slash3/DebugMacros.h"

// Sets constructor default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;
}

// Calls the virtual function BeginPlay() override.
void AItem::BeginPlay()
{
	// Super::BeginPlay() calls the base class's implementation of BeginPlay(). 
	// This is important to ensure that any functionality defined in the base class is executed properly.
	Super::BeginPlay();

	// Prints a message to the output log when the game starts.
	UE_LOG(LogTemp, Warning, TEXT("Greetings from the Item class BeginPlay() Function !!!"));

	// GEngine is a global pointer to the game engine, which provides various functions and properties related to the game.
	if (GEngine)
	{
		// This log message uses the GEngine pointer to display a message on the screen. 
		// It takes 4 parameters: a key (1 in this case), the duration to display the message (60 seconds),
		// the color of the text (cyan), and the message itself.
		// This is called when a "Print String" function in blueprint scripting is called and has 'Print to Screen' checked 'true'
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Greetings from the Item Class BeginPlay() Function !!!"));
	}

	// Cached world pointer used as a local staging point for testing new debug
	// helpers before promoting them into project-wide macros in Slash3.h.
	UWorld* World = GetWorld();

	// GetActorLocation() is a member function of the AActor class. 
	// Calls AActor::GetActorLocation() and returns the current position as an FVector.
	FVector Location = GetActorLocation();

	// GetActorForwardVector() is a member function of the AActor class 
	// that returns a unit vector representing the forward direction of the actor.
	FVector Forward = GetActorForwardVector();

	// DRAW_SPHERE is a macro defined in the project’s primary module header (Slash3.h).
	// DrawDebugSphere() function with specific parameters to draw a Green sphere at the given location in the world.
	DRAW_SPHERE_G(Location * 3.f);

	// DRAW_LINE is a macro defined in the project’s primary module header (Slash3.h).
	// It validates GetWorld() and draws a persistent blue debug line between two locations
	// using DrawDebugLine() with infinite lifetime and thickness of 1.0.
	DRAW_LINE_G(Location * 3.f, (Location * 3.f) + (Forward * 100.f));

	// DRAW_POINT is a macro defined in the project’s primary module header (Slash3.h).
	// It validates GetWorld() and draws a persistent blue debug point at the given location in the world
	// using DrawDebugPoint() with infinite lifetime and size of 20.
	DRAW_POINT_G((Location * 3.f) + (Forward * 100.f));

	// DRAW_SPHERE is a macro defined in the project’s primary module header (Slash3.h).
	// DrawDebugSphere() function with specific parameters to draw a red sphere at the given location in the world.
	DRAW_SPHERE(Location);

	// DRAW_VECTOR is a macro defined in the project’s primary module header (Slash3.h).
	DRAW_VECTOR(Location, Location + Forward * 100.f);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	// Super::Tick(DeltaTime) calls the base class's implementation of Tick().
	// The Super:: means that it is calling the Tick() function defined in the parent class (AActor in this case).
	Super::Tick(DeltaTime);
}

