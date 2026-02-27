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

// pragma once tells the compiler to include this header file only once in a single compilation, 
// preventing duplicate definitions and improving compilation speed.
#pragma once

// This is a list of include directives that bring in the necessary header files for this class.
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

// A Macro that tells Unreal Engine to generate code for this class, enabling features like reflection and serialization. 
UCLASS()

// Creates a new class called AItem that inherits from AActor.
class SLASH3_API AItem : public AActor
{
	/* This macro is used to generate boilerplate code for the AItem class.
	It is necessary for Unreal Engine's reflection system, 
	which allows the engine to recognize and interact with the class in various ways, 
	such as exposing it to Blueprints, enabling serialization, and more. */
	GENERATED_BODY()
	
public:	
	// Creates a constructor for the AItem class.
	AItem();
	// Called every frame (this is the blueprint equivalent of the Event Tick in Unreal Engine).
	virtual void Tick(float DeltaTime) override;

protected:
	// Creates a function override for the BeginPlay() function.
	virtual void BeginPlay() override;
};
