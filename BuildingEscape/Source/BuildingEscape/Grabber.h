// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	float Reach{ 100.f };

	UPhysicsHandleComponent* PhysicsHandle{ nullptr };
	
	UInputComponent* InputComponent {nullptr };


	void SetupInputComponent();

	void FindPhysicsHandleComponent();

	void Grab();
	void Release();

	const FHitResult GetFirstPhysicsBodyInReach();
	const FVector GetReachLineStart() const;
	const FVector GetReachLineEnd() const;
};
