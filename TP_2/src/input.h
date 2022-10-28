#ifndef INPUT_H_
#define INPUT_H_

/**
* \brief Take a string and evaluate if it is an integer
* \param pResultado Receive the number entered in case of success
* \param mensaje It is the message that is shown to the user before entering data
* \param mensajeError It is the message that is displayed in case of error
* \param minimo the minimum amount allowed
* \param maximo the maximun amount allowed
* \param reintentos Number of times the user can re-enter the data
* \return In case of success it returns 0, if not -1
*/
int getNumber(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);

/**
* \brief receives a string and evaluates it to be a valid name
* \param stringRecibido received string
* \return In case of success it returns 0, if not -1
*/
int isValidName(char* stringRecibido);

/**
* \brief receives a string and evaluates it to be a valid name
* \param resultado  received string
* \param mensaje It is the message that is shown to the user before entering data
* \param mensajeError It is the message that is displayed in case of error
* \param minimo the minimum amount of char allowed
* \param maximo the maximun amount of char allowed
* \param reintentos Number of times the user can re-enter the data
* \return In case of success it returns 0, if not -1
*/
int getName(char* resultado, char* msg, char* msgError, int min, int max, int reintentos);

/**
* \brief receives a string and evaluates it to be a valid position
* \param pAlfabetico  received string
* \param limite limit of string length
* \param mensaje It is the message that is shown to the user before entering data
* \param mensajeError It is the message that is displayed in case of error
* \param reintentos Number of times the user can re-enter the data
* \return In case of success it returns 0, if not -1
*/
int getPosition(char *pAlfabetico, int limite, char *mensaje,char *mensajeError, int reintentos);

/**
* \brief receives a string and evaluates it to be a valid confederation
* \param pAlfabetico  received string
* \param limite limit of string length
* \param mensaje It is the message that is shown to the user before entering data
* \param mensajeError It is the message that is displayed in case of error
* \param reintentos Number of times the user can re-enter the data
* \return In case of success it returns 0, if not -1
*/
int getConfederation(char *pAlfabetico, int limite, char *mensaje,char *mensajeError, int reintentos);

/**
* \brief receives a string and evaluates it to be a valid region
* \param pAlfabetico  received string
* \param limite limit of string length
* \param mensaje It is the message that is shown to the user before entering data
* \param mensajeError It is the message that is displayed in case of error
* \param reintentos Number of times the user can re-enter the data
* \return In case of success it returns 0, if not -1
*/
int getRegion(char *pAlfabetico, int limite, char *mensaje,char *mensajeError, int reintentos);

/**
* \brief Take a string and evaluate if it is a short integer
* \param pResultado Receive the number entered in case of success
* \param mensaje It is the message that is shown to the user before entering data
* \param mensajeError It is the message that is displayed in case of error
* \param minimo the minimum amount allowed
* \param maximo the maximun amount allowed
* \param reintentos Number of times the user can re-enter the data
* \return In case of success it returns 0, if not -1
*/
int getShort(short *pResultado, char *mensaje, char *mensajeError, short minimo, short maximo, int reintentos);

/**
* \brief Take a string and evaluate if it is a float
* \param str receive the string
* \return In case of success it returns 0, if not -1
*/
int isValidFloat(char *str);

/**
* \brief Take a string and evaluate if it is a float
* \param pFloat Receive the number entered in case of success
* \return In case of success it returns 0, if not -1
*/
int isFloat(float* pResult);

/**
* \brief Take a string and evaluate if it is a float
* \param pResult Receive the number entered in case of success
* \param message It is the message that is shown to the user before entering data
* \param errorMessage It is the message that is displayed in case of error
* \param min the minimum amount allowed
* \param max the maximun amount allowed
* \param retries Number of times the user can re-enter the data
* \return In case of success it returns 0, if not -1
*/
int getFloat(float* pResult, char* message, char* errorMessage, float min, float max, int retries);

#endif /* INPUT_H_ */
