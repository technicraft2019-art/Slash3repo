// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"

// Debug helpers.
// IMPORTANT:
// These macros require a calling context that has GetWorld() available
// (commonly AActor, UActorComponent, or a UObject that can return a valid UWorld*).

// Draw a persistent red debug sphere at Location.
// Radius = 25, Segments = 12, Persistent = true
#define DRAW_SPHERE(Location) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugSphere(__World, (Location), 25.f, 12, FColor::Red, true); \
    } \
} while (0)

// Draw a persistent blue debug line from StartLocation to EndLocation.
// Color = Blue, Persistent = true, Lifetime = -1 (infinite), DepthPriority = 0, Thickness = 1.0
#define DRAW_LINE(StartLocation, EndLocation) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugLine(__World, (StartLocation), (EndLocation), FColor::Blue, true, -1.f, 0, 1.f); \
    } \
} while (0)