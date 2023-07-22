// Copyright Epic Games, Inc. All Rights Reserved.


#include "Pregunta2GameModeBase.h"
#include "Cuerpo1.h"


APregunta2GameModeBase::APregunta2GameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	Tiempo = 0.0f;
	ControlT = 3.0f;
}

void APregunta2GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	for (int i = 0; i < 4; i++)
	{
		ACuerpo1* Cuerpo = GetWorld()->SpawnActor<ACuerpo1>(ACuerpo1::StaticClass());
		Cuerpo->SetActorLocation(FVector(0, 0, 100 * i));

		Cuerpos.Add(Cuerpo);
	}
}

void APregunta2GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Tiempo++;
	
	if (Tiempo >= ControlT)
	{
		//Cuerpos[indice]->Pintar();
		
		//Cuerpos[indice]->Mover(FVector(0,10,10), FVector(10,10,10), FRotator(0,0,0));
		if (indice < 4) {
			indice++;
		}
		else {
			indice = 0;
		}
		Tiempo = 0;
	}
}

