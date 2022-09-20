//Alumno: Christian Geovany Muñoz Rodríguez Fecha: 21 de septiembre del 2021 
#include <stdio.h>

int main()
{
    //Declaración de variables
    int horas,salario;

    //Ingreso de datos por teclado
    printf("---Bienvenido a la calculadora laboral---\n\n");
    printf("Ingrese las horas que usted trabaj%c en la semana: ",162);
    scanf("%i",&horas);

    //Sentencias selectivas
    if(horas > 0)
    {
        if(horas <= 40)
            salario = 16 * horas;
        if(horas > 40)
            salario = 640 + (horas -40) * 20;
        //Mostrar los resultados en pantalla
        printf("\nSu salario de esta semana es de %i pesos\n\n",salario);
    }
    else
        printf("\nUsted no pudo trabajar una cantidad de horas negativas en la semana\n\n");

    system("PAUSE");
    return 0;    
}