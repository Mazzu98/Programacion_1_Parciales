#include "fecha.h"
#include <stdlib.h>


int setFecha(Fecha* fecha,int dia, int mes, int anio)
{
    int ret = 1;
    if(fecha != NULL)
    {
        fecha->dia = dia;
        fecha->mes = mes;
        fecha->anio = anio;
        ret = 0;
    }
    return ret;
}

int getFecha(Fecha* fecha,int* dia, int* mes, int* anio)
{
    int ret = 1;
    if(fecha != NULL)
    {
        *dia = fecha->dia;
        *mes = fecha->mes;
        *anio = fecha->anio;
        ret = 0;
    }
    return ret;
}

void fechaToString(Fecha fecha,char* cadena)
{
    char dia[3];
    char mes[3];
    char anio[5];
    int i,j=0;
    itoa(fecha.dia,dia,10);
    itoa(fecha.mes,mes,10);
    itoa(fecha.anio,anio,10);

    for(i=0;i<2;i++)
    {
        cadena[j]=dia[i];
        j++;
    }
    cadena[j]='/';
    j++;
    for(i=0;i<2;i++)
    {
        cadena[j]=mes[i];
        j++;
    }
    cadena[j]='/';
    j++;
    for(i=0;i<5;i++)
    {
        cadena[j]=anio[i];
        j++;
    }
}


