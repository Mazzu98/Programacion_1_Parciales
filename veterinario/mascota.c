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

int hardCodeEmascota(Emascota list[], int len,char nombre[],int tipo,char raza[],int edad,float peso,char sexo,int idDueno)
{
    int index;
    index = getEmptyPositionEmascota(list,len);
    if(index != -1 )
    {
        list[index].id = newIdEmascota(list,len);
        strcpy(list[index].nombre,nombre);
        list[index].tipo = tipo;
        strcpy(list[index].raza,raza);
        list[index].edad = edad;
        list[index].peso = peso;
        list[index].sexo = sexo;
        list[index].idDueno = idDueno;
        list[index].isEmpty = 0;
        return 0;
    }
    else
    {
        return -1;
    }
    return -1;
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


int bajaMascota(Emascota listaMascota[],int tamMascota)
{
    int index,id;
    id = getInt("ingrese id de la mascota: ");
    index = findEmascotaById(listaMascota,tamMascota,id);
    if(index != -1)
    {
        listaMascota[index].isEmpty = 1;
        return 0;
    }
    return index;
}
