#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    EMovie movie[100];
    iniciarMovie(movie);
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(movie);
                break;
            case 2:
                borrarPelicula(movie);
                break;
            case 3:
                generarPagina(movie);
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
