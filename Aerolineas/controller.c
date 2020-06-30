
#include "LinkedList.h"
#include "entradaValidada.h"
#include "vuelo.h"
#include "parcer.h"
#include "piloto.h"
#include <string.h>

int controller_mazzucchelli_vuelosFromText(char* path, LinkedList* lista)
{
    FILE* archivo;
    int ret;

    archivo = fopen(path,"r");
    ret = parser_vueloFromText(archivo,lista);
    fclose(archivo);

    return ret;
}

int controller_mazzucchelli_pilotosFromText(char* path, LinkedList* lista)
{
    FILE* archivo;
    int ret;

    archivo = fopen(path,"r");
    ret = parser_pilotoFromText(archivo,lista);
    fclose(archivo);

    return ret;
}

int controller_mazzucchelli_listToText(LinkedList* lista,FILE* pFile)
{
    int len;
    int ret = 1;
    Vuelo* vuelo;
    Vuelo vueloAux;
    int i;
    char fecha[11];

    if(lista!= NULL)
    {
        if(pFile != NULL)
        {
            len = ll_len(lista);
            fprintf(pFile,"idVuelo,idAvion,idPiloto,Fecha,Destino,CantPasajeros,Despegue,Llegada\n");
            for(i=0;i<len;i++)
            {
                vuelo = ll_get(lista,i);
                vueloAux = *vuelo;
                fechaToString(vueloAux.fecha,fecha);
                fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d\n",vueloAux.idVuelo,vueloAux.idAvion,vueloAux.idPiloto,fecha,
                            vueloAux.destino,vueloAux.cantPasajeros,vueloAux.horaDespegue,vueloAux.horaLlegada);

            }
            ret = 0;
        }

    }
    return ret;
}

int controller_mazzucchelli_listPilotoToText(LinkedList* lista,char* path)
{
    FILE* pFile;
    Piloto* piloto;
    Piloto aux;
    int ret = -1;
    int len;
    int i;

    if(lista != NULL)
    {
        ret = 1;
        pFile = fopen(path,"w");
        if(pFile != NULL)
        {

            len = ll_len(lista);
            fprintf(pFile,"id,Nombre\n");
            for(i=0;i<len;i++)
            {
                piloto = ll_get(lista,i);
                aux = *piloto;
                fprintf(pFile,"%d,%s\n",aux.id,aux.nombre);
            }
            fclose(pFile);
            ret = 0;
        }
    }
    return ret;
}


int controller_mazzucchelli_findPilotoById(LinkedList* lista,int id)
{
    int idCompare;
    int i;
    int ret = -1;
    Piloto* piloto;

    if(lista != NULL && id > 0)
    {
        for(i=0;i<ll_len(lista);i++)
        {
            piloto = ll_get(lista,i);
            getIdP(piloto,&idCompare);
            if(idCompare == id)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

void controller_mazzucchelli_imprimirListaVuelos(LinkedList* lista)
{
    int len;
    Vuelo* vuelo;
    int i;

    if(lista != NULL)
    {
        len = ll_len(lista);
        printf("idVuelo  idAvion  idPiloto     Fecha           Destino    CantPasajeros  Despegue  Llegada\n");
        for(i=0;i<len;i++)
        {
            vuelo = ll_get(lista,i);
            imprimirVuelo(vuelo);
        }
    }
}

void controller_mazzucchelli_imprimirListaPilotos(LinkedList* lista)
{
    Piloto* piloto;
    Piloto auxPiloto;
    int len;
    int i;
    if(lista != NULL)
    {
        len = ll_len(lista);
        printf(" id        Nombre\n\n");
        for(i=0;i<len;i++)
        {
            piloto = ll_get(lista,i);
            auxPiloto = *piloto;
            printf("%2d%18s\n",auxPiloto.id,auxPiloto.nombre);
        }
        printf("\n");
    }
}

void controller_mazzucchelli_imprimirVueloConPiloto(LinkedList* listaPilotos,Vuelo* vuelo)
{
    int idPiloto;
    int index;
    char nombre[51];
    Vuelo auxVuelo;
    Piloto* piloto;
    if(vuelo != NULL)
    {
        auxVuelo = *vuelo;
        printf("%4d%9d%9d/%d/%d%15s%11d%13d%10d",auxVuelo.idVuelo,auxVuelo.idAvion
               ,auxVuelo.fecha.dia,auxVuelo.fecha.mes,auxVuelo.fecha.anio,auxVuelo.destino
               ,auxVuelo.cantPasajeros,auxVuelo.horaDespegue,auxVuelo.horaLlegada);

        getIdPiloto(vuelo,&idPiloto);
        index = controller_mazzucchelli_findPilotoById(listaPilotos,idPiloto);
        if(index != -1)
        {
            piloto = ll_get(listaPilotos,index);
            getNombreP(piloto,nombre);
            printf("%18s\n",nombre);
        }
        else
        {
            printf("\n");
        }
    }
}


void controller_mazzucchelli_imprimirListaVuelosConPiloto(LinkedList* listaVuelos,LinkedList* listaPilotos)
{
    int len;
    Vuelo* vuelo;
    int i;
    if (listaPilotos != NULL && listaVuelos != NULL)
    {
        len = ll_len(listaVuelos);
        printf("idVuelo  idAvion      Fecha           Destino    CantPasajeros  Despegue  Llegada      Piloto\n\n");
        for(i=0;i<len;i++)
        {
            vuelo = ll_get(listaVuelos,i);
            controller_mazzucchelli_imprimirVueloConPiloto(listaPilotos,vuelo);
        }
    }
}

int controller_mazzucchelli_cantPasajeros(void* vuelo)
{
    int ret;

    if (vuelo != NULL)
    {
        vuelo = (Vuelo*) vuelo;
        getCantPasajeros(vuelo,&ret);
    }
    return ret;
}
int controller_mazzucchelli_cantPasajerosIrlanda(void* vuelo)
{
    int ret = 0;
    char destino[21];
    if (vuelo != NULL)
    {
        vuelo = (Vuelo*) vuelo;
        getDestino(vuelo,destino);
        if(strcmp(destino,"Irlanda")==0)
        {
            getCantPasajeros(vuelo,&ret);
        }
    }
    return ret;
}

int controller_mazzucchelli_vuelosCortosCsv(char* path,LinkedList* listaVuelos)
{
    FILE* pFile;
    int ret = 1;
    LinkedList* nuevaLista;

    if(listaVuelos != NULL)
    {
        nuevaLista = ll_filter(listaVuelos,vuelo_vuelosCortos);
        pFile = fopen(path,"w");
        if(pFile != NULL)
        {
            ret = controller_mazzucchelli_listToText(nuevaLista,pFile);
            fclose(pFile);
        }
        ll_deleteLinkedList(nuevaLista);
    }
    return ret;
}

void controller_mazzucchelli_imprimirMenu()
{
    printf("1. Cargar archivos\n");
    printf("2. imprimir vuelos\n");
    printf("3. Cantidad de pasajeros\n");
    printf("4. Cantidad de pasajeros a Irlanda\n");
    printf("5. Filtrar vuelos cortos\n");
    printf("6. Listar vuelos a Portugal\n");
    printf("7. Filtrar a Alex Lifeson\n");
    printf("8. Filtrar pilotos por nombre\n");
    printf("9. Salir\n");
}

void controller_mazzucchelli_succes(int ret,char succes[],char error[])
{
    if(ret == 0)
    {
        printf("%s\n",succes);
    }
    else if(ret == 1)
    {
        printf("%s\n",error);
    }
}

void controller_mazzucchelli_succesP(void* element,char succes[],char error[])
{
    if(element != NULL)
    {
        printf("%s\n",succes);
    }
    else if(element == NULL)
    {
        printf("%s\n",error);
    }
}


int controller_mazzucchelli_filtroPilotos(void* piloto, char* cadena)
{
    int ret = 0;
    char nombre[51];
    if(piloto != NULL)
    {
        piloto = (Piloto*) piloto;
        getNombreP(piloto,nombre);
        if(strcmp(nombre,cadena)!=0)
        {
            ret = 1;
        }
    }
    return ret;
}


int controller_mazzucchelli_filtrarPilotoPorNombre(LinkedList* listaPilotos)
{
    int ret = 1;
    char cadena[51];
    LinkedList* nuevaLista;

    if(listaPilotos != NULL)
    {
        getString("Ingresar nommbre del piloto a filtrar:",cadena);
        nuevaLista = ll_filterParametro(listaPilotos,cadena,controller_mazzucchelli_filtroPilotos);
        controller_mazzucchelli_imprimirListaPilotos(nuevaLista);
        controller_mazzucchelli_listPilotoToText(nuevaLista,"pilotoFiltrado.csv");
        ret = 0;
        ll_deleteLinkedList(nuevaLista);
    }
    return ret;
}


