#include "vuelo.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Vuelo* newVuelo()
{
    Vuelo* nueva;
    nueva = (Vuelo*)calloc(sizeof(Vuelo),1);
    return nueva;
}

Vuelo* newVueloParametrized(char* idVuelo,char* idAvion,char* idPiloto,Fecha fecha, char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada)
{
    Vuelo* nueva;
    nueva = newVuelo();
    if (nueva!= NULL)
    {
        setIdVuelo(nueva,atoi(idVuelo));
        setIdAvion(nueva,atoi(idAvion));
        setIdPiloto(nueva,atoi(idPiloto));
        setFechaV(nueva,fecha);
        setDestino(nueva,destino);
        setCantPasajeros(nueva,atoi(cantPasajeros));
        setHoraLlegada(nueva,atoi(horaLlegada));
        setHoraDespegue(nueva,atoi(horaDespegue));
    }
    return nueva;
}

void imprimirVuelo(Vuelo* vuelo)
{
    Vuelo aux;
    if(vuelo != NULL)
    {
        aux = *vuelo;
        printf("%4d%9d%9d%9d/%d/%d%15s%11d%13d%10d\n",aux.idVuelo,aux.idAvion,aux.idPiloto
               ,aux.fecha.dia,aux.fecha.mes,aux.fecha.anio,aux.destino
               ,aux.cantPasajeros,aux.horaDespegue,aux.horaLlegada);
        /*
        printf("%4d%9d%9d%9d/%d/%d%15s%11d%13d%10d\n",vuelo->idVuelo,vuelo->idAvion,vuelo->idPiloto
               ,vuelo->fecha.dia,vuelo->fecha.mes,vuelo->fecha.anio,vuelo->destino
               ,vuelo->cantPasajeros,vuelo->horaDespegue,vuelo->horaLlegada);*/
    }
}

//*******************GETTERS***************************
int getIdVuelo(Vuelo* vuelo,int* id)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        *id = vuelo->idVuelo;
        ret = 0;
    }
    return ret;
}

int getIdAvion(Vuelo* vuelo,int* id)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        *id = vuelo->idAvion;
        ret = 0;
    }
    return ret;
}

int getIdPiloto(Vuelo* vuelo,int* id)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        *id = vuelo->idPiloto;
        ret = 0;
    }
    return ret;
}

int getFechaV(Vuelo* vuelo,Fecha* fecha)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        *fecha = vuelo->fecha;
        ret = 0;
    }
    return ret;
}

int getDestino(Vuelo* vuelo,char* destino)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        strcpy(destino,vuelo->destino);
        ret = 0;
    }
    return ret;
}

int getCantPasajeros(Vuelo* vuelo,int* cant)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        *cant = vuelo->cantPasajeros;
        ret = 0;
    }
    return ret;
}

int getHoraDespegue(Vuelo* vuelo,int* hora)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        *hora = vuelo->horaDespegue;
        ret = 0;
    }
    return ret;
}

int getHoraLlegada(Vuelo* vuelo,int* hora)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        *hora = vuelo->horaLlegada;
        ret = 0;
    }
    return ret;
}
//*************************SETTERS********************************
int setIdVuelo(Vuelo* vuelo,int id)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        vuelo->idVuelo = id;
        ret = 0;
    }
    return ret;
}

int setIdAvion(Vuelo* vuelo,int id)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        vuelo->idAvion = id;
        ret = 0;
    }
    return ret;
}

int setIdPiloto(Vuelo* vuelo,int id)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        vuelo->idPiloto = id;
        ret = 0;
    }
    return ret;
}

int setFechaV(Vuelo* vuelo,Fecha fecha)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        vuelo->fecha = fecha;
        ret = 0;
    }
    return ret;
}

int setDestino(Vuelo* vuelo,char* destino )
{
    int ret = 1;
    if(vuelo != NULL)
    {
        strcpy(vuelo->destino,destino);
        ret = 0;
    }
    return ret;
}

int setCantPasajeros(Vuelo* vuelo,int cant)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        vuelo->cantPasajeros = cant;
        ret = 0;
    }
    return ret;
}

int setHoraDespegue(Vuelo* vuelo,int hora)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        vuelo->horaDespegue = hora;
        ret = 0;
    }
    return ret;
}

int setHoraLlegada(Vuelo* vuelo,int hora)
{
    int ret = 1;
    if(vuelo != NULL)
    {
        vuelo->horaLlegada = hora;
        ret = 0;
    }
    return ret;
}

