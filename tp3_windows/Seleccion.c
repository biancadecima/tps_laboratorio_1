#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"

Seleccion* selec_new() {
	Seleccion *nuevaSeleccion = NULL;

	nuevaSeleccion = (Seleccion*) malloc(sizeof(Seleccion));

	if (nuevaSeleccion != NULL) {
		nuevaSeleccion->id = 0;
		strcpy(nuevaSeleccion->pais, " ");
		strcpy(nuevaSeleccion->confederacion, " ");
		nuevaSeleccion->convocados = 0;
	}

	return nuevaSeleccion;
}

Seleccion* selec_newParametros(char *idStr, char *paisStr, char *confederacionStr, char *convocadosStr) {
	Seleccion *nuevaSeleccion = selec_new();

	if (nuevaSeleccion != NULL && idStr != NULL && paisStr != NULL
			&& confederacionStr != NULL && convocadosStr != NULL) {
		nuevaSeleccion->id = atoi(idStr);
		strcpy(nuevaSeleccion->pais, paisStr);
		strcpy(nuevaSeleccion->confederacion, confederacionStr);
		selec_setConvocados(nuevaSeleccion, atoi(convocadosStr));
	} else {
		free(nuevaSeleccion);
		nuevaSeleccion = NULL;
	}

	return nuevaSeleccion;
}

void selec_delete(Seleccion *this) {
	free(this);
	this = NULL;
}

int selec_getId(Seleccion *this, int *id) {
	int retorno = 0;

	if (this != NULL) {
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int selec_getPais(Seleccion *this, char *pais) {
	int retorno = 0;

	if (this != NULL) {
		strcpy(pais, this->pais);
		retorno = 1;
	}

	return retorno;
}

int selec_getConfederacion(Seleccion *this, char *confederacion) {
	int retorno = 0;

	if (this != NULL) {
		strcpy(confederacion, this->confederacion);
		retorno = 1;
	}

	return retorno;
}

int selec_setConvocados(Seleccion *this, int convocados) {
	int retorno = 0;

	if (this != NULL) {
		this->convocados = convocados;
		retorno = 1;
	}

	return retorno;
}

int selec_getConvocados(Seleccion *this, int *convocados) {
	int retorno = 0;

	if (this != NULL) {
		*convocados = this->convocados;
		retorno = 1;
	}

	return retorno;
}
