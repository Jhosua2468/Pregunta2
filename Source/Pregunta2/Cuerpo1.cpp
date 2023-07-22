// Fill out your copyright notice in the Description page of Project Settings.


#include "Cuerpo1.h"

// Sets default values
ACuerpo1::ACuerpo1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh1"));
	Mesh1->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")).Object);
	//Mesh1->SetMaterial(0, ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'")).Object);
	RootComponent = Mesh1;

}

// Called when the game starts or when spawned
void ACuerpo1::BeginPlay()
{
	Super::BeginPlay();
	UMaterial* Material0 = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Rock_Sandstone.M_Rock_Sandstone'"));
	UMaterial* Material1 = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
	UMaterial* Material2 = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));
	UMaterial* Material3 = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Metal_Rusted_Steel.M_Metal_Rusted_Steel'"));
	Materiales.Add(Material0);
	Materiales.Add(Material1);
	Materiales.Add(Material2);
	Materiales.Add(Material3);
	indice=0;
}

// Called every frame
void ACuerpo1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACuerpo1::Pintar()
{

	Mesh1->SetMaterial(0, Materiales[indice]);
	FVector Locacion = FVector(0.0f, 0.0f, 0.0f);
	FVector escala = FVector(0.1f, 0.1f, 0.1f);
	FRotator rotacion = FRotator(0.0f, 0.0f, 0.0f);
	indice++;
	if (indice >=3)
	{
		indice = 0;
	}
	Mesh1->SetRelativeLocationAndRotation(Locacion, rotacion);
	Mesh1->SetRelativeScale3D(escala);


}

void ACuerpo1::Mover(FVector Locacion, FVector escala, FRotator rotacion)
{

	this->SetActorLocation(Locacion);
	this->SetActorRotation(rotacion);
	this->SetActorScale3D(escala);
}
