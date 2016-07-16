// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Hair.generated.h"

UCLASS()
class ARCHSHAIRYLAB_API AHair : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHair();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<class AHairLayer*> HairLayers;
	
	UPROPERTY(BlueprintReadWrite)
	float GlobalXWidth = 100.0f;

	UPROPERTY(BlueprintReadWrite)
	float GlobalYWidth = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UProceduralMeshData* ProceduralMeshData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UProceduralMeshData* StartMeshData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UProceduralMeshData* MiddleMeshData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UProceduralMeshData* EndMeshData;

	// Data for connecting to components
	UPROPERTY(BlueprintReadWrite)
	FVector AnchorA = FVector(0, 0, 0);
	UPROPERTY(BlueprintReadWrite)
	FVector AnchorB = FVector(0, 0, 0);
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> EndPointsA;
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> EndPointsB;
	UPROPERTY(BlueprintReadWrite)
	FVector P1 = FVector(0, 0, 0);
	UPROPERTY(BlueprintReadWrite)
	FVector P2 = FVector(0, 0, 0);

	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> Vertices;
	UPROPERTY(BlueprintReadWrite)
	TArray<int> Triangles;
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector2D> UVs;

	UPROPERTY(BlueprintReadWrite)
	int NumTriangles = 0;
	//UPROPERTY(BlueprintReadWrite)
	//int NumNodes = 0;
	UPROPERTY(BlueprintReadWrite)
	bool IsUVReversed = true;
	UPROPERTY(BlueprintReadWrite)
	bool IsExtending = false;
	UPROPERTY(BlueprintReadWrite)
	float Weight = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Prodecural Mesh Methods")
	void CalculateEndPoints(TArray<FVector> InVertices);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Methods")
	void SetupMesh();

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Methods")
	void AssignPositions(FVector InP1, FVector InP2);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	AHairSegment* SpawnSegment();

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	void ExtendSegment();

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	AHairNode* SpawnNode(AMyPlayerController* Controller, UWorld* World, FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	void UpdateSegment(class AHairSegment* InSegment);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Generation")
	void ClearMeshData();

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Methods")
	FVector MapVertex(FVector V, FVector Direction, FVector Normal, float XWidth, float YWidth, float InWeight);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Methods")
	void AddVertices(int FirstIndex, TArray<FVector> InVertices, FVector Direction, FVector Normal);

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Methods")
	void AddTriangles();

	UFUNCTION(BlueprintCallable, Category = "Procedural Mesh Methods")
	void AddUVs(bool IsFirst);
};
