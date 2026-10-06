// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "Slash/DebugMacros.h" 

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	/*UE_LOG(LogTemp, Warning, TEXT("Begin Play called"));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 20.f, FColor::Cyan, FString("Item on Screen Message"));
	}*/

	//UWorld* World = GetWorld();


	/*SetActorLocation(FVector(0.f, 0.f, 50.f));
	SetActorRotation(FRotator(0.f, 45.f, 0.f));*/
	//FVector Location = GetActorLocation();
	//FVector Forward = GetActorForwardVector();
	/*if (World)
	{
		DrawDebugSphere(World, Location, 25.f, 12, FColor::Red, true);
	}*/
	//DRAW_SPHERE(Location);

	/*if (World)
	{
		FVector Forward = GetActorForwardVector();
		DrawDebugLine(World, Location, Location + Forward * 100.f, FColor::Blue, true, -1.f, 0, 1.f);
	}*/
	//DRAW_LINE(Location, Location + Forward * 100.f);

	/*if (World)
	{
		DrawDebugPoint(World, Location + Forward * 100.f, 15.f, FColor::Blue, true);
	}*/
	//DRAW_POINT(Location + Forward * 100.f);

	//DRAW_VECTOR(Location, Location + Forward * 100.f);
	
	//int32 AvgInt = Avg<int32>(1, 3);
	//UE_LOG(LogTemp, Warning, TEXT("Average of 1 and 3 is: %d"), AvgInt);

	//float AvgFloat = Avg<float>(1.21f, 3.42f);
	//UE_LOG(LogTemp, Warning, TEXT("Average of 1.21 and 3.42 is: %f"), AvgFloat);
}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);

	if (GEngine)
	{
		FString Name = GetName();
		FString Message = FString::Printf(TEXT("Item Name: %s"), *Name);
		GEngine->AddOnScreenDebugMessage(1, 20.f, FColor::Cyan, Message);

		UE_LOG(LogTemp, Warning, TEXT("Item Name: %s"), *Name);
	}*/

	//Movement rate in units per second
	/*float MovementRate = 50.f;
	float RotationRate = 45.f;*/

	//MovementRate(cm/s) * DeltaTime(s/frame) = Distance to move (cm/frame)
	/*AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));*/

	RunningTime += DeltaTime;

	//float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);

	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

	/*DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	DRAW_POINT_SingleFrame(AvgVector);*/

	float MovementRate = 50.f;
	float RotationRate = 360.f;
	AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));

}

