//Alumno: Christian Geovany Muñoz Rodríguez
//Fecha: 6 de diciembre del 2021
#include <stdio.h>
#include <stdlib.h>

struct producto
{
	char codigo[20];
	char articulo[20];
	char marca[20];
	float precio;
}inventario[5];

struct producto registrar();
void imprimir(struct producto producto);

int main() 
{	
	system("CLS");
	int i,opc,registro=0;

	do
	{
		printf("REGISTRO DE INVENTARIO DE ABARROTERA\n\n");
		printf("OPCIONES..\n");
		printf("1.-CAPTURAR DATOS\n");
		printf("2.-CONSULTAR DATOS\n");
		printf("3.-SALIR\n\n");
		printf("INGRESE UNA OPCION-->");scanf("%i",&opc);
		switch (opc)
		{
			case 1: 
				system("CLS");
				printf("CAPTURAR DATOS DE LOS PRODUCTOS\n");
				printf("-----------------------------\n");
				for (i=0;i<5;i++)
				{
					printf("PRODUCTO NO.%i DEL INVENTARIO\n",i+1);
					inventario[i] = registrar();
					printf("-----------------------------\n");
				}
				registro = 1;
				system("PAUSE");			
				break;
			case 2: 
				system("CLS");
				if(!registro)
					printf("POR FAVOR REGISTRE LOS PRODUCTOS PARA PODER CONSULTAR LOS DATOS\n");
				else
				{
					printf("IMPRIMIR LOS DATOS DE LOS PRODUCTOS\n");
					printf("---------------------------------\n");
					for(i=0;i<5;i++)
					{
						printf("PRODUCTO NO.%i DEL INVENTARIO\n",i+1);
						imprimir(inventario[i]);
						printf("---------------------------\n");
					}
				}
				system("PAUSE");
				break;
			case 3: 
				system("CLS");
				printf("GRACIAS POR USAR EL PROGRAMA...\n");
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

struct producto registrar()
{
	struct producto producto;
    printf("Codigo: ");
	fflush(stdin);
	gets(producto.codigo);
	printf("Articulo: ");
    fflush(stdin);
	gets(producto.articulo);
	printf("Marca: ");
    fflush(stdin);
	gets(producto.marca);
	printf("Precio: ");
    scanf("%f",&producto.precio);
	return producto;
}

void imprimir(struct producto producto)
{
	printf("Codigo: %s\n",producto.codigo);
	printf("Articulo: %s\n",producto.articulo);
	printf("Marca: %s\n",producto.marca);
	printf("Precio: %.3f\n",producto.precio);
}