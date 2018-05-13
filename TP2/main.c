#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>
#include <string.h>
#define TAM 20

int main()
{
    EPersona listaPersonas[TAM];
    inicializar(listaPersonas,TAM);
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                altaPersona(listaPersonas,TAM);
                break;
            case 2:
                bajaPersona(listaPersonas,TAM);
                break;
            case 3:
                ordenarPorNombre(listaPersonas,TAM);
                mostrarPersonas(listaPersonas,TAM);
                break;
            case 4:
                calculaEstadistica(listaPersonas,TAM);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

