#include "piloto.h"
#include<stdlib.h>
#include<string.h>

Piloto* newPiloto()
{
    Piloto* nuevo;
    nuevo = (Piloto*)calloc(sizeof(Piloto),1);
    return nuevo;
}

Piloto* newPilotoParametrized(char* id,char* nombre)
{
    Piloto* nuevo;
    nuevo = newPiloto();
    if(nuevo != NULL)
    {
        nuevo->id = atoi(id);
        strcpy(nuevo->nombre,nombre);
    }
    return nuevo;
}



int getIdP(Piloto* piloto,int* id)
{
    int ret = 1;
    if(piloto != NULL)
    {
        *id = piloto->id;
        ret = 0;
    }
    return ret;
}

int getNombreP(Piloto* piloto,char* nombre)
{
    int ret = 1;
    if(piloto != NULL)
    {
        strcpy(nombre,piloto->nombre);
        ret = 0;
    }
    return ret;
}

int setIdP(Piloto* piloto,int id)
{
    int ret = 1 ;
    if(piloto != NULL)
    {
        piloto->id = id;
        ret = 0;
    }
    return ret;
}

int setNombreP(Piloto* piloto,char* nombre)
{
    int ret = 1;
    if(piloto != NULL)
    {
        strcpy(piloto->nombre,nombre);
        ret = 0;
    }
    return ret;
}
