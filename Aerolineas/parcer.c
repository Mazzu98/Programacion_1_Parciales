
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "vuelo.h"
#include "piloto.h"

int parser_vueloFromText(FILE* pFile, LinkedList* lista)
{
    char idVuelo[10],idAvion[10],idPiloto[10],dia[3],mes[3],anio[5],destino[31],cantPasajeros[6],horaDespegue[3],horaLlegada[3];
    char auxString[100];
    Vuelo *aux ;
    Fecha auxFecha;
    int ret = 1;

    if(pFile != NULL && lista != NULL)
    {
        fscanf(pFile,"%[^\n]\n",auxString);
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,dia,mes,anio,destino,cantPasajeros,horaDespegue,horaLlegada)==10)
            {
                setFecha(&auxFecha,atoi(dia),atoi(mes),atoi(anio));
                aux = newVueloParametrized(idVuelo,idAvion,idPiloto,auxFecha,destino,cantPasajeros,horaDespegue,horaLlegada);
                ll_add(lista,aux);
            }
            ret = 0;
        }
    }
    return ret;
}

int parser_pilotoFromText(FILE* pFile,LinkedList* lista)
{
    char id[5],nombre[31];
    char auxString[100];
    Piloto *aux ;
    int ret = 1;

    if(pFile != NULL && lista != NULL)
    {
        fscanf(pFile,"%[^\n]\n",auxString);
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^\n]\n",id,nombre)==2)
            {
                aux = newPilotoParametrized(id,nombre);
                ll_add(lista,aux);
            }
            ret = 0;
        }

    }
    return ret;
}
