#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Validaciones.h"

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
