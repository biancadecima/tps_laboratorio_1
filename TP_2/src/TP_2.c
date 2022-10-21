#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "player.h"
#include "confederations.h"

#define LEN_PL 3000
#define LEN_CF 6
/*
 *
 *
 *
 *
 *
 *
 * Validar return de las funciones utn
 *
 *
 *
 *
 *
 *
 *
 *
 * */

int main(void) {
	setbuf(stdout,NULL);
	int flagCase1 = 0;

	sPlayer players[LEN_PL];
	sConfederation confederations[LEN_CF];

	initPlayers(players, LEN_PL);
	hardcodeConfederations(confederations);
	do {
		switch (showMenu()) {
		case 1: //alta
			if(addPlayer(players, LEN_PL, confederations, LEN_CF)){
				printf("Alta exitosa.\n");
				flagCase1 = 1;
			}else{
				printf("No se pudo realizar el alta de jugador.\n");
			}
			//confirmNavigation();
			break;
		case 2: //baja
			if(flagCase1 && deletePlayer(players, LEN_PL, confederations, LEN_CF)){
				printf("Baja exitosa.\n");
			}else{
				printf("No se puede realizar sin antes cargar jugadores");
			}
			break;
		case 3: //modificacion
			if (flagCase1 && modifyProducto(players, LEN_PL, confederations, LEN_CF)) {
				printf("Modificación exitosa.\n");
			} else {
				printf("No se puede realizar sin antes cargar jugadores");
			}
			break;
		case 4: // informes
			if (flagCase1) {
				      /*"3. Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.\n"
						"4. Informar la confederación con mayor cantidad de años de contratos total.\n"
						"5. Informar porcentaje de jugadores por cada confederación.\n"
						"6. Informar cual es la región con más jugadores y el listado de los mismos.\n"*/
				switch (showReportsMenu()) {
				case 1:
					sortByConfederationNameAndPlayerName(players, LEN_PL, confederations, LEN_CF);
					break;
				case 2:
					showConfederationsPlayers(players, LEN_PL, confederations, LEN_CF);
					break;
				case 3:

					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				}
			} else {
				printf("No se puede realizar sin antes cargar jugadores");
			}
			break;
		case 5: //salir
			//confirmNavigation();
			break;
		}
	} while (confirmNavigation() == 1);

	return EXIT_SUCCESS;
}
