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



/** \brief Inicializa empleados con la variable isempty igualandola a 1(espacio libre)
 *
 * \param eEmpleado lista[] para recorrer lo que tenga en la estructura empleados
 * \param int tam que es el tamanio.
 * \return void
 *
 */
void initEmployees(eEmployee[], int);





/** \brief da de alta un empleado
 *
 * \param int id
 * \param eEmployee estructura
 * \param int tam
 * \return int confirmo, que si es = 1 confirma el alta y caso contrario no se da el alta.
 *
 */
int addEmployees(int, eEmployee [], int);



/** \brief Busca un lugar que no este ocupado
 *
 * \param eEmploye estructura
 * \param int tam tamanio
 * \return indice que me permite confirma si hay un lugar libre.
 *
 */
int findFree(eEmployee [], int);



/** \brief  encuentro un empleado mediante la coincidencia de sus id
 * \param id para comprar con el id de la estructura
 * \param eEmployee estructura
 * \param tam tamanio
 * \return indice que permite saber si se encontro al empelado o no
 *
 */
int findEmployeesById(int,eEmployee[], int);



/** \brief un menu de opciones para elejir que quiero enseñar
 *
 * \param eEmployee estructura
 * \param tam tamanio
 * \return void
 *
 */
void informar(eEmployee[], int);




/** \brief ordena empelados por apellido y sector
 *
 * \param eEmployee estructura
 * \param tam tamanio
 * \return void
 *
 */
void ordenarPorApellidoYSector(eEmployee [], int );





/** \brief Modifica empleados segun la opcion que se elija
 *
 * \param eEmploye estructura
 * \param tam tamanio
 * \return void
 *
 */
void modifyEmployees(eEmployee [], int);





/** \brief Borra al empleado
 *
 * \param eEmployee estructura
 * \param tam tamanio
 * \return void
 *
 */
void removeEmployee(eEmployee[], int);




/** \brief enseña a los empleados
 *
 * \param eEmployee estructura
 * \param tam tamanio
 * \return la bandera que depende su valor me enseña los empleados o no
 *
 */
int printEmployees(eEmployee[], int);






/** \brief Se encarga de cargar los empleados a mostrar para la funcion printEmployees
 *
 * \param eEmployee estructura
 * \return void
 *
 */
void printEmployee(eEmployee);




/** \brief Muestra el salario promedio, el salario maximo y el empleado con mejor salario que el promedio
 *
 * \param eEmployee estructura
 * \param tam tamanio
 * \return void
 *
 */
void printSalaries(eEmployee[], int);

#endif // ARRAYEMPLOYEES_H_INCLUDED

#include "Validaciones.h"
