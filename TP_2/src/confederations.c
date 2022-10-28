#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederations.h"

static int incrementalIDConfederations() {
	static int id = 1000;
	return id++;
}

void hardcodeConfederations(sConfederation confederations[]) {
	sConfederation hardcode[6] = {
			{1001,"AFC","Asia",1954},
			{1002,"CAF","Africa",1968},
			{1003,"CONCACAF","Norte",2015},
			{1004,"CONMEBOL","Sudamerica",1916},
			{1005,"OFC","Oceania",1973},
			{1006,"UEFA","Europa",1954}
	};

	for(int i = 0; i<6; i++){
		confederations[i] = hardcode[i];
	}
}

void showConfederation(sConfederation confederations){
	printf("|| %d | %12s | %10s | %7d ||\n", confederations.id, confederations.name, confederations.region, confederations.creationYear);
}

int listConfederations(sConfederation confederations[], int len_cf) {
	int rtn = 0;

	if (confederations != NULL && len_cf > 0) {
		printf("\n====================================================\n");
		printf("||  ID  | CONFEDERACION |   REGION   | A�O DE CREACION ||\n");
		for (int i = 0; i < len_cf; i++) {
			showConfederation(confederations[i]);
		}
		rtn = 1;
	}
	return rtn;
}

int loadConfederationsName(sConfederation confederations[], int len, int idConfederation, char name[]){
	int rtn = 0;

	if (confederations != NULL && len > 0 && name != NULL){
		for(int i = 0; i<len; i++){
			if(confederations[i].id == idConfederation){
				strcpy(name, confederations[i].name);
				rtn = 1;
				break;
			}
		}
	}

	return rtn;
}

int loadConfederationsRegion(sConfederation confederations[], int len, int idConfederation, char region[]) {
	int rtn = 0;

	if (confederations != NULL && len > 0 && region != NULL) {
		for (int i = 0; i < len; i++) {
			if (confederations[i].id == idConfederation) {
				strcpy(region, confederations[i].region);
				rtn = 1;
				break;
			}
		}
	}

	return rtn;
}

int initConfederations(sConfederation confederations[], int len) {
	int rtn = 0;
	int i;

	if (confederations != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			confederations[i].isEmpty = FREE;
		}
		rtn = 1;
	}
	return rtn;
}
int id;
	char name[50];
	char region[50];
	int creationYear;


sConfederation loadConfederation() {

	sConfederation aux;

	if (getConfederation(aux.name, 50, "Ingrese nombre de confederacion: ", "Nombre inv�lido", 3) == 0
			&& getRegion(aux.region, 50, "Ingrese region de confederacion: ", "Region inv�lido", 3) == 0
			&& getNumber(&aux.creationYear, "Ingrese a�o de creacion de la confederaci�n: ", "A�o inv�lido", 1916, 2015, 3) == 0) {
		aux.id = incrementalIDConfederations();
		aux.isEmpty = OCCUPIED;
	}

	return aux;
}

int findIsEmptyConfederation(sConfederation confederations[], int len) {
	int rtn = 0;
	int i;

	if (confederations != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (confederations[i].isEmpty == FREE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int addConfederation(sConfederation confederations[], int len) {
	int rtn = 0;
	int i;

	if (confederations != NULL && len > 0) {
		i = findIsEmptyConfederation(confederations, len);
		if (i != -1) {
			confederations[i] = loadConfederation();
		}
		rtn = 1;
	}

	return rtn;
}

int findByIDConfederation(sConfederation confederations[], int len, int id) {
	int rtn = -1;
	int i;

	if (confederations != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (confederations[i].id == id) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int deleteConfederation(sConfederation confederations[], int len) {
	int rtn = 0;
	int id;
	int i;

	printf("Ingrese el ID de la confederacion que desea eliminar: ");
	scanf("%d", &id);

	if (confederations != NULL && len > 0) {
		i = findByIDConfederation(confederations, len, id);
		if (i != -1) {
			confederations[i].isEmpty = FREE;
			rtn = 1;
		}else{
			printf("El ID ingresado no se encontr�");
		}
	}

	return rtn;
}

int modifyConfederation(sConfederation confederations[], int len) {
	int rtn = 0;
	int id;
	int i;
	int option;

	printf("\nIngrese el ID de la confederacion que desea modificar: ");
	scanf("%d", &id);

	if (confederations != NULL && len > 0 && id > 0) {
		i = findByIDConfederation(confederations, len, id);
		if (i != -1) {
			printf("\nModificar:\n1. Nombre\n2. Regi�n\n3. A�o de creaci�n\n");
			scanf("%d", &option);
			switch (option) {
			case 1:
				getConfederation(confederations[i].name, 50, "\nIngrese el nuevo nombre: ", "Nombre inv�lido", 3);
				break;
			case 2:
				getRegion(confederations[i].region, 50, "\nIngrese la nueva regi�n: ", "Region inv�lido", 3);
				break;
			case 3:
				printf("\nIngrese el nuevo a�o de creaci�n: ");
				getNumber(&confederations[i].creationYear, "\nIngrese el nuevo a�o de creaci�n: ", "A�o inv�lido", 1916, 2015, 3);
				break;
			}
		rtn = 1;
		}else{
			printf("El ID ingresado no se encontr�");
		}
	}

	return rtn;
}

