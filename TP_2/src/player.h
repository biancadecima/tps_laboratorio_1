#ifndef PLAYER_H_
#define PLAYER_H_
#include "input.h"
#include "confederations.h"
#include "calculations.h"

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

/**
* \brief Shows the  menu and asks the user to enter an option
* \return option Returns the  menu option chosen by the user
*/
int showMenu();

/**
* \brief Ask the user if he wants to exit the program
* \return 1 if want to leave and 2 if not
*/
int confirmExit();

/**
* \brief initialize the player array to zero
 \param players[] receive the array of players
* \param len get the length of the array of players
* \return In case of success it returns 1, otherwise zero
*/
int initPlayers(sPlayer players[], int len);

/**
* \brief find out the status of the player array
 \param players[] receive the array of players
* \param len get the length of the array of players
* \return 0 if empty, 1 there is at least one player, -1 full;
*/
int arrayState(sPlayer players[], int len);

/**
* \brief ask for a player's data
 \param players[] receive the array of players
* \param len get the length of the array of players
* \param confederations[] receive the array of confederations
* \param len_cf get the length of the array of confederations
* \return the player struct
*/
sPlayer loadPlayer(sConfederation confederations[], int len_cf);

/**
* \brief load the player data in an empty space of the array
 \param players[] receive the array of players
* \param len get the length of the array of players
* \param confederations[] receive the array of confederations
* \param len_cf get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int addPlayer(sPlayer players[], int len_pl, sConfederation confederations[],int len_cf);

/**
* \brief sort the array of players by its id
 \param players[] receive the array of players
* \param len get the length of the array of players
* \return In case of success it returns 1, otherwise zero
*/
int sortByID(sPlayer players[], int len);

/**
* \brief remove a player from the array by changing its isEmpty value to 0
 \param players[] receive the array of players
* \param len get the length of the array of players
* \param confederations[] receive the array of confederations
* \param len_cf get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int deletePlayer(sPlayer players[], int len, sConfederation confederations[],int len_cf);

/**
* \brief shows the data of a player
 \param player receive player
* \param confederations[] receive the array of confederations
* \param len_cf get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
void showPlayer(sPlayer player, sConfederation confederations[], int len_cf);

/**
* \brief shows the data of all players
 \param players[] receive the array of players
* \param len get the length of the array of players
* * \param confederations[] receive the array of confederations
* \param len_cf get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int listPlayers(sPlayer players[], int len, sConfederation confederations[], int len_cf);

/**
* \brief find an empty space in the array
 \param players[] receive the array of players
* \param len get the length of the array of playerss
* \return In case of success it returns 1, otherwise zero
*/
int findIsEmpty(sPlayer players[], int len);

/**
* \brief search for a player by his id
 \param players[] receive the array of players
* \param len get the length of the array of playerss
* \param id id of the player
* \return In case of success it returns -1, otherwise index number of the player
*/
int findByID(sPlayer players[], int len, int id);

/**
* \brief modify a player by its id
 \param players[] receive the array of players
* \param len get the length of the array of players
* * \param confederations[] receive the array of confederations
* \param len_cf get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int modifyPlayer(sPlayer players[], int len, sConfederation confederations[],int len_cf);

#endif /* PLAYER_H_ */
