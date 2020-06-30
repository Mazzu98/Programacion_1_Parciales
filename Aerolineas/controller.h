
int controller_mazzucchelli_vuelosFromText(char* , LinkedList*);
int controller_mazzucchelli_pilotosFromText(char* , LinkedList* );
int controller_mazzucchelli_listToText(LinkedList* ,FILE* );

int controller_mazzucchelli_listPilotoToText(LinkedList* ,char* );

void controller_mazzucchelli_imprimirListaVuelos(LinkedList* );
void controller_mazzucchelli_imprimirListaPilotos(LinkedList*);
int controller_mazzucchelli_findPilotoById(LinkedList* ,int );
void controller_mazzucchelli_imprimirListaVuelosConPiloto(LinkedList* ,LinkedList* );
void controller_mazzucchelli_imprimirVueloConPiloto(LinkedList* ,Vuelo* );
int controller_mazzucchelli_cantPasajeros(void*);
int controller_mazzucchelli_cantPasajerosIrlanda(void* );
int controller_mazzucchelli_vuelosCortosCsv(char* ,LinkedList* );
void controller_mazzucchelli_imprimirMenu(void);
void controller_mazzucchelli_succes(int ,char [],char []);
void controller_mazzucchelli_succesP(void* ,char [],char []);

int controller_mazzucchelli_filtrarPilotoPorNombre(LinkedList* );
int controller_mazzucchelli_filtroPilotos(void* , char* );
