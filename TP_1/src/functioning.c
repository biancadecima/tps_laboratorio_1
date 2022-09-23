#include "functioning.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int isNumber(char* cadena);
static int passToInt(int* pResultado);
static int myGets(char* cadena, int longitud);

static int myGets(char *cadena, int longitud) {
	if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n')
		{
			cadena[strlen(cadena) - 1] = '\0';
		}
		return 0;
	}
	return -1;
}

static int passToInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && isNumber(buffer)) {

			*pResultado = atoi(buffer);
			retorno = 0;
		}

	}
	return retorno;
}

static int isNumber(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int getNumber(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos){
	int bufferInt;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (passToInt(&bufferInt) == 0) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

void showMenu(int* lodgingCost, int* foodCost, int* transportCost, int* goalkeeperCounter, int* defenderCounter, int* midfieldCounter, int* strikerCounter){
	printf(
			"\n**** Menú Principal ****\n"
					"1. Ingreso de costos de Mantenimiento\nCosto de hospedaje -> $%d\nCosto de comida -> $%d\nCosto de transporte -> $%d\n"
					"2. Carga de jugadores\nArqueros -> %d\nDefensores -> %d\nMediocampistas -> %d\nDelanteros -> %d\n"
					"3. Realizar todos los calculos\n"
					"4. Informar resultados\n"
					"5. Salir\n",
			*lodgingCost, *foodCost, *transportCost, *goalkeeperCounter, *defenderCounter, *midfieldCounter, *strikerCounter);
}

int confirmNavigation() {
	int navigation;

	getNumber(&navigation, "¿Desea seguir cargando datos en el programa?\n1. Si\n2. No\n", "Opción inválida", 1, 2, 3);
	if(navigation == 2){
		printf("¡Gracias por usar el programa!\n");
	}

	return navigation;

}

int loadMaintenanceCosts(int option, int *lodgingCost, int *foodCost, int *transportCost){
	int rtn = -1;
	int cost;

	if(lodgingCost != NULL && foodCost != NULL && transportCost != NULL){
		rtn = 0;
		switch (option) {
		case 1:
			getNumber(&cost, "Cargue el costo de hospedaje: $", "Valor inválido", 0, 2147483640, 3);
			*lodgingCost = cost;
			break;
		case 2:
			getNumber(&cost, "Cargue el costo de comida: $", "Valor inválido", 0, 2147483640, 3);
			*foodCost = cost;
			break;
		case 3:
			getNumber(&cost, "Cargue el costo de trasporte: $", "Valor inválido", 0, 2147483640, 3);
			*transportCost = cost;
			break;
		}
	}

	return rtn;
}

int loadPlayer(int *playerCounter, int* shirtNumber, int* confederation) {
	int rtn = -1;
	int number;

	if(playerCounter != NULL && shirtNumber != NULL && confederation != NULL){
		rtn = 0;

		getNumber(&number, "Cargue el numero de camiseta: ", "Número inválido", 1, 99, 3);
		*shirtNumber = number;

		getNumber(&number, "1. AFC\n2. CAF\n3. CONCACAF\n4. CONMEBOL\n5. UEFA\n6. OFC\nIngrese la confederación del jugador: ", "Selección inválida", 1, 6, 3);
		*confederation = number;

		(*playerCounter)++;
	}

	return rtn;
}

void confederationCounter(int *confederation, int *counterAFC, int *counterCAF, int *counterCONCACAF, int *counterCONMEBOL, int *counterUEFA, int *counterOFC) {
	int conf = *confederation;

	switch (conf) {
	case 1:
		(*counterAFC)++;
		break;
	case 2:
		(*counterCAF)++;
		break;
	case 3:
		(*counterCONCACAF)++;
		break;
	case 4:
		(*counterCONMEBOL)++;
		break;
	case 5:
		(*counterUEFA)++;
		break;
	case 6:
		(*counterOFC)++;
		break;
	}
}
