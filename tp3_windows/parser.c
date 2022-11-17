#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno;
	// lo que levanta el fscanf del archivo
 	char auxId[2000];
	char auxNombreCompleto[2000];
	char auxEdad[2000];
	char auxPosicion[2000];
	char auxNacionalidad[2000];
	char auxIdSeleccion[2000];
	// numero de lecturas que realizo fscanf
	int retornoFscanf;
	Jugador* pJugador;

	if(pFile != NULL && pArrayListJugador != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad, auxIdSeleccion);// lectura fantasma
		do{
			retornoFscanf = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad, auxIdSeleccion);
			if(retornoFscanf == 6){
				pJugador = jug_newParametros(auxId, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad, auxIdSeleccion);
				if(pJugador != NULL){
					ll_add(pArrayListJugador, pJugador);
					retorno = 1;
				}
			}else{
				retorno = 0;
				break;
			}
		}while(!feof(pFile));
	}

    return retorno;
}

int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador){
	int retorno = 0;
	Jugador* pJugador;

	if(pFile != NULL && pArrayListJugador != NULL){
		do{
			pJugador = jug_new();
			if(pJugador != NULL){
				if(fread(pJugador, sizeof(Jugador)*1, 1, pFile)){
					ll_add(pArrayListJugador, pJugador);
					retorno = 1;
				}
			}
		}while(!feof(pFile));
	}

    return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno;
	// lo que levanta el fscanf del archivo
 	char auxId[2000];
	char auxPais[2000];
	char auxConfederacion[2000];
	char auxConvocados[2000];
	// numero de lecturas que realizo fscanf
	int retornoFscanf;
	Seleccion* pSeleccion;

	if(pFile != NULL && pArrayListSeleccion != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxPais, auxConfederacion, auxConvocados);
		do{
			retornoFscanf = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxPais, auxConfederacion, auxConvocados);
			if(retornoFscanf == 4){
				pSeleccion = selec_newParametros(auxId, auxPais, auxConfederacion, auxConvocados);
				if(pSeleccion != NULL){
					ll_add(pArrayListSeleccion, pSeleccion);
					retorno = 1;
				}
			}else{
				retorno = 0;
				break;
			}
		}while(!feof(pFile));
	}

    return retorno;
}

