#include <stdio.h>
#include <stdlib.h>
#include "calcu.h"

int main()
{

    int NumUno;
    int NumDos;
    int Resultado1;
    int Resultado2;
    int Restulado3;
    int Resultado4;
    int Resultado5;
    int Resultado6;
    int opcion;
    int flag = 0;
    int flag2 = 0;
    char seguir = 's';



    system("cls");

    do
    {
        if(flag == 1 && flag2 == 1)
        {
            printf("Numeros elejidos: %d y %d \n",NumUno, NumDos );
        }
        else
        {
            printf("No se elijieron numeros aun");
        }
        printf("\nElija una opcion: ");
        printf("\n1.Elejir numero 1\n2.Elejir numero 2\n3.Realizar operaciones\n4 Mostrar Resultados\n5 Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("Introduzca un numero: ");
            scanf("%d",& NumUno);
            flag = 1;
            break;
        case 2:
            system("cls");
            if(flag == 1)
            {
                printf("Introduzca un numero: ");
                scanf("%d",& NumDos);
                flag2 = 1;
            }
            else
            {
                printf("Introduzca el numero 1");
            }
            break;
        case 3:
            if(flag == 1 && flag2 ==1)
            {

                Resultado1 = sumarNumeros(NumUno, NumDos);

                Resultado2 = restarNumeros(NumUno, NumDos);

                Restulado3 = dividirNumeros(NumUno, NumDos);

                Resultado4 = multiplicarNumeros(NumUno, NumDos);

                Resultado5 =  factorear(NumUno);

                Resultado6 =  factorear(NumDos);


            }
            else
            {
                printf("No se introdujieron los numeros");
            }
            system("cls");
            break;

        case 4:
            if(flag == 1 && flag2 ==1)
            {
                printf("La suma es: %d\n",Resultado1);
                printf("\n\nLa resta es: %d\n",Resultado2);
                printf("\n\nLa division es: %d\n", Restulado3);
                printf("\n\nLa multiplicacion es: %d\n", Resultado4);
                printf("\nEl factoreo del primer numero es: %d y del segundo: %d\n", Resultado5, Resultado6);
            }
            else
            {
                printf("No se introdujieron los numeros");
            }
            break;
        case 5:
            system("cls");
            seguir = 'n';
            printf("Saliendo...\n");
            break;
        default:
            printf("\nError. Ingrese una opcion valida\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(seguir == 's');
    return 0;


    return 0;
}


