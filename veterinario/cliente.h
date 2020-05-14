#include <stdio.h>
#include <string.h>
#define TAM 51

typedef struct
{
    int id;
    char nombre[TAM];
    char apellido[TAM];
    char localidad[TAM];
    int tel;
    int edad;
    char sexo;
    int isEmpty;
}Ecliente;

int initEcliente(Ecliente [], int );

int hardCodeEcliente(Ecliente [], int ,char [],char [],char [],int ,int ,char );

int getEmptyPositionEcliente(Ecliente [],int );

int newIdEcliente(Ecliente [],int );

void imprimirListaEcliente(Ecliente [],int);

void imprimirEcliente(Ecliente);

int findEclienteById(Ecliente [], int ,int );

int altaCliente(Ecliente [],int );

int modificarCliente(Ecliente [],int);

