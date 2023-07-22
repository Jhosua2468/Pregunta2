// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cuerpo1.generated.h"

UCLASS()
class PREGUNTA2_API ACuerpo1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACuerpo1();
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh1;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	void Pintar();
	TArray<class UMaterial*> Materiales = {};
	int indice ;
	void Mover(FVector Locacion, FVector escala, FRotator rotacion);

};
