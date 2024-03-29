// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
public:	
	UGrabber();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	// How far ahead of the player can we reach in cm
	float Reach = 100.f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	// Raycast and grab what is in reach
	void Grab();
	// Called when grab is released
	void GrabReleased();
	// Find attached physics handle
	void FindPhysicsHandleComponent();
	// Setup (assumed) attached input component
	void SetupInputComponent();
	// Return hit for first physics body in reach
	FHitResult GetFirstPhysicsBodyInReach() const;
	// Returns current start of reach line
	FVector GetReachLineStart() const;
	// Returns current end of reach line
	FVector GetReachLineEnd() const;
};
