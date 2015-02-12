// Fill out your copyright notice in the Description page of Project Settings.

#include "Bomb.h"
#include "Countdown.h"

ACountdown::ACountdown(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	CountdownTime = 10;
}

void ACountdown::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		Count();
	}
}

void ACountdown::Count()
{
	if (CountdownTime >= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::FromInt(CountdownTime));
		CountdownTime--;
		GetWorldTimerManager().SetTimer(this, &ACountdown::Count, 1.f, true);
	}
}