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

#define DRAW_SPHERE(Location, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugSphere(__World, (Location), 25.f, 12, Color, true, -1.f, 0, 1.f); \
    } \
} while (0)

#define DRAW_SPHERE_SingleFrame(Location, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugSphere(__World, (Location), 25.f, 12, Color, false, -1.f, 0, 1.f); \
    } \
} while (0)

#define DRAW_LINE(StartLocation, EndLocation, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugLine(__World, StartLocation, EndLocation, Color, true, -1.f, 0, 1.f); \
    } \
} while (0)

#define DRAW_LINE_SingleFrame(StartLocation, EndLocation, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugLine(__World, StartLocation, EndLocation, Color, false, -1.f, 0, 1.f); \
    } \
} while (0)

#define DRAW_POINT(Location, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugPoint(__World, Location, 20.f, Color, true, -1.f, 0); \
    } \
} while (0)

#define DRAW_POINT_SingleFrame(Location, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) { \
        DrawDebugPoint(__World, Location, 20.f, Color, false, -1.f, 0); \
    } \
} while (0)

#define DRAW_VECTOR(StartLocation, EndLocation, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) \
    { \
        DrawDebugLine(__World, StartLocation, EndLocation, Color, true, -1.f, 0, 1.f); \
        DrawDebugPoint(__World, EndLocation, 20.f, Color, true, -1.f, 0); \
    } \
} while (0)

#define DRAW_VECTOR_SingleFrame(StartLocation, EndLocation, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) \
    { \
        DrawDebugLine(__World, StartLocation, EndLocation, Color, false, -1.f, 0, 1.f); \
        DrawDebugPoint(__World, EndLocation, 20.f, Color, false, -1.f, 0); \
    } \
} while (0)

#define DRAW_DIR_ARROW(StartLocation, EndLocation, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) \
    { \
        DrawDebugDirectionalArrow(__World, StartLocation, EndLocation, 50.f, Color, true, -1.f, 0, 3.f); \
    } \
} while (0)

#define DRAW_DIR_ARROW_SingleFrame(StartLocation, EndLocation, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) \
    { \
        DrawDebugDirectionalArrow(__World, StartLocation, EndLocation, 50.f, Color, false, -1.f, 0, 3.f); \
    } \
} while (0)

#define DRAW_COORD_SYS(Location, Rotation) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) \
    { \
        DrawDebugCoordinateSystem(__World, Location, Rotation, 15.f, true, -1.f, 0, 2.f); \
    } \
} while (0)

#define DRAW_COORD_SYS_SingleFrame(Location, Rotation) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) \
    { \
        DrawDebugCoordinateSystem(__World, Location, Rotation, 15.f, false, -1.f, 0, 2.f); \
    } \
} while (0)

#define DRAW_STRING(Location, NewString, Color) \
do { \
    UWorld* __World = GetWorld(); \
    if (__World) \
    { \
        DrawDebugString(__World, Location, NewString, nullptr, Color, -1.f, false, 3.F); \
    } \
} while (0)
