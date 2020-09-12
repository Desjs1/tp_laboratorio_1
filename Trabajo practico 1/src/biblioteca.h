/*
 * biblioteca.h
 *
 *  Created on: 12 sep. 2020
 *      Author: Jay
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>
int recibirNumero();
int suma(int num1,int num2);
int resta(int num1,int num2);
int multi(int num1,int num2);
float division(int num1,int num2);
int factorial(int num);
int menu();
char menuOp();
char menuRes();
void mostrarSuma(int resultado);
void mostrarResta(int resultado);
void mostrarMulti(int resultado);
void mostrarDiv(float resultado);
void mostrarFact(int resultado);


#endif /* BIBLIOTECA_H_ */
