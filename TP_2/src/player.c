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
	getNumber(&option, "Ingrese la opcion que desea: ", "Opci�n inv�lida", 1, 5, 3);

	return option;
}

int confirmExit() {
	int exit;
	getNumber(&exit, "�Desea salir del programa?\n1. Si\n2. No\n", "Opci�n inv�lida", 1, 2, 3);
	if(exit == 1){
		printf("�Gracias por usar el programa!\n");
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

	getName(aux.name, "Ingrese el nombre del jugador: ", "Nombre inv�lido ", 4,
			50, 3);
	getPosition(aux.position, 50, "Ingrese posici�n de jugador: ",
			"Posici�n inv�lida. ", 3);
	getShort(&aux.shirtNumber, "Ingrese n�mero de camiseta: ",
			"N�mero inv�lido", 1, 99, 3);
	listConfederations(confederations, len_cf);
	getNumber(&aux.idConfederation, "Ingrese id de la confederaci�n: ",
			"ID inv�lido", 1001, 1006, 3);
	getFloat(&aux.salary, "Ingrese el salario del jugador: ",
			"Salario inv�lido. ", 100, 80000, 3);
	getShort(&aux.contractYears, "Ingrese a�os de contrato: ",
			"N�mero inv�lido", 1, 50, 3);
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

		getNumber(&id, "Ingrese el ID del jugador que desea eliminar: ", "ID inv�lido.\n", 1, 3000, 3);

		if (players != NULL && len > 0 && confederations != NULL && len_cf > 0
				&& id > 0) {
			i = findByID(players, len, id);
			if (i != -1) {
				players[i].isEmpty = FREE;
				rtn = 1;
			} else {
				printf("El ID ingresado no se encontr�");
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
		printf("||  ID  |       NOMBRE       |    POSICI�N    | NRO DE CAMISETA |  CONFEDERACI�N  |  SALARIO  | A�OS DE CONTRATO ||\n");
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

		getNumber(&id, "\nIngrese el ID del jugador que desea modificar: ", "ID inv�lido.\n", 1, 3000, 3);

		if (players != NULL && len > 0 && id > 0 && confederations != NULL&& len_cf > 0) {
			i = findByID(players, len, id);
			if (i != -1) {
				getNumber(&option,
						"\nModificar:\n1. Nombre\n2. Posici�n\n3. N�mero de camiseta\n4. Confederaci�n\n5. Salario\n6. A�os de contrato\n",
						"Opci�n inv�lida.\n", 1, 6, 3);
				switch (option) {
				case 1:
					printf("\nIngrese el nuevo nombre: ");
					getName(players[i].name, "\nIngrese el nuevo nombre: ", "Nombre inv�lido ", 7, 50, 3);
					break;
				case 2:
					getPosition(players[i].position, 50,"\nIngrese la nueva posici�n: ","Posici�n inv�lida. ", 3);
					break;
				case 3:
					getShort(&players[i].shirtNumber,
							"\nIngrese el nuevo n�mero de camiseta: ",
							"N�mero inv�lido", 1, 99, 3);
					break;
				case 4:
					listConfederations(confederations, len_cf);
					getNumber(&players[i].idConfederation,
							"\nIngrese la nueva confederaci�n: ", "ID inv�lido",
							1001, 1006, 3);
					break;
				case 5:
					getFloat(&players[i].salary, "\nIngrese el nuevo salario: ","Salario inv�lido", 100, 80000, 3);
					break;
				case 6:
					getShort(&players[i].contractYears,
							"\nIngrese los nuevos a�os de contrato: ", "N�mero inv�lido", 1,
							50, 3);
					break;
				}
				rtn = 1;
			} else {
				printf("El ID ingresado no se encontr�");
			}
		}

	return rtn;
}
