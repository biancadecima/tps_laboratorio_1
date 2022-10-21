#ifndef PLAYER_H_
#define PLAYER_H_

#include "confederations.h"

#define FREE 0
#define OCCUPIED 1

typedef struct {
	int id;
	char name[50];
	char position[50];
	short shirtNumber;
	int idConfederation;
	float salary;
	short contractYears;
	short isEmpty;
} sPlayer;

int showMenu();

int confirmNavigation();

int initPlayers(sPlayer players[], int len);

sPlayer loadPlayer(sConfederation confederations[], int len_cf);

int addPlayer(sPlayer players[], int len_pl, sConfederation confederations[],int len_cf);

int sortByID(sPlayer players[], int len);

int deletePlayer(sPlayer players[], int len, sConfederation confederations[],int len_cf) ;

void showPlayer(sPlayer player, sConfederation confederations[], int len_cf);

int listPlayers(sPlayer players[], int len, sConfederation confederations[], int len_cf);

int findIsEmpty(sPlayer players[], int len);

int findByID(sPlayer players[], int len, int id);

int modifyProducto(sPlayer players[], int len, sConfederation confederations[],int len_cf);

int showReportsMenu();

int showPlayersOfAConfederation(sPlayer players[], int len, sConfederation confederations[], int len_cf, int idConfederation);

int showConfederationsPlayers(sPlayer players[], int len, sConfederation confederations[], int len_cf);

int sortByConfederationNameAndPlayerName(sPlayer players[], int len, sConfederation confederations[], int len_cf);

#endif /* PLAYER_H_ */
