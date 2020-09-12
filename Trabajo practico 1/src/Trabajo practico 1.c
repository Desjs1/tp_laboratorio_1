/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
int main(void)
{
	setbuf(stdout,NULL);
	   int a;
	   int b;
	    int salir = 1;
	    int resultadoSuma;
	    int resultadoResta;
	    int resultadoMulti;
	    int resultado1;
	    int resultado2;
	    float resultadoDiv;
	    do{
	    switch(menu())
	    {
	    case 1:
	        a = recibirNumero();
	        break;
	    case 2 :
	        b = recibirNumero();
	        break;
	    case 3 :
	        switch(menuOp())
	        {
	    case 'a':
	        resultadoSuma = suma(a,b);
	        break;
	    case 'b':
	        resultadoResta = resta(a,b);
	        break;
	    case 'c':
	        resultadoMulti = multi(a,b);
	        break;
	    case 'd':
	        resultadoDiv = division(a,b);
	        break;
	    case 'e':
	        resultado1 = factorial(a);
	        resultado2 = factorial(b);
	        break;
	        }
	        break;
	    case 4:
	        switch(menuRes())
	        {
	        case 'a':
	            mostrarSuma(resultadoSuma);
	            break;
	        case 'b':
	            mostrarResta(resultadoResta);
	            break;
	        case 'c':
	            mostrarMulti(resultadoMulti);
	            break;
	        case 'd':
	            mostrarDiv(resultadoDiv);
	            break;
	        case 'e':
	            mostrarFact(resultado1);
	            mostrarFact(resultado2);
	            break;
	        }
	        break;
	        case 5:
	        	salir = 0;
	        	break;
	        default:
	    printf("\n Opcion invalida \n");
	    break;
	    }
	    }while(salir);
	return EXIT_SUCCESS;
}
