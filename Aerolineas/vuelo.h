#include "fecha.h"
typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    Fecha fecha;
    char destino[21];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}Vuelo;

Vuelo* newVuelo();
Vuelo* newVueloParametrized(char* ,char* ,char* ,Fecha , char* ,char* ,char* ,char* );

void imprimirVuelo(Vuelo* );

int getIdVuelo(Vuelo*,int*);
int getIdAvion(Vuelo*,int*);
int getIdPiloto(Vuelo*,int*);
int getFechaV(Vuelo*,Fecha*);
int getDestino(Vuelo*,char*);
int getCantPasajeros(Vuelo*,int*);
int getHoraDespegue(Vuelo*,int*);
int getHoraLlegada(Vuelo*,int*);

int setIdVuelo(Vuelo*,int);
int setIdAvion(Vuelo*,int);
int setIdPiloto(Vuelo*,int);
int setFechaV(Vuelo*,Fecha);
int setDestino(Vuelo*,char*);
int setCantPasajeros(Vuelo*,int);
int setHoraDespegue(Vuelo*,int);
int setHoraLlegada(Vuelo*,int);

