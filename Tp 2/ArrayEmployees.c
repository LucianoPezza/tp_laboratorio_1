#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Validaciones.h"
#define LIBRE 1
#define OCUPADO 0

void initEmployees(eEmployee lista[], int tam)
{
    for(int i =0; i< tam; i++)
    {
        lista[i].isEmpty = LIBRE;
    }
}
int addEmployees(int pid, eEmployee lista[], int tam)
{
    int indice = findFreeEmployees(lista, tam);
    int confirmo = 0;

    eEmployee auxNot;

    if(indice == -1)
    {
        printf("Sistema lleno \n");
    }
    else
    {

        auxNot.id = pid;
        getnombre("Ingrese El nombre: ","Error. Solo letras: ", auxNot.name);
        getnombre("Ingrese El Apellido: ","Error. Solo letras: ", auxNot.lastName);
        auxNot.salary = getFloat("Ingrese el salario: ","Error. Solo numeros decimales: ");
        auxNot.sector = getInt("Ingrese el sector: ","Error. Solo numeros enteros: ");
        auxNot.isEmpty = OCUPADO;

        lista[indice] = auxNot;
        confirmo = 1;


        //printf("Ingrese legajo: ");
        //scanf("%d", &legajo);
        //existe = buscarAlumno(legajo, lista, tam);
        /*

            if(existe != -1)
            {
                printf("Ya existe un empleado registrado con ese legajo \n");
            }
            else
            {
            }
        }
        */
    }
    return confirmo;
}
int findFreeEmployees(eEmployee lista[], int tam)
{
    int indice = -1;
    for(int i =0; i< tam; i++)
    {
        if(lista[i].isEmpty == LIBRE)
        {
            indice = i;
        }
    }
    return indice;
}
int findEmployeesById(int id,eEmployee lista[], int tam)
{
    int indice = -1;
    for(int i =0; i< tam; i++)
    {
        if(lista[i].id == id && lista[i].isEmpty == OCUPADO)
        {
            indice = i;
        }
    }
    return indice;
}
void modifyEmployees(eEmployee lista[], int tam)
{
    int id;
    int opcion;
    int indice;
    char auxNombre[51];
    char auxApellido[51];
    int auxSector;
    float auxSalario;
    char follow = 's';
    int auxTipo;

    printEmployees(lista, tam);
    id = getInt("\nIngrese id: ", "Error. Ingrese numeros: ");
    indice =findEmployeesById(id, lista, tam);

    if(indice == -1)
    {
        printf("No hay registro de ningun empleado con ese id\n");
        system("pause");
    }
    else
    {
        do
        {
            opcion = getInt("Elija lo que quiera modificar: \n1.Nombre \n2.Apellido\n3.Salario\n4.Sector \n5. Salida:.","Opcion Erronea, ingrese numeros: ");
            switch(opcion)
            {
            case 1:
                system("cls");
                getnombre("Ingrese el nuevo Nombre: ","Error. Ingrese solo letras: ", auxNombre);
                strcpy(lista[indice].name, auxNombre);
                break;
            case 2:
                system("cls");
                getnombre("Ingrese el nuevo Apellido: ","Error. Ingrese solo letras: ", auxApellido);
                strcpy(lista[indice].lastName, auxApellido);
                break;
            case 3:
                auxSalario = getFloat("Ingrese el nuevo salario: ", "Error. Solo numeros flotantes: ");
                break;
            case 4:
                auxSector = getInt("Ingrese el nuevo sector: ", "Error. Solo numeros enteros: ");
                break;
            case 5:
                follow = 'n';
                break;
            default:
                opcion = getInt("Ingrese una opcion correcta: ","Solo numeros: ");
                break;
            }
        }
        while(follow == 's');
    }
}
void removeEmployee(eEmployee lista[], int tam)
{
    int idX;
    int indice;
    char confirmacion;

    printEmployees(lista, tam);
    idX = getInt("\nIngrese Id: ", "Error. Ingrese numeros: ");
    indice = findEmployeesById(idX, lista, tam);
    if(indice == -1)
    {
        printf("No hay registro de ningun NotBoock con ese id\n");
        system("pause");
    }
    else
    {
        confirmacion = getLetra("Confirma baja? S/N :","Error, Solo letras: ");

        if(confirmacion == 's' || 'S')
        {
            lista[indice].isEmpty = LIBRE;
            printf("Se ha realizado la baja con exito \n\n");

        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }
}
void printEmployee(eEmployee Empleado)
{
   printf("\n%d %8s %8s \t \t %f %12d",Empleado.id, Empleado.name, Empleado.lastName, Empleado.salary, Empleado.sector);
}

int printEmployees(eEmployee lista[], int tam)
{
    printf("%s %10s %10s %15s %18s", "ID", "Nombre", "Apellido", "Salario", "Sector");
    int flag = 0;

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty != 1)
        {
            printEmployee(lista[i]);
            flag = 1;
        }
    }if(flag == 0)
    {
        printf("No hay empleados que listar");
    }

    return flag;
}
void ordenarPorApellidoYSector(eEmployee lista[], int tam)
{
     eEmployee aux;

        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(lista[i].lastName, lista[j].lastName)> 0)
                {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                }
                else if((strcmp(lista[i].lastName, lista[j].lastName) == 0) && (lista[i].sector > lista[j].sector))
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
            }
        }
}
void informar(eEmployee lista[], int tam)
{
    int opcion;
    opcion = getInt("Ingrese opcion a ordenar: \n1.Mostrar empleados ordenados por su apellido y sector\n2.Mostrar empleados por su total, promedio y cantidad de empleados que superan el promedio de los salarios\n: ", "Error. Ingrese solo numeros: ");
    switch(opcion)
    {
    case 1:
        system("cls");
        ordenarPorApellidoYSector(lista, tam);
        printEmployees(lista, tam);
        printf("\n");
        system("pause");

        break;
    case 2:
        system("cls");
        printSalaries(lista, tam);
        system("pause");
        break;
    }
}

void printSalaries(eEmployee lista[], int tam)
{
    int i;
    float SalariosAcumulador = 0;
    float SalariosTotal = 0;
    int SalariosContador = 0;
    int ContadorSalarioMayor = 0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            SalariosAcumulador = SalariosAcumulador + lista[i].salary;
            SalariosContador++;
        }
    }

    SalariosTotal = (SalariosAcumulador) / (SalariosContador);

    for(i=0; i<tam; i++)
    {
        if((lista[i].isEmpty == 0) && (lista[i].salary > SalariosTotal))
        {
            ContadorSalarioMayor++;
        }
    }

    printf("\nTotal de los salarios: %.2f", SalariosAcumulador);
    printf("\nPromedio de los salarios: %.2f", SalariosTotal);
    printf("\nCantidad de empleados que superan el salario promedio: %d\n\n", ContadorSalarioMayor);
}
