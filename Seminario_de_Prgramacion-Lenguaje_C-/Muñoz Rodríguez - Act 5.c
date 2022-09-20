//Alumno: Christian Geovany Muñoz Rodríguez
//Fecha: 18 de noviembre del 2021
#include <stdio.h>

int main()
{
    int matriz[4][4], opc,i,j,aux,contador;
    float promedio;

    do{
        printf("---------------------------------------\n");
        printf("Elija una opcion:\n");
        printf("1. Capturar la matriz\n");
        printf("2. Imprimir en pantalla el contenido de la matriz\n");
        printf("3. Sumar todos los elementos de la matriz\n");
        printf("4. Obtener el promedio de todos los elementos de la matriz\n");
        printf("5. Identificar el valor del elemento menor de todos los elementos de la matriz\n");
        printf("6. Identificar el valor del elemento mayor de todos los elementos de la matriz\n");
        printf("7. Identificar la cantidad de elementos que son iguales al elemento menor\n");
        printf("8. Identificar la cantidad de elementos que son iguales al elemento mayor\n");
        printf("9. Identificar la cantidad de elementos que son mayores al elemento menor\n");
        printf("10. Identificar la cantidad de elementos que son menores al elemento mayor\n");
        printf("11. Sumar cada una de las cuatro filas de la matriz\n");
        printf("12. Sumar cada una de las cuatro columnas de la matriz\n");
        printf("13. Salir\n");
        printf("Seleccion ----->");
        scanf("%i",&opc);
        printf("---------------------------------------\n");
        
        switch(opc)
        {
            case 1:
                printf("CAPTURAR LA MATRIZ\n");

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        printf("Ingrese un dato en el indice [%i][%i]:",i,j);
                        scanf("%i",&matriz[i][j]);
                    }
                }
                break;
            case 2:
                printf("CONTENIDO DE LA MATRIZ\n");

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        printf("%i\t",matriz[i][j]);
                        if(j==3)
                            printf("\n");
                    }
                }
                break;
            case 3:
                aux=0;
                printf("SUMA DE LOS ELEMENTOS DE LA MATRIZ\n");

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        aux+=matriz[i][j];
                    }
                }
                printf("La suma es %i\n",aux);
                break;
            case 4:
                promedio=0;
                printf("PROMEDIO DE LOS ELEMENTOS DE LA MATRIZ\n");

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        promedio+=matriz[i][j];
                    }
                }
                printf("El promedio es %f\n",promedio/16);
                break;
            case 5:
                aux= matriz[0][0];
                printf("ELEMENTO MENOR DE LA MATRIZ\n");

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(matriz[i][j]<aux)
                            aux = matriz[i][j];
                    }
                }
                printf("El elemento menor es %i\n",aux);
                break;
            case 6:
                aux= matriz[0][0];
                printf("ELEMENTO MAYOR DE LA MATRIZ\n");

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(matriz[i][j]>aux)
                            aux = matriz[i][j];
                    }
                }
                printf("El elemento mayor es %i\n",aux);
                break;
            case 7:
                aux= matriz[0][0];
                printf("ELEMENTOS IGUALES AL ELEMENTO MENOR DE LA MATRIZ\n");

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(matriz[i][j]<aux)
                            aux = matriz[i][j];
                    }
                }

                contador=0;
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(matriz[i][j]==aux)
                            contador++;
                    }
                }
            
                printf("Elementos iguales al elemento menor son %i\n",contador);
                break;
            case 8:
                aux= matriz[0][0];
                printf("ELEMENTOS IGUALES AL MAYOR DE LA MATRIZ\n");

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(matriz[i][j]>aux)
                            aux = matriz[i][j];
                    }
                }

                contador=0;
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(matriz[i][j]==aux)
                            contador++;
                    }
                }
            
                printf("Elementos iguales al elemento mayor son %i\n",contador);
                break;
            case 9:
                printf("ELEMENTOS MAYORES AL ELEMENTO MENOR\n");
                aux= matriz[0][0];

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(matriz[i][j]<aux)
                            aux = matriz[i][j];
                    }
                }

                contador = 0;

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(aux<matriz[i][j])
                            contador++;
                    }
                }
                printf("Elementos mayores al elemento menor son %i\n",contador);
                break;
            case 10:
                printf("ELEMENTOS MENORES AL ELEMENTO MAYOR\n");
                aux= matriz[0][0];

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(matriz[i][j]>aux)
                            aux = matriz[i][j];
                    }
                }

                contador = 0;

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(aux>matriz[i][j])
                            contador++;
                    }
                }
                printf("Elementos menores al elemento mayor son %i\n",contador);
                break;
            case 11:
                printf("SUMA DE LAS FILAS DE LA MATRIZ\n");

                for(i=0;i<4;i++)
                {
                    aux=0;
                    for(j=0;j<4;j++)
                    {
                        aux+=matriz[i][j];
                    }
                    printf("La fila %i suma %i\n",i,aux);
                }
                break;
            case 12:
                printf("SUMA DE LAS COLUMNAS DE LA MATRIZ\n");

                for(i=0;i<4;i++)
                {
                    aux=0;
                    for(j=0;j<4;j++)
                    {
                        aux+=matriz[j][i];
                    }
                    printf("La comlumna %i suma %i\n",i,aux);
                }
                break;
            case 13:
                printf("Hasta pronto :)\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }

    }while(opc!=13);

    return 0;

}