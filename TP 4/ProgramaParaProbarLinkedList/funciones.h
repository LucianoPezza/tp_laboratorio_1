#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
Employee* employee_newParametrosConvertido(int id,char* nombreStr,int horasTrabajadas, int sueldo);

void employee_delete();

int employee_setIdChar(Employee* this,char* id);
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setHorasTrabajadasChar(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_setSueldoChar(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


int employee_SortBySalary(void* employeeA,void* employeeB);
int employee_SortByhoursWorked(void* employeeA,void* employeeB);
int employee_SortByName(void* employeeA,void* employeeB);
int employee_sortById(void* employeeA,void* employeeB);

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);



#endif // FUNCIONES_H_INCLUDED
