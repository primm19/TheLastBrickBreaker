// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/SphereComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	DefaultRoot = CreateDefaultSubobject<USceneComponent>(FName("Default Scene Root"));
	SetRootComponent(DefaultRoot);

	SphereCollider = CreateDefaultSubobject<USphereComponent>(FName("Sphere Collider"));
	SphereCollider->SetupAttachment(DefaultRoot);

	PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Paddle Mesh"));
	PaddleMesh->SetupAttachment(SphereCollider);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

