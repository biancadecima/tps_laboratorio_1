#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "input.h"
#include "output.h"

int main()
{
	setbuf(stdout,NULL);
	int opcion;
    int flagGuardar = 0;
    int flagBinario = 0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSeleccion = ll_newLinkedList();

    do{
    	opcion = manejarMenuPrincipal();
        switch(opcion)
        {
            case 1://CARGA DE ARCHIVOS
            	if(controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores) == 1 &&
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv" , listaSeleccion) == 1){
            		printf("\nSe cargaron correctamente los archivos\n");
            	}else{
            		printf("\nNo se cargaron correctamente los archivos\n");
            	}
                break;
            case 2: //alta jugador
            	if(controller_agregarJugador(listaJugadores)){
            		printf("\n Alta exitosa \n");
            	}else{
            		printf("\nNo se pudo dar de alta al jugador\n");
            	}
            	break;
            case 3:// modificacion de jugador
				if (ll_isEmpty(listaJugadores) == 0) {
					if (controller_ordenarJugadores(listaJugadores) && controller_editarJugador(listaJugadores)) {
						printf("\n Modificacion Exitosa \n");
					} else {
						printf("\nNo se pudo realizar la modificación\n");
					}
				} else {
					printf("\nERROR: No hay jugadores cargados para modificar\n");
				}
            	break;
            case 4://baja jugador
				if (ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSeleccion) == 0) {
					if (controller_ordenarJugadores(listaJugadores) && controller_removerJugador(listaJugadores, listaSeleccion)) {
						printf("\n Baja Exitosa \n");
					} else {
						printf("\n No se pudo realizar la baja \n");
					}
				} else {
					printf("\nERROR: No hay jugadores cargados para elimminar\n");
				}
            	break;
            case 5: //listados
				if (ll_isEmpty(listaJugadores) == 0 || ll_isEmpty(listaSeleccion) == 0) {
					switch (manejarMenuListados()) {
					case 1: //A) TODOS LOS JUGADORES.
						if (!controller_listarJugadoresConSeleccion(listaJugadores, listaSeleccion)) {
							printf("\nNo se pudo listar a los jugadores\n");
						}
						break;
					case 2: //B) TODAS LAS SELECCIONES.
						if (!controller_ordenarSelecciones(listaSeleccion)) {
							printf("\nNo se pudo listar a las selecciones\n");
						}
						break;
					case 3: //C) JUGADORES CONVOCADOS (únicamente).
						if (!controller_listarJugadoresConvocados(listaJugadores)) {
							printf("\nNo se pudo listar a los jugadores convocados\n");
						}
						break;
					}
				} else {
					printf("\nERROR: No hay jugadores o selecciones cargados para listar\n");
				}

            	break;
			case 6:
				if (ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSeleccion) == 0) {
					if(!controller_editarSeleccion(listaSeleccion, listaJugadores)){
						printf("\nNo se pudo editar la seleccion\n");
					}
				} else {
					printf("\nERROR: No hay jugadores cargados para convocar\n");
				}

				break;
            case 7:// ordenar y listar
            	if (ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSeleccion) == 0) {
            		if(!controller_ordenarJugadoresSelecciones(listaJugadores, listaSeleccion)){
						printf("\nNo se pudo ordenar a los jugadores/selecciones\n");
            		}
            	}else{
            		printf("\nERROR: No hay jugadores cargados para ordenar\n");
            	}

            	break;
            case 8: //Generar y guardar en binario una nueva lista que contenga los jugadores convocados de una confederación ingresada por el usuario.
            	if (ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSeleccion) == 0) {
            		if(controller_guardarJugadoresModoBinario("convocados.bin", listaJugadores, listaSeleccion)){
            			printf("\nEl archivo binario se generó correctamente\n");
            			flagBinario = 1;
            		}
            	}else{
            		printf("\nERROR: No hay jugadores cargados para listar\n");
            	}
            	break;
            case 9: //Se deberá leer e imprimir los datos del archivo generado en el punto 8.
            	if (flagBinario == 1) {
            		if(controller_cargarJugadoresDesdeBinario("convocados.bin", listaJugadores, listaSeleccion)){
            			printf("\nSe leyó el archivo binario de los jugadores correctamente\n");
					}else{
						printf("\nNo se cargó el archivo binario de los jugadores correctamente\n");
					}
            	}else{
            		printf("\nERROR: No genero un archivo binario para leer\n");
            	}
            	break;
            case 10: // guardar archivos .csv
            	if (ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSeleccion) == 0) {
            		if(controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores) && controller_guardarSeleccionesModoTexto("selecciones.csv" , listaSeleccion)){
            			printf("\nSe guardaron los archivos de texto exitosamente\n");
            			flagGuardar = 1;
					}else{
						printf("\nNo se pudieron guardar los archivos de texto\n");
					}
            	}else{
            		printf("\nERROR: No hay jugadores o selecciones cargados para guardar\n");
            	}
            	break;
            case 11: // salir.
				if (flagGuardar == 1) {
					if (manejoSalida() == 1) {
						controller_eliminarListas(listaJugadores, listaSeleccion);
						opcion = 12;
					}
            	}else{
            		printf("\nERROR. Guardar cambios antes de terminar el programa\n");
            		opcion = 0;
            	}
            	break;
        }
    }while(opcion != 12);

    return 0;
}
