#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "funciones.h"
#include "Validaciones.h"


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

Employee* employee_new()
{
    Employee* oneEmployee;

    if(oneEmployee == NULL)
    {
        printf("No se pudo asignar memoria");
    }

    return oneEmployee =(Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
    return employee_newParametrosConvertido(atoi(idStr),nombreStr, atoi(horasTrabajadasStr),atoi(sueldo));
    /*int id;
    int horasTrabajadas;
    int salario;

    Employee* pEmployee;
    pEmployee = employee_new();

    id = atoi(idStr);
    salario = atoi(sueldo);
    horasTrabajadas = atoi(horasTrabajadasStr);


    employee_setId(pEmployee,id);
    employee_setSueldo(pEmployee,salario);
    employee_setHorasTrabajadas(pEmployee,horasTrabajadas);
    employee_setNombre(pEmployee,nombreStr);
    return pEmployee;*/
}

Employee* employee_newParametrosConvertido(int id,char* nombreStr,int horasTrabajadas, int sueldo)
{
    Employee* oneEmployee;
    oneEmployee = employee_new();
    if(oneEmployee !=NULL)
    {
        if(!(employee_setId(oneEmployee, id)
                && employee_setSueldo(oneEmployee, sueldo)
                && employee_setHorasTrabajadas(oneEmployee, horasTrabajadas)
                && employee_setNombre(oneEmployee, nombreStr)))
        {

            free(oneEmployee);
            oneEmployee = NULL;
        }
    }
    return oneEmployee;
}


int employee_setId(Employee* this,int id)
{
int correct;
    if(this!=NULL && id >= 0)
    {
        this->id=id;
        correct = 1;
    }
return correct;
}

int employee_setNombre(Employee* this,char* nombre)
{
int correct;
    if(this!=NULL && nombre !=NULL &&  strlen(nombre) >= 3 && strlen(nombre) < 128)
    {
        strcpy(this->nombre,nombre);
        correct = 1;
    }
return correct;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
int correct;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        correct = 1;
    }
return correct;

}




int employee_setSueldo(Employee* this,int sueldo)
{
int correct;
    if(this!=NULL && sueldo >= 5000 )
    {
     this->sueldo=sueldo;
     correct = 1;
    }
return correct;
}




int employee_getId(Employee* this,int* id)
{
int correct;
    if(this != NULL)
    {
       *id = this->id;
       correct = 1;
    }
return correct;
}




int employee_getNombre(Employee* this,char* nombre)
{
int correct;
    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        correct = 1;
    }
return correct;
}




int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
int correct;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        correct = 1;
    }
return correct;

}




int employee_getSueldo(Employee* this,int* sueldo)
{
int correct;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        correct = 1;
    }
return correct;
}





void employee_delete(Employee*liberar)
{
    if(liberar!=NULL)
    {
        free(liberar);
    }
}

int employee_sortById(void* employeeA,void* employeeB)
{

    int ret;

    if((employeeA != NULL)&&(employeeB !=NULL))
    {
        int auxIntA, auxIntB;
        employee_getId(employeeA,&auxIntA);
        employee_getId(employeeB,&auxIntB);

        if(auxIntA > auxIntB)
        {
            ret = 1;
        }
        else if(auxIntA == auxIntB)
        {
            ret = 0;
        }
        else
        {
            ret = -1;
        }
    }
    return ret;

}

int employee_SortByName(void* employeeA,void* employeeB)
{
    char auxNameA [128], auxNameB [128];
    int ret;

    if((employeeA != NULL)&&(employeeB !=NULL))
    {
        employee_getNombre(employeeA, auxNameA);
        employee_getNombre(employeeB, auxNameB);

        ret = strcmp(auxNameA, auxNameB);

    }
    return ret;

}

int employee_SortByhoursWorked(void* employeeA,void* employeeB)
{


    int ret;

    if((employeeA != NULL)&&(employeeB !=NULL))
    {
        int auxIntA, auxIntB;

        employee_getHorasTrabajadas(employeeA, &auxIntA);
        employee_getHorasTrabajadas(employeeB, &auxIntB);

        if(auxIntA > auxIntB)
        {
            ret = 1;
        }
        else if(auxIntA == auxIntB)
        {
            ret = 0;
        }
        else
        {
            ret = -1;
        }
    }
    return ret;

}

int employee_SortBySalary(void* employeeA,void* employeeB)
{

       int ret;

    if((employeeA != NULL)&&(employeeB !=NULL))
    {
        int auxIntA, auxIntB;

        employee_getSueldo(employeeA, &auxIntA);
        employee_getSueldo(employeeB, &auxIntB);

        if(auxIntA > auxIntB)
        {
            ret = 1;
        }
        else if(auxIntA == auxIntB)
        {
            ret = 0;
        }
        else
        {
            ret = -1;
        }
    }
    return ret;

}

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

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployeeDELETE;
    int auxId;
    int tamanioLista;
    tamanioLista = ll_len(pArrayListEmployee);
    if(pArrayListEmployee !=NULL)
    {
        auxId = getInt("ingrese ID  a remover: ","Error. solo ingrese numeros: ");
        for(int i=0; i<tamanioLista; i++)
        {
            auxEmployeeDELETE = (Employee*)ll_get(pArrayListEmployee, i);

            if(auxEmployeeDELETE->id == auxId)
            {
                ll_remove(pArrayListEmployee, i);
                printf("\nEmpleado dado de BAJA.\n");
            //    employee_delete(auxEmployeeDELETE);
                break;
            }
        }

    }
    return 1;
}
