#ifndef INPUT_H_
#define INPUT_H_
#include "output.h"

/** \brief pide una cadena de caracteres
 *
 * \param char* msg
 * \param  char* msgError
 * \param  int max
 * \param  int min
 * \param  int* reintentos
 * \param  char* resultado
 * \return  int retorno. 0 exitoso, -1 error.
 */
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);

/** \brief pide un nombre
 *
 * \param char* msg
 * \param  char* msgError
 * \param  int max
 * \param  int min
 * \param  int reintentos
 * \param  char* resultado
 * \return  int retorno. 0 exitoso, -1 error.
 */
int getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);

/** \brief valida que el string recibido sea un nombre valido
 *
 * \param char* stringRecibido
 * \return  int retorno. 1 exitoso, 0 error.
 */
int isValidName(char* stringRecibido);

/** \brief pide un numero
 *
 * \param char* mensaje
 * \param  char* mensajeError
 * \param  int maximo
 * \param  int minimo
 * \param  int reintentos
 * \param  char* resultado
 * \return int retorno. 1 exitoso, 0 error.
 */
int getNumber(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);

/** \brief pide una nacionalidad
 *
 * \param char nacionalidad[]
 * \return  int retorno. 1 exitoso, 0 error.
 */
int getNacionalidad(char nacionalidad[]);

/** \brief pide una posicion
 *
 * \param char posicion[]
 * \return  int retorno. 1 exitoso, 0 error.
 */
int getPosicion(char posicion[]);

/** \brief pide una confederacion
 *
 * \param char confederacion[]
 * \return  int retorno. 1 exitoso, 0 error.
 */
int getConfederacion(char confederacion[]);

#endif /* INPUT_H_ */
