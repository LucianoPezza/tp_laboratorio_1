#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Validaciones.h"

int getInt(char mensaje[], char mensajeError[])
{
    char auxiliarChar[20];
    int enteroADevolver;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", auxiliarChar);
    enteroADevolver = atoi(auxiliarChar);

    while(getInti(auxiliarChar)!=1)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%s", auxiliarChar);
        enteroADevolver = atoi(auxiliarChar);
    }


    return enteroADevolver;
}
float getFloat(char mensaje[], char mensajeError[])
{
    char Aux[10];
    float Floatad;

    printf("%s", mensaje);
    scanf("%s", Aux);
    fflush(stdin);
    Floatad = atof(Aux);

    while(Floatad == 0)
    {
        printf("%s", mensajeError);
        scanf("%s", Aux);
        fflush(stdin);
        Floatad = atof(Aux);
    }


    return Floatad;

}
int getInti(char str[])
{
    int retorno = 1;
    for(int i =0; str[i]!='\0'; i++)
    {
        if(str[i]<'0' || str[i]>'9')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getfloati(char str[])
{
    int retorno = 1;
     for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]<'0' || str[i]>'9') && (str[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
}

void getnombre(char mensaje[],char mensajeError[], char input[])
{
    printf("%s", mensaje);
    fflush(stdin);
    gets(input);

    strlwr(input);
    input[0] = toupper(input[0]);
    while(nombresValidos(input)!= 1)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        gets(input);
        input[0] = toupper(input[0]);
    }

}

int letraValida(char letra)
{
    int retorno = 1;
    if(letra <'A' || (letra>'Z' && letra<'a') || letra>'z')
    {
        retorno = 0;
    }
    return retorno;
}
char getLetra(char mensaje[], char mensajeError[])
{
    char letra;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letra);

    while(letraValida(letra)!=1)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%c", &letra);

    }
    return letra;
}
int nombresValidos(char str[])
{
    int retorno = 1;
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]<'A' || (str[i]>'Z' && str[i]<'a') || str[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int getSexo(char mensaje[])
{
    /*char letra;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letra);
    while(!(isalpha(letra)))
    {
        printf("Error. Introduzca solo 1 caracter");
        scanf("%c", &letra);
    }*/
    char sexo;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &sexo);
    sexo = toupper(sexo);
    while(sexo != 'F' && sexo != 'M')
    {
        printf("Error. Introduzca los caracteres validos F/M: ");
        fflush(stdin);
        scanf("%c", &sexo);
        sexo = toupper(sexo);
    }
    return sexo;
}

int getEdad()
{
    int edad;
    edad = getInt("Ingrese edad: ", "Error. Ingrese numeros: ");

    while(edad >= 100 || edad<= 0)
    {
        edad = getInt("Error. Ingrese una edad valida (entre 1 y 99 años): ","Solo numeros");
    }
    return edad;
}
