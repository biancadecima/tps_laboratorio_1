#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Jugador.h"

Jugador* jug_new(){
	Jugador* nuevoJugador = NULL;

	nuevoJugador = (Jugador*)malloc(sizeof(Jugador));

	if(nuevoJugador != NULL){
		nuevoJugador -> id = 0;
		strcpy(nuevoJugador -> nombreCompleto, " ");
		nuevoJugador -> edad = 0;
		strcpy(nuevoJugador -> posicion, " ");
		strcpy(nuevoJugador -> nacionalidad, " ");
		nuevoJugador -> idSeleccion = 0;
	}

	return nuevoJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr){
	Jugador* nuevoJugador = jug_new();

	if(nuevoJugador != NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL){
		if(!(jug_setId(nuevoJugador, atoi(idStr)) &&
			jug_setNombreCompleto(nuevoJugador, nombreCompletoStr) &&
			jug_setPosicion(nuevoJugador, posicionStr) &&
			jug_setNacionalidad(nuevoJugador, nacionalidadStr) &&
			jug_setEdad(nuevoJugador, atoi(edadStr)) &&
			jug_setIdSeleccion(nuevoJugador, atoi(idSelccionStr))))
		{
			free(nuevoJugador);
			nuevoJugador = NULL;
		}
	}

	return nuevoJugador;
}

int jug_asignarID(){// el csv ya tiene que estar creado y con 370 cargado
    FILE* pArchivo;
	char idStr[10];
	int id;

	pArchivo = fopen("idJugador.csv", "r");

	if(pArchivo!=NULL){
		do{
			fscanf(pArchivo, "%[^\n]\n", idStr);
		}while(!feof(pArchivo));
	}

	id = atoi(idStr);

	fclose(pArchivo);

	return id+1;
}

void jug_actualizarID(int id){// abre el archivo en modo escritura y escribe el id que le paso por parametro
	FILE* pArchivo;

	pArchivo = fopen("idJugador.csv", "w");

	fprintf(pArchivo, "%d\n", id);

	fclose(pArchivo);
}

int jug_cargarPaisSeleccion(Jugador* pJugador,  LinkedList* pArrayListSeleccion, char paisJugador[]){
	int retorno = 0;
	int idSeleccionJug;
	int indice;
	Seleccion* pSeleccion = NULL;

	if(pJugador != NULL && pArrayListSeleccion != NULL){
		jug_getSIdSeleccion(pJugador, &idSeleccionJug);
		if(idSeleccionJug == 0){
			strcpy(paisJugador, "No convocado");
		}else{
			indice = selec_BuscarPorID(pArrayListSeleccion, idSeleccionJug);
			if(indice > 0){
				pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indice);
				if(pSeleccion != NULL){
				selec_getPais(pSeleccion, paisJugador);
				retorno = 1;
				}
			}
		}
	}

	return retorno;
}

void jug_MostrarJugador(Jugador* this){
	int id;
	char nombre[100];
	char posicion[100];
	char nacionalidad[100];
	int edad;
	int idSeleccion;
	char estado[100];

	if(this != NULL){
		if(jug_getId(this, &id)
			&& jug_getNombreCompleto(this, nombre)
			&& jug_getPosicion(this, posicion)
			&& jug_getNacionalidad(this, nacionalidad)
			&& jug_getEdad(this, &edad)
			&& jug_getSIdSeleccion(this, &idSeleccion)){
			if(idSeleccion == 0){
				strcpy(estado, "No convocado");
			}else{
				strcpy(estado, "Convocado");
			}
			printf("| %3d | %-24s | %-20s | %4d | %-15s | %5s |\n", id, nombre, posicion, edad, nacionalidad, estado);
		}

	}
}

void jug_MostrarJugadorConSeleccion(Jugador* this, LinkedList* pArrayListSeleccion){
	int id;
	char nombre[100];
	char posicion[100];
	char nacionalidad[100];
	int edad;
	int idSeleccion;
	char paisJugador[100];

	if(this != NULL && pArrayListSeleccion != NULL){
		if(jug_getId(this, &id)
			&& jug_getNombreCompleto(this, nombre)
			&& jug_getPosicion(this, posicion)
			&& jug_getNacionalidad(this, nacionalidad)
			&& jug_getEdad(this, &edad)
			&& jug_getSIdSeleccion(this, &idSeleccion)){
			jug_cargarPaisSeleccion(this, pArrayListSeleccion, paisJugador);
			printf("| %3d | %-24s | %-20s | %-15s | %4d | %4s |\n", id, nombre, posicion, nacionalidad, edad, paisJugador);
		}

	}
}

int jug_BuscarPorID(LinkedList* pArrayListJugador, int idBuscado)
{
	int indice = -1;
	int largoJugador;
	int idAux;
	Jugador* pJugador;

	if (pArrayListJugador != NULL && idBuscado > 0) {
		largoJugador = ll_len(pArrayListJugador);
		for (int i = 0; i < largoJugador; i++) {
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);
			if (pJugador != NULL) {
				jug_getId(pJugador, &idAux);
				if (idAux == idBuscado) {
					indice = i;
					break;
				}
			}
		}
	}


	return indice;
}

int jug_CompareById(void *j1, void *j2) {
	int compara = 0;
	Jugador* pJugadorUno = NULL;
	Jugador* pJugadorDos = NULL;
	int id1;
	int id2;

	if (j1 != NULL && j2 != NULL) {
		pJugadorUno = (Jugador*) j1;
		pJugadorDos = (Jugador*) j2;
		if (pJugadorUno != NULL && pJugadorDos != NULL) {
			jug_getId(pJugadorUno, &id1);
			jug_getId(pJugadorDos, &id2);
			if(id1 > id2){
				compara = 1;
			}else{
				compara = -1;
			}
		}
	}

	return compara;
}

int jug_CompareByNationality(void* j1, void* j2) {//en el caso de los strings, retorno el retorno de strcmp
	int compara;
	Jugador* pJugadorUno = NULL;
	Jugador* pJugadorDos = NULL;
	char nacionalidadUno[50];
	char nacionalidadDos[50];

	if(j1 != NULL && j2 != NULL){
		pJugadorUno = (Jugador*) j1;
		pJugadorDos = (Jugador*) j2;
		if(pJugadorUno != NULL && pJugadorDos != NULL){
			jug_getNacionalidad(pJugadorUno, nacionalidadUno);
			jug_getNacionalidad(pJugadorDos, nacionalidadDos);

			compara = strcmp(nacionalidadUno, nacionalidadDos);
		}

	}

	return compara;
}

int jug_CompareByAge(void* j1, void* j2) {
	int compara = 0;// si no hay comparacion, es decir, los dos numeros son iguales, queda en cero (como el strcmp)
	Jugador* pJugadorUno = NULL;
	Jugador* pJugadorDos = NULL;
	int edadUno;
	int edadDos;

	if(j1 != NULL && j2 != NULL){
		pJugadorUno = (Jugador*) j1;
		pJugadorDos = (Jugador*) j2;
		if(pJugadorUno != NULL && pJugadorDos != NULL){
			jug_getEdad(pJugadorUno, &edadUno);
			jug_getEdad(pJugadorDos, &edadDos);
			if(edadUno > edadDos){
				compara = 1;
			}else if(edadDos > edadUno){
				compara = -1;
			}
		}
	}

	return compara;
}

int jug_CompareByName(void* j1, void* j2) {
	int compara;
	Jugador* pJugadorUno = NULL;
	Jugador* pJugadorDos = NULL;
	char nombreUno[50];
	char nombreDos[50];

	if(j1 != NULL && j2 != NULL){
		pJugadorUno = (Jugador*) j1;
		pJugadorDos = (Jugador*) j2;
		if(pJugadorUno != NULL && pJugadorDos != NULL){
			jug_getNombreCompleto(pJugadorUno, nombreUno);
			jug_getNombreCompleto(pJugadorDos, nombreDos);

			compara = strcmp(nombreUno, nombreDos);
		}

	}

	return compara;
}

void jug_delete(Jugador* this){
	free(this);
	this = NULL;
}

int jug_setId(Jugador* this,int id){
	int retorno = 0;

	if(this != NULL){
		this -> id = id;
		retorno = 1;
	}

	return retorno;
}
int jug_getId(Jugador* this,int* id){
	int retorno = 0;

	if(this != NULL){
		*id = this -> id;
		retorno = 1;
	}

	return retorno;
}

int jug_setNombreCompleto(Jugador *this, char *nombreCompleto) {
	int retorno = 0;

	if (this != NULL) {
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno = 1;
	}

	return retorno;
}

int jug_getNombreCompleto(Jugador *this, char *nombreCompleto) {
	int retorno = 0;

	if (this != NULL) {
		strcpy(nombreCompleto, this->nombreCompleto);
		retorno = 1;
	}

	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion){
	int retorno = 0;

	if (this != NULL) {
		strcpy(this->posicion, posicion);
		retorno = 1;
	}

	return retorno;
}

int jug_getPosicion(Jugador *this, char *posicion) {
	int retorno = 0;

	if (this != NULL) {
		strcpy(posicion, this->posicion);
		retorno = 1;
	}

	return retorno;
}

int jug_setNacionalidad(Jugador *this, char *nacionalidad) {
	int retorno = 0;

	if (this != NULL) {
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 1;
	}

	return retorno;
}

int jug_getNacionalidad(Jugador *this, char *nacionalidad) {
	int retorno = 0;

	if (this != NULL) {
		strcpy(nacionalidad, this->nacionalidad);
		retorno = 1;
	}

	return retorno;
}

int jug_setEdad(Jugador *this, int edad) {
	int retorno = 0;

	if (this != NULL) {
		this->edad = edad;
		retorno = 1;
	}

	return retorno;
}

int jug_getEdad(Jugador *this, int *edad) {
	int retorno = 0;

	if (this != NULL) {
		*edad = this->edad;
		retorno = 1;
	}

	return retorno;
}

int jug_setIdSeleccion(Jugador *this, int idSeleccion) {
	int retorno = 0;

	if (this != NULL) {
		this->idSeleccion = idSeleccion;
		retorno = 1;
	}

	return retorno;
}

int jug_getSIdSeleccion(Jugador *this, int *idSeleccion) {
	int retorno = 0;

	if (this != NULL) {
		*idSeleccion = this->idSeleccion;
		retorno = 1;
	}

	return retorno;
}
