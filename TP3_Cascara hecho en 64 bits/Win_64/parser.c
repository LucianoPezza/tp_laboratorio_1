#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    auxEmployee=employee_new();
    int retorno;
    char auxId[50];
    char auxNombre[128];
    char auxHorasTrabajadas[50];
    char auxSueldo[50];
    int r;

    if(pFile == NULL)
    {
        retorno = -1;
    }
    else
    {
        retorno = 1;
        while(!feof(pFile))
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            if(r == 4)
            {
                auxEmployee = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
                ll_add(pArrayListEmployee, auxEmployee);
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee employeeAux;
    int retorno;
    fread(&employeeAux, sizeof(Employee), 1, pFile);
    if(pFile==NULL)
    {
        retorno = -1;
    }
    else
    {
        retorno =1;
        while(!feof(pFile))
        {
            Employee *employeeNew = employee_new();
            employee_setId(employeeNew,employeeAux.id);
            employee_setHorasTrabajadas(employeeNew,employeeAux.horasTrabajadas);
            employee_setNombre(employeeNew,employeeAux.nombre);
            employee_setSueldo(employeeNew,employeeAux.sueldo);
            ll_add(pArrayListEmployee, employeeNew);
            fread(&employeeAux, sizeof(Employee), 1, pFile);
        }

    }
    return retorno;
}
