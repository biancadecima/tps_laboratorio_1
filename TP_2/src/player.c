#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "player.h"
#include "confederations.h"

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

int confirmNavigation() {
	int navigation;

	getNumber(&navigation, "�Desea seguir cargando datos en el programa?\n1. Si\n2. No\n", "Opci�n inv�lida", 1, 2, 3);
	if(navigation == 2){
		printf("�Gracias por usar el programa!\n");
	}

	return navigation;
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

sPlayer loadPlayer(sConfederation confederations[], int len_cf) {
	sPlayer aux;

	aux.id = incrementalID();
	getName(aux.name, 50, "Ingrese el nombre del jugador: ", "Nombre inv�lido ", 3);
	getPosition(aux.position, 50, "Ingrese posici�n de jugador: ","Posici�n inv�lida. ", 3);
	getShort(&aux.shirtNumber, "Ingrese n�mero de camiseta: ", "N�mero inv�lido", 1, 99, 3);
	listConfederations(confederations, len_cf);
	getNumber(&aux.idConfederation, "Ingrese id de la confederaci�n: ", "ID inv�lido", 1001, 1006, 3);
	getFloat(&aux.salary, 10000000, "Ingrese el salario del jugador: ","Salario inv�lido", 3);
	getShort(&aux.contractYears, "Ingrese a�os de contrato: ", "N�mero inv�lido", 1, 50, 3);
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

	sortByID(players, len);
	listPlayers( players, len, confederations, len_cf);

	getNumber(&id, "Ingrese el ID del jugador que desea eliminar: ", "ID inv�lido.\n", 1, 3000, 3);

	if (players != NULL && len > 0 && confederations != NULL && len_cf > 0 && id > 0) {
		i = findByID(players, len, id);
		if (i != -1) {
			players[i].isEmpty = FREE;
			rtn = 1;
		}else{
			printf("El ID ingresado no se encontr�");
		}
	}

	return rtn;
}

void showPlayer(sPlayer player, sConfederation confederations[], int len_cf){ // le cambie el nombre de la estructura de players a player
	char confederationName[50];
	loadConfederationsName(confederations, len_cf, player.idConfederation, confederationName);

	printf("| %d | %10s | %10s | %d | %10s | %2.f | %d |\n", player.id, player.name, player.position, player.shirtNumber, confederationName, player.salary, player.contractYears);
}

int listPlayers(sPlayer players[], int len, sConfederation confederations[], int len_cf) {
	int rtn = 0;
	int i;

	if (players != NULL && len > 0) {
		printf("==============================================================================================\n");
		printf("|| ID | NOMBRE | POSICI�N | NRO DE CAMISETA || CONFEDERACI�N || SALARIO || A�OS DE CONTRATO ||\n");
		for (i = 0; i < len; i++) {
			if(players[i].isEmpty == OCCUPIED){
				printf("==============================================================================================\n");
				showPlayer(players[i], confederations, len_cf);
				printf("\n==============================================================================================\n");
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
				break; //para romper las siguientes iteraciones del for una vez que se cumpla la condicion del if
			}
		}
	}

	return rtn;
}

int findByID(sPlayer players[], int len, int id) {
	int rtn = -1; // para hacer if i<0 el legajo no existe
	int i;

	if (players != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (players[i].id == id && players[i].isEmpty == OCCUPIED) {
				rtn = i;
				break; //para romper las siguientes iteraciones del for una vez que se cumpla la condicion del if
			}
		}
	}

	return rtn;
}

int modifyProducto(sPlayer players[], int len, sConfederation confederations[],int len_cf) {
	int rtn = 0;
	int id;
	int i;
	int option;

	sortByID(players, len);
	listPlayers( players, len, confederations, len_cf);

	getNumber(&id, "Ingrese el ID del jugador que desea modificar: ", "ID inv�lido.\n", 1, 3000, 3);

	if (players != NULL && len > 0 && id > 0 && confederations != NULL && len_cf > 0) {
		i = findByID(players, len, id);
		if (i != -1) {
			getNumber(&option, "\nModificar:\n1. Nombre\n2. Posici�n\n3. N�mero de camiseta\n4. Confederaci�n\n5. Salario\n6. A�os de contrato\n", "Opci�n inv�lida.\n", 1, 6, 3);
			switch (option) {
			case 1:
				printf("\nIngrese el nuevo nombre: ");
				getName(players[i].name, 50, "\nIngrese el nuevo nombre: ", "Nombre inv�lido ", 3);
				break;
			case 2:
				getPosition(players[i].position, 50, "\nIngrese la nueva posici�n: ","Posici�n inv�lida. ", 3);
				break;
			case 3:
				getShort(&players[i].shirtNumber, "\nIngrese el nuevo n�mero de camiseta: ", "N�mero inv�lido", 1, 99, 3);
				break;
			case 4:
				listConfederations(confederations, len_cf);
				getNumber(&players[i].idConfederation, "\nIngrese la nueva confederaci�n: ", "ID inv�lido", 1001, 1006, 3);
				break;
			case 5:
				printf("\nIngrese el nuevo salario: ");
				getFloat(&players[i].salary, 10000000, "Ingrese el salario del jugador: ","Salario inv�lido", 3);
				break;
			case 6:
				printf("\nIngrese los nuevos a�os de contrato: ");
				getShort(&players[i].contractYears, "Ingrese a�os de contrato: ", "N�mero inv�lido", 1, 50, 3);
				break;
			}
		rtn = 1;
		}else{
			printf("El ID ingresado no se encontr�");
		}
	}

	return rtn;
}

int showReportsMenu(){
	int option;

	printf("Elija la opcion de informe que desea:"
					"1. Listado de los jugadores ordenados alfab�ticamente por nombre de confederaci�n y nombre de jugador.\n"
					"2. Listado de confederaciones con sus jugadores.\n"
					"3. Total y promedio de todos los salarios y cu�ntos jugadores cobran m�s del salario promedio.\n"
					"4. Informar la confederaci�n con mayor cantidad de a�os de contratos total.\n"
					"5. Informar porcentaje de jugadores por cada confederaci�n.\n"
					"6. Informar cual es la regi�n con m�s jugadores y el listado de los mismos.\n");
	getNumber(&option, "Elija la opcion de informe que desea ver: ", "Opci�n inv�lida ", 1, 6, 3);

	return option;
}

int showPlayersOfAConfederation(sPlayer players[], int len, sConfederation confederations[], int len_cf, int idConfederation){
	int rtn = 0;
	int flag = 1;

	if (players != NULL && len > 0 && confederations != NULL && len_cf > 0 && (idConfederation >= 1001 && idConfederation <= 1006)) {
		for (int i = 0; i < len; i++) {
			if (players[i].isEmpty == OCCUPIED
					&& players[i].idConfederation == idConfederation) {
				showPlayer(players[i], confederations, len_cf);
				flag = 0;
			}
		}
		if (flag) {
			printf("\nNo se encuentran jugadores perteenecientes a la confederacion");
		}
		rtn = 1;

	}

	return rtn;
}

int showConfederationsPlayers(sPlayer players[], int len, sConfederation confederations[], int len_cf){
	int rtn = 0;
	//int idConfederation = 1001;

	if (players != NULL && len > 0 && confederations != NULL && len_cf > 0) {
		/*printf("LISTADO DE CONFEDERACIONES Y SUS JUGADORES\n");
		for(int i=0; i<len_cf; i++){
			printf("CONFEDERACI�N: %s\n", confederations[i].name);
			for(int id = 1001; id<=1006; id++){
				showPlayersOfAConfederation(players, len, confederations, len_cf, 1001);
			}
		}*/

		printf("CONFEDERACI�N AFC\n");
		showPlayersOfAConfederation(players, len, confederations, len_cf, 1001);
		printf("\nCONFEDERACI�N CAF\n");
		showPlayersOfAConfederation(players, len, confederations, len_cf, 1002);
		printf("\nCONFEDERACI�N CONCACAF\n");
		showPlayersOfAConfederation(players, len, confederations, len_cf, 1003);
		printf("\nCONFEDERACI�N CONMEBOL\n");
		showPlayersOfAConfederation(players, len, confederations, len_cf, 1004);
		printf("\nCONFEDERACI�N OFC\n");
		showPlayersOfAConfederation(players, len, confederations, len_cf, 1005);
		printf("\nCONFEDERACI�N UEFA\n");
		showPlayersOfAConfederation(players, len, confederations, len_cf, 1006);

		rtn = 1;
	}

	return rtn;
}

//Total y promedio de todos los salarios y cu�ntos jugadores cobran m�s del salario promedio.\n"
int calculateTotalSalaries(){
	int rtn = 0;

	return rtn;
}

float calculateAverage(int amount, int total){
	float average;

	average = (float) amount / total;

	return average;
}

int sortByConfederationNameAndPlayerName(sPlayer players[], int len, sConfederation confederations[], int len_cf){
	int rtn = 0;
	sPlayer aux;
	char confName1[50];
	char confName2[50];

	if(players != NULL && len > 0 && confederations != NULL && len_cf > 0){
		for(int i = 0; i < len-1; i++){
			for(int j = i+1; j < len; j++){
				loadConfederationsName(confederations, len_cf, players[i].idConfederation, confName1);
				loadConfederationsName(confederations, len_cf, players[j].idConfederation, confName2);
				if( strcmp(confName1, confName2) > 0 || (strcmp(confName1, confName2) == 0 && strcmp(players[i].name, players[j].name) > 0)	){
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
