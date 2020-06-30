#include <stdio.h>
#include <stdlib.h>
#include "vuelo.h"
#include "LinkedList.h"
#include "piloto.h"
#include "controller.h"
#include "entradaValidada.h"
#include "parcer.h"

int main()
{
    int opcion;
    int cant;
    int ret;
    char path[15];
    LinkedList* listaVuelos = ll_newLinkedList();
    LinkedList* listaPiloto = ll_newLinkedList();
    LinkedList* listaFiltrada;

    controller_mazzucchelli_pilotosFromText("pilotos.csv",listaPiloto);

    do
    {
        controller_mazzucchelli_imprimirMenu();
        opcion = getInt("Ingrese una opcion");

        switch(opcion)
        {
            case 1: getString("Ingresar nombre del archivo:",path);
                    ret = controller_mazzucchelli_vuelosFromText(path,listaVuelos);
                    system("cls");
                    controller_mazzucchelli_succes(ret,"Listado correctamente\n","No se pudo listar\n");
                    break;
            case 2: controller_mazzucchelli_imprimirListaVuelosConPiloto(listaVuelos,listaPiloto);
                    break;
            case 3: cant = ll_count(listaVuelos,controller_mazzucchelli_cantPasajeros);
                    system("cls");
                    printf("La cantidad total de pasajeros es: %d\n\n",cant);
                    break;
            case 4: cant = ll_count(listaVuelos,controller_mazzucchelli_cantPasajerosIrlanda);
                    system("cls");
                    printf("La cantidad total de pasajeros que viajan a Irlanda es: %d\n\n",cant);
                    break;
            case 5: ret = controller_mazzucchelli_vuelosCortosCsv("vuelosCortos.csv",listaVuelos);
                    system("cls");
                    controller_mazzucchelli_succes(ret,"\nvuelosCortos.csv generado correctamente\n","No se pudo generar\n");
                    break;
            case 6: listaFiltrada = ll_filter(listaVuelos,vuelo_vuelosPortugal);
                    system("cls");
                    controller_mazzucchelli_imprimirListaVuelosConPiloto(listaFiltrada,listaPiloto);
                    controller_mazzucchelli_succesP(listaFiltrada,"\nlista a portugal generada correctamente\n","\nNo se pudo generar\n");
                    break;
            case 7: listaFiltrada = ll_filter(listaVuelos,vuelo_sinAlexLifeson);
                    system("cls");
                    controller_mazzucchelli_imprimirListaVuelosConPiloto(listaFiltrada,listaPiloto);
                    controller_mazzucchelli_succesP(listaFiltrada,"\nlista sin Alex Lifeson generada correctamente\n","\nNo se pudo generar\n");
                    break;
            case 8: controller_mazzucchelli_filtrarPilotoPorNombre(listaPiloto);
                    break;
            case 9:
                    break;
            default: printf("Opcion invalida\n");
        }
    }while(opcion != 9);

    return 0;
}
