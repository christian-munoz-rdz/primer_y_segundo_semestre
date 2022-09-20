//Alumno: Christian Geovany Muñoz Rodríguez
//Fecha: 22 de noviembre del 2021
#include <stdio.h>

int main()
{
    float matriz[3][3],suma,menor;
    int opc,i,j;
    do{
        printf("Elija una opcion...\n");
        printf("1. Capturar la matriz\n");
        printf("2. Imprimir los elementos de la matriz\n");
        printf("3. Sumar los elementos de la matriz\n");
        printf("4. Mostrar el valor menor de la matriz\n");
        printf("5. Salir\n");
        printf("Seleccion---->");
        scanf("%i",&opc);
        printf("-----------------------------------------------\n\n\n");

        switch(opc)
        {
            case 1:
                printf("CAPTURANDO LOS ELEMENTOS DE LA MATRIZ\n\n\n");
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        printf("Elemento en [%i][%i]: ",i,j);
                        scanf("%f",&matriz[i][j]);
                    }
                }
                printf("\n\n\n");
                printf("-----------------------------------------------\n\n\n");
                break;
            case 2:
                printf("IMPRIMIENDO LOS ELEMENTOS DE LA MATRIZ\n\n\n");
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        printf("\t%.3f",matriz[i][j]);
                        if(j==2)
                        {
                            printf("\n");
                        }
                    }
                }
                printf("\n\n");
                printf("-----------------------------------------------\n\n\n");
                break;
            case 3:
                suma=0;
                printf("SUMANDO LOS ELEMENTOS DE LA MATRIZ\n");
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        printf("Sumando---->\t%.3f+%.3f\n",suma,matriz[i][j]);
                        suma+=matriz[i][j];
                    }
                }
                printf("\n\n");
                printf("Total = %.3f\n\n\n",suma);
                printf("-----------------------------------------------\n\n\n");
                break;
            case 4:
            printf("MOSTRANDO EL ELEMENTO MENOR DE LA MATRIZ\n\n\n");
                menor=matriz[0][0];
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        if(matriz[i][j]<menor)
                            menor=matriz[i][j];
                    }
                }
                printf("El elemento menor de la matriz es %.3f\n\n\n",menor);
                printf("-----------------------------------------------\n\n\n");
                break;
            case 5:
                printf("SALIENDO DEL PROGRAMA...\n\n\n");
                printf("-----------------------------------------------\n\n\n");
                break;
            default:
                printf("INGRESE UNA OPCION VALIDA\n\n\n");
                printf("-----------------------------------------------\n\n\n");
                break;
        }
    }while(opc!=5);
    return 0;
}