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
    int idRaza;
    int edad;
    float peso;
    char sexo;
    int idDueno;
    int isEmpty;
}Emascota;

int getEmptyPositionEmascota(Emascota [],int );

int newIdEmascota(Emascota [],int );

int findEmascotaById(Emascota [], int ,int );

float promEdadMascotas(Emascota [], int);

float promEdadMascotasTipo(Emascota [], int,int);
