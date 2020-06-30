#include"LinkedList.h"
typedef struct
{
    int id;
    char nombre[51];
}Piloto;

Piloto* newPiloto();
Piloto* newPilotoParametrized(char*,char*);

int getIdP(Piloto* ,int* );
int getNombreP(Piloto* ,char* );
int setIdP(Piloto* ,int );
int setNombreP(Piloto* ,char* );

