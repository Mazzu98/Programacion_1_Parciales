#include "cliente.h"
#include "mascota.h"

int initEmascota(Emascota [], int,Ecliente [],int );

int hardCodeEmascota(Emascota [], int ,Ecliente [],int,char [],int,char [],int ,float ,char ,int);

void hardCodeInicialMascotas(Emascota [],int,Ecliente [],int);

void imprimirListaEmascotaCD(Emascota [],int,Ecliente [],int); //2

void imprimirClientesConMascota(Ecliente [],int,Emascota [],int);//3

int addMascota(Emascota [], int ,Ecliente [], int ); //4

int bajaMascota(Emascota [],int,Ecliente [],int ); //5

int modificarMascota(Emascota [],int,Ecliente [], int ); //6

int borrarCliente(Ecliente [],int,Emascota [],int); //8

void imprimirMascotaCD(Emascota,Ecliente [],int);

void ordenarPorTipo(Emascota [],int ,Ecliente[],int); //9

void imprimirClientesVariasMascotas(Ecliente [],int,Emascota [],int,int); //11

void imprimirMascotasSiEsMayorA(Ecliente [],int,Emascota [],int,int); // 12

void imprimirMascotaPorTipo(Emascota [],int,Ecliente[],int,int); //13

void ordenarDuenoPorCantidades(Ecliente [],int);

void ordenarDuenoPorCantidadesYalfabeto(Ecliente [],int);

void mensaje(int,char [],char []);

void menuPrincipal();

void menuListar(Emascota [],int,Ecliente [],int );

void menuABM(Emascota [],int,Ecliente [],int );

void menuOrdenar(Emascota [],int,Ecliente [],int );

void menuPromedios(Emascota [],int,Ecliente [],int );


