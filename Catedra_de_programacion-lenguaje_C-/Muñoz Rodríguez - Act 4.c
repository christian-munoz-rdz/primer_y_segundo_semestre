//Alumno: Christian Geovany Muñoz Rodríguez
//Fecha: 3 de noviembre del 2021
#include <stdio.h>
#include <string.h> //string.h incluye la funcion memcpy para copiar un vector

int main()
{
    //variables
    int opcion; //opcion ingresada por el usuario
    int i,j; //iteradores
    int vector[10]={},vector_ordenado[10]; //vector original y vector ordenado(copia)
    int intercambio; //variable temporal utilizada para el ordenamiento
    int verificacion_vacio=0; //Si el programa se ejecuta por primera vez y se elige la opcion 2 o 3 reinicia el ciclo

    do
    {
        //Menu
        printf("\n---ORDENAMIENTO DE UN VECTOR---\n");
        printf("Elija una opcion:\n1.-Capturar los datos del vector\n2.-Ordenar el vector de forma ascendente\n3.-Ordenar el vector de forma descendente\n4.-Salir.\nDame una opcion---->");
        scanf("%i",&opcion);
        printf("\n-------------------------------------------------------\n");

        for(i=0;i<10;i++) //verifica que el vector no esté vacío
        {
            verificacion_vacio+=vector[i];
        }

        switch(opcion)
        {
            case 1://Captura de Datos

                printf("\n---CAPTURA DE DATOS---\n");
                for(i=0;i<10;i++)
                {
                    printf("Dato %i: ",i+1);
                    scanf("%i",&vector[i]);
                }
                memcpy(vector_ordenado,vector,sizeof(vector)); //copia los valores del vector original a uno nuevo para ser ordenados
                printf("\n-------------------------------------------------------\n");
                break;

            case 2://Ordenamiento Ascendente
                
                if(!verificacion_vacio) //Si no se han ingresado valores al vector original reinicia el ciclo
                {
                    printf("Aun no ingresado ningun dato al vector...\n-------------------------------------------------------\n");
                    break;
                }

                printf("\n---VECTOR CAPTURADO---");
                printf("\n[");
                for(i=0;i<10;i++)
                {
                    printf("%i",vector[i]);
                    if(i<9)
                        printf(",");
                }
                printf("]\n"); //imprime vector original

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

                printf("\n---VECTOR ASCENDENTE---"); //Imprime el vector ordenado
                printf("\n[");
                for(i=0;i<10;i++)
                {
                    printf("%i",vector_ordenado[i]);
                    if(i<9)
                        printf(",");
                }
                printf("]\n");
                printf("\n-------------------------------------------------------\n");     
                break;

            case 3://Ordenamiento descendente

                if(!verificacion_vacio)
                {
                    printf("Aun no ingresado ningun dato al vector...\n-------------------------------------------------------\n");
                    break;
                }

                printf("\n---VECTOR CAPTURADO---");
                printf("\n[");
                for(i=0;i<10;i++)
                {
                    printf("%i",vector[i]);
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
                    printf("%i",vector_ordenado[i]);
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