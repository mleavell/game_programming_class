// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Countdown.generated.h"

/**
 * 
 */
UCLASS()
class BOMB_API ACountdown : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 CountdownTime;

	ACountdown(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	void Count();
};
