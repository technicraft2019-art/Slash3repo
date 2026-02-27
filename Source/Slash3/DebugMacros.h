#pragma once

#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"

// Debug helpers.
// IMPORTANT:
// These macros require a calling context that has GetWorld() available
// (commonly AActor, UActorComponent, or a UObject that can return a valid UWorld*).

// Draw a persistent red debug sphere at Location.
// Radius = 25, Segments = 12, Persistent = true
#define DRAW_SPHERE(Location, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugSphere(__World, (Location), 25.f, 12, Color, true, -1.f, 0, 1.f); \
    } \
} while (0)

// Draw a persistent blue debug line from StartLocation to EndLocation.
// Color = Blue, Persistent = true, Lifetime = -1 (infinite), DepthPriority = 0, Thickness = 1.0
#define DRAW_LINE(StartLocation, EndLocation, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugLine(__World, StartLocation, EndLocation, Color, true, -1.f, 0, 1.f); \
    } \
} while (0)

// Draw a persistent blue debug point at Location.
// Color = Blue, Persistent = true, Lifetime = -1 (infinite), DepthPriority = 0, Size = 20
#define DRAW_POINT(Location, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugPoint(__World, Location, 20.f, Color, true, -1.f, 0); \
    } \
} while (0)

// Draws a persistent debug line between StartLocation and EndLocation and a debug point at EndLocation. 
// Uses the DRAW_LINE() and DRAW_POINT() MACROS.
#define DRAW_VECTOR(StartLocation, EndLocation, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) \
    { \
        DrawDebugLine(__World, StartLocation, EndLocation, Color, true, -1.f, 0, 1.f); \
        DrawDebugPoint(__World, EndLocation, 20.f, Color, true, -1.f, 0); \
    } \
} while (0)

#define DRAW_DIR_ARROW(StartLocation, EndLocation, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) \
    { \
        DrawDebugDirectionalArrow(__World, StartLocation, EndLocation, 50.f, Color, true, -1.f, 0, 5.f); \
    } \
} while (0)
