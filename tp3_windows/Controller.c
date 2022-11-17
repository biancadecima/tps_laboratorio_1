#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Controller.h"

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

int controller_cargarJugadoresDesdeBinario(char *path, LinkedList *pArrayListJugador, LinkedList* pArrayListSeleccion) {
	int retorno = 0;
	FILE *pArchivo;
	LinkedList * clon;

	if (pArrayListJugador != NULL) {
		clon = ll_clone(pArrayListJugador);
		ll_clear(clon);

		if (path != NULL && clon != NULL) {
			pArchivo = fopen(path, "rb");
			if (pArchivo != NULL) {
				if (parser_JugadorFromBinary(pArchivo, clon)) {
					controller_ordenarJugadoresSelecciones(clon, pArrayListSeleccion);
					retorno = 1;
				}
			}
			fclose(pArchivo);
		}
	}

	return retorno;
}

int controller_agregarJugador(LinkedList* pArrayListJugador){
	int retorno = 0;
	int id;
	char nombre[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];
	Jugador* pJugador = NULL;

	pJugador = jug_new();
	if(getName("\nIngrese nombre del jugador: \n", "Nombre inválido. ", 4, 100, 3, nombre) == 0
		&& getNumber(&edad, "\nIngrese edad del jugador: \n", "Edad Inválida. ", 18, 40, 3)
		&& getNacionalidad(nacionalidad)
		&& getPosicion(posicion))
	{
		id = jug_asignarID();
		if(jug_setId(pJugador, id)
			&& jug_setNombreCompleto(pJugador,nombre)
			&& jug_setEdad(pJugador,edad)
			&& jug_setPosicion(pJugador,posicion)
			&& jug_setNacionalidad(pJugador,nacionalidad)
			&& jug_setIdSeleccion(pJugador,0))
		{
			if(ll_add(pArrayListJugador, pJugador) == 0){
				jug_actualizarID(id);
				retorno = 1;
			}
		}
	}

    return retorno;
}

int controller_editarJugador(LinkedList *pArrayListJugador) {
	int retorno = 0;
	int idBuscado;
	int opcion;
	int indice;
	Jugador *pJugador = NULL;
	char nombre[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];

	if (pArrayListJugador != NULL) {
		if (getNumber(&idBuscado,"\nIngrese el ID del jugador que desea modificar: \n","ID inválido. ", 1, 1000, 3)) {
			indice = jug_BuscarPorID(pArrayListJugador, idBuscado);
			if (indice > 0) {
				pJugador = (Jugador*) ll_get(pArrayListJugador, indice);
				if (pJugador != NULL) {
					getNumber(&opcion,"\n1. Nombre\n2. Edad\n3. Posicion\n4. Nacionalidad\nIngrese opcion de modificación: \n","Opción inválida. ", 1, 4, 3);
					switch (opcion) {
					case 1:
						if (getName("\nIngrese nuevo nombre del jugador: \n","Nombre inválido. ", 4, 100, 3, nombre) == 0) {
							jug_setNombreCompleto(pJugador, nombre);
							retorno = 1;
						}
						break;
					case 2:
						if (getNumber(&edad,"\nIngrese nueva edad del jugador: \n","Edad Inválida. ", 18, 40, 3)) {
							jug_setEdad(pJugador, edad);
							retorno = 1;
						}
						break;
					case 3:
						if (getPosicion(posicion)) {
							jug_setPosicion(pJugador, posicion);
							retorno = 1;
						}
						break;
					case 4:
						if (getNacionalidad(nacionalidad)) {
							jug_setNacionalidad(pJugador, nacionalidad);
							retorno = 1;
						}
						break;
					}
				}
			}else{
				printf("\nNo se encontró el ID buscado\n");
			}
		}
	}

	return retorno;
}




int controller_removerJugador(LinkedList *pArrayListJugador,LinkedList *pArrayListSeleccion) {
	int retorno = 0;
	int indice;
	int idBuscado;
	int idSeleccionJugador;
	Jugador *pJugador = NULL;

	getNumber(&idBuscado, "\nIngrese el ID del jugador que desea eliminar: \n","ID Inválido. ", 1, 1000, 3);
	indice = jug_BuscarPorID(pArrayListJugador, idBuscado);
	if (indice > 0) {
		pJugador = (Jugador*) ll_get(pArrayListJugador, indice);
		if (pJugador != NULL) {
			jug_getSIdSeleccion(pJugador, &idSeleccionJugador);
			if (idSeleccionJugador != 0) {
				selec_BuscarPorID(pArrayListSeleccion, idSeleccionJugador);
				selec_decrementarConvocados(pArrayListSeleccion,idSeleccionJugador);
			}
			ll_remove(pArrayListJugador, indice);
			retorno = 1;
		}
	}

	return retorno;
}

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

	largoList = ll_len(pArrayListJugador);

	printf("\n*** LISTA DE JUGADORES ***\n");
	printf("===================================================================================\n");
	printf("|  ID |          NOMBRE          |       POSICION      | EDAD  |   NACIONALIDAD   |\n");
	printf("===================================================================================\n");
	for(int i=0; i<largoList; i++){
		pJugador = (Jugador*) ll_get(pArrayListJugador, i);
		if (pJugador != NULL && ll_isEmpty(pArrayListJugador) == 0) {
			jug_getId(pJugador, &id);
			jug_getNombreCompleto(pJugador, nombre);
			jug_getPosicion(pJugador, posicion);
			jug_getNacionalidad(pJugador, nacionalidad);
			jug_getEdad(pJugador, &edad);
			printf("| %3d | %-24s | %-20s | %4d | %-15s |\n", id, nombre, posicion, edad, nacionalidad);
			retorno = 1;
		}
		printf("===================================================================================\n");
	}

    return retorno;
}

int controller_listarJugadoresConSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int largoList;
	Jugador* pJugador = NULL;

	largoList = ll_len(pArrayListJugador);

	printf("\n*** LISTA DE JUGADORES ***\n");
	printf("\n*** LISTA DE JUGADORES CONVOCADOS ***\n");
	printf("==================================================================================================\n");
	printf("|  ID |          NOMBRE          |       POSICION       |  NACIONALIDAD   |  EDAD  |   SELECCION  |\n");
	printf("==================================================================================================\n");
	for(int i=0; i<largoList; i++){
		pJugador = (Jugador*) ll_get(pArrayListJugador, i);
		if (pJugador != NULL && ll_isEmpty(pArrayListJugador) == 0) {
			jug_MostrarJugadorConSeleccion(pJugador, pArrayListSeleccion);

			retorno = 1;
		}
		printf("==================================================================================================\n");
	}

    return retorno;
}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador){
	int retorno = 0;
	int largoList;
	Jugador* pJugador = NULL;
	// aux para el get
	int id;
	char nombre[100];
	char posicion[100];
	char nacionalidad[100];
	int edad;
	int idSeleccion;

	largoList = ll_len(pArrayListJugador);

	printf("\n*** LISTA DE JUGADORES CONVOCADOS ***\n");
	printf("===================================================================================\n");
	printf("|  ID |          NOMBRE          |       POSICION      | EDAD  |   NACIONALIDAD   |\n");
	printf("===================================================================================\n");
	for(int i=0; i<largoList; i++){
		pJugador = (Jugador*) ll_get(pArrayListJugador, i);
		if (pJugador != NULL) {
			jug_getSIdSeleccion(pJugador, &idSeleccion);
			if(idSeleccion > 0){
				jug_getId(pJugador, &id);
				jug_getNombreCompleto(pJugador, nombre);
				jug_getPosicion(pJugador, posicion);
				jug_getNacionalidad(pJugador, nacionalidad);
				jug_getEdad(pJugador, &edad);
				printf("| %3d | %-24s | %-20s | %4d | %-15s |\n", id, nombre, posicion, edad, nacionalidad);
				retorno = 1;
			}
		}
	}
	printf("===================================================================================\n");

    return retorno;
}

int controller_ordenarJugadores(LinkedList* pArrayListJugador){
	int retorno = 0;

	LinkedList* clone = NULL;
	clone = ll_clone(pArrayListJugador);

	if (pArrayListJugador != NULL && clone != NULL) {
		ll_sort(clone, jug_CompareById, 1);
		controller_listarJugadores(clone);
		retorno = 1;
	}

	return retorno;
}

int controller_ordenarJugadoresSelecciones(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno = 0;
	int opcion;
	LinkedList *cloneJugadores = NULL;
	LinkedList *cloneSelecciones = NULL;
	int orden;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		cloneJugadores = ll_clone(pArrayListJugador);
		cloneSelecciones = ll_clone(pArrayListSeleccion);
		if (cloneJugadores != NULL && cloneSelecciones != NULL) {
			getNumber(&opcion,"\n1. Jugadores por nacionalidad\n2. Jugadores por edad\n3. Selecciones por confederacion \n4. Jugadores por nombre\nIngrese opcion: ","Opcion Invalida. ", 1, 4, 3);
			switch (opcion) {
			case 1: //A) JUGADORES POR NACIONALIDAD.
				getNumber(&orden,"\n0. Orden descendente\n1. Orden ascendente\nIngrese opcion: ","Opcion Invalida. ", 0, 1, 3);
				ll_sort(cloneJugadores, jug_CompareByNationality, orden);
				controller_listarJugadores(cloneJugadores);
				retorno = 1;
				break;
			case 2: //C) JUGADORES POR EDAD.
				getNumber(&orden,"\n0. Orden descendente\n1. Orden ascendente\nIngrese opcion: ","Opcion Invalida. ", 0, 1, 3);
				ll_sort(cloneJugadores, jug_CompareByAge, orden);
				controller_listarJugadores(cloneJugadores);
				retorno = 1;
				break;
			case 3:
				getNumber(&orden,"\n0. Orden descendente\n1. Orden ascendente\nIngrese opcion: ","Opcion Invalida. ", 0, 1, 3);
				ll_sort(cloneSelecciones, selec_CompareByConfederation, orden);
				printf("\n**** LISTA DE SELECCIONES ORDENADA POR CONFEDERACION ****\n");
				controller_listarSelecciones(cloneSelecciones);
				retorno = 1;
				break;
			case 4: //D) JUGADORES POR NOMBRE.
				getNumber(&orden,"\n0. Orden descendente\n1. Orden ascendente\nIngrese opcion: ","Opcion Invalida. ", 0, 1, 3);
				ll_sort(cloneJugadores, jug_CompareByName, orden);
				controller_listarJugadores(cloneJugadores);
				retorno = 1;
				break;
			}

		}
	}
	return retorno;
}

int controller_guardarJugadoresModoTexto(char *path, LinkedList *pArrayListJugador) {
	int retorno = 0;
	FILE *pArchivo;
	Jugador *pJugador = NULL;
	int largoJugadores;
	int id;
	char nombre[100];
	char posicion[100];
	char nacionalidad[100];
	int edad;
	int idSeleccion;

	if (path != NULL && pArrayListJugador != NULL) {
		largoJugadores = ll_len(pArrayListJugador);
		pArchivo = fopen(path, "w");
		if (pArchivo != NULL && largoJugadores > 0) {
			fprintf(pArchivo, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
			for (int i = 0; i < largoJugadores; i++) {
				pJugador = (Jugador*) ll_get(pArrayListJugador, i);
				if (pJugador != NULL) {
					if (jug_getId(pJugador, &id)
							&& jug_getNombreCompleto(pJugador, nombre)
							&& jug_getPosicion(pJugador, posicion)
							&& jug_getNacionalidad(pJugador, nacionalidad)
							&& jug_getEdad(pJugador, &edad)
							&& jug_getSIdSeleccion(pJugador, &idSeleccion)) {
						fprintf(pArchivo, "%d,%s,%d,%s,%s,%d\n", id, nombre, edad, posicion, nacionalidad, idSeleccion);
						retorno = 1;
					}
				}
			}
			jug_actualizarID(id);
			fclose(pArchivo);
		}

	}

	return retorno;
}

int controller_guardarJugadoresModoBinario(char *path,LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {
	int retorno = 0;
	int largoJugadores;
	int indice;
	int idSeleccionJugador;
	FILE *pArchivo;
	Jugador *pJugador = NULL;
	Seleccion* pSeleccion = NULL;
	char confederacion[50];
	char confederacionSeleccion[50];

	if (path != NULL && pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		getConfederacion(confederacion); // elije la confederacion que quiere
		pArchivo = fopen(path, "wb"); // abro el archivo en modo escritura
		if (pArchivo != NULL) {
			largoJugadores = ll_len(pArrayListJugador);
			if (largoJugadores > 0) {
				for (int i = 0; i < largoJugadores; i++) {
					pJugador = (Jugador*) ll_get(pArrayListJugador, i);
					if (pJugador != NULL) {
						jug_getSIdSeleccion(pJugador, &idSeleccionJugador);
						if (idSeleccionJugador != 0) {
							indice = selec_BuscarPorID(pArrayListSeleccion, idSeleccionJugador);
							if (indice > 0) {
								pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indice);
								if (pSeleccion != NULL) {
									selec_getConfederacion(pSeleccion, confederacionSeleccion);
									if (strcmp(confederacionSeleccion, confederacion) == 0) {
										if (fwrite(pJugador, sizeof(Jugador), 1, pArchivo) == 1) {
											retorno = 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}

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

int controller_editarSeleccion(LinkedList* pArrayListSeleccion)///////////////////////////////aca podria hacer el menu de convocados
{

    return 1;
}

int controller_listarSelecciones(LinkedList *pArrayListSeleccion) {
	int retorno = 0;
	int largoList;
	Seleccion *pSeleccion = NULL;

	if (pArrayListSeleccion != NULL) {
		largoList = ll_len(pArrayListSeleccion);

		printf("\n*** LISTA DE SELECCIONES ***\n");
		printf("========================================================\n");
		printf("|  ID |       PAIS      | CONFEDERACION |  CONVOCADOS  |\n");
		printf("========================================================\n");
		for (int i = 0; i < largoList; i++) {
			pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
			if (pSeleccion != NULL && ll_isEmpty(pArrayListSeleccion) == 0) {
				selec_MostrarSeleccion(pSeleccion);
				retorno = 1;
			}
		}
		printf("=======================================================\n");
	}

	return retorno;
}

int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	LinkedList* clone = NULL;
	clone = ll_clone(pArrayListSeleccion);

	if (pArrayListSeleccion != NULL && clone != NULL) {
		ll_sort(clone, selec_CompareById, 1);
		printf("\n**** LISTA DE SELECCIONES ****\n");
		controller_listarSelecciones(clone);
		retorno = 1;
	}

	return retorno;
}

int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    int retorno = 0;
    FILE* pArchivo;
    Seleccion* pSeleccion = NULL;
    int largoSeleccion;
    int id;
    char pais[100];
    char confederacion[100];
    int convocados;

    if(path != NULL && pArrayListSeleccion != NULL){
        largoSeleccion = ll_len(pArrayListSeleccion);
        pArchivo = fopen(path, "w");
        if(pArchivo != NULL && largoSeleccion > 0){
             for(int i = 0; i<largoSeleccion; i++){
                pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
                if(pSeleccion != NULL){
                    if(selec_getId(pSeleccion, &id) && selec_getPais(pSeleccion, pais)
                    && selec_getConfederacion(pSeleccion, confederacion) && selec_getConvocados(pSeleccion, &convocados) ){
                       fprintf(pArchivo, "%d,%s,%s,%d\n", id, pais, confederacion, convocados);
                       retorno = 1;
                    }
                }
            }
            fclose(pArchivo);
        }
    }

    return retorno;
}

int controller_convocarJugadores(LinkedList *pArrayListJugador,LinkedList *pArrayListSeleccion) {
	int retorno = 0;
	int indice;
	int idJugadorBuscado;
	Jugador *pJugador = NULL;
	int idSeleccionJugador;
	int idSeleccionBuscado;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		controller_listarJugadores(pArrayListJugador);
		getNumber(&idJugadorBuscado, "\nIngrese ID del jugador a convocar: ","ID inválido. ", 1, 1000, 3);
		indice = jug_BuscarPorID(pArrayListJugador, idJugadorBuscado);
		if (indice > 0) {
			pJugador = (Jugador*) ll_get(pArrayListJugador, indice);
			if (pJugador != NULL) {
				jug_getSIdSeleccion(pJugador, &idSeleccionJugador);
				if (idSeleccionJugador == 0) {
					controller_ordenarSelecciones(pArrayListSeleccion);
					getNumber(&idSeleccionBuscado,"\nIngrese ID de la seleccion a convocar: ","ID inválido. ", 1, 32, 3);
					selec_incrementarConvocados(pArrayListSeleccion,idSeleccionBuscado);
					jug_setIdSeleccion(pJugador, idSeleccionBuscado);
					retorno = 1;
				} else {
					printf("\nEl jugador ya fue convocado\n");
				}
			} else {
				printf("\nEl ID del jugador no se encontró\n");
			}
		}
	}

	return retorno;
}

int controller_quitarJugadorDeSeleccion(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {
	int retorno = 0;
	int idJugador;
	int indice;
	Jugador *pJugador = NULL;
	int idSeleccionJugador;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		controller_listarJugadoresConvocados(pArrayListJugador);
		if (getNumber(&idJugador, "\nIngrese ID del jugador a desconvocar: ","ID inválido. ", 1, 1000, 3)) {
			indice = jug_BuscarPorID(pArrayListJugador, idJugador);
			if (indice > 0) {
				pJugador = (Jugador*) ll_get(pArrayListJugador, indice);
				if (pJugador != NULL) {
					jug_getSIdSeleccion(pJugador, &idSeleccionJugador);
					selec_decrementarConvocados(pArrayListSeleccion, idSeleccionJugador);
					jug_setIdSeleccion(pJugador, 0);
					retorno = 1;
				}
			}

		}
	}

	return retorno;
}

int controller_eliminarListas(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion){
	int retorno = 0;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		ll_deleteLinkedList(pArrayListJugador);
		ll_deleteLinkedList(pArrayListSeleccion);
		retorno = 1;
	}

	return retorno;
}

