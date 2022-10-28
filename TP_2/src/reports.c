#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reports.h"


int showReportsMenu(){
	int option;

	printf("\n1. Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.\n"
			"2. Listado de confederaciones con sus jugadores.\n"
			"3. Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.\n"
			"4. Informar la confederación con mayor cantidad de años de contratos total.\n"
			"5. Informar porcentaje de jugadores por cada confederación.\n"
			"6. Informar cual es la región con más jugadores y el listado de los mismos.\n");
	getNumber(&option, "\nElija la opcion de informe que desea ver: ", "Opción inválida ", 1, 6, 3);

	return option;
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

int showPlayersOfAConfederation(sPlayer players[], int len, sConfederation confederations[], int len_cf, int idConfederation){
	int rtn = 0;
	int flag = 1;

	if (players != NULL && len > 0 && confederations != NULL && len_cf > 0 && (idConfederation >= 1001 && idConfederation <= 1006)) {
		for (int i = 0; i < len; i++) {
			if (players[i].isEmpty == OCCUPIED && players[i].idConfederation == idConfederation) {
				showPlayer(players[i], confederations, len_cf);
				flag = 0;
			}
		}
		if (flag) {
			printf("No se encuentran jugadores perteenecientes a la confederacion\n");
		}
		rtn = 1;
	}

	return rtn;
}

int showConfederationsPlayers(sPlayer players[], int len, sConfederation confederations[], int len_cf) {
	int rtn = 0;

	if (players != NULL && len > 0 && confederations != NULL && len_cf > 0) {
		printf("LISTADO DE CONFEDERACIONES Y SUS JUGADORES\n");
		printf("CONFEDERACIÓN AFC\n");
		showPlayersOfAConfederation(players, len, confederations, len_cf, 1001);
		printf("\nCONFEDERACIÓN CAF\n");
		showPlayersOfAConfederation(players, len, confederations, len_cf, 1002);
		printf("\nCONFEDERACIÓN CONCACAF\n");
		showPlayersOfAConfederation(players, len, confederations, len_cf, 1003);
		printf("\nCONFEDERACIÓN CONMEBOL\n");
		showPlayersOfAConfederation(players, len, confederations, len_cf, 1004);
		printf("\nCONFEDERACIÓN OFC\n");
		showPlayersOfAConfederation(players, len, confederations, len_cf, 1005);
		printf("\nCONFEDERACIÓN UEFA\n");
		showPlayersOfAConfederation(players, len, confederations, len_cf, 1006);
		rtn = 1;
	}

	return rtn;
}

int calculateTotalPlayersSalaries(sPlayer players[], int len, float* total){
	int rtn = 0;
	*total = 0;

	if(players != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(players[i].isEmpty == OCCUPIED){
				*total += players[i].salary;
				rtn = 1;
			}
		}
	}

	return rtn;
}

int calculateTotalPlayers(sPlayer players[], int len, int* total){
	int rtn = 0;
	*total = 0;

	if(players != NULL && len > 0){
			for(int i = 0; i < len; i++){
				if(players[i].isEmpty == OCCUPIED){
					(*total)++;
					rtn = 1;
				}
			}
		}

	return rtn;
}

int calculateSalariesAverage(sPlayer players[], int len, float* averageSalary){
	int rtn = 0;
	float totalSalaries;
	int totalPlayers;

	if(players != NULL && len > 0){
		if(calculateTotalPlayersSalaries(players, len, &totalSalaries) && calculateTotalPlayers(players, len, &totalPlayers)){
			*averageSalary = calculateAverage(totalSalaries, totalPlayers);
			rtn = 1;
		}
	}

	return rtn;
}

int countSalariesAboveAverage(sPlayer players[], int len, int* counter){
	int flag = 0;
	float average;
	*counter = 0;

	if (players != NULL && len > 0) {
		if (calculateSalariesAverage(players, len, &average)) {
			for (int i = 0; i < len; i++) {
				if (players[i].isEmpty == OCCUPIED && players[i].salary > average) {
					(*counter)++;
					flag = 1;
				}
			}
			if (flag == 0) {
					printf("\nNo hay jugadores con sueldos que superen el promedio\n");
			}
		}
	}

	return flag;
}

int calculateConfederationsTotalContractYears(sPlayer players[], int len, int* contractYearsAFC, int* contractYearsCAF, int* contractYearsCONCACAF, int* contractYearsCONMEBOL, int* contractYearsOFC, int* contractYearsUEFA){
	int rtn = 0;
	*contractYearsAFC = 0;
	*contractYearsCAF = 0;
	*contractYearsCONCACAF = 0;
	*contractYearsCONMEBOL = 0;
	*contractYearsOFC = 0;
	*contractYearsUEFA = 0;

	if (players != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (players[i].isEmpty == OCCUPIED) {
				switch (players[i].idConfederation) {
				case 1001:
					*contractYearsAFC += players[i].contractYears;
					rtn = 1;
					break;
				case 1002:
					*contractYearsCAF += players[i].contractYears;
					rtn = 1;
					break;
				case 1003:
					*contractYearsCONCACAF += players[i].contractYears;
					rtn = 1;
					break;
				case 1004:
					*contractYearsCONMEBOL += players[i].contractYears;
					rtn = 1;
					break;
				case 1005:
					*contractYearsOFC += players[i].contractYears;
					break;
				case 1006:
					*contractYearsUEFA += players[i].contractYears;
					rtn = 1;
					break;
				}
			}
		}
	}

	return rtn;
}

int getConfederationWithMoreContractYears(sPlayer players[], int len){
	int contractYearsAFC;
	int	contractYearsCAF;
	int	contractYearsCONCACAF;
	int	contractYearsCONMEBOL;
	int	contractYearsOFC;
	int	contractYearsUEFA;
	int idConfederationWithMoreContractYears;

	if (players != NULL && len > 0) {
		calculateConfederationsTotalContractYears(players, len, &contractYearsAFC, &contractYearsCAF, &contractYearsCONCACAF, &contractYearsCONMEBOL, &contractYearsOFC, &contractYearsUEFA);

		if(contractYearsAFC >= contractYearsCAF && contractYearsAFC >= contractYearsCONCACAF && contractYearsAFC >= contractYearsCONMEBOL && contractYearsAFC >= contractYearsOFC && contractYearsAFC >=contractYearsUEFA){
			idConfederationWithMoreContractYears = 1001;
		}else if(contractYearsCAF >= contractYearsAFC && contractYearsCAF >= contractYearsCONCACAF && contractYearsCAF >= contractYearsCONMEBOL && contractYearsCAF >= contractYearsOFC && contractYearsCAF >= contractYearsUEFA){
			idConfederationWithMoreContractYears = 1002;
		}else if(contractYearsCONCACAF >= contractYearsAFC && contractYearsCONCACAF >= contractYearsCAF && contractYearsCONCACAF >= contractYearsCONMEBOL && contractYearsCONCACAF >= contractYearsOFC && contractYearsCONCACAF >=contractYearsUEFA){
			idConfederationWithMoreContractYears = 1003;
		}else if(contractYearsCONMEBOL >= contractYearsAFC && contractYearsCONMEBOL >= contractYearsCONCACAF && contractYearsCONMEBOL >= contractYearsCAF && contractYearsCONMEBOL >= contractYearsOFC && contractYearsCONMEBOL >=contractYearsUEFA){
			idConfederationWithMoreContractYears = 1004;
		}else if(contractYearsOFC >= contractYearsAFC && contractYearsOFC >= contractYearsCONCACAF && contractYearsOFC >= contractYearsCONMEBOL && contractYearsOFC >= contractYearsCAF && contractYearsOFC >=contractYearsUEFA){
			idConfederationWithMoreContractYears = 1005;
		}else if(contractYearsUEFA >= contractYearsAFC && contractYearsUEFA >= contractYearsCONCACAF && contractYearsUEFA >= contractYearsCONMEBOL && contractYearsUEFA >= contractYearsOFC && contractYearsUEFA >=contractYearsCAF){
			idConfederationWithMoreContractYears = 1006;
		}
	}

	return idConfederationWithMoreContractYears;
}

int calculatePlayersPerConfederation(sPlayer players[], int len, int* playersAFC, int* playersCAF, int* playersCONCACAF, int* playersCONMEBOL, int* playersOFC, int* playersUEFA){
	int rtn = 0;
	*playersAFC = 0;
	*playersCAF = 0;
	*playersCONCACAF = 0;
	*playersCONMEBOL = 0;
	*playersOFC = 0;
	*playersUEFA = 0;

	if (players != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (players[i].isEmpty == OCCUPIED) {
				switch (players[i].idConfederation) {
				case 1001:
					(*playersAFC) ++;
					rtn = 1;
					break;
				case 1002:
					(*playersCAF) ++;
					rtn = 1;
					break;
				case 1003:
					(*playersCONCACAF) ++;
					rtn = 1;
					break;
				case 1004:
					(*playersCONMEBOL) ++;
					rtn = 1;
					break;
				case 1005:
					(*playersOFC) ++;
					break;
				case 1006:
					(*playersUEFA) ++;
					rtn = 1;
					break;
				}
			}
		}
	}

	return rtn;
}

int calculatePercentagePlayersPerConfederation (sPlayer players[], int len, float* percentagePlayersAFC, float* percentagePlayersCAF, float* percentagePlayersCONCACAF, float* percentagePlayersCONMEBOL, float* percentagePlayersOFC, float* percentagePlayersUEFA){
	int rtn = 0;
	int totalPlayers;
	int playersAFC;
	int	playersCAF;
	int	playersCONCACAF;
	int	playersCONMEBOL;
	int	playersOFC;
	int	playersUEFA;

	if (players != NULL && len > 0) {
		calculatePlayersPerConfederation(players, len, &playersAFC, &playersCAF, &playersCONCACAF, &playersCONMEBOL, &playersOFC, &playersUEFA);
		calculateTotalPlayers(players, len, &totalPlayers);

		*percentagePlayersAFC = calculatePercentage(playersAFC, totalPlayers);
		*percentagePlayersCAF = calculatePercentage(playersCAF, totalPlayers);
		*percentagePlayersCONCACAF = calculatePercentage(playersCONCACAF, totalPlayers);
		*percentagePlayersCONMEBOL = calculatePercentage(playersCONMEBOL, totalPlayers);
		*percentagePlayersOFC = calculatePercentage(playersOFC, totalPlayers);
		*percentagePlayersUEFA = calculatePercentage(playersUEFA, totalPlayers);
		rtn = 1;
	}

	return rtn;
}

int getMostPlayersConfederation(sPlayer players[], int len, sConfederation confederations[], int len_cf) {
	int idMostPlayersConfederation;
	int playersAFC;
	int playersCAF;
	int playersCONCACAF;
	int playersCONMEBOL;
	int playersOFC;
	int playersUEFA;



	calculatePlayersPerConfederation(players, len, &playersAFC, &playersCAF, &playersCONCACAF, &playersCONMEBOL, &playersOFC, &playersUEFA);
	if (playersAFC >= playersCAF
			&& playersAFC >= playersCONCACAF
			&& playersAFC >= playersCONMEBOL
			&& playersAFC >= playersOFC
			&& playersAFC >= playersUEFA) {
		idMostPlayersConfederation = 1001;
	} else if (playersCAF >= playersAFC
			&& playersCAF >= playersCONCACAF
			&& playersCAF >= playersCONMEBOL
			&& playersCAF >= playersOFC
			&& playersCAF >= playersUEFA) {
		idMostPlayersConfederation = 1002;
	} else if (playersCONCACAF >= playersAFC
			&& playersCONCACAF >= playersCAF
			&& playersCONCACAF >= playersCONMEBOL
			&& playersCONCACAF >= playersOFC
			&& playersCONCACAF >= playersUEFA) {
		idMostPlayersConfederation = 1003;
	} else if (playersCONMEBOL >= playersAFC
			&& playersCONMEBOL >= playersCAF
			&& playersCONMEBOL >= playersCONCACAF
			&& playersCONMEBOL >= playersOFC
			&& playersCONMEBOL >= playersUEFA) {
		idMostPlayersConfederation = 1004;
	} else if (playersOFC >= playersAFC
			&& playersOFC >= playersCAF
			&& playersOFC >= playersCONCACAF
			&& playersOFC >= playersCONMEBOL
			&& playersOFC >= playersUEFA) {
		idMostPlayersConfederation = 1005;
	} else if (playersUEFA >= playersAFC
			&& playersUEFA >= playersCAF
			&& playersUEFA >= playersCONCACAF
			&& playersUEFA >= playersCONMEBOL
			&& playersUEFA >= playersOFC) {
		idMostPlayersConfederation = 1006;
	}

	return idMostPlayersConfederation;
}

int reportManagement(sPlayer players[], int len, sConfederation confederations[], int len_cf) {
	int rtn = 0;
	float totalPlayersSalaries;
	float averagePlayersSalaries;
	int playersSalariesAboveAverage;
	int idConfederationWithMoreContractYears;
	char confederationName[50];
	float percentagePlayersAFC;
	float percentagePlayersCAF;
	float percentagePlayersCONCACAF;
	float percentagePlayersCONMEBOL;
	float percentagePlayersOFC;
	float percentagePlayersUEFA;
	int idMostPlayersConfederation;
	char mostPlayersRegion[50];

		switch (showReportsMenu()) {
		case 1:
			sortByConfederationNameAndPlayerName(players, len, confederations, len_cf);
			listPlayers( players, len, confederations, len_cf);
			break;
		case 2:
			showConfederationsPlayers(players, len, confederations, len_cf);
			break;
		case 3:
			calculateTotalPlayersSalaries(players, len, &totalPlayersSalaries);
			printf("\nEl total de todos los salarios de los jugadores es de: $ %.2f", totalPlayersSalaries);

			calculateSalariesAverage(players, len, &averagePlayersSalaries);
			printf("\nEl promedio de los salarios de los jugadores es de: $ %.2f", averagePlayersSalaries);

			if(countSalariesAboveAverage(players, len, &playersSalariesAboveAverage)){
				printf("\nEl numero de jugadores cuyo salario supera el promedio es de: %d", playersSalariesAboveAverage);
			}
			break;
		case 4:
			idConfederationWithMoreContractYears = getConfederationWithMoreContractYears(players, len);
			loadConfederationsName(confederations, len_cf, idConfederationWithMoreContractYears, confederationName);
			printf("\n La confederacion con mayor cantidad de años de contrato es: %s \n", confederationName);
			break;
		case 5:
			calculatePercentagePlayersPerConfederation(players, len, &percentagePlayersAFC, &percentagePlayersCAF, &percentagePlayersCONCACAF, &percentagePlayersCONMEBOL, &percentagePlayersOFC, &percentagePlayersUEFA);

			printf("\nEl porcentaje de jugadores en AFC es: %.2f", percentagePlayersAFC);
			printf("\nEl porcentaje de jugadores en CAF es: %.2f", percentagePlayersCAF);
			printf("\nEl porcentaje de jugadores en CONCACAF es: %.2f", percentagePlayersCONCACAF);
			printf("\nEl porcentaje de jugadores en CONMEBOL es: %.2f", percentagePlayersCONMEBOL);
			printf("\nEl porcentaje de jugadores en OFC es: %.2f", percentagePlayersOFC);
			printf("\nEl porcentaje de jugadores en UEFA es: %.2f", percentagePlayersUEFA);
			break;
		case 6:
			idMostPlayersConfederation = getMostPlayersConfederation(players, len, confederations, len_cf);
			loadConfederationsRegion(confederations,  len, idMostPlayersConfederation, mostPlayersRegion);
			printf("\n La region con mas jugadores es %s \n", mostPlayersRegion);
			showPlayersOfAConfederation(players, len, confederations, len_cf, idMostPlayersConfederation);
			break;
		}

	return rtn;
}

