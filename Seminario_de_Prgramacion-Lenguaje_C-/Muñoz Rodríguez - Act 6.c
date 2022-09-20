//Alumno: Christian Geovany Muñoz Rodríguez
//Fecha: 26 de noviembre del 2021
#include<stdio.h>
#include<stdlib.h>
#define PI 3.1416

void menu();
float circulo(float r,char o);
float triangulo(float b,float h,float la, float lb, char o);
float cuadrado(float l, char o);
float rectangulo(float b,float h, char o);
float rombo(float l,float D,float d, char o);
float trapecio(float B, float b, float h, float l, char o);


int main(){
	
	menu();
	
	return 0;
}

void menu(){
	int opc;
	float a,b,c,d;
	do
		{
			printf("\n1. Area y perimetro de un circulo\n");
			printf("2. Area y perimetro de un triangulo\n");
			printf("3. Area y perimetro de un cuadrado\n");
			printf("4. Area y perimetro de un rectangulo\n");
			printf("5. Area y perimetro de un rombo\n");
			printf("6. Area y perimetro de un trapecio\n");
			printf("7. Salir\n");
			printf("Ingrese una opcion: "); scanf("%i",&opc);
			switch(opc)
				{
					
					case 1: system("CLS"); 
                            printf("Circulo\n"); 
                            printf("Ingrese el radio: "); scanf("%f",&a);
							printf("El area del circulo con radio = %.2f es %.2f\n",a,circulo(a,'a'));
                            printf("El perimetro del circulo con diametro = %.2f es %.2f\n",a*2,circulo(a,'p'));
							system("PAUSE");
							break;
					case 2: system("CLS"); 
                            printf("Triangulo\n"); 
                            printf("Ingrese la base: "); scanf("%f",&a);
							printf("Ingrese la altura: "); scanf("%f",&b);
                            printf("Ingrese la medida del segundo lado: "); scanf("%f",&c);
                            printf("Ingrese la medida del tercer lado: "); scanf("%f",&d);
							printf("El area del triangulo con base = %.2f y altura = %.2f es %.2f\n",a,b,triangulo(a,b,c,d,'a'));
                            printf("El area del triangulo con base = %.2f, lado 2 = %.2f y lado 3 = %.2f es %.2f\n",a,c,d,triangulo(a,b,c,d,'p'));
							system("PAUSE");
							break;
					case 3: system("CLS"); 
                            printf("Cuadrado\n"); 
                            printf("Ingrese el lado: "); scanf("%f",&a);
							printf("El area del cuadrado con lado = %.2f es %.2f\n",a,cuadrado(a,'a'));
                            printf("El perimetro del cuadrado con lado = %.2f es %.2f\n",a,cuadrado(a,'p'));
							system("PAUSE");
							break;
					case 4: system("CLS"); 
                            printf("Rectangulo\n"); 
                            printf("Ingrese la base: "); scanf("%f",&a);
							printf("Ingrese la altura: "); scanf("%f",&b);
							printf("El area del rectangulo con base = %.2f y altura = %.2f es %.2f\n",a,b,rectangulo(a,b,'a'));
                            printf("El perimetro del rectangulo con base = %.2f y altura = %.2f es %.2f\n",a,b,rectangulo(a,b,'p'));
							system("PAUSE");
							break;
					case 5: system("CLS");
                            printf("Rombo\n");
                            printf("Ingrese el lado: "); scanf("%f",&a);
                            printf("Ingrese la diagonal mayor: "); scanf("%f",&b);
                            printf("Ingrese la diagonal menor: "); scanf("%f",&c);
                            printf("El area del rombo con diagonal mayor = %.2f y diagonal menor = %.2f es %.2f\n",b,c,rombo(a,b,c,'a'));
                            printf("El perimetro del rombo con lado = %.2f es %.2f\n",a,rombo(a,b,c,'p'));
                            system("PAUSE");
							break;
					case 6: system("CLS");
                            printf("Trapecio\n");
                            printf("Ingrese la base mayor: "); scanf("%f",&a);
                            printf("Ingrese la base menor: "); scanf("%f",&b);
                            printf("Ingrese la altura: "); scanf("%f",&c);
                            printf("Ingrese la medida de los otros dos lados: "); scanf("%f",&d);
                            printf("El area del trapecio con base mayor = %.2f, base menor = %.2f y altura = %.2f es %.2f\n",a,b,c,trapecio(a,b,c,d,'a'));
                            printf("El perimetro del trapecio con base mayor = %.2f, base menor = %.2f y lados = %.2f es %.2f\n",a,b,d,trapecio(a,b,c,d,'p'));
                            system("PAUSE");
							break;
					case 7: system("CLS");
                            printf("Gracias por usar el programa.\nHasta pronto!\n");
                            system("PAUSE");
                            break;
					default: 
                            printf("ERROR, ingresa una opcion valida\n");  
                            sleep(1);
				}
			system("CLS");
		}while(opc != 7);
}

float circulo(float r,char o)
{
	float area,perimetro;
	area = PI*r*r;
    perimetro = PI * r * 2;

    if(o == 'a') 
	    return area;
    else
        return perimetro;
}

float triangulo(float b,float h,float la, float lb, char o)
{
	float area,perimetro;
	area = (b*h)/2;
    perimetro = b + la + lb;
    
    if(o == 'a') 
	    return area;
    else
        return perimetro;
}

float cuadrado(float l, char o)
{
	float area,perimetro;
	area = l*l;
    perimetro = l*4;
    
    if(o == 'a') 
	    return area;
    else
        return perimetro;
}

float rectangulo(float b,float h, char o)
{
	float area, perimetro;
	area = b*h;
    perimetro = (b*2) + (h*2);

    if(o == 'a') 
	    return area;
    else
        return perimetro;
}

float rombo(float l,float D,float d, char o)
{
    float area, perimetro;
    area = (D * d)/2;
    perimetro = l*4;

    if(o == 'a') 
	    return area;
    else
        return perimetro;
}

float trapecio(float B, float b, float h, float l, char o)
{
    float area, perimetro;
    area = ((B + b) / 2) * h;
    perimetro = (B + b) + (l*2);

    if(o == 'a') 
	    return area;
    else
        return perimetro;
}