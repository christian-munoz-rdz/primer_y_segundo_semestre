//Alumno: Christian Geovany Muñoz Rodríguez. Fecha: 22 de septiembre del 2021.

//Llamar a las librerías necesarias y definición de la constante PI
#include <stdio.h>
#include <math.h>
#define PI 3.1416

int main()
{
    //Declaración de variables
    float radio, area;
    //Solicitud de los datos por teclado
    printf("VAMOS A CALCULAR EL AREA DE UN C%cRCULO\n\n",214);
    printf("Ingrese la medida del radio del c%crculo: ",161);
    scanf("%f",&radio);

    //Cálculo del area del círculo
    area = PI * pow(radio,2);

    //Impresión en pantalla de los datos
    printf("\nEl area del c%crculo es: %.4f unidades cuadradas\n\n",161,area);

    system("PAUSE");
    return 0;
}