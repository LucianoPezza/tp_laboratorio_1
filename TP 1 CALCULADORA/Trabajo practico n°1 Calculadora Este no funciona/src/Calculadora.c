/*
 * Calculadora.c
 *
 *  Created on: 8 abr. 2020
 *      Author: Luciano
 */
#include "Calculadora.h"

int sumarNumeros(int numUno, int numDos)
{
    return numUno+numDos;
}
int restarNumeros(int numUno, int numDos)
{
    return numUno-numDos;
}
int dividirNumeros(int numUno, int numDos)
{
    return numUno/numDos;
}
int multiplicarNumeros(int numUno, int numDos)
{
    return numUno*numDos;
}

int factorear(int numero)
{
    int factorial;

    if (numero<0)
    {
        printf("\nIntroduzca un numero mayor o igual a cero para poder factorear\n");
    }
    else if (numero == 0 || numero == 1)
    {
        factorial= 1;
    }
    else
    {
    factorial= numero*factorear(numero-1);
    }

    return factorial;
}
