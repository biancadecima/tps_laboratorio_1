#ifndef OPERATIONS_H_
#define OPERATIONS_H_

/**
* \brief calculates the total loaded players
* \param goalkeeperCounter count players in goalkeeping position
* \param defenderCounter count players in defender position
* \param midfieldCounter count players in midfield position
* \param strikerCounter count players in striker position
* \return totalLoadedPlayers the total loaded players
*/
int calculateTotalPlayers(int* goalkeeperCounter, int* defenderCounter, int* midfieldCounter, int* strikerCounter);

/**
* \brief calculates the average between a number and a total
* \param amount stores the number on which the average is calculated
* \param total stores the total on which the average is calculated
* \return average stores the average
*/
float calculateAverage(int amount, int total);

/**
* \brief calculates the total value of the maintenance cost by adding the costs of lodging, food and transportation
* \param maintenance save maintenance cost
* \param lodging save lodging cost
* \param food save food cost
* \param transport save transport cost
* \return 0 if it worked fine, -1 if not
*/
int calculateMaintenance (int* maintenance, int lodging, int food, int transport);

/**
* \brief calculate the increase of 0.35 of the cost of maintenance if the majority of the players are from UEFA
* \param totalLoadedPlayers saves the total number of loaded players
* \param counterUEFA saves the number of players that belong to UEFA confederation
* \param maintenanceCost save maintenance cost
* \param maintenanceCostIncrease saves the maintenance cost increase
* \param increasedMaintenanceCost saves maintenance cost increase added to maintenance cost
* \return 0 if it worked fine, -1 if not
*/
int calculateMaintenanceIncrease(int totalLoadedPlayers, int counterUEFA, int maintenanceCost, float* maintenanceCostIncrease, float* increasedMaintenanceCost);

#endif /* OPERATIONS_H_ */
