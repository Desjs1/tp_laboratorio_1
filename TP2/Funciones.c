#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int getInt(int* pResultado);
static int getFloat(float* pResultado);
static int getNombre(char*pResultado,int longitud);
static int getString(char*cadena,int longitud);
static int esNumerica(char* cadena);
static int esFlotante(char* cadena);
static int esNombre(char*cadena,int longitud);

char menu()
{
    char opcion;
    printf("\n----Menu de empleados----\n");
    printf("a)Alta de empleado\n");
    printf("b)Baja de empleado \n");
    printf("c)Modificacion de empleado \n");
    printf("d)Mostrar lista de empleado");
    printf("e)Mostrar empleados alfabeticamente \n");
    printf("f)Mostrar total de salarios juntos, promedio y empleados que superan el promedio \n");
    printf("g)Salir \n");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}
char submenu()
{
    char opcion;
    printf("\n----Menu de empleados----\n");
    printf("a)Nombre: \n");
    printf("b)Apellido: \n");
    printf("c)Salario: \n");
    printf("d)Sector: \n");
    printf("e)Todo: \n");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}
char menuLista()
{
    char opcion;
    printf("a)lista ordenada alfabeticamente \n");
    printf("b)promedio de salarios y empleado con mayor salario \n");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
{
		while(reintentos>=0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(getInt(&bufferInt) ==0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		printf("%s",mensajeError);
		}
}
	return retorno;
}

float get_numerofloat(float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int reintentos)
{
	float bufferfloat;
	int retorno =-1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getFloat(&bufferfloat)==0 && bufferfloat >= minimo && bufferfloat <= maximo)
		{
			*pResultado = bufferfloat;
			retorno = 0;
			break;
		}
	    	printf("%s",mensajeError);
	}
	return retorno;
}

int utn_getNombre(char* pResultado, int longitud, char* mensaje,char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno =-1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getNombre(bufferString,sizeof(bufferString))==0 && strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
	    	printf("%s",mensajeError);
	}
	return retorno;
}
static int getInt(int* pResultado){
	int retorno=-1;
	char buffer[4096];
	if(pResultado != NULL)
	{
	if(myGets(buffer, sizeof(buffer))==0 && esNumerica(buffer)){
		*pResultado = atoi(buffer);
		retorno=0;
	}
	}
	return retorno;
}
static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[4096];
	if(pResultado != NULL)
	{
	if(myGets(buffer,sizeof(buffer))==0 && esFlotante(buffer))
	  {
		*pResultado = atof(buffer);
		retorno=0;
	  }
	}
	return retorno;
}
static int getNombre(char*pResultado,int longitud)
{
	int retorno=-1;
	char buffer[1000];
	if(pResultado !=NULL)
	{
		if(getString(buffer,sizeof(buffer))==0 &&
			esNombre(buffer,sizeof(buffer))&&
			strnlen(buffer,sizeof(buffer)<longitud))
			{
			strncpy(pResultado,buffer,longitud);
			retorno=0;
			}
	}
	return retorno;
}
static int getString(char*cadena,int longitud)
{
	int retorno=-1;
	char bufferString[1000];
	if(cadena != NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}
int myGets(char* cadena, int longitud)
{
		fflush(stdin);
	if(cadena!=NULL && longitud>0 && fgets(cadena,longitud,stdin)==cadena)
	{
		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]='\0';
		}
		return 0;
	}
	return -1;
}
static int esNumerica(char* cadena)
{
	int retorno= 1;
	int i=0;
	if(cadena!=NULL && strlen(cadena)>0)
	{
	 for(i=0; cadena[i] != '\0';i++)
	 {
	  if(i==0 && (cadena[i]=='-'||cadena[i]=='+'))
	   {
		continue;
	   }
	if(cadena[i]<'0'||cadena[i]>'9')
	  {
		retorno = 0;
		break;
	   }
	  }
	 }
	return retorno;
}
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno= 1;
	int contadorPuntos=0;
	if(cadena!=NULL && strlen(cadena) > 0)
	{
	for(i=0;cadena[i] != '\0';i++)
	{
	if(i==0 && (cadena[i]=='-'||cadena[i]=='+'))
	 {
		continue;
	 }
	if(cadena[i]<'0'||cadena[i]>'9')
	{
		if(cadena[i]=='.'&& contadorPuntos == 0)
		{
			contadorPuntos++;
		}
		else
		{
		retorno = 0;
		break;
		}
	   }
	  }
	}
	return retorno;
}
static int esNombre(char*cadena,int longitud)
{
	int retorno=-1;
	int i=0;
	if(cadena != NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i < longitud;i++)
		{
			if((cadena[i]<'A'||cadena[i]>'Z')&& (cadena[i]<'a'||cadena[i]>'z'))
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

