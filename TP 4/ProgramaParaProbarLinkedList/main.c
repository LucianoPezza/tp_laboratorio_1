#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "funciones.h"
#include "Validaciones.h"


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        printf("\n1.Para cargar los datos por texto\n2.Para mostrar los empleados\n3. Editar empleados\n4.Borrar empleado(no incluido el borrado espacio-temporal) \n5. para salir\n");
        option = getInt("Ingrese una opcion: ","Error. Solo puede ingresar numeros: ");
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            system("cls");
            break;
        case 2:
            system("cls");
            controller_ListEmployee(listaEmpleados);
            system("pause");
            system("cls");
            break;
        case 3:
            controller_editEmployee(listaEmpleados);
            break;
        case 4:
            system("cls");
            controller_removeEmployee(listaEmpleados);
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != 5);

}
