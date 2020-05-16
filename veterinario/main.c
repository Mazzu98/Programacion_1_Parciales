#include <stdio.h>
#include <stdlib.h>
#include "clienteConMascota.h"
#define CLIENTES 10
#define MASCOTAS 20
int main()
{
    Ecliente listaCliente[CLIENTES];
    Emascota listaMascota[MASCOTAS];
    initEcliente(listaCliente,CLIENTES);
    initEmascota(listaMascota,MASCOTAS,listaCliente,CLIENTES);

    hardCodeInicialCliente(listaCliente,CLIENTES);
    hardCodeInicialMascotas(listaMascota,MASCOTAS,listaCliente,CLIENTES);

    //addMascota(listaMascota,MASCOTAS,listaCliente,CLIENTES);

    bajaMascota(listaMascota,MASCOTAS,listaCliente,CLIENTES);

    imprimirListaEcliente(listaCliente,CLIENTES);

    //imprimirClientesConMascota(listaCliente,CLIENTES,listaMascota,MASCOTAS);

    //borrarCliente(listaCliente,CLIENTES,listaMascota,MASCOTAS);

    //modificarMascota(listaMascota,MASCOTAS,listaCliente,CLIENTES);

    //imprimirListaEmascotaCD(listaMascota,MASCOTAS,listaCliente,CLIENTES);

    //ordenarPorTipo(listaMascota,MASCOTAS,listaCliente,CLIENTES);

    //modificarCliente(listaCliente,CLIENTES);

    //imprimirListaEcliente(listaCliente,CLIENTES);

    //imprimirClientesVariasMascotas(listaCliente,CLIENTES,listaMascota,MASCOTAS,2);

    //imprimirMascotasSiEsMayorA(listaCliente,CLIENTES,listaMascota,MASCOTAS,3);

    //listarMascotaPorTipo(listaMascota,MASCOTAS,listaCliente,CLIENTES,2);

    //ordenarDuenoPorCantidadesYalfabeto(listaCliente,CLIENTES);


    return 0;
}
