//Alumno: Christian Geovany Muñoz Rodríguez Fecha: 21 de septiembre del 2021 
#include <stdio.h>
#include <math.h>
#define PI 3.1416

int main()
{
    //Declaración de variables
    float radio, volumen;

    printf("VAMOS A CALCULAR EL VOLUMEN DE UNA ESFERA\n");
    //Pedir datos por teclado
    printf("\nIngrese el valor del radio de su esfera: ");
    scanf("%f",&radio);

    //Calculo del vlumen de la esfera
    volumen = (4.00/3.00) * PI * pow(radio,3);

    //Mostrar en pantalla los resultados obtenidos
    printf("\nEl volumen de su esfera es: %.3f unidades c%cbicas\n\n",volumen,163);    


    system("PAUSE");
    return 0;
}


