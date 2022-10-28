#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

int showMenu(){
	int option;

	printf("*** MENU PRINCIPAL ***\n"
						"1. ALTA JUGADOR\n"
						"2. BAJA JUGADOR\n"
						"3. MODIFICAR JUGADOR\n"
						"4. LISTAR INFORMES\n"
						"5. SALIR\n");
	getNumber(&option, "Ingrese la opcion que desea: ", "Opción inválida", 1, 5, 3);

	return option;
}

int confirmExit() {
	int exit;
	getNumber(&exit, "¿Desea salir del programa?\n1. Si\n2. No\n", "Opción inválida", 1, 2, 3);
	if(exit == 1){
		printf("¡Gracias por usar el programa!\n");
	}
	return exit;
}

static int incrementalID() {
	static int id = 1;
	return id++;
}

int initPlayers(sPlayer players[], int len) {
	int rtn = 0;
	int i;

	if (players != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			players[i].isEmpty = FREE;
		}
		rtn = 1;
	}
	return rtn;
}

int arrayState(sPlayer players[], int len) {
	int rtn = 0; // 0 vacio, 1 hay al menos un jugador, -1 lleno;
	int counter = 0;

	for (int i = 0; i < len; i++) {
		if (players[i].isEmpty == OCCUPIED) {
			counter++;
			rtn = 1;
		}
	}
	if (counter == len) {
		rtn = -1;
	}

	return rtn;
}

sPlayer loadPlayer(sConfederation confederations[], int len_cf) {
	sPlayer aux;

	getName(aux.name, "Ingrese el nombre del jugador: ", "Nombre inválido ", 4,
			50, 3);
	getPosition(aux.position, 50, "Ingrese posición de jugador: ",
			"Posición inválida. ", 3);
	getShort(&aux.shirtNumber, "Ingrese número de camiseta: ",
			"Número inválido", 1, 99, 3);
	listConfederations(confederations, len_cf);
	getNumber(&aux.idConfederation, "Ingrese id de la confederación: ",
			"ID inválido", 1001, 1006, 3);
	getFloat(&aux.salary, "Ingrese el salario del jugador: ",
			"Salario inválido. ", 100, 80000, 3);
	getShort(&aux.contractYears, "Ingrese años de contrato: ",
			"Número inválido", 1, 50, 3);
	aux.id = incrementalID();
	aux.isEmpty = OCCUPIED;

	return aux;
}

int addPlayer(sPlayer players[], int len_pl, sConfederation confederations[],int len_cf) {
	int rtn = 0;
	int i;

	if (players != NULL && len_pl > 0 && confederations != NULL && len_cf > 0) {
		i = findIsEmpty(players, len_pl);
		if (i != -1) {
				players[i] = loadPlayer(confederations, len_cf);
				rtn = 1;
			}
		}

	return rtn;
}

int sortByID(sPlayer players[], int len){
	int rtn = 0;
	sPlayer aux;

	if(players != NULL && len > 0){
		for(int i = 0; i<len-1; i++){
			for(int j = i+1; j<len; j++){
				if(players[i].id > players[j].id){
					aux = players[i];
					players[i] = players[j];
					players[j] = aux;
				}
			}
		}
		rtn = 1;
	}
	return rtn;
}

int deletePlayer(sPlayer players[], int len, sConfederation confederations[],int len_cf) {
	int rtn = 0;
	int id;
	int i;

		getNumber(&id, "Ingrese el ID del jugador que desea eliminar: ", "ID inválido.\n", 1, 3000, 3);

		if (players != NULL && len > 0 && confederations != NULL && len_cf > 0
				&& id > 0) {
			i = findByID(players, len, id);
			if (i != -1) {
				players[i].isEmpty = FREE;
				rtn = 1;
			} else {
				printf("El ID ingresado no se encontró");
			}
		}

	return rtn;
}

void showPlayer(sPlayer player, sConfederation confederations[], int len_cf){ // le cambie el nombre de la estructura de players a player
	char confederationName[50];
	loadConfederationsName(confederations, len_cf, player.idConfederation, confederationName);

	printf("\n| %-4d | %-19s | %-14s | %-15d | %15s | %-9.2f | %-18d |\n", player.id, player.name, player.position, player.shirtNumber, confederationName, player.salary, player.contractYears);
}

int listPlayers(sPlayer players[], int len, sConfederation confederations[], int len_cf) {
	int rtn = 0;
	int i;

	if (players != NULL && len > 0) {
		printf("===================================================================================================================\n");
		printf("||  ID  |       NOMBRE       |    POSICIÓN    | NRO DE CAMISETA |  CONFEDERACIÓN  |  SALARIO  | AÑOS DE CONTRATO ||\n");
		printf("===================================================================================================================");
		for (i = 0; i < len; i++) {
			if(players[i].isEmpty == OCCUPIED){
				showPlayer(players[i], confederations, len_cf);
				printf("===================================================================================================================");
			}

		}
		rtn = 1;
	}

	return rtn;
}

int findIsEmpty(sPlayer players[], int len) {
	int rtn = 0;
	int i;

	if (players != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (players[i].isEmpty == FREE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int findByID(sPlayer players[], int len, int id) {
	int rtn = -1;
	int i;

	if (players != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (players[i].id == id && players[i].isEmpty == OCCUPIED) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int modifyPlayer(sPlayer players[], int len, sConfederation confederations[],int len_cf) {
	int rtn = 0;
	int id;
	int i;
	int option;

		getNumber(&id, "\nIngrese el ID del jugador que desea modificar: ", "ID inválido.\n", 1, 3000, 3);

		if (players != NULL && len > 0 && id > 0 && confederations != NULL&& len_cf > 0) {
			i = findByID(players, len, id);
			if (i != -1) {
				getNumber(&option,
						"\nModificar:\n1. Nombre\n2. Posición\n3. Número de camiseta\n4. Confederación\n5. Salario\n6. Años de contrato\n",
						"Opción inválida.\n", 1, 6, 3);
				switch (option) {
				case 1:
					printf("\nIngrese el nuevo nombre: ");
					getName(players[i].name, "\nIngrese el nuevo nombre: ", "Nombre inválido ", 7, 50, 3);
					break;
				case 2:
					getPosition(players[i].position, 50,"\nIngrese la nueva posición: ","Posición inválida. ", 3);
					break;
				case 3:
					getShort(&players[i].shirtNumber,
							"\nIngrese el nuevo número de camiseta: ",
							"Número inválido", 1, 99, 3);
					break;
				case 4:
					listConfederations(confederations, len_cf);
					getNumber(&players[i].idConfederation,
							"\nIngrese la nueva confederación: ", "ID inválido",
							1001, 1006, 3);
					break;
				case 5:
					getFloat(&players[i].salary, "\nIngrese el nuevo salario: ","Salario inválido", 100, 80000, 3);
					break;
				case 6:
					getShort(&players[i].contractYears,
							"\nIngrese los nuevos años de contrato: ", "Número inválido", 1,
							50, 3);
					break;
				}
				rtn = 1;
			} else {
				printf("El ID ingresado no se encontró");
			}
		}

	return rtn;
}
