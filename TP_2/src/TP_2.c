#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "player.h"
#include "confederations.h"
#include "calculations.h"
#include "reports.h"

#define LEN_PL 3000
#define LEN_CF 6

int main(void) {
	setbuf(stdout,NULL);
	int option;

	sPlayer players[LEN_PL];
	sConfederation confederations[LEN_CF];

	initPlayers(players, LEN_PL);
	hardcodeConfederations(confederations);

	do {
		option = showMenu();
		switch (option) {
		case 1:
			if(addPlayer(players, LEN_PL, confederations, LEN_CF) == 1){
				printf("\n **** Alta exitosa. **** \n");
			}else{
				printf("\nNo se pudo realizar el alta de jugador.\n");
			}
			break;
		case 2:
			if (!(arrayState(players, LEN_PL)==0) && sortByID(players, LEN_PL)
					&& listPlayers(players, LEN_PL, confederations, LEN_CF)
					&& deletePlayer(players, LEN_PL, confederations, LEN_CF)) {
				printf("\n **** Baja exitosa. **** \n");
			} else {
				printf("\nNo se puede realizar la baja de jugadores\n");
			}
			break;
		case 3:
			if (!(arrayState(players, LEN_PL)==0) && sortByID(players, LEN_PL)
					&& listPlayers(players, LEN_PL, confederations, LEN_CF)
					&& modifyPlayer(players, LEN_PL, confederations, LEN_CF)) {
				printf("\n **** Modificación exitosa. ****\n");
			} else {
				printf("\nNo se puede realizar la modificacion de jugadores\n");
			}
			break;
		case 4:
			if(!(arrayState(players, LEN_PL)==0)){
				reportManagement(players, LEN_PL, confederations, LEN_CF);
			}else{
				printf("\nNo se pueden realizar los informes de jugadores\n");
			}
			break;
		case 5:
			if(confirmExit() == 1){
				option = 6;
			}
			break;
		}
	} while (option != 6);

	return EXIT_SUCCESS;
}
