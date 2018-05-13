#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

int obtenerEspacioLibre(EPersona lista[], int tam)
{
    int indice = -1;
    for (int i=0;i<tam;++i){
        if (lista[i].estado == 0){
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarPorDni(int dni,EPersona lista[], int tam)
{
    int indice = -1;
    for (int i = 0 ; i<tam ; ++i){
        if (lista[i].dni == dni && lista[i].estado== 1){
            indice = i;
            break;
        }
    }
    return indice;
}


void inicializar (EPersona lista[],int tam)
{
    int i;
    for (i=0;i<tam;i++){
            lista[i].estado=0;
    }
}


void mostrarPersonas(EPersona lista[], int tam)
{
    int flag = 0 ;
    int i;
    for (i=0;i<tam;i++){
        if(lista[i].estado == 1){
            mostrarPersona(lista[i]);
            flag=1;
        }
    }
    if (flag == 0){
        printf("\nNo hay cargada ninguna persona!!!\n");
    }
}


void mostrarPersona(EPersona unaPersona)
{
    printf(" %s    %d     %d \n", unaPersona.nombre,unaPersona.dni,unaPersona.edad);
}

void altaPersona (EPersona lista[], int tam)
{
    EPersona nuevaPersona;
    int lugar=-1;
    int dni;
    int esta;

    lugar = obtenerEspacioLibre(lista,tam);
    if (lugar == -1){
        printf("El sistema esta lleno\n");
    } else {
        printf("\nIngrese el dni:");
        scanf("%d",&dni);
        esta=buscarPorDni(dni,lista,tam);
            if (esta == -1){
                nuevaPersona.dni=dni;
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(nuevaPersona.nombre);
                printf("Ingrese edad: ");
                scanf("%d", &nuevaPersona.edad);
                nuevaPersona.estado=1;
                lista[lugar]=nuevaPersona;
            }       else {
                        printf("La persona ya esta cargada");
                    }

    }
}


void ordenarPorNombre(EPersona lista[], int tam)
{
    EPersona aux;
     int i;
     int j;
   for(i=0; i<tam-1; i++)
   {
       for(j=i+1; j<tam; j++)
       {
           if(stricmp(lista[i].nombre,lista[j].nombre)>0)
           {
               aux=lista[i];
               lista[i]=lista[j];
               lista[j]=aux;
           }
       }
   }
}


void bajaPersona (EPersona lista[], int tam)
{
    int esta;
    int dni;
    char confirma;
    printf("\nIngrese el dni:");
        scanf("%d",&dni);
    esta=buscarPorDni(dni,lista,tam);
            if (esta == -1){
               printf("\nNo hay ninguna persona cargada con ese dni");
            }
            else {
                mostrarPersona(lista[esta]);
                printf("\nConfirma la baja?: ");
                fflush(stdin);
                confirma = getchar();
                if (confirma == 's'|| confirma == 'S'){
                        lista[esta].estado=0;
                        printf("\nPersona dada de baja \n");
                }

            }

}

void calculaEstadistica (EPersona lista [],int tam)
{
    int cont = 0;
    int cont2 = 0;
    int cont3 = 0;
    for (int i = 0; i<tam;i++){
        if (lista[i].edad < 19 && lista[i].estado==1){
            cont++;
        } else if (lista[i].edad >= 19 && lista[i].edad <= 35 && lista[i].estado==1){
            cont2++;
        } else if (lista[i].edad > 35 && lista[i].estado==1){
            cont3++;
        }
    }
    int mayor=cont;
    if (mayor < cont2){
        mayor=cont2;
    } else if (mayor < cont3){
        mayor=cont3;
    }
    char estadistica [mayor][3];
    for (int i = 0; i<cont ; i++){
        estadistica[i][0]='*';
    }
    for (int i = cont ; i<mayor ; i++){
        estadistica[i][0]= ' ';
    }

    for (int i = 0; i<cont2 ; i++){
        estadistica[i][1]='*';
    }
    for (int i = cont2 ; i<mayor;i++){
        estadistica[i][1]= ' ';
    }

    for (int i = 0; i<cont3 ; i++){
        estadistica[i][2]='*';
    }
    for (int i = cont3 ; i<mayor;i++){
        estadistica[i][2]= ' ';
    }

    for (int i = mayor-1; i>=0 ; i--){
        printf("\n    %c         %c         %c    \n",estadistica[i][0],estadistica[i][1],estadistica[i][2]);
    }
    printf("   <18      19-35     >35   \n");
}

