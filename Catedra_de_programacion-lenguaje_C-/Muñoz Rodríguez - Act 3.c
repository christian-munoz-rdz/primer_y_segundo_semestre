//Alumno: Christian Geovany Muñoz Rodríguez
//Fecha: 23 de octubre del 2021

//Llamar a las librerías
#include <stdio.h>

int main()
{
    //Declaración de variables para clacular la potencia de un número
    float base, exponente,potencia=1;
    //Varible iterador
    int i;

    //Solicitar datos por teclado
    printf("Dame la base: ");
    scanf("%f",&base);
    printf("Dame el exponente: ");
    scanf("%f",&exponente);

    //Calculo de la potencia con sentencia iterativa for    
    for(i=1;i<=exponente;i++)
        //La potencia inicializada en 1 se multiplica por la cantidad de veces ingresadas por el usuario (exponente)        
        potencia*=base;

    //Impresión del resultado en pantalla    
    printf("%.0f^%.0f=%.0f",base,exponente,potencia);

    return 0;
}