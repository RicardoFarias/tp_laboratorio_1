#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
    char seguir='s';
    int opcion=0;
    float resultadodiv;
    int resultado;
    int A=0;
    int B=0;

    while(seguir=='s')
    {
        printf("Elija la opcion deseada:\n");
        printf("1- Ingresar 1er operando %d\n",A);
        printf("2- Ingresar 2do operando %d\n",B);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    printf("Ingrese el valor para el numero A:\n");
                    scanf("%d",&A);
                    printf("El valor ingresado para el numero A es: %d\n",A);
                break;
            case 2:
                    printf("Ingrese el valor para el numero B:\n");
                    scanf("%d",&B);
                    printf("El valor ingresado para el numero B es: %d\n",B);
                break;
            case 3:
                    resultado=suma (A,B);
                    printf("La suma de los numeros da como resultado: %d\n",resultado);
                break;
            case 4:
                resultado=resta (A,B);
                printf("La resta de los numeros da como resultado: %d\n",resultado);
                break;
            case 5:
                  if(B!=0)
                    {
                    resultadodiv=division (A,B);
                    printf("La division de los numeros da como resultado: %.2f\n",resultadodiv);
                    }
                        else
                        {
                        printf("No se puede realizar la division por 0\n");
                        }
                break;
            case 6:
                    resultado=multiplicacion (A,B);
                    printf("La multiplicacion de los numeros da como resultado: %d\n",resultado);
                break;
            case 7:
                    resultado=factorial(A);
                    printf("El factorial de A es: %d\n\n",resultado);
                break;
            case 8:
                    resultado=suma (A,B);
                    printf("La suma es: %d\n",resultado);
                    resultado=resta (A,B);
                    printf("La resta es: %d\n",resultado);
                    resultadodiv=division (A,B);
                    printf("La division es: %.2f\n",resultadodiv);
                    resultado=multiplicacion (A,B);
                    printf("La multiplicacion es: %d\n",resultado);
                    resultado=factorial (A);
                    printf("El factorial de A! es: %d\n\n",resultado);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
}
