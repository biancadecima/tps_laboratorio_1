#include "LinkedList.h"
#include "Seleccion.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

/** \brief Pide memoria dinamica e inicializa los datos
 *
 * \return Jugador*
 */
Jugador* jug_new();

/** \brief pide memoria dinamica y carga a un jugador con datos
 *
 * \param idStr char*
 * \param nombreCompletoStr char*
 * \param edadStr char*
 * \param posicionStr char*
 * \param nacionalidadStr char*
 * \param idSelccionStr char*
 * \return Jugador*
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

/** \brief asigna un nuevo id a un jugador
 *
 * \return int id
 */
int jug_asignarID();

/** \brief abre el archivo en modo escritura y escribe el id que le paso por parametro
 * \param int id
 */
void jug_actualizarID(int id);

/** \brief carga el pais a un jugador dependiendo su seleccion
 *
 * \param Jugador* pJugador
 * \param LinkedList* pArrayListSeleccion
 * \param char paisJugador[]
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_cargarPaisSeleccion(Jugador* pJugador,  LinkedList* pArrayListSeleccion, char paisJugador[]);

/** \brief muentra un jugador
 *
 * \param Jugador* this
 * \param LinkedList* pArrayListSeleccion
 */
void jug_MostrarJugador(Jugador* this);

/** \brief muentra un jugador con el nombre de su seleccion
 *
 * \param Jugador* this
 * \param LinkedList* pArrayListSeleccion
 */
void jug_MostrarJugadorConSeleccion(Jugador* this, LinkedList* pArrayListSeleccion);

/** \brief busca un jugador por su id
 *
 * \param LinkedList *pArrayListJugador
 * \param int idBuscado
 * \return int indice donde se encuentra jugador buscado
 */
int jug_BuscarPorID(LinkedList* pArrayListJugador, int idBuscado);

/** \brief compara dos jugadores por id
 *
 * \param void *j1
 * \param void *j2
 * \return int compara, 0 si no se pudo comparar, 1 si se compara ascendente, -1 si decreciente
 */
int jug_CompareById(void *j1, void *j2);

/** \brief compara dos jugadores por nacionalidad
 *
 * \param void *j1
 * \param void *j2
 * \return int compara, 0 si no se pudo comparar, 1 si se compara ascendente, -1 si decreciente
 */
int jug_CompareByNationality(void* j1, void* j2);

/** \brief compara dos jugadores por edad
 *
 * \param void *j1
 * \param void *j2
 * \return int compara, 0 si no se pudo comparar, 1 si se compara ascendente, -1 si decreciente
 */
int jug_CompareByAge(void* j1, void* j2);

/** \brief compara dos jugadores por nombre
 *
 * \param void *j1
 * \param void *j2
 * \return int compara, 0 si no se pudo comparar, 1 si se compara ascendente, -1 si decreciente
 */
int jug_CompareByName(void* j1, void* j2);

/** \brief elimina un jugador
 *
 * \param Jugador* this
 */
void jug_delete(Jugador* this);

/** \brief carga el id a u jugador
 *
 * \param Jugador* this
 * \param int id
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_setId(Jugador* this,int id);

/** \brief consigue el id de un jugador
 *
 * \param Jugador* this
 * \param int* id
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_getId(Jugador* this,int* id);

/** \brief carga el nombre a un jugador
 *
 * \param Jugador* this
 * \param char* nombreCompleto
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);

/** \brief consigue el nombre de un jugador
 *
 * \param Jugador* this
 * \param char* nombreCompleto
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

/** \brief carga posicion a un jugador
 *
 * \param Jugador* this
 * \param char* posicion
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_setPosicion(Jugador* this,char* posicion);

/** \brief consigue posicion de un jugador
 *
 * \param Jugador* this
 * \param char* posicion
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_getPosicion(Jugador* this,char* posicion);

/** \brief carga nacionalidad a un jugador
 *
 * \param Jugador* this
 * \param char* nacionalidad
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad);

/** \brief consigue nacionalidad de un jugador
 *
 * \param Jugador* this
 * \param char* nacionalidad
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

/** \brief carga edad a u jugador
 *
 * \param Jugador* this
 * \param int edad
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_setEdad(Jugador* this,int edad);

/** \brief consigue edad de un jugador
 *
 * \param Jugador* this
 * \param int* edad
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_getEdad(Jugador* this,int* edad);

/** \brief carga el idSeleccion a u jugador
 *
 * \param Jugador* this
 * \param int idSeleccion
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion);

/** \brief consigue el idSeleccion de un jugador
 *
 * \param Jugador* this
 * \param int* idSeleccion
 * \return  int retorno. 0 error, 1 exitoso.
 */
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

#endif // jug_H_INCLUDED
