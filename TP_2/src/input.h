#ifndef INPUT_H_
#define INPUT_H_

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int getNumber(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);

/**
* \brief Toma una cadena y evalua si tiene solo letras
* \param pAlfabetico Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int getAlfabetico(char *pAlfabetico, int limite, char *mensaje,char *mensajeError, int reintentos);

int getName(char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos);

/**
* \brief Toma una cadena y evalua si es un float
* \param pFloat Recibe el numero ingresado en caso de exito
* \param limite Es el numero de cifras
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*/
int getFloat(float *pFloat, int limite, char *mensaje, char *mensajeError, int reintentos);

int getPosition(char *pAlfabetico, int limite, char *mensaje,char *mensajeError, int reintentos);

int getShort(short *pResultado, char *mensaje, char *mensajeError, short minimo, short maximo, int reintentos);

int utn_getFloatPositivo(   float *pFloat, int limite, char *mensaje,
                            char *mensajeError, int reintentos);

#endif /* INPUT_H_ */
