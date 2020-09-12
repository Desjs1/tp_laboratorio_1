/*
 * biblioteca.c
 *
 *  Created on: 12 sep. 2020
 *      Author: Jay
 */
#include <stdio.h>
#include <stdlib.h>

/** \brief Esta funcion pide un numero por medio del printf y se recibirá por un scanf
 *
 * \param No pide una variable
 * \param
 * \return Devolverá el numero ingresado
 *
 */

int recibirNumero()
{
    int numero;
    printf("Ingrese el numero: \n");
    fflush(stdin);
    scanf("%d",&numero);
    return numero;
}

/** \brief Esta funcion pide que se elija una opcion por medio del printf y se recibirá por un scanf
 *
 * \param No pide ninguna variable para funcionar
 * \param
 * \return Devolverá la opcion elegida
 *
 */
int menu()
{
    int opcion;
    printf("\n----Menu de opciones----\n");
    printf("1)Ingresa el primer numero.\n");
    printf("2)Ingresa el segundo numero\n");
    printf("3)Eliga el calculo deseado \n");
    printf("4)Mostrar resultados\n");
    printf("5)Salir\n");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
/** \brief Esta funcion pide que se elija una opcion por medio del printf y se recibirá por un scanf
 *
 * \param No pide ninguna variable para funcionar
 * \param
 * \return Devolverá la opcion elegida
 *
 */
char menuOp()
{
    char opcion;
    printf("\n----Menu de operaciones----\n");
    printf("a)Suma de a+b \n");
    printf("b)Resta de a-b \n");
    printf("c)Multiplicacion de a*b \n");
    printf("d)Division de a/b \n");
    printf("e)Factorial de los numeros\n");
    fflush(stdin);
    tolower(scanf("%c",&opcion));
    return opcion;
}
/** \brief Esta funcion pide que se elija una opcion por medio del printf y se recibirá por un scanf
 *
 * \param No pide ninguna variable para funcionar
 * \param
 * \return Devolverá la opcion elegida
 *
 */
char menuRes()
{
    int opcion;
    printf("\n----Menu de operaciones----\n");
    printf("a)Mostrar resultado de suma \n");
    printf("b)Mostrar resultado de resta \n");
    printf("c)Mostrar resultado de multiplicacion\n");
    printf("d)Mostrar resultado de division\n");
    printf("e)Mostrar factorial de numero a y b\n");
    fflush(stdin);
    opcion=tolower(getchar());
    return opcion;
}
/** \brief Se sumaran 2 numeros ingresados anteriormente
 *
 * \param Se pide un numero entero
 * \param Se pide un numero entero
 * \return Se devuelve el resultado
 *
 */
int suma(int num1,int num2)
{
    int resultado = 0;
    resultado = num1 + num2;
    return resultado;
}
/** \brief Se restaran 2 numeros ingresados anteriormente
 *
 * \param Se pide un numero entero
 * \param Se pide un numero entero
 * \return Se devuelve el resultado
 *
 */
int resta(int num1,int num2)
{
    int resultado = 0;
    resultado = num1 - num2;
    return resultado;
}
/** \brief Se mutiplicaran 2 numeros ingresados anteriormente
 *
 * \param Se pide un numero entero
 * \param Se pide un numero entero
 * \return Se devuelve el resultado
 *
 */
int multi(int num1,int num2)
{
    int resultado = 0;
    resultado = num1 * num2;
    return resultado;
}
/** \brief Se sumaran 2 numeros ingresados anteriormente y se convertirá 1 en flotante para poder devolver un flotante.
 *
 * \param Se pide un numero entero
 * \param Se pide un numero entero
 * \return Se devuelve el resultado
 *
 */
float division(int num1,int num2)
{
    float resultado = 0;
    if(num2 == 0)
        {
    	printf("\n No se puede dividir por 0 \n");
        }else{
        	resultado = (float)num1 / num2;
        }
    return resultado;
}
/** \brief Se llamara a la misma funcion hasta que el numero haya llegado a uno. Ya logrado esto, las otras funciones empezaran realizar
 * sus debidas cuentas con la variable fact(la cual debe valer 1) hasta poder devolver el resultado
 *
 * \param Se pide un numero entero
 * \param
 * \return Se devuelve el resultado
 *
 */
int factorial(int num)
{
    long long int resultado;
    if(num == 1)
    {
    resultado=1;
    }
    else if(num >1)
    {
    resultado = (long long int)num * factorial(num-1);
    }else
    {
        printf("\n No es hacer el factorial de ese numero \n");
    }
    return resultado;
}
/** \brief Se muestra el resultado de la cuenta con un printf
 *
 * \param Se pide el resultado de la cuenta a la que hace referencia
 * \param
 * \return
 *
 */
void mostrarSuma(int resultado)
{
    printf("El resultado de la suma es: %d",resultado);
}
/** \brief Se muestra el resultado de la cuenta con un printf
 *
 * \param Se pide el resultado de la cuenta a la que hace referencia
 * \param
 * \return
 *
 */
void mostrarResta(int resultado)
{
    printf("El resultado de la resta es: %d",resultado);
}
/** \brief Se muestra el resultado de la cuenta con un printf
 *
 * \param Se pide el resultado de la cuenta a la que hace referencia
 * \param
 * \return
 *
 */
void mostrarMulti(int resultado)
{
    printf("El resultado de la multiplicacion es: %d",resultado);
}
/** \brief Se muestra el resultado de la cuenta con un printf
 *
 * \param Se pide el resultado de la cuenta a la que hace referencia
 * \param
 * \return
 *
 */
void mostrarDiv(float resultado)
{
    printf("El resultado de la division es: %.2f",resultado);
}
/** \brief Se muestra el resultado de la cuenta con un printf
 *
 * \param Se pide el resultado de la cuenta a la que hace referencia
 * \param
 * \return
 *
 */
void mostrarFact(int resultado)
{
    printf("El resultado del factorial es: %d",resultado);
}
