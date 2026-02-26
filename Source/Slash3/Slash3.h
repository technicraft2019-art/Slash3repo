// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// This macro creates a simple way to draw a debug sphere in the world at a specified location.
// It checks if the world context is valid using GetWorld(), and if so, 
// it calls the DrawDebugSphere() function with specific parameters:
#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true);
