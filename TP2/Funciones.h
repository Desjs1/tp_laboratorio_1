#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

char menu();
char submenu();
char menuLista();
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
float get_numerofloat(float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud, char* mensaje,char* mensajeError, int reintentos);
int myGets(char* cadena, int longitud);
#endif // FUNCIONES_H_INCLUDED
