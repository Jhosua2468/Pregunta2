// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Pregunta2GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PREGUNTA2_API APregunta2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	APregunta2GameModeBase();
	virtual void Tick(float DeltaTime) override;
	UPROPERTY()
		TArray<class ACuerpo1*> Cuerpos = {};
	

protected:
	virtual void BeginPlay() override;
	float Tiempo;
	float ControlT;
	int indice = 0;
	FVector Locacion = FVector(0.0f, 0.0f, 0.0f);
	FVector escala = FVector(0.1f, 0.1f, 0.1f);
	FRotator rotacion = FRotator(0.0f, 0.0f, 0.0f);

	
};
