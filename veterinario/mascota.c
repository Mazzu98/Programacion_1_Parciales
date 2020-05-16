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


