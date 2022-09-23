#include <stdio.h>
#include <stdlib.h>

#include "functioning.h"
#include "operations.h"

#define AFC 1
#define CAF 2
#define CONCACAF 3
#define CONMEBOL 4
#define UEFA 5
#define OFC 6

int main(void) {
	setbuf(stdout, NULL);

	int option;
	int cost;
	int lodgingCost=0;
	int foodCost=0;
	int transportCost=0;
	int position;
	int shirtNumber;
	int confederation;
	int goalkeeperCounter = 0;
	int defenderCounter = 0;
	int midfieldCounter = 0;
	int strikerCounter = 0;
	int counterAFC = 0;
	int counterCAF = 0;
	int counterCONCACAF = 0;
	int counterCONMEBOL = 0;
	int counterUEFA = 0;
	int counterOFC = 0;
	int totalLoadedPlayers;
	float averageUEFAPlayers;
	float averageCONMEBOLPlayers;
	float averageCONCACAFPlayers;
	float averageAFCPlayers;
	float averageOFCPlayers;
	float averageCAFPlayers;
	int maintenanceCost= 0;
	float maintenanceCostIncrease = 0;
	float increasedMaintenanceCost = 0;
	int flagIncrease = 1;
	int flagCase1 = 1;
	int flagCase2 = 1;
	int flagCase3 = 1;

	do {
		showMenu(&lodgingCost, &foodCost, &transportCost, &goalkeeperCounter, &defenderCounter, &midfieldCounter, &strikerCounter);
		getNumber(&option, "\nSeleccione una opción: ", "Opción inválida", 1, 5, 3);
		switch (option) {
			case 1: //Ingreso de los costos de Mantenimiento.
				getNumber(&cost, "\n1. Costo de hospedaje\n2. Costo de comida\n3. Costo de transporte\nSeleccione una opción: ", "Opción inválida", 1, 3, 3);
				loadMaintenanceCosts(cost, &lodgingCost, &foodCost, &transportCost);
				if(lodgingCost > 0 && foodCost > 0 && transportCost > 0){
					flagCase1 = 0;
				}
			break;
			case 2: //Carga de jugadores:
				//do {
				printf("1. Arqueros\n2. Defensores\n3. Mediocampistas\n4. Delanteros\n");
				getNumber(&position, "Seleccione la posición a ingresar: ","Opción inválida", 1, 4, 3);
				switch (position) {
					case 1://Arqueros
						if (goalkeeperCounter < 2) {
							loadPlayer(&goalkeeperCounter, &shirtNumber, &confederation);
							confederationCounter(&confederation, &counterAFC, &counterCAF, &counterCONCACAF, &counterCONMEBOL, &counterUEFA, &counterOFC);
						} else{
							printf("No se pueden seguir cargando datos de arqueros\n");
						}
					break;
					case 2: // Defensores
						if (defenderCounter < 8) {
							loadPlayer(&defenderCounter, &shirtNumber, &confederation);
							confederationCounter(&confederation, &counterAFC, &counterCAF, &counterCONCACAF, &counterCONMEBOL, &counterUEFA, &counterOFC);
						} else {
							printf("No se pueden seguir cargando datos de defensores\n");
						}
						break;
					case 3: // Mediocampistas
						if (midfieldCounter < 8) {
							loadPlayer(&midfieldCounter, &shirtNumber, &confederation);
							confederationCounter(&confederation, &counterAFC, &counterCAF, &counterCONCACAF, &counterCONMEBOL, &counterUEFA, &counterOFC);
						} else {
							printf("No se pueden seguir cargando datos de mediocampistas\n");
						}
						break;
					case 4: // Delanteros
						if (strikerCounter < 4) {
							loadPlayer(&strikerCounter, &shirtNumber, &confederation);
							confederationCounter(&confederation, &counterAFC, &counterCAF, &counterCONCACAF, &counterCONMEBOL, &counterUEFA, &counterOFC);
						} else {
							printf("No se pueden seguir cargando datos de delanteros\n");
						}
						break;
				}
				if(goalkeeperCounter == 2 && defenderCounter == 8 && midfieldCounter == 8 && strikerCounter == 4){
					flagCase2 = 0;
				}
			break;
			case 3: //Realizar todos los cálculos.
				if(flagCase1 == 0 && flagCase2 == 0){
					totalLoadedPlayers = calculateTotalPlayers(&goalkeeperCounter, &defenderCounter, &midfieldCounter, &strikerCounter);
					averageAFCPlayers = calculateAverage(counterAFC, totalLoadedPlayers);
					averageCAFPlayers = calculateAverage(counterCAF, totalLoadedPlayers);
					averageCONCACAFPlayers = calculateAverage(counterCONCACAF, totalLoadedPlayers);
					averageCONMEBOLPlayers = calculateAverage(counterCONMEBOL, totalLoadedPlayers);
					averageUEFAPlayers = calculateAverage(counterUEFA, totalLoadedPlayers);
					averageOFCPlayers = calculateAverage(counterOFC, totalLoadedPlayers);
					calculateMaintenance (&maintenanceCost, lodgingCost, foodCost, transportCost);
					flagIncrease = calculateMaintenanceIncrease(totalLoadedPlayers, counterUEFA, maintenanceCost, &maintenanceCostIncrease, &increasedMaintenanceCost);
					printf("\nLos calculos se realizaron correctamente\n");
					flagCase3 = 0;
				}else {
					printf("\nEs necesario cargar datos en las opciones 1 y 2\n");
				}
			break;
			case 4: //Informar todos los resultados.
				if (flagCase1 == 0 && flagCase2 == 0 && flagCase3 == 0) {
					printf("total %d cAFC %d cCAF%d cCAOCACAF %d cUEFA %d", totalLoadedPlayers, counterAFC, counterCAF, counterCONCACAF, counterUEFA);
					printf("Informar todos los resultados\nPromedio UEFA: %.2f\nPromedio CONMEBOL: %.2f\nPromedio CONCACAF: %.2f\nPromedio AFC: %.2f\nPromedio OFC: %.2f\nPromedio CAF: %.2f\n",
							averageUEFAPlayers, averageCONMEBOLPlayers,averageCONCACAFPlayers, averageAFCPlayers, averageOFCPlayers, averageCAFPlayers);
					if(flagIncrease == 0){
						printf("\nEl costo de mantenimiento era de %d y recibió un aumento de %.2f, su nuevo valor es de %.2f\n", maintenanceCost, maintenanceCostIncrease, increasedMaintenanceCost);
					}else{
						printf("\nEl costo de mantenimiento es de %d\n", maintenanceCost);
					}
				} else {
					printf("Es necesario cargar datos en las opciones 1, 2 y 3\n");
				}
			break;
			case 5: //Salir.
			break;
			default:
				printf("Programa terminado.");
		}
	} while (confirmNavigation() == 1);
	return EXIT_SUCCESS;
}
