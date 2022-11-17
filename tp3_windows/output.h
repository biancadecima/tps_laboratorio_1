#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "input.h"

/** \brief muestra el menu principal y pide una opcion
 *
 * \return  int opcion elegida
 */
int manejarMenuPrincipal();

/** \brief muestra el menu de listados y pide una opcion
 *
 * \return  int opcion elegida
 */
int manejarMenuListados();

/** \brief muestra el menu de convocados y pide una opcion
 *
 * \return  int opcion elegida
 */
int manejarMenuConvocados();

/** \brief muestra las nacionalidades
 *
 */
void mostrarNacionalidades();

/** \brief muestra las posiciones
 *
 */
void mostrarPosiciones();

/** \brief muestra las confederaciones
 *
 */
void mostrarConfederaciones();

/** \brief muestra el menu de salida y pide una opcion
 *
 * \return  int opcion elegida
 */
int manejoSalida();

#endif /* OUTPUT_H_ */
