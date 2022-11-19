#include "Jugador.h"
#include "LinkedList.h"
#include "parser.h"
#include "input.h"
#include "output.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int retorno. 0 error, 1 exitoso.
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_cargarJugadoresDesdeBinario(char *path, LinkedList *pArrayListJugador, LinkedList* pArrayListSeleccion);

/** \brief Alta de jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador);

/** \brief Modificar datos del jugador
 *
 * \param pArrayListJugador LinkedList*
* \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_editarJugador(LinkedList *pArrayListJugador);

/** \brief Baja del jugador
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
* \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_removerJugador(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion);

/** \brief Listar jugadores
 *
 * \param pArrayListJugador LinkedList*
* \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador);

/** \brief Listar jugadores con el nombre de su seleccion
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
* \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_listarJugadoresConSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/** \brief Listar jugadores convocados
 *
 * \param pArrayListJugador LinkedList*
* \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador);

/** \brief ordena jugadores por su id
 *
 * \param pArrayListJugador LinkedList*
* \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador);

/** \brief maneja opciones de ordenamiento de jugadores y selecciones
 * \param pArrayListSeleccion LinkedList *
 * \param pArrayListJugador LinkedList*
* \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_ordenarJugadoresSelecciones(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param pArrayListSeleccion LinkedList*
 * \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList *
 * \return  int retorno. 0 error, 1 exitoso.
 *
 */
int controller_guardarJugadoresModoBinario(char *path, LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion);// aca le agregue el array seleccion

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return  int retorno. 0 error, 1 exitoso.
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

/** \brief Modificar datos de seleccion
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion,LinkedList *pArrayListJugador);

/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return  int retorno. 0 error, 1 exitoso.
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

/** \brief Ordenar selecciones por id
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return  int retorno. 0 error, 1 exitoso.
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

/** \brief convoca un jugador a una seleccion
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_convocarJugadores(LinkedList* pArrayListJugador,  LinkedList* pArrayListSeleccion);

/** \brief da de baja un jugador de la seleccion a la que esta convocado
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_quitarJugadorDeSeleccion(LinkedList* pArrayListJugador,  LinkedList* pArrayListSeleccion);

/** \brief elimina las linkedlist
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_eliminarListas(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion);
