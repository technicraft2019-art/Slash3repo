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
	UE_LOG(LogTemp, Warning, TEXT("Hello from Item class BeginPlay()"));

	// GEngine is a global pointer to the game engine, which provides various functions and properties related to the game.
	if (GEngine)
	{
		// This log message uses the GEngine pointer to display a message on the screen. 
		// It takes 4 parameters: a key (1 in this case), the duration to display the message (60 seconds),
		// the color of the text (cyan), and the message itself.
		// This is called when a "Print String" function in blueprint scripting is called and has 'Print to Log' checked 'true'
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Item on Screen Message from BeginPlay() !!!"));
	}

	// GetWorld() is a member function of the AActor class that returns a pointer to the UWorld object that this actor belongs to.
	UWorld* World = GetWorld();

	// This checks if the World pointer is valid (not null) before attempting to use it. 
	// Then it calls the DrawDebugSphere() function.
	if (World)
	{
		// GetActorLocation() is a member function of the AActor class. 
		// Calls AActor::GetActorLocation() and returns the current position as an FVector.
		FVector Location = GetActorLocation();
		// DRAW_SPHERE is a macro defined at the top of this file that takes a Location parameter and calls the 
		// DrawDebugSphere() function with specific parameters to draw a red sphere at the given location in the world.
		DRAW_SPHERE(Location);
	}

}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	// Super::Tick(DeltaTime) calls the base class's implementation of Tick().
	Super::Tick(DeltaTime);

	// Prints the value of DeltaTime to the output log.
	UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);

	// GEngine is a global pointer to the game engine, which provides various functions and properties related to the game.
	if (GEngine)
	{
		// Get the name of the item using the GetName() function, which is inherited from the UObject class.
		FString Name = GetName();

		// Create a formatted message string that includes the name of the item. 
		// The FString::Printf function is used to format the string, similar to printf in C.
		// The * operator is used to dereference the FString and get a pointer to the underlying character array, 
		// which is required for the %s format specifier.
		FString Message = FString::Printf(TEXT("Item Name: %s"), *Name);

		// This log message uses the GEngine pointer to display a message on the screen. 
		// It takes 4 parameters: a key (1 in this case), the duration to display the message (60 seconds),
		// the color of the text (cyan), and the message itself.
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, Message);

		// Prints the name of the item to the output log. 
		// The * operator is used to dereference the FString and get a pointer to the underlying character array.
		UE_LOG(LogTemp, Warning, TEXT("Item Name: %s"), *Name);
	}
}

