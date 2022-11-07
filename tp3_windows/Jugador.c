#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Jugador.h"

Jugador* jug_new(){//Pide memoria dinC!mica e inicializa los datos vacios
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

void jug_delete(Jugador* this){
	free(this);
	this = NULL;
}
/*
int jug_NewID() {
	FILE *pArchivo;
	char idStr[10];
	int id;

	pArchivo = fopen("jugadores.csv", "r");

	if (pArchivo != NULL) {
		do {
			fscanf(pArchivo, "%[^,]", idStr);

		} while (!feof(pArchivo));
	}

	id = atoi(idStr);

	fclose(pArchivo);

	return id + 1;
}
*/
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
