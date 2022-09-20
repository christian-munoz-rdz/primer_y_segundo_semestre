//Alumno: Christian Geovany Muñoz Rodríguez
//Fecha: 29 de noviembre del 2021

//funciones CON paso de parametros
//CON retorno de valores
#include <stdio.h>
#include <stdlib.h>
//declaración de funciones
float cuadrado(float lado);
float triangulo(float base, float altura);
float rombo(float dMenor, float dMayor);
float trapecio(float bMenor, float bMayor, float altura);

int main(int argc, char *argv[]) {
	//variables locales en el main
	int opc;
	float a,b,c,area;
	do
	{
		printf("1.Area de un cuadrado\n2.Area de un Triangulo\n3.Area de un Rombo\n4.Area de un Trapecio\n5.Salir\n");
		printf("Dame una opcion: ");
		scanf("%i",&opc);
        printf("\n\n\n");
		switch (opc)
			{
			case 1:	printf("AREA DE UN CUADRADO\n\n");
                    printf("Dame el lado: ");
					scanf("%f",&a);
					area=cuadrado(a);//llamada a función
					printf("El area es %f \n\n\n",area); 
					break;
			case 2:	printf("AREA DE UN TRIANGULO\n\n");
                    printf("Dame la base: ");
					scanf("%f",&a);
					printf("Dame la altura: ");
					scanf("%f",&b);
					area=triangulo(b,a);//llamada a función
					printf("El area es %f \n\n\n",area);
					break;
            case 3: printf("AREA DE UN ROMBO\n\n");
                    printf("Dame la diagonal menor: ");
                    scanf("%f",&a);
                    printf("Dame la diagonal mayor: ");
                    scanf("%f",&b);
                    area = rombo(a,b);//llamada a funcion
                    printf("El area es %f \n\n\n",area);
                    break;
            case 4: printf("AREA DE UN TRAPECIO\n\n");
                    printf("Dame la base menor: ");
                    scanf("%f",&a);
                    printf("Dame la base mayor: ");
                    scanf("%f",&b);
                    printf("Dame la altura: ");
                    scanf("%f",&c);
                    area = trapecio(a,b,c);//llamada a funcion
                    printf("El area es %f \n\n\n",area);
                    break;
			case 5:	printf("Gracias por usar el programa...\n\n\n");
					break;
			default: printf("Opcion incorrecta \n\n\n");
			}
	}while(opc!=5);
	return 0;
}

float cuadrado(float lado)
{	
    float a_cuadrado;//variable local
	a_cuadrado=lado*lado;
	return a_cuadrado;//el return devuelve el resultado
}

float triangulo(float base, float altura)	
{	
    float a_triangulo;//variable local
	a_triangulo=base*altura/2;
	return a_triangulo;//el return devuelve el resultado
}

float rombo(float dMenor, float dMayor)
{
    float a_rombo;//variable local
    a_rombo = dMenor*dMayor/2;
    return a_rombo;//el return devuelve el resultado
}

float trapecio(float bMenor, float bMayor, float altura)
{
    float a_trapecio;//variable local
    a_trapecio = (bMenor+bMayor)*(altura/2);
    return a_trapecio;
}
