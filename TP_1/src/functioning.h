#ifndef FUNCTIONING_H_
#define FUNCTIONING_H_

/**
* \brief Request a number from the user, after verifying it returns the result
* \param pResultado Pointer to the memory space where the result of the function will be left
* \param mensaje the message to be displayed
* \param mensajeError the message to be displayed
* \param minimo It is the maximum number to be accepted
* \param maximo It is the minimum minimum to be accepted
* \return 1 if he want to continue uploading data, 2 if not
*/
int getNumber(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

/**
* \brief Shows menu's printf
* \param lodgingCost shows the value of the hosting cost
* \param foodCost shows the value of the cost of food
* \param transportCost shows the value of the transportation cost
* \param goalkeeperCounter shows the value of the goalkeeper counter
* \param defenderCounter shows the value of the defender counter
* \param midfieldCounter shows the value of the midfield counter
* \param strikerCounter shows the value of the striker counter
*/
void showMenu(int* lodgingCost, int* foodCost, int* transportCost, int* goalkeeperCounter, int* defenderCounter, int* midfieldCounter, int* strikerCounter);

/**
* \brief asks the user if he wants to continue loading data
* \return 1 if he want to continue uploading data, 2 if not
*/
int confirmNavigation();

/**
* \brief loads the costs of transportation, food and lodging
* \param option saves the cost option number that is entered
* \param lodgingCost saves the cost of lodging
* \param foodCost saves the cost of food
* \param transportCost saves the cost of transportation
* \return 0 if it worked fine, -1 if not
*/
int loadMaintenanceCosts(int option, int *lodgingCost, int *foodCost, int *transportCost);

/**
* \brief loads a player
* \param playerCounter saves the number of players that were loaded
* \param shirtNumber saves the player's shirt number
* \param confederation saves the player's confederation number
* \return 0 if it worked fine, -1 if not
*/
int loadPlayer(int *playerCounter, int* shirtNumber, int* confederation);

/**
* \brief loads the confederation counters for each player
* \param confederation load the confederation number to which the player belongs
* \param counterAFC count the players that belong to AFC confederation
* \param counterCAF count the players that belong to CAF confederation
* \param counterCONCACAF count the players that belong to CONCACAF confederation
* \param counterCONMEBOL count the players that belong to CONMEBOL confederation
* \param counterUEFA count the players that belong to UEFA confederation
* \param counterOFC count the players that belong to OFC confederation
*/
void confederationCounter(int *confederation, int *counterAFC, int *counterCAF, int *counterCONCACAF, int *counterCONMEBOL, int *counterUEFA, int *counterOFC);

		#endif /* FUNCTIONING_H_ */
