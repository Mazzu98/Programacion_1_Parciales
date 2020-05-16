#include "mascota.h"

int initEmascota(Emascota list[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        list[i].isEmpty = 1;
        list[i].id = 0;
    }
    return 0;
}

int getEmptyPositionEmascota(Emascota list[],int tam)
{
    int i, index = -1;
    for(i=0;i<tam;i++)
    {
        if(list[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int newIdEmascota(Emascota list[],int len)
{
    int i, maxId = 0;

    for(i=0;i<len;i++)
    {
        if(list[i].id > maxId)
        {
            maxId = list[i].id;
        }
    }
    maxId++;
    return maxId;
}

int findEmascotaById(Emascota list[], int len,int id)
{
    int i, index = -1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == 0 && list[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

float promEdadMascotas(Emascota listaMascota[], int tamMascota)
{
    int i,suma = 0,cont = 0;
    float prom;

    for(i=0;i<tamMascota;i++)
    {
        if(listaMascota[i].isEmpty == 0)
        {
            suma += listaMascota[i].edad;
            cont++;
        }
    }
    prom = (float)suma/cont;
    return prom;
}

float promEdadMascotasTipo(Emascota listaMascota[], int tamMascota,int tipo)
{
    int i,suma = 0,cont = 0;
    float prom;

    for(i=0;i<tamMascota;i++)
    {
        if(listaMascota[i].isEmpty == 0 && listaMascota[i].tipo == tipo)
        {
            suma += listaMascota[i].edad;
            cont++;
        }
    }
    prom = (float)suma/cont;
    return prom;
}
