#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int calculateTotalPlayers(int* goalkeeperCounter, int* defenderCounter, int* midfieldCounter, int* strikerCounter){

	int totalLoadedPlayers ;
	int goalkeepers = *goalkeeperCounter;
	int defenders = *defenderCounter;
	int midfielders = *midfieldCounter;
	int strikers = *strikerCounter;

	totalLoadedPlayers = goalkeepers + defenders + midfielders + strikers;

	return totalLoadedPlayers;
}

float calculateAverage(int amount, int total){
	float average;

	average = (float) amount / total;

	return average;
}

int calculateMaintenance (int* maintenance, int lodging, int food, int transport){
	int rtn = -1;
	int total;

	if(maintenance != NULL) {
		total = lodging + food + transport;
		*maintenance = total;
		rtn = 0;
	}

	return rtn;
}

int calculateMaintenanceIncrease(int totalLoadedPlayers, int counterUEFA, int maintenanceCost, float* maintenanceCostIncrease, float* increasedMaintenanceCost){
	int rtn = -1;
	float increase;
	float costPlusIncrease;

	if (totalLoadedPlayers / 2 < counterUEFA){
		rtn = 0;

		increase = (float) maintenanceCost * 0.35;
		*maintenanceCostIncrease = increase;

		costPlusIncrease = (float) maintenanceCost + increase;
		*increasedMaintenanceCost = costPlusIncrease;
	}

	return rtn;
}
