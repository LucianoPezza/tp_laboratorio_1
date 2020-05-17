#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

void Hardcodear(eEmployee lista[], int tam);
void initEmployees(eEmployee[], int);
int addEmployees(int, eEmployee [], int);
int findFreeEmployees(eEmployee [], int);
int findEmployeesById(int,eEmployee[], int);
void informar(eEmployee[], int);
void ordenarPorApellidoYSector(eEmployee [], int );
void modifyEmployees(eEmployee [], int);
void removeEmployee(eEmployee[], int);
int printEmployees(eEmployee[], int);
void printEmployee(eEmployee);
void printSalaries(eEmployee[], int);

#endif // ARRAYEMPLOYEES_H_INCLUDED

#include "Validaciones.h"
