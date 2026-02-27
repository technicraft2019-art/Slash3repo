// ============================================================
//  Copyright (c) 2026 Charles C. Poole Jr.
//  d/b/a CPTechnicraft Interactive Studio
//
//  All Rights Reserved.
//
//  This software and associated source files are the intellectual
//  property of Charles C. Poole Jr. Unauthorized copying,
//  modification, distribution, or use without permission is
//  prohibited except where expressly allowed.
//
//  Project: Slash3 (Unreal Engine)
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"

// Debug helpers.
// IMPORTANT:
// These macros require a calling context that has GetWorld() available
// (commonly AActor, UActorComponent, or a UObject that can return a valid UWorld*).

// Draw a persistent debug sphere at Location.
// Input Parameters for Location and Color, the rest are manually set
#define DRAW_SPHERE(Location, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugSphere(__World, (Location), 25.f, 12, Color, true, -1.f, 0, 1.f); \
    } \
} while (0)

// Draw a persistent debug line from one Location to another location.
// Input Parameters for StartLocation, EndLocation and Color, the rest are manually set
#define DRAW_LINE(StartLocation, EndLocation, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugLine(__World, StartLocation, EndLocation, Color, true, -1.f, 0, 1.f); \
    } \
} while (0)

// Draw a persistent debug point at Location.
// Input Parameters for Location and Color, the rest are manually set
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

// Draws a persistent debug directional arrow from one Location to another location.
// Input Parameters for StartLocation, EndLocation and Color, the rest are manually set
#define DRAW_DIR_ARROW(StartLocation, EndLocation, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) \
    { \
        DrawDebugDirectionalArrow(__World, StartLocation, EndLocation, 50.f, Color, true, -1.f, 0, 5.f); \
    } \
} while (0)
