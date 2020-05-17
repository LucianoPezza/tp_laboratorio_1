#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "ArrayEmployees.h"
#define TAM 14
#define HARD 4

int main()
{
    int opcion;
    char seguis = 's';
    int idget = 1000;
    int flag =0;
    eEmployee unEmpleado[TAM];

    initEmployees(unEmpleado, TAM);

    do
    {
        printf("********************Primer Parcial********************\n");
        opcion = getInt("Ingrese una opcion \n1.Alta\n2.Modificacion\n3.Baja\n4.Informar \n5. Salir\n Elija:","Ingrese solo numeros: ");
        switch(opcion)
        {
        case 1:
            if(flag == 0)
            {
                system("cls");
                if(addEmployees(idget, unEmpleado, TAM))
                {
                    idget ++;
                }
                flag =1;
            }
            break;
        case 2:
            if(flag ==1)
            {
                system("cls");
                modifyEmployees(unEmpleado, TAM);

            }
            else
            {
                printf("Primero de de alta un empleado\n");
                system("pause");
            }
            break;
        case 3:
            if(flag ==1)
            {
                system("cls");
                removeEmployee(unEmpleado, TAM);
            }
            else
            {
                printf("Primero de de alta un empleado\n");
                system("pause");
            }
            break;
        case 4:
            if(flag ==1)
            {
                system("cls");
                informar(unEmpleado,TAM);
                printf("\n");
            }else
            {
                printf("Primero de de alta un empleado\n");
                system("pause");
            }
            break;
        case 5:
            seguis = 'n';
            break;
        default:
            opcion = getInt("Ingrese una opcion correca: ", "Solo numeros: ");
            break;
        }
        system("cls");
    }
    while(seguis == 's');
    return 0;
}
