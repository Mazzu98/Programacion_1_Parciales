#include "cliente.h"
#include "entradaValidada.h"
int initEcliente(Ecliente list[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        list[i].isEmpty = 1;
        list[i].id = 0;
    }
    return 0;
}

int getEmptyPositionEcliente(Ecliente list[],int tam)
{
    int i, index = -1;
    for(i=0;i<tam;i++)
    {
        if(list[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int newIdEcliente(Ecliente list[],int len)
{
    int i, maxId = 0;

    for(i=0;i<len;i++)
    {
        if(list[i].id > maxId)
        {
            maxId = list[i].id;
        }
    }
    maxId++;
    return maxId;
}

int hardCodeEcliente(Ecliente list[], int len,char nombre[],char apellido[],char localidad[],int tel,int edad,char sexo)
{
    int index;
    index = getEmptyPositionEcliente(list,len);
    if(index != -1 )
    {
        list[index].id = newIdEcliente(list,len);
        strcpy(list[index].nombre,nombre);
        strcpy(list[index].apellido,apellido);
        strcpy(list[index].localidad,localidad);
        list[index].tel = tel;
        list[index].edad = edad;
        list[index].sexo = sexo;
        list[index].isEmpty = 0;
        return 0;
    }
    else
    {
        return -1;
    }
    return -1;
}
void imprimirListaEcliente(Ecliente lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty == 0)
        {
            imprimirEcliente(lista[i]);
        }
    }
    printf("\n\n");
}

void imprimirEcliente(Ecliente cliente)
{
    printf("%d%10s%11s%11s%10d%6d%6c\n",cliente.id,cliente.nombre,cliente.apellido,cliente.localidad,cliente.tel,cliente.edad,cliente.sexo);
}

int findEclienteById(Ecliente list[], int len,int id)
{
    int i, index = -1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == 0 && list[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

int altaCliente(Ecliente listaCliente[],int tamCliente)
{
    int index;
    index = getEmptyPositionEcliente(listaCliente,tamCliente);
    if(index != -1)
    {
        getOLString("Ingrese el nombre del cliente:",listaCliente[index].nombre);
        getOLString("Ingrese el apellido del cliente:",listaCliente[index].apellido);
        getOLString("Ingrese la localidad del cliente:",listaCliente[index].localidad);
        listaCliente[index].tel = getInt("Ingrese telefono:");
        listaCliente[index].edad = getInt("Ingrese edad:");
        do{
                printf("Ingrese el sexo del cliente f(femenino) m(masculino): ");
                fflush(stdin);
                listaCliente[index].sexo = getchar();
            }while(listaCliente[index].sexo != 'f' && listaCliente[index].sexo != 'm');
        listaCliente[index].isEmpty = 0;
        return 0;
    }
    return index;
}

int modificarCliente(Ecliente listaCliente[],int tamCliente)
{
    int id, index, opcion;
    imprimirListaEcliente(listaCliente,tamCliente);
    id = getInt("Ingrese el id de el cliente a modificar: ");
    index = findEclienteById(listaCliente,tamCliente,id);
    if(index != -1)
    {
        do{
        printf("\n1. Modificar nombre\n2. Modificar apellido\n3. Modificar localidad\n4. Modificar telefono\n5. Modificar edad\n6. Modificar sexo\n7. Cancelar\n");
        opcion = getInt("Ingrese una opcion: ");
        switch(opcion)
        {
            case 1: getOLString("Ingrese nuevo nombre: ",listaCliente[index].nombre);
                break;
            case 2: getOLString("Ingrese nuevo apellido: ",listaCliente[index].apellido);
                break;
            case 3: getOLString("Ingrese nueva localidad: ",listaCliente[index].localidad);
                break;
            case 4: listaCliente[index].tel = getInt("Ingrese nuevo telefono: ");
                break;
            case 5: listaCliente[index].edad = getInt("Ingrese nueva edad: ");
                break;
            case 6: do{
                        printf("ingrese nuevo sexo f(femenino) m(masculino): ");
                        fflush(stdin);
                        listaCliente[index].sexo = getchar();
                    }while(listaCliente[index].sexo != 'f' && listaCliente[index].sexo != 'm');
                    break;
            case 7: return -1;
                break;
        }
        }while(opcion < 1 || opcion > 7 );
    }
    return index;
}
int modificarDueno(Ecliente [],int);
