// Copyright (c) 2026 Charles C. Poole Jr.   d/b/a CPTechnicraft Interactive Studio

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item2.generated.h"

UCLASS()
class SLASH3_API AItem2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem2();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters");
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters");
	float TimeConstant = 5.f;

	UFUNCTION(BlueprintPure, Category = "My Math")
	float TransformedSin() const;

	UFUNCTION(BlueprintPure, Category = "My Math")
	float TransformedCos() const;

	// Declaration of a function template, fpr a template named Avg() of type T.
	template<typename T>
	T Avg(T First, T Second);

private:
	// Keep the UPROPERTY and the member on the same line to avoid parser/IDE tokenization issues.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Sine Parameters");
	float RunningTime = 0.f;

	// Creates a pointer to a UStaticMeshComponent and name it ItemMesh.
	// Make this pointer visible in the editor details panel and instances in Unreal Engine Blueprints.
	// It is not editable in the editor anywhere.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ItemMesh;
};

// Defintion of the type T function named Avg(), used with inline specifier for efficiency.
// This Definition limits the template usage to types that can be used with the "+" and "/" operators.
// This Definition lies outside the class Declaration, so it is visible to all .cpp files who implement it.
template<typename T>
inline T AItem2::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
