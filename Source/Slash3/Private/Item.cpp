// Fill out your copyright notice in the Description page of Project Settings.
#include "Item.h"
#include "DrawDebugHelpers.h"
#include "Slash3/Slash3.h"

// This macro creates a simple way to draw a debug sphere in the world at a specified location.
// It checks if the world context is valid using GetWorld(), and if so, 
// it calls the DrawDebugSphere() function with specific parameters:
// Macro is commented out here because it is already defined in Slash3.h, which is included in Item.h.
/*  #define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true);  */

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

	// GetWorld() is a member function of the AActor class that returns a pointer to the UWorld object that this actor belongs to.
	UWorld* World = GetWorld();

	// GetActorLocation() is a member function of the AActor class. 
	// Calls AActor::GetActorLocation() and returns the current position as an FVector.
	FVector Location = GetActorLocation();

	// GetActorForwardVector() is a member function of the AActor class 
	// that returns a unit vector representing the forward direction of the actor.
	FVector Forward = GetActorForwardVector();

	// DRAW_SPHERE is a macro defined Primary Project Module file. It takes a Location parameter and calls the 
	// DrawDebugSphere() function with specific parameters to draw a red sphere at the given location in the world.
	DRAW_SPHERE(Location);

	// DRAW_LINE is a macro defined Primary Project Module file. It takes two parameters, StartLocation and EndLocation, and calls the
	// DrawDebugLine() function is used to draw a line in the world for debugging purposes.
	DRAW_LINE(Location, Location + Forward * 100.f);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	// Super::Tick(DeltaTime) calls the base class's implementation of Tick().
	// The Super:: means that it is calling the Tick() function defined in the parent class (AActor in this case).
	Super::Tick(DeltaTime);
}

