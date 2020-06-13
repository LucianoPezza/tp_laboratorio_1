#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Validaciones.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flagTexto = 0;
    int flagBinario= 0;
    int contadorTexto = 1;
    int contadorBinario = 1;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        printf("\n1.Para cargar los datos por texto\n2.Para cargar los datos por binario\n3 para agregar empleados\n4.Para editar empleados\n5.Para remover empleados\n6.Para mostrar\n7.Para ordenar empleados\n8.Para guardar datos cargados en texto\n9.Para guardar los datos cargados en binario\n10.Salir\n");
        option = getInt("Ingrese una opcion: ","Error. Solo puede ingresar numeros: ");
        switch(option)
        {
        case 1:
            if(flagTexto == 0)
            {
                system("cls");
                controller_loadFromText("data.csv",listaEmpleados);
                flagTexto =1;
                contadorTexto++;
            }if(contadorTexto >1)
            {
                system("cls");
                printf("Los archivos ya han sido cargados\n");
                system("pause");
                system("cls");
            }
            break;
        case 2:
            system("cls");
            if(flagBinario == 0)
            {
                controller_loadFromBinary("data.bin", listaEmpleados);
                system("cls");
                flagBinario = 1;
                contadorBinario++;
            }if(contadorBinario >1)
            {
                printf("Los archivos ya han sido cargados\n");
                system("pause");
                system("cls");
            }
            break;
        case 3:
            if(flagTexto == 1 || flagBinario == 1)
            {
                controller_addEmployee(listaEmpleados);
                system("cls");
            }else
            {
                printf("Primero abra el archivo Binario o archivo de texto\n");
                system("pause");
                system("cls");
            }
            break;
        case 4:
            if(flagTexto == 1 || flagBinario == 1)
            {
            system("cls");
            controller_editEmployee(listaEmpleados);
            }else
            {
                printf("Primero abra el archivo Binario o archivo de texto\n");
                system("pause");
                system("cls");
            }
            break;
        case 5:
            if(flagTexto == 1 || flagBinario == 1)
            {
            system("cls");
            controller_removeEmployee(listaEmpleados);
            system("pause");
            system("cls");
            }else
            {
                printf("Primero abra el archivo Binario o archivo de texto\n");
                system("pause");
                system("cls");
            }
            break;
        case 6:
            if(flagTexto == 1 || flagBinario == 1)
            {
            controller_ListEmployee(listaEmpleados);
            system("pause");
            system("cls");
            }else
            {
                printf("Primero abra el archivo Binario o archivo de texto\n");
                system("pause");
                system("cls");
            }
            break;
        case 7:
            if(flagTexto == 1 || flagBinario == 1)
            {
            system("cls");
            controller_sortEmployee(listaEmpleados);
            system("cls");
            }else
            {
                printf("Primero abra el archivo Binario o archivo de texto\n");
                system("pause");
                system("cls");
            }
            break;
        case 8:
            if(flagTexto == 1)
            {
            controller_saveAsText("data.csv",listaEmpleados);
            system("cls");
            }else
            {
                printf("Primero abra el archivo\n");
                system("pause");
                system("cls");
            }
            break;
        case 9:
            if(flagBinario == 1)
            {
            controller_saveAsBinary("data.bin", listaEmpleados);
            system("pause");
            system("cls");
            }else
            {
                printf("Primero abra el archivo Binario\n");
                system("pause");
                system("cls");
            }
            break;
        default:
            option = getInt("Ingrese una opcion valida: ");
            break;
        }
    }
    while(option != 10);
    return 0;
}
