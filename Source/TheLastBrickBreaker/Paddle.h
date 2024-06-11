// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Paddle.generated.h"

UCLASS()
class THELASTBRICKBREAKER_API APaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	class UInputMappingContext* PaddleMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* MoveAction;

	void Move(const FInputActionValue& value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Base Properties")
	USceneComponent* DefaultRoot;
	
	UPROPERTY(EditAnywhere, Category = "Base Properties")
	class UCapsuleComponent* CapsuleCollider = nullptr;

	UPROPERTY(EditAnywhere, Category="Base Properties")
	class UStaticMeshComponent* PaddleMesh = nullptr;

};
