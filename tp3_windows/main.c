#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int optionCase5 = 0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSeleccion = ll_newLinkedList();

    do{
    	getNumber(&option, "\nIngrese opcion: ", "Opcion invalida. ", 1, 11, 3);
        switch(option)
        {
            case 1://CARGA DE ARCHIVOS: Se deben leer los archivos .csv de jugadores y selecciones
            	if(controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores) == 1 &&
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv" , listaSeleccion) == 1){
            		printf("\nSe cargaron correctamente los archivos\n");
            	}else{
            		printf("\nNo se cargaron correctamente los archivos\n");
            	}
                break;
            case 2: //alta jugador
            	if(controller_agregarJugador(listaJugadores)){
            		printf("\nSe dió de alta correctamente al jugador\n");
            	}else{
            		printf("\nNo se pudo dar de alta al jugador\n");
            	}
            	break;
            case 3:// modificacion de jugador
            	if(controller_listarJugadores(listaJugadores) &&){
            		printf("\n Modificacion Exitosa \n");
            	}
            	break;
            case 4://baja jugador
            	if(controller_listarJugadores(listaJugadores) && controller_removerJugador(listaJugadores)){
            		printf("\n Baja Exitosa \n");
            	}else{
            		printf("\n No se pudo realizar la baja \n");
            	}
            	break;
            case 5: //listados
            	getNumber(&optionCase5, "\nIngrese opcion: ", "Opcion Invalida. ", 1, 3, 3);
            	switch(optionCase5){
            	case 1://A) TODOS LOS JUGADORES.
            		if(!controller_listarJugadores(listaJugadores)){
            			printf("\nNo se pudo listar a los jugadores\n");
            		}
            		break;
            	case 2://B) TODAS LAS SELECCIONES.
            		if(!controller_listarSelecciones(listaSeleccion)){
            			printf("\nNo se pudo listar a las selecciones\n");
            		}
            		break;
            	case 3://C) JUGADORES CONVOCADOS (únicamente).
            		/*if(!){
            			printf("\nNo se pudo listar a los jugadores convocados\n");
            		}*/
            		break;
            	}
            	break;
            case 6:
            	//convocar
            	//quitar de seleccion
            	break;
            case 7:// ordenar y listar
            	break;
            case 8: //Generar y guardar en binario una nueva lista que contenga los jugadores convocados de una confederación ingresada por el usuario.

            	break;
            case 9: //Se deberá leer e imprimir los datos del archivo generado en el punto 8.
            	if(controller_cargarJugadoresDesdeBinario("jugadores.csv", listaJugadores)){
            		printf("\nSe cargó el archivo binario de los jugadores correctamente\n");
            	}else{
            		printf("\nNo se cargó el archivo binario de los jugadores correctamente\n");
            	}
            	break;
            case 10: // guardar archivos .csv
            	break;
            case 11: // salir
            	break;
        }
    }while(option != 11);

    return 0;
}

