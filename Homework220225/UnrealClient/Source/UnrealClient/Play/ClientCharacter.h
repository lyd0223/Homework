// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ClientEnums.h"
#include "ClientCharacter.generated.h"

class UClientAnimInstance;

UCLASS()
class UNREALCLIENT_API AClientCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AClientCharacter();

	FORCEINLINE UClientAnimInstance* GetClientAnimInstance() 
	{
		return AnimationInst;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientData", meta = (AllowPrivateAccess = "true"))
	TMap <ClientAnimationType, class UAnimMontage* > Animations_;

	UClientAnimInstance* AnimationInst;
};
