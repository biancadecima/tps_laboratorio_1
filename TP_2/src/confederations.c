#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederations.h"
#include "input.h"
#include "player.h"

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
	printf("|| %d | %10s | %10s | %d ||\n", confederations.id, confederations.name, confederations.region, confederations.creationYear);
}

int listConfederations(sConfederation confederations[], int len_cf) {
	int rtn = 0;

	if (confederations != NULL && len_cf > 0) {
		printf("\n====================================================\n");
		printf("|| ID | CONFEDERACION | REGION | AÑO DE CREACION ||\n");
		for (int i = 0; i < len_cf; i++) {
			//printf("===================================\n");
			showConfederation(confederations[i]);
			//printf("===================================");
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
/*
//////////// ABM CONFERERATIONS /////////////

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
	char auxName;
	char auxRegion;

	aux.id = incrementalID();

	getName(&auxName, 50, "Ingrese nombre de confederacion: ", "Nombre inválido", 3);
	strcpy(aux.name, auxName);


	getNumber(&aux.creationYear, "Ingrese año de creación: ", "ID inválido", 1001, 1006, 3);

	//aux.isEmpty = OCCUPIED;

	return aux;
}

int findIsEmpty(sConfederation confederations[], int len) {
	int rtn = 0;
	int i;

	if (confederations != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (confederations[i].isEmpty == FREE) {
				rtn = i;
				break; //para romper las siguientes iteraciones del for una vez que se cumpla la condicion del if
			}
		}
	}

	return rtn;
}

int addConfederation(sConfederation confederations[],int len) {
	int rtn = 0;
	int i;

	if (confederations != NULL && len > 0) {
		i = findIsEmpty(confederations, len);
		if (i != -1) {
			confederations[i] = loadConfederation();
		}
		rtn = 1;
	}

	return rtn;
}

int findByID(sConfederation confederations[], int len, int id) {
	int rtn = -1; // para hacer if i<0 el legajo no existe
	int i;

	if (confederations != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (confederations[i].id == id) {
				rtn = i;
				break; //para romper las siguientes iteraciones del for una vez que se cumpla la condicion del if
			}
		}
	}

	return rtn;
}

int deletePlayer(sConfederation confederations[], int len) { // se muestra lista de jugadores ordenados por id y se elimina por id
	int rtn = 0;
	int id;
	int i;

	printf("Ingrese el ID del jugador que desea eliminar: ");
	scanf("%d", &id);

	if (confederations != NULL && len > 0 && id < 1) {
		i = findByID(confederations, len, id);
		if (i != -1) {
			confederations[i].isEmpty = FREE;
			rtn = 1;
		}else{
			printf("El ID ingresado no se encontró");
		}
	}

	return rtn;
}

int modifyProducto(sConfederation confederations[], int len) { // para borrar un prod primero le muestro todo lo que tenga
	int rtn = 0;
	int id;
	int i;
	int option;

	printf("Ingrese el ID del jugador que desea modificar: ");
	scanf("%d", &id);

	if (confederations != NULL && len > 0 && id > 0) {
		i = findByID(confederations, len, id);
		if (i != -1) {
			printf("\nModificar:\n1. Nombre\n2. Región\n3. Año de creación\n");
			scanf("%d", &option);
			switch (option) {
			case 1:
				printf("\nIngrese el nuevo nombre: ");

				break;
			case 2:
				printf("\nIngrese la nueva región: ");

				break;
			case 3:
				printf("\nIngrese el nuevo año de creación: ");

				break;
			}
		rtn = 1;
		}else{
			printf("El ID ingresado no se encontró");
		}
	}

	return rtn;
}
*/



