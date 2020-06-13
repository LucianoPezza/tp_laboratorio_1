#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "Validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE*pFile;
    int retorno = -1;

    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
        retorno =0;
    }
    else
    {
        printf("No hay espacio  en memoria para abrir el archivo");
    }
    fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pArchivo = fopen(path, "rb");
    int retorno;
    if(pArchivo == NULL)
    {
        retorno = -1;
        printf("El archivo no se pudo cargar.\n");
        fclose(pArchivo);
        exit(1);

    }
    else
    {
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
        retorno = 1;
    }

    fclose(pArchivo);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSalario;
    int tamanioLista;
    int auxID;
    Employee* auxNewEmployee;

    tamanioLista = ll_len(pArrayListEmployee);
    auxNewEmployee = employee_new();
    if(pArrayListEmployee !=NULL)
    {
        auxID=getInt("Ingrese el id del nuevo empleado: ","Error. Solo ingrese numeros para obtener el id: ");
        for(int i =0; i<tamanioLista; i++)
        {
            auxNewEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            if( auxNewEmployee->id == auxID)
            {
                printf("El id que intenta agregar esta ocupado.\n");
                break;
            }
        }
        if(auxNewEmployee->id != auxID)
        {
            getnombre("ingrese el nombre: \n","Error. Solo letras: ", auxNombre);
            auxSalario = getInt("Ingrese el salario: ", "Error. solo ingrese numeros para obtener el numero: ");
            auxHorasTrabajadas = getInt("Ingrese las horas trabajadas: ","Error. Solo ingrese numeros para obtener las horas trabajadas: ");

            auxNewEmployee = employee_newParametrosConvertido(auxID, auxNombre, auxHorasTrabajadas, auxSalario);
            ll_add(pArrayListEmployee, auxNewEmployee);
        }
    }
    return 1;

}
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char auxNombre[128];
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* auxEmployeeModify;
    int tamanioLista;
    int option;

    tamanioLista = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        auxId = getInt("\nIngrese el id para encontrar el empleado a modificar: \n","Error. Solo numeros: ");

        for(int i=0; i<tamanioLista; i++)
        {
            auxEmployeeModify = (Employee*)ll_get(pArrayListEmployee, i);
            if(auxId==auxEmployeeModify->id)
            {
                system("cls");
                do
                {
                    printf("\n1.Para ingresar el nombre del empleado\n2.Para ingresar las horas trabajadas\n3.Para ingresar el sueldo\n4 Para salir.");
                    option=getInt("Ingrese la opcion: ","Error. solo ingrese numeros para elejir la opcion: ");

                    switch(option)
                    {
                    case 1:
                        system("cls");
                        getnombre("Ingrese el nuevo nombre: \n","Error. Solo puede ingresar letras: ", auxNombre);
                        employee_setNombre(auxEmployeeModify, auxNombre);
                        system("cls");
                        break;
                    case 2:
                        system("cls");
                        auxHorasTrabajadas = getInt("ingrese la cantidad horas trabajadas: \n","Error. Solo ingrese numeros para obtener las horas trabajadas: ");
                        employee_setHorasTrabajadas(auxEmployeeModify, auxHorasTrabajadas);
                        system("cls");
                        break;
                    case 3:
                        system("cls");
                        auxSueldo = getInt("ingrese el salario: \n","Error. Solo ingrese numeros para obtener el salario: ");
                        employee_setSueldo(auxEmployeeModify, auxSueldo);
                        system("cls");
                        break;
                    case 4:
                        option = 4;
                        system("cls");
                        break;
                    default:
                        option = getInt("Ingrese una opcion valida: \n1.Para ingresar el nombre del empleado\n2.Para ingresar las horas trabajadas\n3.Para ingresar el sueldo\n4 Para salir.");
                        break;
                    }
                }
                while(option != 4);
            }
        }
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployeeDELETE;
    int auxId;
    int tamanioLista;
    tamanioLista = ll_len(pArrayListEmployee);
    if(pArrayListEmployee !=NULL)
    {
        auxId = getInt("ingrese ID  a remover","Error. solo ingrese numeros: ");
        for(int i=0; i<tamanioLista; i++)
        {
            auxEmployeeDELETE = (Employee*)ll_get(pArrayListEmployee, i);

            if(auxEmployeeDELETE->id == auxId)
            {
                ll_remove(pArrayListEmployee, i);
                printf("\nEmpleado dado de BAJA.\n");
                employee_delete(auxEmployeeDELETE);
                break;
            }
        }

    }
    return 1;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int auxId;
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSalario;
    int tamanio;
    tamanio = ll_len(pArrayListEmployee);
    if(pArrayListEmployee!=NULL)
    {
        printf(" Id------Nombre-----Horas trabajadas---Sueldo \n");
        for(int i=0; i<tamanio; i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            employee_getId(auxEmployee, &auxId);
            employee_getNombre(auxEmployee,auxNombre);
            employee_getHorasTrabajadas(auxEmployee,&auxHorasTrabajadas);
            employee_getSueldo(auxEmployee,&auxSalario);
            printf("%5d  %15s %15d  %15d\n",auxId, auxNombre, auxHorasTrabajadas, auxSalario);

        }
    }
    else
    {
        printf("Los datos no se pudieron mostrar");
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;
    char optionchar;
    int opcionDescendente;
    if(pArrayListEmployee != NULL)
    {
        option = getInt("Ingrese un numero segun como quiera ordenar: \n1.Ordenar Ascendente\n2.Ordenar Descendente: ");

        switch(option)
        {
        case 1:
            system("cls");
            printf("ASCENDENTE/n/n");
            optionchar = getLetra("Ingrese la opcion para ordenar ascendente las siguientes opciones \na.ID\nb.NOMBRES\nc.HORAS TRABAJADAS\nd.SUELDO: ","Error. Solo use letras: ");
            switch(optionchar)
            {
            case 'a':
                system("cls");
                printf("Esto puede tardar unos segundirijillos...");
                ll_sort(pArrayListEmployee, employee_sortById,1);
                break;
            case 'b':
                system("cls");
                printf("Esto puede tardar unos segundirijillos...");

                ll_sort(pArrayListEmployee, employee_SortByName, 1);
                break;
            case 'c':
                system("cls");
                printf("Esto puede tardar unos segundirijillos...");
                ll_sort(pArrayListEmployee, employee_SortByhoursWorked, 1);
                break;
            case 'd':
                system("cls");
                printf("Esto puede tardar unos segundirijillos...");
                ll_sort(pArrayListEmployee, employee_SortBySalary, 1);
                break;
            default:
                optionchar = getLetra("Error. Reingrese la opcion para ordenar ascendente las siguientes opciones \n.aID\n.bNOMBRES\nc.HORAS TRABAJADAS\nd.SUELDO: ","Error. Solo use letras: ");
                break;
            }
            break;
        case 2:
            system("cls");
            printf("Descendente/n/n");
            opcionDescendente = getInt("Ingrese la opcion para ordenar Descendente las siguientes opciones \n3.ID\n4.NOMBRES\n5.HORAS TRABAJADAS\n6.SUELDO: ","Error. Solo numeros: ");
            switch(opcionDescendente)
            {
            case 3:
                system("cls");
                printf("Esto puede tardar unos segundirijillos...");
                ll_sort(pArrayListEmployee, employee_sortById,0);
                break;
            case 4:
                system("cls");
                printf("Esto puede tardar unos segundirijillos...");
                ll_sort(pArrayListEmployee, employee_SortByName, 0);
                break;
            case 5:
                system("cls");
                printf("Esto puede tardar unos segundirijillos...");
                ll_sort(pArrayListEmployee, employee_SortByhoursWorked, 0);
                break;
            case 6:
                system("cls");
                printf("Esto puede tardar unos segundirijillos...");
                ll_sort(pArrayListEmployee, employee_SortBySalary, 0);
                break;
            default:
                opcionDescendente = getInt("Error. Reingrese la opcion para ordenar Descendente las siguientes opciones \na.ID\nb.NOMBRES\nc.HORAS TRABAJADAS\nd.SUELDO: ","Error. Solo numeros: ");
                break;
            }
            break;
        }
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int listLen = ll_len(pArrayListEmployee);
    Employee* pEmpleadoAux;
    FILE* pArchivo = fopen(path, "w");
    int i;
    if(pArchivo != NULL)
    {

        fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");

        if(pArrayListEmployee!=NULL)
        {
            for(i = 0; i < listLen; i++)
            {
                pEmpleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
                fprintf(pArchivo, "%d,%s,%d,%d\n", pEmpleadoAux->id, pEmpleadoAux->nombre, pEmpleadoAux->horasTrabajadas, pEmpleadoAux->sueldo);
            }
            printf("Archivo guardado con exito\n");
        }
        fclose(pArchivo);
        return 1;
    }
    else
    {
        printf("Error al abrir archivo\n");
        return 0;
    }
    return 1;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployeeSaveBinari;
    FILE*pFile;
    int retorno;
    pFile= fopen(path, "wb");

    int tamanioLista;
    tamanioLista = ll_len(pArrayListEmployee);
    if(pFile == NULL)
    {
        printf("Error al guardar\n");
        retorno = -1;
    }

    if(pArrayListEmployee!=NULL)
    {
        retorno=1;
        for(int i=0; i<tamanioLista; i++)
        {
            auxEmployeeSaveBinari = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(auxEmployeeSaveBinari,sizeof(Employee), 1, pFile);
        }
        printf("\nSe han guardado los cambios.\n");
    }
    fclose(pFile);
    return retorno;

}
