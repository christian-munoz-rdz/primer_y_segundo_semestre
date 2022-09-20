//Alumno: Christian Geovany Muñoz Rodríguez. Fecha: 22 de septiembre del 2021.

//Llamar a las librerias necesarias
#include <stdio.h>

int main()
{
    //Declaración de variables de entrada y salida
    int opcion;
    float unidadEntrada, unidadSalida;

    //Pide al usuario elegir una opción por teclado
    printf("---CONVERSOR DE DISTANCIAS---\n\n---MENU:\n");
    printf("...Presione 1 para convertir de Pulgadas a Mil%cmetros\n...Presione 2 para convertir de Yardas a Metros\n...Presione 3 para convertir de Millas a Kil%cmetros\n...Elija una opci%cn: ",161,162,162);
    scanf("%i",&opcion);

    //La sentencia selectiva evalua el valor de la opcion (entero) para saber cual bloque de sentencias ejecutar
    //Cada caso incluye un mensaje similar cambiando solo las unidades, lo mismo con la impresión del resultado. El cambio más importante está en el cálculo de la unidad de salida, donde cambia el valor por el que se multiplica 
    switch(opcion)
    {
        case 1:
            printf("\n---Conversor de Pulgadas a Mil%cmetros---\n...Ingrese la cantidad de Pulgadas a convertir: ",161);
            scanf("%f",&unidadEntrada);
            unidadSalida = unidadEntrada * 25.4;
            printf("\n%.4f Pulgadas equivalen a %.4f Mil%cmetros\n\n",unidadEntrada,unidadSalida,161);
            break;
        case 2:
            printf("\n---Conversor de Yardas a Metros---\n...Ingrese la cantidad de Yardas a convertir: ");
            scanf("%f",&unidadEntrada);
            unidadSalida = unidadEntrada * 0.9144;
            printf("\n%.4f Yardas equivalen a %.4f Metros\n\n",unidadEntrada,unidadSalida);
            break;
        case 3:
            printf("\n---Conversor de Millas a Kil%cmetros---\n...Ingrese la cantidad de Millas a convertir: ",162);
            scanf("%f",&unidadEntrada);
            unidadSalida = unidadEntrada * 1.6093;
            printf("\n%.4f Millas equivalen a %.4f Kil%cmetros\n\n",unidadEntrada,unidadSalida,162);
            break;
        default:
            printf("\nIngres%c una opci%cn fuera del men%c\n\n",162,162,163);
    }

    system("PAUSE");
    return 0;
}
