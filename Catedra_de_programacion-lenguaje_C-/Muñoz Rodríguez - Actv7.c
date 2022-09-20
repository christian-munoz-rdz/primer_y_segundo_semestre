//Alumno: Christian Geovany Muñoz Rodríguez
//Fecha: 6 de diciembre del 2021
#include <stdio.h>
#include <stdlib.h>

struct ficha_bibliografica
{
	char nombre[50];
	char autor[30];
	char editorial[15];
	int ano;
	int paginas;
}coleccion[5];

struct ficha_bibliografica registrar();
void imprimir(struct ficha_bibliografica libro);

int main() 
{	
	system("CLS");
	int i,opc,registro=0;

	do
	{

		printf("REGISTRO DE UNA COLECCION DE LIBROS\n\n");
		printf("OPCIONES..\n");
		printf("1.-CAPTURAR DATOS\n");
		printf("2.-CONSULTAR DATOS\n");
		printf("3.-SALIR\n\n");
		printf("INGRESE UNA OPCION-->");scanf("%i",&opc);
		switch (opc)
		{
			case 1: 
				system("CLS");
				printf("CAPTURAR DATOS DE LOS LIBROS\n");
				printf("-----------------------------\n");
				for (i=0;i<5;i++)
				{
					printf("REGISTRO DEL LIBRO NO.%i\n",i+1);
					coleccion[i] = registrar();
					printf("-----------------------------\n");
				}
				registro = 1;
				system("PAUSE");			
				break;
			case 2: 
				system("CLS");
				if(!registro)
					printf("POR FAVOR REGISTRE LOS LIBROS PARA PODER CONSULTAR LOS DATOS\n");
				else
				{
					printf("IMPRIMIR LOS DATOS DE LOS LIBROS\n");
					printf("---------------------------------\n");
					for(i=0;i<5;i++)
					{
						printf("LIBRO NO.%i\n",i+1);
						imprimir(coleccion[i]);
						printf("---------------------------\n");
					}
				}
				system("PAUSE");
				break;
			case 3: 
				system("CLS");
				printf("GRACIAS POR USAR EL PROGRAMA\n");
				system("PAUSE");
				break;	
			default:
				system("CLS");
				printf("ERROR, OPCION INVALIDA\n");
				system("PAUSE");
		}
		system("CLS");
	} while(opc!=3);

	return 0;
}

struct ficha_bibliografica registrar()
{
	struct ficha_bibliografica libro;
    printf("Nombre: ");
	fflush(stdin);
	gets(libro.nombre);
	printf("Autor: ");
    fflush(stdin);
	gets(libro.autor);
	printf("Editorial: ");
    fflush(stdin);
	gets(libro.editorial);
	printf("A%co de edicion: ",164);
    scanf("%i",&libro.ano);
	printf("Paginas: ");
    scanf("%i",&libro.paginas);
	return libro;
}

void imprimir(struct ficha_bibliografica libro)
{
	printf("Nombre: %s\n",libro.nombre);
	printf("Autor: %s\n",libro.autor);
	printf("Editorial: %s\n",libro.editorial);
	printf("A%co de edicion: %i\n",164,libro.ano);
	printf("Numero de paginas:%i\n",libro.paginas);
}