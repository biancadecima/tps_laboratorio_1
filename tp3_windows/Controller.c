#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno;
	FILE* pArchivo;
	int rtnParserJug;
	if(path != NULL && pArrayListJugador != NULL){
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL){
			rtnParserJug = parser_JugadorFromText(pArchivo, pArrayListJugador);
			if(rtnParserJug == 1){
				retorno = 1;
		}else{
			retorno = 0;
		}
		fclose(pArchivo);
	}
	}

    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char *path, LinkedList *pArrayListJugador) {
	int retorno = 0;
	FILE *pArchivo;

	if (path != NULL && pArrayListJugador != NULL) {
		pArchivo = fopen(path, "rb");
		if (pArchivo != NULL) {
			if (parser_JugadorFromBinary(pArchivo, pArrayListJugador)) {
				printf("\nSe leyó el archivo correctamente\n");
				retorno = 1;
			}
			fclose(pArchivo);
		}
	}

	return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador){
	int retorno = 0;
	///
	//int id;
	char nombre[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];

	Jugador* pJugador = NULL;

	pJugador = jug_new();
	if(getName("\nIngrese nombre del jugador: \n", "Nombre inválido. ", 4, 100, 3, nombre)
		&& getNumber(&edad, "\nIngrese edad del jugador: \n", "Edad Inválida. ", 18, 40, 3)
		&& getPosicion("\nIngrese posicion del jugador: \n", "Posicion inválida. ", 3, posicion)
		&& getString("\nIngrese nacionalidad del jugador: \n", "Nacionalidad inválida. ", 7, 20, 3, nacionalidad))
	{
		//id = jug_newID;
		if(jug_setNombreCompleto(pJugador,nombre)
			&& jug_setEdad(pJugador,edad)
			&& jug_setPosicion(pJugador,posicion)
			&& jug_setNacionalidad(pJugador,nacionalidad)
			&& jug_setIdSeleccion(pJugador,0))
		{
			ll_add(pArrayListJugador, pJugador);
			// jug_updateID(id);
			retorno = 1;
		}
	}

    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList *pArrayListJugador) {
	int retorno;
	int flag = 0;
	int largoList;
	int idBuscado;
	int id;
	Jugador *pJugador = NULL;

	getNumber(&idBuscado, "\nIngrese el ID del jugador que desea eliminar: \n", "ID Inválido. ", 1, 1000, 3);
	largoList = ll_len(pArrayListJugador);

	for (int i = 0; i < largoList; i++) {
		pJugador = (Jugador*) ll_get(pArrayListJugador, i);
		if (pJugador != NULL) {
			jug_getId(pJugador, &id);
			if (id == idBuscado) {
				ll_remove(pArrayListJugador, i);
				flag = 1;
				retorno = 1;
			}
		}
	}
	if(flag == 0){
		printf("\nNo se encontro el id del jugador\n");
	}

	return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int largoList;
	Jugador* pJugador = NULL;
	// aux para el get
	int id;
	char nombre[100];
	char posicion[100];
	char nacionalidad[100];
	int edad;
	int idSeleccion;/// hay que imprimir el nombre de la descripcion

	largoList = ll_len(pArrayListJugador);

	printf("\n*** LISTA DE JUGADORES ***\n");
	for(int i=0; i<largoList; i++){
		pJugador = (Jugador*) ll_get(pArrayListJugador, i);
		if (pJugador != NULL && ll_isEmpty(pArrayListJugador) == 0) {
			jug_getId(pJugador, &id);
			jug_getNombreCompleto(pJugador, nombre);
			jug_getPosicion(pJugador, posicion);
			jug_getNacionalidad(pJugador, nacionalidad);
			jug_getEdad(pJugador, &edad);
			jug_getSIdSeleccion(pJugador, &idSeleccion);
			printf("| %3d | %-24s | %-20s | %-15s | %4d | %4d |\n", id, nombre, posicion, nacionalidad, edad, idSeleccion);
			retorno = 1;
		}
		/*funcion que mediante el idSeleccion, traiga el nombre de la seleccion*/
		retorno = 1;
	}

    return retorno;
}

controller_listarJugadoresConvocados(LinkedList* pArrayListJugador){
	int retorno = 0;
	int largoList;
	Jugador* pJugador = NULL;
	// aux para el get
	int id;
	char nombre[100];
	char posicion[100];
	char nacionalidad[100];
	int edad;
	int idSeleccion;/// hay que imprimir el nombre de la descripcion

	largoList = ll_len(pArrayListJugador);

	printf("\n*** LISTA DE JUGADORES ***\n");
	for(int i=0; i<largoList; i++){
		pJugador = (Jugador*) ll_get(pArrayListJugador, i);
		if (pJugador != NULL && ll_isEmpty(pArrayListJugador) == 0) {
			jug_getId(pJugador, &id);
			jug_getNombreCompleto(pJugador, nombre);
			jug_getPosicion(pJugador, posicion);
			jug_getNacionalidad(pJugador, nacionalidad);
			jug_getEdad(pJugador, &edad);
			jug_getSIdSeleccion(pJugador, &idSeleccion);
			if(idSeleccion != 0){
				printf("| %3d | %-24s | %-20s | %-15s | %4d | %4d |\n", id, nombre, posicion, nacionalidad, edad, idSeleccion);
				retorno = 1;
			}
		}
		/*funcion que mediante el idSeleccion, traiga el nombre de la seleccion*/
	}

    return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char *path, LinkedList *pArrayListSeleccion) {
	int retorno;
	FILE *pArchivo;
	int rtnParserSelec;

	if (path != NULL && pArrayListSeleccion != NULL) {
		pArchivo = fopen(path, "r");
		if (pArchivo != NULL) {
			rtnParserSelec = parser_SeleccionFromText(pArchivo ,pArrayListSeleccion);
			if (rtnParserSelec == 1) {
				retorno = 1;
			}else{
				retorno = 0;
			}
			fclose(pArchivo);
		}
	}

	return retorno;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList *pArrayListSeleccion) {
	int retorno = 0;
	int largoList;
	Seleccion *pSeleccion = NULL;
	// aux para el get
	int id;
	char pais[100];
	char confederacion[100];
	int convocados;

	largoList = ll_len(pArrayListSeleccion);

	printf("\n*** LISTA DE SELECCIONES ***\n");
	for (int i = 0; i < largoList; i++) {
		pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
		if (pSeleccion != NULL && ll_isEmpty(pArrayListSeleccion) == 0) {
			if (selec_getId(pSeleccion, &id) && selec_getPais(pSeleccion, pais)
					&& selec_getConfederacion(pSeleccion, confederacion)
					&& selec_getConvocados(pSeleccion, &convocados)) {
				printf("| %3d | %-15s | %-10s | %3d |\n", id, pais,
						confederacion, convocados);
				retorno = 1;
			}
		}
	}
	return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}


