#include "entradaValidada.h"
#include <stdio.h>
#include <string.h>
#define TAM 51

typedef struct
{
    int id;
    char nombre[TAM];
    int tipo;
    char raza[TAM];
    int edad;
    float peso;
    char sexo;
    int idDueno;
    int isEmpty;
}Emascota;

int initEmascota(Emascota [], int );

int hardCodeEmascota(Emascota [], int ,char [],int,char [],int ,float ,char ,int);

int getEmptyPositionEmascota(Emascota [],int );

int newIdEmascota(Emascota [],int );

int bajaMascota(Emascota [],int );

int findEmascotaById(Emascota [], int ,int );


