// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(FName("Default Scene Root"));
	SetRootComponent(DefaultRoot);
	
	CapsuleCollider = CreateDefaultSubobject<UCapsuleComponent>(FName("CapsuleCollider"));
	CapsuleCollider->SetupAttachment(DefaultRoot);

	PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Paddle Mesh"));
	PaddleMesh->SetupAttachment(CapsuleCollider);

}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PaddleMappingContext, 0);
		}
	}
	
}

void APaddle::Move(const FInputActionValue& Value)
{
	const float CurrentValue = Value.Get<float>();
	if (CurrentValue)
	{
		FVector CurrentLocation = GetActorLocation();

		float MovementSpeed = 1500.f;
		float MovementDistance = CurrentValue * MovementSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);

		FVector NewLocation = CurrentLocation + FVector(0.f, MovementDistance, 0.f);

		float MinY = -1700.f;
		float MaxY = 1700.f;

		NewLocation.Y = FMath::Clamp(NewLocation.Y, MinY, MaxY);

		SetActorLocation(NewLocation);
	}
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APaddle::Move);
	}

}

