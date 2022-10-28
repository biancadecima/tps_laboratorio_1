#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

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

static int getString(char *pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0 )
    {
    	fflush(stdin);
        fgets(bufferString, 4096, stdin);
        len = strlen(bufferString);
        if(len <= limite)
        {
            if(len != limite-1 || bufferString[limite-2] == '\n')
            {
                bufferString[len-1] = '\0';
            }
            strncpy(pBuffer, bufferString, limite);
            retorno = 0;
        }
        else
        {
            printf("Se admite un maximo de %d caracteres\n", limite - 1);
        }
    }
    return retorno;
}

static int isValidAlfabetico(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0)
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(!(tolower(pBuffer[i]) >= 'a' && tolower(pBuffer[i]) <= 'z'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int isValidString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
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

static int isValidShort(short *pResultado) {
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
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
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

int getName(char* resultado, char* msg, char* msgError, int min, int max, int reintentos)
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!isValidString(msg,msgError,min,max,&reintentos,bufferStr)) //==0
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

int getPosition(char *pAlfabetico, int limite, char *mensaje,char *mensajeError, int reintentos){
	int rtn = -1;
	char bufferAlfabetico[4096];
	if (pAlfabetico != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0) {
		do {
			reintentos--;
			printf("\n%s", mensaje);
			if (getString(bufferAlfabetico, limite) == 0
					&& isValidAlfabetico(bufferAlfabetico, limite)
					&& (strcmp(bufferAlfabetico, "defensor") == 0
							|| strcmp(bufferAlfabetico, "Defensor") == 0
							|| strcmp(bufferAlfabetico, "arquero") == 0
							|| strcmp(bufferAlfabetico, "Arquero") == 0
							|| strcmp(bufferAlfabetico, "Delantero") == 0
							|| strcmp(bufferAlfabetico, "delantero") == 0
							|| strcmp(bufferAlfabetico, "Mediocampista") == 0
							|| strcmp(bufferAlfabetico, "mediocampista") == 0)) {
				strncpy(pAlfabetico, bufferAlfabetico, limite);
				rtn = 0;
				break;
			} else {
				printf("\n%s", mensajeError);
			}
		} while (reintentos >= 0);
	}

	return rtn;
}

int getConfederation(char *pAlfabetico, int limite, char *mensaje,char *mensajeError, int reintentos){
	int rtn = -1;
	char bufferAlfabetico[4096];
	if (pAlfabetico != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0) {
		do {
			reintentos--;
			printf("\n%s", mensaje);
			if (getString(bufferAlfabetico, limite) == 0
					&& isValidAlfabetico(bufferAlfabetico, limite)
					&& (strcmp(bufferAlfabetico, "UEFA") == 0
							|| strcmp(bufferAlfabetico, "uefa") == 0
							|| strcmp(bufferAlfabetico, "OFC") == 0
							|| strcmp(bufferAlfabetico, "ofc") == 0
							|| strcmp(bufferAlfabetico, "afc") == 0
							|| strcmp(bufferAlfabetico, "AFC") == 0
							|| strcmp(bufferAlfabetico, "CAF") == 0
							|| strcmp(bufferAlfabetico, "caf") == 0
							|| strcmp(bufferAlfabetico, "CONCACAF") == 0
							|| strcmp(bufferAlfabetico, "concacaf") == 0
							|| strcmp(bufferAlfabetico, "CONMEBOL") == 0
							|| strcmp(bufferAlfabetico, "conmebol") == 0)) {
				strncpy(pAlfabetico, bufferAlfabetico, limite);
				rtn = 0;
				break;
			} else {
				printf("\n%s", mensajeError);
			}
		} while (reintentos >= 0);
	}

	return rtn;
}

int getRegion(char *pAlfabetico, int limite, char *mensaje,char *mensajeError, int reintentos){
	int rtn = -1;
	char bufferAlfabetico[4096];
	if (pAlfabetico != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0) {
		do {
			reintentos--;
			printf("\n%s", mensaje);
			if (getString(bufferAlfabetico, limite) == 0
					&& isValidAlfabetico(bufferAlfabetico, limite)
					&& (strcmp(bufferAlfabetico, "Asia") == 0
							|| strcmp(bufferAlfabetico, "Africa") == 0
							|| strcmp(bufferAlfabetico, "Norte") == 0
							|| strcmp(bufferAlfabetico, "Sudamerica") == 0
							|| strcmp(bufferAlfabetico, "Oceania") == 0
							|| strcmp(bufferAlfabetico, "Europa") == 0)) {
				strncpy(pAlfabetico, bufferAlfabetico, limite);
				rtn = 0;
				break;
			} else {
				printf("\n%s", mensajeError);
			}
		} while (reintentos >= 0);
	}

	return rtn;
}

int getShort(short *pResultado, char *mensaje, char *mensajeError, short minimo, short maximo, int reintentos) {
	short bufferShort;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (isValidShort(&bufferShort) == 0) {
			if (bufferShort >= minimo && bufferShort <= maximo) {
				*pResultado = bufferShort;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int isValidFloat(char *str) {
    int rtn = -1;
    int longitud = strlen(str);
    while (longitud > 0 && isspace(str[longitud - 1]))
        longitud--;
    if (longitud <= 0) return 0;
    int i;
    int haEncontradoElPunto = 0;
    for (i = 0; i < longitud; ++i) {
        if (str[i] == '-' && i > 0) {
            rtn = 0;
            break;
        }
        if (str[i] == '.') {
            if (haEncontradoElPunto) {
                rtn = 0;
                break;
            } else {

                haEncontradoElPunto = 1;
            }
        }
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '.') {
            rtn = 0;
            break;
        }
    }
    return rtn;
}

int isFloat(float* pResult)
{
    int retorno=-1;
    char buffer[64];
    if(pResult != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && isValidFloat(buffer))
        {
            *pResult = atof(buffer);
            retorno = 0;
        }
    }

    return retorno;
}

int getFloat(float* pResult, char* message, char* errorMessage, float min, float max, int retries)
{
    float bufferFloat;
    int retorno = -1;
    while(retries>0)
    {
        retries--;
        printf("%s",message);
        if(isFloat(&bufferFloat) == 0)
        {
            if(bufferFloat >= min && bufferFloat <= max)
            {
                *pResult = bufferFloat;
                retorno = 0;
                break;
            }
        }
        printf("%s",errorMessage);
    }
    return retorno;
}
