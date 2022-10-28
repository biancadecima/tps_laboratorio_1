#ifndef REPORTS_H_
#define REPORTS_H_
#include "player.h"
#include "confederations.h"
#include "calculations.h"

/**
* \brief Shows the report menu and asks the user to enter an option
* \return option Returns the reports menu option chosen by the user
*/
int showReportsMenu();

/**
* \brief sort the array of players by confederation name and by player name
* \param players[] receive the array of players
* \param len get the length of the array of players
* \param confederations[] receive the array of confederations
* \param len_cf get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int sortByConfederationNameAndPlayerName(sPlayer players[], int len, sConfederation confederations[], int len_cf);

/**
* \brief shows the players of a confederation which is indicated by its id
* \param players[] receive the array of players
* \param len get the length of the array of players
* \param confederations[] receive the array of confederations
* \param len_cf get the length of the array of confederations
* \param idConfederation get id of the confederation
* \return In case of success it returns 1, otherwise zero
*/
int showPlayersOfAConfederation(sPlayer players[], int len, sConfederation confederations[], int len_cf, int idConfederation);

/**
* \brief show the players by confederation
 \param players[] receive the array of players
* \param len get the length of the array of players
* \param confederations[] receive the array of confederations
* \param len_cf get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int showConfederationsPlayers(sPlayer players[], int len, sConfederation confederations[], int len_cf);

/**
* \brief calculates the total of the players' salaries
 \param players[] receive the array of players
* \param len get the length of the array of players
* \param total* receive the total of players' salaries
* \return In case of success it returns 1, otherwise zero
*/
int calculateTotalPlayersSalaries(sPlayer players[], int len, float* total);

/**
* \brief calculates the total of  players
 \param players[] receive the array of players
* \param len get the length of the array of players
* \param total* receive the total of players
* \return In case of success it returns 1, otherwise zero
*/
int calculateTotalPlayers(sPlayer players[], int len, int* total);

/**
* \brief calculates the average of players' salaries
 \param players[] receive the array of players
* \param len get the length of the array of players
* \param averageSalary* receive the average of players' salaries
* \return In case of success it returns 1, otherwise zero
*/
int calculateSalariesAverage(sPlayer players[], int len, float* averageSalary);

/**
* \brief counts the number of players' salaries that are Above Average
 \param players[] receive the array of players
* \param len get the length of the array of players
* \param counter* receive the number of players' salaries that are Above Average
* \return In case of success it returns 1, otherwise zero
*/
int countSalariesAboveAverage(sPlayer players[], int len, int* counter);

/**
* \brief counts the number of players' contarct years per confederation
 \param players[] receive the array of players
* \param len get the length of the array of players
* \param contractYearsAFC gets the number of contract years of afc players
* \param contractYearsCAF gets the number of contract years of caf players
 \param contractYearsCONCACAF gets the number of contract years of concacaf players
* \param contractYearsCONMEBOL gets the number of contract years of conmebol players
* \param contractYearsOFC gets the number of contract years of ofc players
* \param contractYearsUEFA gets the number of contract years of uefa players
* \return In case of success it returns 1, otherwise zero
*/
int calculateConfederationsTotalContractYears(sPlayer players[], int len, int* contractYearsAFC, int* contractYearsCAF, int* contractYearsCONCACAF, int* contractYearsCONMEBOL, int* contractYearsOFC, int* contractYearsUEFA);

/**
* \brief calculates the confederation whose players have more contract years
 \param players[] receive the array of players
* \param len get the length of the array of players
* \return In case of success it returns 1, otherwise zero
*/
int getConfederationWithMoreContractYears(sPlayer players[], int len);

/**
* \brief counts the number of players for confederation
 \param players[] receive the array of players
 * \param len get the length of the array of players
* \param playersAFC gets the number of afc players
* \param playersCAF gets the number of caf players
 \param playersCONCACAF gets the number of concacaf players
* \param playersCONMEBOL gets the number of conmebol players
* \param playersOFC gets the number of ofc players
* \param playersUEFA gets the number of uefa players
* \return In case of success it returns 1, otherwise zero
*/
int calculatePlayersPerConfederation(sPlayer players[], int len, int* playersAFC, int* playersCAF, int* playersCONCACAF, int* playersCONMEBOL, int* playersOFC, int* playersUEFA);

/**
* \brief calculates the Percentage of Players Per Confederation
 \param players[] receive the array of players
* \param percentagePlayersAFC gets the percentage of afc players
* \param percentagePlayersCAF gets the percentage of caf players
 \param percentagePlayersCONCACAF gets the percentage of concacaf players
* \param percentagePlayersCONMEBOL gets the percentage of conmebol players
* \param percentagePlayersOFC gets the percentage of ofc players
* \param percentagePlayersUEFA gets the percentage of uefa players
* \return In case of success it returns 1, otherwise zero
*/
int calculatePercentagePlayersPerConfederation (sPlayer players[], int len, float* percentagePlayersAFC, float* percentagePlayersCAF, float* percentagePlayersCONCACAF, float* percentagePlayersCONMEBOL, float* percentagePlayersOFC, float* percentagePlayersUEFA);
/**
* \brief Calculates the confederation with the most players
 \param players[] receive the array of players
* \param len get the length of the array of players
* \param confederations[] receive the array of confederations
* \param len_cf get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int getMostPlayersConfederation(sPlayer players[], int len, sConfederation confederations[], int len_cf);

/**
* \brief contains the report menu and its functions
 \param players[] receive the array of players
* \param len get the length of the array of players
* \param confederations[] receive the array of confederations
* \param len_cf get the length of the array of confederations
* \return In case of success it returns 1, otherwise zero
*/
int reportManagement(sPlayer players[], int len, sConfederation confederations[], int len_cf);

#endif /* REPORTS_H_ */
