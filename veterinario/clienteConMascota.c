#include "clienteConMascota.h"

void imprimirClientesConMascota(Ecliente listaCliente[],int tamCliente,Emascota listaMascota[],int tamMascota)
{
    int i,j;
    for(i=0;i<tamCliente;i++)
    {
        if(listaCliente[i].isEmpty == 0)
        {
            imprimirEcliente(listaCliente[i]);
            for(j=0;j<tamMascota;j++)
            {
                if(listaMascota[j].idDueno == listaCliente[i].id)
                {
                    printf("%20d%13s\t  ",listaMascota[j].id,listaMascota[j].nombre);
                    switch(listaMascota[j].tipo)
                    {
                        case 1: printf("gato ");
                            break;
                        case 2: printf("perro");
                            break;
                        case 3: printf("raro ");
                            break;
                    }
                    printf("%13s%8d%8.2f%8c\n",listaMascota[j].raza,listaMascota[j].edad,listaMascota[j].peso,listaMascota[j].sexo);
                }
            }
            printf("\n\n");
        }
    }
}
void imprimirListaEmascota(Emascota lista[],int tam,Ecliente listaCliente[],int tamCliente)
{
    int i,indexCliente;
    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty == 0)
        {
            printf("%d\t%s\t%s\t\t%d\t%.2f\t%c\t",lista[i].id,lista[i].nombre,lista[i].raza,lista[i].edad,lista[i].peso,lista[i].sexo);
            indexCliente = findEclienteById(listaCliente,tamCliente,lista[i].idDueno);
            switch(lista[i].tipo)
            {
                case 1: printf("gato\t");
                    break;
                case 2: printf("perro\t");
                    break;
                case 3: printf("raro\t");
                    break;
            }
            printf("%s\n",listaCliente[indexCliente].nombre);


        }

    }
    printf("\n\n");
}
int addMascota(Emascota listaMascota[], int tamMascota,Ecliente listaCliente[], int tamCliente )
    {
        int indexMascota,id,indexCliente;
        indexMascota = getEmptyPositionEmascota(listaMascota,tamMascota);
        if(indexMascota != -1 )
        {
            listaMascota[indexMascota].id = newIdEmascota(listaMascota,tamMascota);
            getOLString("Ingresar nombre de la mascota: ",listaMascota[indexMascota].nombre);
            do{
                listaMascota[indexMascota].tipo = getInt("Ingrese:\n\t1. Gato \n\t2. Perro\n\t3. Raro");
            }while(listaMascota[indexMascota].tipo < 1 || listaMascota[indexMascota].tipo > 3);
            getOLString("Ingrese la raza de su mascota",listaMascota[indexMascota].raza);
            listaMascota[indexMascota].edad = getInt("Ingrese  la edad de su mascota: ");
            listaMascota[indexMascota].peso = getFloat("Ingrese el peso de su mascota: ");
            do{
                printf("Ingrese el sexo de su mascota f(femenino) m(masculino): ");
                fflush(stdin);
                listaMascota[indexMascota].sexo = getchar();
            }while(listaMascota[indexMascota].sexo != 'f' && listaMascota[indexMascota].sexo != 'm');
            do{
                imprimirListaEcliente(listaCliente,tamCliente);
                id = getInt("Ingrese el id de el dueño de la mascota: ");
                indexCliente = findEclienteById(listaCliente,tamCliente,id);
                if(indexCliente == -1)
                {
                    printf("\n\nerror: ingrese nuevamente\n\n");
                }
            }while(indexCliente == -1);
            listaMascota[indexMascota].idDueno = id;
            listaMascota[indexMascota].isEmpty = 0;
            return 0;
        }
        else
        {
            return -1;
        }
        return -1;
    }

int modificarMascota(Emascota listaMascota[],int tamMascota,Ecliente listaCliente[], int tamCliente)
{
    int opcion,id,index;
    imprimirListaEmascota(listaMascota,tamMascota,listaCliente,tamCliente);
    id = getInt("Ingrese id de la mascota a modificar: ");
    index = findEmascotaById(listaMascota,tamMascota,id);
    if(index != -1)
    {
        do{
            printf("\n1. modificar nombre:\n2. modificar tipo:\n3. modificar raza:\n4. modificar edad: \n5. modificar peso:\n6. modificar sexo:\n7. cancelar\n");
            opcion = getInt("Ingrese una opcion: ");
            switch(opcion)
            {
                case 1: getOLString("Ingrese nuevo nombre",listaMascota[index].nombre);
                    break;
                case 2: do{
                        listaMascota[index].tipo = getInt("Ingrese:\n\t1. Gato \n\t2. Perro\n\t3. Raro\n");
                        }while(listaMascota[index].tipo <1 || listaMascota[index].tipo > 3);
                    break;
                case 3: getOLString("Ingrese nueva raza",listaMascota[index].raza);
                    break;
                case 4: listaMascota[index].edad = getInt("Ingrese nueva edad:");
                    break;
                case 5: listaMascota[index].peso= getFloat("Ingrese nuevo peso: ");
                    break;
                case 6: do{
                            printf("ingrese nuevo sexo f(femenino) m(masculino): ");
                            fflush(stdin);
                            listaMascota[index].sexo = getchar();
                        }while(listaMascota[index].sexo != 'f' && listaMascota[index].sexo != 'm');
                    break;
                case 7: return -1;
                    break;
            }
        }while(opcion <1 || opcion > 7);
        return 0;
    }
    return index;
}

int borrarCliente(Ecliente listaCliente[],int tamCliente,Emascota listaMascota[],int tamMascota)
{
    int id,indexCliente,i;
    id = getInt("Ingrese id de el cliente a borrar: ");
    indexCliente = findEclienteById(listaCliente,tamCliente,id);
    if(indexCliente != -1)
    {
        listaCliente[indexCliente].isEmpty = 1;
        for(i = 0;i<tamMascota;i++)
        {
            if(listaMascota[i].idDueno == id)
            {
                listaMascota[i].isEmpty = 1;
            }
        }
        return 0;
    }
    return indexCliente;
}



