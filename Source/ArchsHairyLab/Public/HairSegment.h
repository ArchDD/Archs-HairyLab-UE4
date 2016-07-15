// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "HairSegment.generated.h"

UCLASS()
class ARCHSHAIRYLAB_API AHairSegment : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh Components")
	class UProceduralMeshComponent* ProceduralMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spline Components")
	class USplineComponent* Spline;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Segment Variables")
	TArray<FVector> Normals;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Segment Variables")
	TArray<class AHairNode*> Nodes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Segment Variables")
	UMaterialInterface* Material;

	// Sets default values for this actor's properties
	AHairSegment();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Spline Methods")
	void AddSplinePoint(FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Segment Methods")
	void SetSegmentMaterial(int Index, UMaterialInterface* InMaterial);
};
