// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// This MACRO creates a simple way to draw a debug sphere in the world at a specified location.
// It checks if the world context is valid using GetWorld(), and if so, 
// it calls the DrawDebugSphere() function with specific parameters:
#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true);

// This MACRO creates a simple way to draw a debug line in the world between two specified locations.
// It checks if the world context is valid using GetWorld(), and if so,
// it calls the DrawDebugLine() function with specific parameters:
#define DRAW_LINE(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Blue, true, -1.f, 0, 1.f);
