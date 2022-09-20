//Alumno: Christian Geovany Muñoz Rodríguez
//Fecha: 21 de octubre del 2021
#include <stdio.h>

int main(){

    //Declaración de la variable iterador
    int i;

    printf("M%cltiplos de 3 y 5:\n\n",163);

    //Ciclo repetitivo for. Variable inicializada en 15.
    //condicional termina el ciclo cuando la variable se igual a 45.
    //La variable incrementa en una unidad        
    for(i=15;i<=45;i++)
        //El operador modulo evala si el residuo de dividir la variable entre 3 o 5 es 0 para imprimirla en pantalla                    
        if(i%3==0||i%5==0)
            printf("%i\n",i);

    return 0;
}
