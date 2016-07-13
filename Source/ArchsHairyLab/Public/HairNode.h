// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "HairNode.generated.h"

UCLASS()
class ARCHSHAIRYLAB_API AHairNode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHairNode();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(BlueprintReadWrite, Category = "Node Variables")
	class AHairSegment* Segment;

	UPROPERTY(BlueprintReadWrite, Category = "Node Variables")
	int Index;
};
