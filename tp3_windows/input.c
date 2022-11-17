#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

int getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,min,max,&reintentos,bufferStr))
            {
                if(isValidName(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,max);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidName(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'A' && stringRecibido[i]!=' ' && stringRecibido[i]!='-') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]<'a') ||
           stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s 1",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}


static int myGets(char *cadena, int longitud) {
	if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		return 0;
	}
	return -1;
}

static int esNumerica(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

static int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int getNumber(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos) {
	int bufferInt;
	int retorno = 0;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 1;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int getNacionalidad(char nacionalidad[]){
	int retorno = 0;
	int opcion;
	char arrayNacionalidades[32][50] = {"Argentino", "Brasilero", "Uruguayo", "Portugues", "Ingles", "Aleman", "Mexicano",
			"Estado Unidense", "Camerunes", "Senegales", "Australiano", "Qatari", "Arabe", "Belga", "Canadiense", "Surcoreano", "Costariqueño", "Croata", "Dinamarques",
			"Ecuatoriano", "Español", "Frances", "Gales", "Ghanes", "Holandes", "Irani", "Japones", "Marroqui", "Polaco", "Serbio", "Suizo", "Tunecino"};

	mostrarNacionalidades();
	if(getNumber(&opcion, "\nIngrese nacionalidad: ", "\nOpción inválida. ", 0, 31, 3)){
		for(int i = 0; i<32; i++){
			if(i == opcion){
				strcpy(nacionalidad, arrayNacionalidades[i]);
				retorno = 1;
			}
		}
	}

	return retorno;
}

int getPosicion(char posicion[]){
	int retorno = 0;
	int opcion;
	char arrayPosiciones[11][50] = {"Portero", "Defensa Central", "Lateral izquierdo", "Lateral derecho", "Pivote", "Mediocentro", "Mediocentro ofensivo",
			"Extremo izquierdo", "Extremo derecho", "Mediapunta", "Delantero centro"};

	mostrarPosiciones();
	if(getNumber(&opcion, "\nIngrese posición: ", "\nOpción inválida. ", 0, 10, 3)){
		for(int i = 0; i<11; i++){
			if(i == opcion){
				strcpy(posicion, arrayPosiciones[i]);
				retorno = 1;
			}
		}
	}

	return retorno;
}

int getConfederacion(char confederacion[]) {
	int retorno = 0;
	int opcion;
	char arrayConfederaciones[5][50] = { "AFC", "CAF", "CONCACAF", "CONMEBOL", "UEFA" };

	mostrarConfederaciones();
	if (getNumber(&opcion, "\nIngrese confederacion: ", "\nOpción inválida. ", 0, 4, 3)) {
		for (int i = 0; i < 5; i++) {
			if (i == opcion) {
				strcpy(confederacion, arrayConfederaciones[i]);
				retorno = 1;
			}
		}
	}

	return retorno;
}
