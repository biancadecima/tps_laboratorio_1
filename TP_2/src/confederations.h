#ifndef CONFEDERATIONS_H_
#define CONFEDERATIONS_H_
#include "input.h"

#define FREE 0
#define OCCUPIED 1

typedef struct {
	int id;
	char name[50];
	char region[50];
	int creationYear;
	int isEmpty;
} sConfederation;

/**
* \brief loads data of all the confederations
*/
void hardcodeConfederations(sConfederation confederations[]);

/**
* \brief shows the data of a confederation
 \param confederation receive confederation
*/
void showConfederation(sConfederation confederations);

/**
* \brief shows the data of all confederations
 \param confederations[] receive the array of confederations
* \param len_cf get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int listConfederations(sConfederation confederations[], int len_cf);

/**
* \brief gives the name of the confederation by entering the corresponding id
 \param confederations[] receive the array of confederations
* \param len get the length of the array of confederations
* \param idConfederation get the confederations id
* \param name[] get the confederations name
* \return In case of success it returns 1, otherwise zero
*/
int loadConfederationsName(sConfederation confederations[], int len, int idConfederation, char name[]);

/**
* \brief gives the region of the confederation by entering the corresponding id
 \param confederations[] receive the array of confederations
* \param len get the length of the array of confederations
* \param idConfederation get the confederations id
* \param region[] get the confederations region
* \return In case of success it returns 1, otherwise zero
*/
int loadConfederationsRegion(sConfederation confederations[], int len, int idConfederation, char region[]);

/**
* \brief initialize the player array to zero
 \param confederations[] receive the array of confederations
* \param len get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int initConfederations(sConfederation confederations[], int len);

/**
* \brief ask for a confederations data
* \return the confederations struct
*/
sConfederation loadConfederation();

/**
* \brief find an empty space in the array
 \param confederations[] receive the array of confederations
* \param len get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int findIsEmptyConfederation(sConfederation confederations[], int len);

/**
* \brief load the confederations data in an empty space of the array
* \param confederations[] receive the array of confederations
* \param len get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int addConfederation(sConfederation confederations[], int len);

/**
* \brief search for a confederation by his id
 \param confederations[] receive the array of confederations
* \param len get the length of the array of confederations
* \param id id of the confederation
* \return In case of success it returns -1, otherwise index number of the confederation
*/
int findByIDConfederation(sConfederation confederations[], int len, int id);

/**
* \brief remove a confederation from the array by changing its isEmpty value to 0
 \param confederations[] receive the array of players
* \param len get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int deleteConfederation(sConfederation confederations[], int len);

/**
* \brief modify a confederation by its id
 \param confederations[] receive the array of confederations
* \param len get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int modifyConfederation(sConfederation confederations[], int len);

#endif /* CONFEDERATIONS_H_ */
