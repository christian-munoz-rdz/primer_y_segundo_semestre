//Alumno: Christian Geovany Muñoz Rodríguez
//Fecha: 3 de noviembre del 2021
#include <stdio.h>
#include <string.h> //string.h incluye la funcion memcpy para copiar un arreglo

int main()
{
    //variables
    int opcion; //opcion ingresada por el usuario
    int i,j; //iteradores
    char vector[10],vector_ordenado[10]; //arreglo original y arreglo ordenado(copia)
    char intercambio; //variable temporal utilizada para el ordenamiento

    do
    {
        //Menu
        printf("\n---ORDENAMIENTO DE UN ARREGLO DE CARACTERES---\n");
        printf("Elija una opcion:\n1.-Capturar los datos del arreglo\n2.-Ordenar el arreglo de forma ascendente\n3.-Ordenar el arreglo de forma descendente\n4.-Salir.\nDame una opcion---->");
        scanf("%i",&opcion);
        printf("\n-------------------------------------------------------\n");

        switch(opcion)
        {
            case 1://Captura de Datos

                printf("\n---CAPTURA DE DATOS---\n");
                for(i=0;i<10;i++)
                {
                    printf("Dato %i: ",i+1);
                    scanf("%s",&vector[i]);
                }
                memcpy(vector_ordenado,vector,sizeof(vector)); //copia los valores del arreglo original a uno nuevo para ser ordenados
                printf("\n-------------------------------------------------------\n");
                break;

            case 2://Ordenamiento Ascendente
                printf("\n---ARREGLO CAPTURADO---");
                printf("\n[");
                for(i=0;i<10;i++)
                {
                    printf("%c",vector[i]);
                    if(i<9)
                        printf(",");
                }
                printf("]\n"); //imprime arreglo original

                for(i=1;i<10;i++) //Ordenamiento de burbuja asdcendente
                {
                    for(j=0;j<10-i;j++)
                    {
                        if(vector_ordenado[j]>vector_ordenado[j+1])
                        {
                            intercambio = vector_ordenado[j];
                            vector_ordenado[j]=vector_ordenado[j+1];
                            vector_ordenado[j+1]=intercambio;
                        }    
                    }
                }

                printf("\n---ARREGLO ASCENDENTE---"); //Imprime el arreglo ordenado
                printf("\n[");
                for(i=0;i<10;i++)
                {
                    printf("%c",vector_ordenado[i]);
                    if(i<9)
                        printf(",");
                }
                printf("]\n");
                printf("\n-------------------------------------------------------\n");     
                break;

            case 3://Ordenamiento descendente
                printf("\n---VECTOR CAPTURADO---");
                printf("\n[");
                for(i=0;i<10;i++)
                {
                    printf("%c",vector[i]);
                    if(i<9)
                        printf(",");
                }
                printf("]\n");

                for(i=1;i<10;i++)//Ordenamiento de burbuja descendente
                {
                    for(j=0;j<10-i;j++)
                    {
                        if(vector_ordenado[j]<vector_ordenado[j+1])
                        {
                            intercambio = vector_ordenado[j];
                            vector_ordenado[j]=vector_ordenado[j+1];
                            vector_ordenado[j+1]=intercambio;
                        }    
                    }
                }

                printf("\n\n---VECTOR DESCENDENTE---");
                printf("\n[");
                for(i=0;i<10;i++)
                {
                    printf("%c",vector_ordenado[i]);
                    if(i<9)
                    printf(",");
                }
                printf("]\n");
                printf("\n-------------------------------------------------------\n");
                break;

            case 4://Salir
                printf("Saliendo del programa...");
                printf("\n-------------------------------------------------------\n");
                break;

            default://Mensaje en caso de ingresar valor invalido
                printf("Ingrese una opcion valida");
                printf("\n-------------------------------------------------------\n");
                break;
        }
    }while(opcion!=4);

    return 0;
}