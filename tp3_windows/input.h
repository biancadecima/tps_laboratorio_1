#ifndef INPUT_H_
#define INPUT_H_

int getString(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int isValidName(char* stringRecibido);

int getPosicion(char* msg, char* msgError, int reintentos, char* resultado);

int getNumber(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);

#endif /* INPUT_H_ */
