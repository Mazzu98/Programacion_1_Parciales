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
    initEmascota(listaMascota,MASCOTAS);

    hardCodeEcliente(listaCliente,CLIENTES,"Marcela","pipi","jaja",324567,43,'f');
    hardCodeEcliente(listaCliente,CLIENTES,"Hector","ksdkd","kasj",356454,66,'m');
    hardCodeEcliente(listaCliente,CLIENTES,"Camila","lopez","jtah",804354,27,'f');
    hardCodeEcliente(listaCliente,CLIENTES,"Tomas","sala","idjhas",847404,20,'m');
    hardCodeEcliente(listaCliente,CLIENTES,"Jorge","jfdi","kfiedk",849374,51,'m');

    hardCodeEmascota(listaMascota,MASCOTAS,"miau",1,"ksl",6,9,'f',1);
    hardCodeEmascota(listaMascota,MASCOTAS,"gatex",1,"fdg",5,3,'f',1);
    hardCodeEmascota(listaMascota,MASCOTAS,"guau",2,"dsfs",9,6,'m',2);
    hardCodeEmascota(listaMascota,MASCOTAS,"guau",2,"sdf",2,2,'m',2);
    hardCodeEmascota(listaMascota,MASCOTAS,"miau",1,"fgd",3,6,'m',2);
    hardCodeEmascota(listaMascota,MASCOTAS,"guau",2,"pitbull",4,2,'m',3);
    hardCodeEmascota(listaMascota,MASCOTAS,"zzzz",3,"ksl",5,7,'f',3);
    hardCodeEmascota(listaMascota,MASCOTAS,"guau",2,"labrado",6,9,'m',4);
    hardCodeEmascota(listaMascota,MASCOTAS,"miau",1,"dsad",6,9,'m',5);
    hardCodeEmascota(listaMascota,MASCOTAS,"miau",1,"asdd",6,9,'m',5);
    hardCodeEmascota(listaMascota,MASCOTAS,"guau",2,"bulldog",2,9,'m',5);

    //addMascota(listaMascota,MASCOTAS,listaCliente,CLIENTES);

    //imprimirListaEcliente(listaCliente,CLIENTES);

    //imprimirClientesConMascota(listaCliente,CLIENTES,listaMascota,MASCOTAS);

    //borrarCliente(listaCliente,CLIENTES,listaMascota,MASCOTAS);

    //modificarMascota(listaMascota,MASCOTAS,listaCliente,CLIENTES);

    //imprimirListaEmascotaCD(listaMascota,MASCOTAS,listaCliente,CLIENTES);

    //ordenarPorTipo(listaMascota,MASCOTAS,listaCliente,CLIENTES);

    //modificarCliente(listaCliente,CLIENTES);

    //imprimirListaEcliente(listaCliente,CLIENTES);

    //imprimirClientesVariasMascotas(listaCliente,CLIENTES,listaMascota,MASCOTAS,2);

    imprimirMascotasSiEsMayorA(listaCliente,CLIENTES,listaMascota,MASCOTAS,3);


    return 0;
}
