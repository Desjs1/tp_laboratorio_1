#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "Empleados.h"
int main()
{
    int auxid;
    char seguir = 's';
    int indice;
    float salarios;
    int cantEmpleados = 0;
    Empleado listaDeEmpleados[EMPLEADOS];
    if(!(incializarLista(listaDeEmpleados,EMPLEADOS))){
        printf("Inicializado con exito \n");
    }
    do{
        switch(menu()){
        case 'a':
            indice = lugarLibre(listaDeEmpleados,EMPLEADOS);
            if(indice >= 0 ){
              if(!(altaEmpleado(listaDeEmpleados,EMPLEADOS,indice))){
                mostrarId(listaDeEmpleados,indice);
                cantEmpleados++;
              }
            }
            break;
        case 'b':
            if(!(utn_getNumero(&auxid,"Ingrese el id","ingrese de nuevo el id: \n",0,EMPLEADOS,3))){
               indice = buscarIdEmpleado(listaDeEmpleados,EMPLEADOS,auxid);
               if(indice >= 0){
                if(bajaEmpleado(listaDeEmpleados,EMPLEADOS, indice)){
                printf("Baja completada \n");+
                cantEmpleados--;
                }
                }
                }
            break;
        case 'c':
            if(utn_getNumero(&auxid,"ingrese el id del empleado: \n", "Error. Reingrese el id: \n",0,EMPLEADOS,3)){
                indice = auxid;
                if(modificarEmpleado(listaDeEmpleados,EMPLEADOS,indice)){
                    printf("Modificacion completada\n");
                }
            }else{
            printf("Modificacion invalida\n");
            }
            break;
        case 'd':
            switch(menuLista()){
        case 'a':
            listaEmpleadosAlf(listaDeEmpleados,EMPLEADOS);
            break;
        case 'b':
            salarios = sumaDeSalarios(listaDeEmpleados,EMPLEADOS);
            promedioDeSalarios(salarios,cantEmpleados);
            break;
            }
            break;
        case 'g':
            printf("¿Quiere seguir?: \n");
            fflush(stdin);
            tolower(getchar());
            break;
        }
    }while(seguir == 's');
    return 0;
}
