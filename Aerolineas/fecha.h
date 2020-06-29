typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

int setFecha(Fecha* ,int , int , int );
int getFecha(Fecha* ,int* ,int* , int* );

void fechaToString(Fecha ,char* );

