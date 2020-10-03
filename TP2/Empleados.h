#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPLEADOS 1000
#define NOMBRE 51
#define APELLIDO 51
#define MAXSALARIO 100.000
#define MINSALARIO 10.000
#define SECTORALTO 1
#define SECTORBAJO 10
typedef struct{
int id;
char nombre[NOMBRE];
char apellido[APELLIDO];
float salario;
int sector;
int isEmpty;
}Empleado;
int incializarLista(Empleado vect[],int tam);
int lugarLibre(Empleado vect[],int tam);
int altaEmpleado(Empleado vect[],int tam,int indice);
int modificarEmpleado(Empleado vect[],int tam,int indice);
int buscarIdEmpleado(Empleado vect[],int tam, int indice);
int bajaEmpleado(Empleado vect[],int tam, int indice);
void ordernarAlf(Empleado vect[],int tam,int criterio);
void listaEmpleadosAlf(Empleado vect[],int tam);
void promedioDeSalarios(float acumulador,int cantidadEmpleados);
void mostrarId(Empleado vect[], int indice);
float sumaDeSalarios(Empleado vect[],int tam);
#endif // EMPLEADOS_H_INCLUDED
