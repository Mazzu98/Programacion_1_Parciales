#include <stdio.h>
#include <stdlib.h>
#include "vuelo.h"
#include "LinkedList.h"
#include "piloto.h"
#include "controller.h"
#include "entradaValidada.h"

int main()
{
    int opcion;
    int cant;
    int ret;
    LinkedList* listaVuelos = ll_newLinkedList();
    LinkedList* listaPiloto = ll_newLinkedList();
    LinkedList* listaFiltrada;

    controller_pilotosFromText("pilotos.csv",listaPiloto);

    do
    {
        imprimirMenu();
        opcion = getInt("Ingrese una opcion");

        switch(opcion)
        {
            case 1: ret = controller_vuelosFromText("vuelos.csv",listaVuelos);
                    system("cls");
                    succes(ret,"Listado correctamente\n","No se pudo listar\n");
                    break;
            case 2: imprimirListaVuelosConPiloto(listaVuelos,listaPiloto);
                    break;
            case 3: cant = ll_count(listaVuelos,cantPasajeros);
                    system("cls");
                    printf("La cantidad total de pasajeros es: %d\n\n",cant);
                    break;
            case 4: cant = ll_count(listaVuelos,cantPasajerosIrlanda);
                    system("cls");
                    printf("La cantidad total de pasajeros que viajan a Irlanda es: %d\n\n",cant);
                    break;
            case 5: ret = vuelosCortosCsv("vuelosCortos.csv",listaVuelos);
                    system("cls");
                    succes(ret,"Generado correctamente\n","No se pudo generar\n");
                    break;
            case 6: listaFiltrada = ll_filter(listaVuelos,vuelosPortugal);
                    system("cls");
                    succesP(listaFiltrada,"Generada correctamente\n","No se pudo generar\n");
                    break;
            case 7: listaFiltrada = ll_filter(listaVuelos,sinAlexLifeson);
                    system("cls");
                    succesP(listaFiltrada,"Generada correctamente\n","No se pudo generar\n");
                    break;
            case 8:
                    break;
            default: printf("Opcion invalida\n");
        }
    }while(opcion != 8);

    return 0;
}
