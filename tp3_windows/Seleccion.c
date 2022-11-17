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

void selec_MostrarSeleccion(Seleccion* this){
	int id;
	char pais[100];
	char confederacion[100];
	int convocados;

	if(this != NULL){
		if(selec_getId(this, &id)
			&& selec_getPais(this, pais)
			&& selec_getConfederacion(this, confederacion)
			&& selec_getConvocados(this, &convocados)){
			printf("| %3d | %-15s | %-12s | %10d |\n", id, pais, confederacion, convocados);
		}

	}
}

int selec_BuscarPorID(LinkedList *pArrayListSeleccion, int idBuscado) {
	int indice = -1;
	int largoSeleccion;
	int idAux;
	Seleccion *pSeleccion;

	if (pArrayListSeleccion != NULL && idBuscado > 0) {
		largoSeleccion = ll_len(pArrayListSeleccion);
		for (int i = 0; i < largoSeleccion; i++) {
			pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
			if (pSeleccion != NULL) {
				selec_getId(pSeleccion, &idAux);
				if (idAux == idBuscado) {
					indice = i;
					break;
				}
			}
		}
	}

	return indice;
}

int selec_CompareById(void *s1, void *s2) {
	int compara = 0;
	Seleccion *pSeleccionUno = NULL;
	Seleccion *pSeleccionDos = NULL;
	int id1;
	int id2;

	if (s1 != NULL && s2 != NULL) {
		pSeleccionUno = (Seleccion*) s1;
		pSeleccionDos = (Seleccion*) s2;
		if (pSeleccionUno != NULL && pSeleccionDos != NULL) {
			selec_getId(pSeleccionUno, &id1);
			selec_getId(pSeleccionDos, &id2);
			if(id1 > id2){
				compara = 1;
			}else{
				compara = -1;
			}

		}
	}

	return compara;
}

int selec_CompareByConfederation(void *s1, void *s2) {
	int compara;
	Seleccion *pSeleccionUno = NULL;
	Seleccion *pSeleccionDos = NULL;
	char confederacionUno[50];
	char confederacionDos[50];

	if (s1 != NULL && s2 != NULL) {
		pSeleccionUno = (Seleccion*) s1;
		pSeleccionDos = (Seleccion*) s2;
		if (pSeleccionUno != NULL && pSeleccionDos != NULL) {
			selec_getConfederacion(pSeleccionUno, confederacionUno);
			selec_getConfederacion(pSeleccionDos, confederacionDos);

			compara = strcmp(confederacionUno, confederacionDos);
		}
	}

	return compara;
}

int selec_decrementarConvocados(LinkedList *pArrayListSeleccion, int idSeleccion) {
	int retorno = 0;
	int indice;
	Seleccion *pSeleccion = NULL;
	int convocados;

	if (pArrayListSeleccion != NULL && idSeleccion > 0) {
		indice = selec_BuscarPorID(pArrayListSeleccion, idSeleccion);
		if (indice > 0) {
			pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indice);
			if (pSeleccion != NULL) {
				selec_getConvocados(pSeleccion, &convocados);
				convocados--;
				if (convocados >= 0) {
					selec_setConvocados(pSeleccion, convocados);
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

int selec_incrementarConvocados(LinkedList *pArrayListSeleccion, int idSeleccion) {
	int retorno = 0;
	int indice;
	Seleccion *pSeleccion = NULL;
	int convocados;

	if (pArrayListSeleccion != NULL && idSeleccion > 0) {
		indice = selec_BuscarPorID(pArrayListSeleccion, idSeleccion);
		if (indice > 0) {
			pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indice);
			if (pSeleccion != NULL) {
				selec_getConvocados(pSeleccion, &convocados);
				convocados++;
				if (convocados >= 0) {
					selec_setConvocados(pSeleccion, convocados);
					retorno = 1;
				}
			}
		}
	}

	return retorno;
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
