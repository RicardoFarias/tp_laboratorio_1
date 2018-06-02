#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void iniciarMovie (EMovie movie[]){
int i;
    for(i=0;i<100;i++){
        movie[i].estado=0;
    }
}
int buscarLibre (EMovie movie[]){
int i;
int index=-1;
    for (i=0;i<100;i++){
        if(movie[i].estado==0){
            index=i;
            return index;
        }
    }
return index;
}

int agregarPelicula(EMovie movie[]){
    int index;
    index=buscarLibre(movie);
    if (index!=-1){
        printf("\nIngrese titulo de la pelicula: ");
        scanf("%s",movie[index].titulo);
        printf("\nIngrese el genero: ");
        scanf("%s",movie[index].genero);
        printf("\nIngrese duracion: ");
        scanf("%d",&movie[index].duracion);
        printf("\nIngrese la descricion: ");
        scanf("%s",movie[index].descripcion);
        printf("\nIngrese el puntaje: ");
        scanf("%d",&movie[index].puntaje);
        printf("\nIngrese link de la imagen: ");
        scanf("%s",movie[index].linkImagen);
    }
    else{
        printf("\nNo hay mas lugar");
    }
    FILE *pArch;
	pArch=fopen("bin.dat", "rb");
	if(pArch==NULL)
	{
		pArch= fopen("bin.dat", "wb");
		if(pArch==NULL)
		{
			printf("No se pudo abrir el archivo");
		}
    fflush(stdin);
	fwrite(&movie[index],sizeof(movie),1,pArch);
    fclose(pArch);
    }
}

int buscarTitulo(EMovie movie[]){
int i,index=-1;
char titulo[20];
printf("\nIngrese el titulo de la pelicula que desea borrar:");
fflush(stdin);
scanf("%s",titulo);
for(i=0;i<100;i++){
    if((strcmp(movie[i].titulo,titulo))==0){
        index=i;
        return index;
        break;
    }
}
return index;
}
int borrarPelicula(EMovie movie[]){
int index;
index=buscarTitulo(movie);
    if(index!=-1){
        movie[index].estado=0;
        printf("\nBorrado exitoso");
    }
    else{
        printf("\nNo existe ese titulo");
    }
}

void generarPagina(EMovie movie[]){
    FILE *pHtml;
   char cadena1[300];
   char cadena2[30];
   char cadena3[30];
   char cadena4[25];
   char cadena5[25];
   char cadena6[25];
   char cadena7[20];

   sprintf(cadena1,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='");
   sprintf(cadena2,"alt=''></a><h3><a href='#'>");
   sprintf(cadena3,"</a></h3><ul><li>Género: ");
   sprintf(cadena4,"</li><li>Puntaje: ");
   sprintf(cadena5,"</li><li>Duración: ");
   sprintf(cadena6,"</li></ul><p>");
   sprintf(cadena7,"</p></article>");

   FILE *pArch;
	pArch=fopen("bin.dat", "rb");
	if(pArch==NULL)
	{
	    printf("No se pudo abrir el archivo");
    }

   if((pHtml=fopen("peliculas.html" , "w"))==NULL)
   {
       printf("\nEl archivo no puede ser abierto");
       exit(1);
   }
   else
   {
       rewind(pArch);
       while(!feof(pArch))
       {
       fread(&movie,sizeof(EMovie),1,pArch);
       if(!feof(pArch))
       {
       fprintf(pHtml,cadena1);
       fprintf(pHtml,movie->linkImagen);
       fprintf(pHtml,cadena2);
       fprintf(pHtml,movie->titulo);
       fprintf(pHtml,cadena3);
       fprintf(pHtml,movie->genero);
       fprintf(pHtml,cadena4);
       fprintf(pHtml, "%d", movie->puntaje);
       fprintf(pHtml,cadena5);
       fprintf(pHtml, "%d", movie->duracion);
       fprintf(pHtml,cadena6);
       fprintf(pHtml,movie->descripcion);
       fprintf(pHtml,cadena7);
       }
       }
       printf("\nArchivo generado\n");
   }
    fclose(pHtml);
    fclose(pArch);
}
