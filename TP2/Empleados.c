#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "Empleados.h"
int incializarLista(Empleado vect[],int tam){
int retorno = 1;
if(vect != NULL && tam>0){
    for(int i=0;i<tam;i++){
        vect[i].isEmpty = 1;
    }
    retorno = 0;
}
return retorno;
}
int lugarLibre(Empleado vect[],int tam){
int retorno = -1;
int i;
if(vect != NULL && tam > 0){
    for( i = 0; i<tam ;i++){
        if(vect[i].isEmpty == 1){
            retorno = i;
            break;
        }
    }
}
return retorno;
}
int altaEmpleado(Empleado vect[],int tam,int indice){
    Empleado bufferEmp;
    int retorno = -1;
    if(vect!=NULL && tam>0 && indice<tam && indice >=0){
        if(utn_getNombre(bufferEmp.nombre, NOMBRE,"Ingresar nombre del empleado: \n","Error. Reingrese un nombre nuevamente: \n",3)==0
           && utn_getNombre(bufferEmp.apellido, APELLIDO,"Ingresar el apellido del empleado: \n","Error. Reingrese el apellid nuevamente: \n",3)==0
           && get_numerofloat(&bufferEmp.salario,"Ingresar el salario del empleado: \n", "Error. Reingresar el salario del empleado",MINSALARIO,MAXSALARIO,3)==0
           && utn_getNumero(&bufferEmp.sector,"Ingrese sector (1 mas alto, 10 masbajo): \n","Error. sector invalido: \n", SECTORBAJO,SECTORALTO,3)==0){
           retorno = 0;
           bufferEmp.id = indice;
           bufferEmp.isEmpty = 0;
           vect[indice] = bufferEmp;
           indice++;
           }
    }
    return retorno;
}
int buscarIdEmpleado(Empleado vect[],int tam, int indice){
int retorno = -1;
for(int i = 0;i<tam;i++){
    if(vect[i].id == indice){
        retorno = i;
        break;
    }
}
return retorno;
}
int modificarEmpleado(Empleado vect[],int tam,int indice){
    Empleado bufferEmp;
    int retorno = 1;
    if(vect!=NULL && tam>0 && indice<tam && indice >=0 && vect[indice].isEmpty == 0){
              switch(submenu()){
        case 'a':
            if(!(utn_getNombre(bufferEmp.nombre, NOMBRE,"Ingresar nombre del empleado: \n","Error. Reingrese un nombre nuevamente: \n",3))){
                printf("Modificacion completada \n");
            }else{
            printf("Modificacion invalida \n");
            }
            break;
        case 'b':
            if(!(utn_getNombre(bufferEmp.apellido, APELLIDO,"Ingresar el apellido del empleado: \n","Error. Reingrese el apellid nuevamente: \n",3))){
                printf("Modificacion completada \n");
            }else{
            printf("Modificacion invalida \n");
            }
            break;
        case 'c':
            if(!(get_numerofloat(&bufferEmp.salario,"Ingresar el salario del empleado: \n", "Error. Reingresar el salario del empleado",MINSALARIO,MAXSALARIO,3))){
                printf("Modificacion completada \n");
            }else{
            printf("Modificacion invalida \n");
            }
            break;
        case 'd':
            if(!(utn_getNumero(&bufferEmp.sector,"Ingrese sector (1 mas alto, 10 masbajo): \n","Error. sector invalido: \n", SECTORBAJO,SECTORALTO,3))){
                printf("Modificacion completada \n");
            }else{
            printf("Modificacion invalida \n");
            }
            break;
        case 'e':
            if(!(utn_getNombre(bufferEmp.nombre, NOMBRE,"Ingresar nombre del empleado: \n","Error. Reingrese un nombre nuevamente: \n",3))
           && !(utn_getNombre(bufferEmp.apellido, APELLIDO,"Ingresar el apellido del empleado: \n","Error. Reingrese el apellid nuevamente: \n",3))
           && !(get_numerofloat(&bufferEmp.salario,"Ingresar el salario del empleado: \n", "Error. Reingresar el salario del empleado",MINSALARIO,MAXSALARIO,3))
           && !(utn_getNumero(&bufferEmp.sector,"Ingrese sector (1 mas alto, 10 mas bajo): \n","Error. sector invalido: \n", SECTORBAJO,SECTORALTO,3))){
           printf("Modificacion completada \n");
           }else{
           printf("Modificacion invalida \n");
           }
            break;
            }
           retorno = 0;
           bufferEmp.id = vect[indice].id;
           bufferEmp.isEmpty = 0;
           vect[indice] = bufferEmp;
    }
    return retorno;
}

int bajaEmpleado(Empleado vect[],int tam, int indice){
int retorno = -1;
if(vect != NULL && tam>0 && indice<tam && indice >=0 && vect[indice].isEmpty ==0){
        vect[indice].isEmpty = 1;
        retorno = 0;
}
return retorno;
}
void ordernarAlf(Empleado vect[],int tam,int criterio){
    Empleado bufferAux;
    if(vect != NULL && tam>0 && criterio >= 0 && criterio <= 1){
    for(int i = 0;i<tam--;i++){
        for(int j=i+1;j<tam;j++){
            if(strcmp(vect[i].apellido, vect[j].apellido) > 0 && criterio && vect[i].isEmpty == 0 && vect[j].isEmpty == 0){
                bufferAux = vect[i];
                vect[i] = vect[j];
                vect[j] = bufferAux;
            }
            }
        }
    }
}
void listaEmpleadosAlf(Empleado vect[],int tam){
    printf("\n----------Lista de empleados-----------\n");
    ordernarAlf(vect,tam,1);
    for(int i = 0;i<tam;i++){
        if(vect[i].isEmpty == 0){
            printf("Apellido: %s     Sector: %d",vect[i].apellido,vect[i].sector);
        }
    }
}
void mostrarId(Empleado vect[], int indice){
    if(vect!= NULL && indice >= 0){
        printf("El id del empleado es: %d \n",vect[indice].id);
    }
}
float sumaDeSalarios(Empleado vect[],int tam){
    float acumulador = 0;
    if(vect != NULL && tam > 0){
        for(int i = 0;i<tam;i++){
            if(vect[i].isEmpty == 0){
                acumulador += vect[i].salario;
            }
        }
    }
    return acumulador;
}

void promedioDeSalarios(float acumulador,int cantidadEmpleados){
    float resultadoProm = 0;
 if(cantidadEmpleados >= 1){
    resultadoProm = acumulador / (float)cantidadEmpleados;
    printf("Promedio de salarios: %.2f",resultadoProm);
 }
}
