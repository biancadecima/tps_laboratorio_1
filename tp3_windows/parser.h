#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

#ifndef PARSER_H_
#define PARSER_H_


/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int retorno. 0 error, 1 exitoso.
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return  int retorno. 0 error, 1 exitoso.
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int retorno. 0 error, 1 exitoso.
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);

#endif /* PARSER_H_ */
