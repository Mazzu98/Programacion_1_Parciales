#include <stdio.h>
#include <stdlib.h>
#include "clienteConMascota.h"
#define CLIENTES 10
#define MASCOTAS 20
#define RAZA 3
int main()
{
    int opcion;
    Ecliente listaCliente[CLIENTES];
    Emascota listaMascota[MASCOTAS];
    Eraza listaRaza[RAZA]={{1,"labrador","frances",0},{2,"lagarto","peruano",0},{3,"gato","persa",0}};
    initEcliente(listaCliente,CLIENTES);
    initEmascota(listaMascota,MASCOTAS,listaCliente,CLIENTES);
    //initEraza(listaRaza,RAZA);


    hardCodeInicialCliente(listaCliente,CLIENTES);
    hardCodeInicialMascotas(listaMascota,MASCOTAS,listaCliente,CLIENTES);

    do{
        menuPrincipal();
        opcion = getInt("\nIngresar una opcion: ");
        system("cls");
        switch(opcion)
        {
            case 1: menuListar(listaMascota,MASCOTAS,listaCliente,CLIENTES,listaRaza,RAZA);
                break;
            case 2: menuABM(listaMascota,MASCOTAS,listaCliente,CLIENTES,listaRaza,RAZA);
                break;
            case 3: menuOrdenar(listaMascota,MASCOTAS,listaCliente,CLIENTES,listaRaza,RAZA);
                break;
            case 4: menuPromedios(listaMascota,MASCOTAS,listaCliente,CLIENTES);
                break;
            case 5: break;
            default: printf("\nOpcion invalida, intenete nuevamente\n");
        }

    }while(opcion != 5);

    return 0;
}
