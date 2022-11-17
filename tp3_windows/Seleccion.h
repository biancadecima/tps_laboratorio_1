#include "LinkedList.h"
//#include "Jugador.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

/** \brief Pide memoria dinamica e inicializa los datos
 *
 * \return Seleccion*
 */
Seleccion* selec_new();

/** \brief pide memoria dinamica y carga a un jugador con datos
 *
 * \param idStr char*
 * \param paisStr char*
 * \param confederacionStr char*
 * \param convocadosStr char*
 * \return Seleccion*
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);

/** \brief muestra una seleccion
 *
 * \param Seleccion* this
 */
void selec_MostrarSeleccion(Seleccion* this);

/** \brief busca una seleccion por su id
 *
 * \param LinkedList *pArrayListSeleccion
 * \param int idBuscado
 * \return int indice donde se encuentra la seleccion buscada
 */
int selec_BuscarPorID(LinkedList *pArrayListSeleccion, int idBuscado);

/** \brief compara dos selecciones por id
 *
 * \param void *s1
 * \param void *s2
 * \return int compara, 0 si no se pudo comparar, 1 si se compara ascendente, -1 si decreciente
 */
int selec_CompareById(void *s1, void *s2);

/** \brief compara dos selecciones por confederacion
 *
 * \param void *s1
 * \param void *s2
 * \return int compara, 0 si no se pudo comparar, 1 si se compara ascendente, -1 si decreciente
 */
int selec_CompareByConfederation(void *s1, void *s2);

/** \brief decrementa 1 en los convocados de una seleccion
 *
 * \param LinkedList* pArrayListSeleccion
 * \param int idSeleccion
 * \return  int retorno. 0 error, 1 exitoso.
 */
int selec_decrementarConvocados(LinkedList* pArrayListSeleccion, int idSeleccion);

/** \brief incrementa 1 en los convocados de una seleccion
 *
 * \param LinkedList* pArrayListSeleccion
 * \param int idSeleccion
 * \return  int retorno. 0 error, 1 exitoso.
 */
int selec_incrementarConvocados(LinkedList* pArrayListSeleccion, int idSeleccion);

/** \brief elimina una seleccion
 *
 * \param Seleccion *this
 */
void selec_delete(Seleccion *this);

/** \brief consigue el id de una seleccion
 *
 * \param Seleccion* this
 * \param int* id
 * \return  int retorno. 0 error, 1 exitoso.
 */
int selec_getId(Seleccion* this,int* id);

/** \brief consigue el pais de una seleccion
 *
 * \param Seleccion* this
 * \param char* pais
 * \return  int retorno. 0 error, 1 exitoso.
 */
int selec_getPais(Seleccion* this,char* pais);

/** \brief consigue el confederacion de una seleccion
 *
 * \param Seleccion* this
 * \param char* confederacion
 * \return  int retorno. 0 error, 1 exitoso.
 */
int selec_getConfederacion(Seleccion* this,char* confederacion);

/** \brief carga el numero de convocados de una seleccion
 *
 * \param Seleccion* this
 * \param int convocados
 * \return  int retorno. 0 error, 1 exitoso.
 */
int selec_setConvocados(Seleccion* this,int convocados);

/** \brief consigue el numero de convocados de una seleccion
 *
 * \param Seleccion* this
 * \param int convocados
 * \return  int retorno. 0 error, 1 exitoso.
 */
int selec_getConvocados(Seleccion* this,int* convocados);

#endif // selec_H_INCLUDED
