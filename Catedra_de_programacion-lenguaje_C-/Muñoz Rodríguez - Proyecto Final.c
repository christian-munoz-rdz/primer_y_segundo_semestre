/*
Alumno: Christian Geovany Muñoz Rodríguez
Fecha: 8 de Noviembre del 2021
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct producto
{
    char articulo[20];
    char marca[50];
    char codigo[20];
    float precio;
    int dsponibilidad;
};
	
void capturar(struct producto inventario[], int indice);
void mostrar(struct producto inventario[],int capturado);
int buscar(struct producto inventario[], char articulo_buscar[20],int capturado, int encontrado);
void modificar(struct producto inventario[]);
int eliminar(struct producto inventario[],int capturado);

void main(int argc, char *argv[]) 
{
	struct producto inventario[MAX];
	int opc,capturado=0,indice=0,i,encontrado,modifica,indice_modificado;
	char articulo_buscar[20];
	
	do{
        system("CLS");
		printf("1.Capturar datos del inventario\n2.Mostrar datos del inventario\n3.Buscar productos en el inventario\n4.Modificar productos del iventario\n5.Eliminar productos del inventario\n6.Salir\n");
		printf("Selecciona una opcion: "); 
        scanf("%i",&opc);
		switch(opc)
		{
		 case 1:
                system("CLS");
                if (capturado==MAX)
				   		printf("\nYa se lleno la base de datos\n");
				else
					{
						capturar(inventario,indice);
						indice++;
				   		capturado++;
				   }
                system("PAUSE");
				break;
		 case 2:
                system("CLS");
                if (capturado==0)
		 			{
		 				printf("No se han capturado registros \n");
                        system("PAUSE");
		 				break;
					 }
		 		mostrar(inventario,capturado);
                system("PAUSE");
				break;
		 case 3:
                system("CLS");
                if (capturado==0)
		 			{
		 				printf("No se han capturado registros \n");
                        system("PAUSE");
		 				break;
					 }
		 		printf("Dame un producto a buscar: "); 
                scanf("%s",&articulo_buscar);
		 		encontrado=0;
		 		encontrado=buscar(inventario,articulo_buscar,capturado,encontrado);
         		if(encontrado==0)
				 	printf("\nNo se encontro ninguna coincidencia\n\n");
                system("PAUSE");
				break;
		 case 4:
                system("CLS");
                if (capturado==0)
		 			{
		 				printf("No se han capturado registros \n");
                        system("PAUSE");
		 				break;
					}
		 		printf("Dame un producto a buscar: "); 
                scanf("%s",&articulo_buscar);
		 		encontrado=0;
		 		encontrado=buscar(inventario,articulo_buscar,capturado,encontrado);
				 if(!encontrado)
				 	printf("\nNo se encontro ninguna coincidencia\n\n");
				else
				{
					modificar(inventario);
                    system("CLS");
					printf("Datos actualizados:\n\n");
					mostrar(inventario,capturado);
				}
                system("PAUSE");
				break;
		 case 5:
                system("CLS");
                if (capturado==0)
		 			{
		 				printf("No se han capturado registros\n");
                        system("PAUSE");
		 				break;
					 }
		 		printf("Dame un producto a eliminar: "); 
                scanf("%s",&articulo_buscar);
		 		encontrado=0;
		 		encontrado=buscar(inventario,articulo_buscar,capturado,encontrado);
				 if(!encontrado)
				 	printf("No se encontro ninguna coincidencia\n");
				else
				    {
					    capturado=eliminar(inventario,capturado);
					    indice=capturado;
                        system("CLS");
					    printf("Datos actualizados:\n\n");
					    mostrar(inventario,capturado);	
		 	        }
                system("PAUSE");
		         break;
		 case 6:
                break;
		 default:
                printf("\nOpcion equivocada, selecciona otra vez\n\n");
                system("PAUSE");
		}
	} while(opc!=6);
	
	system("PAUSE");
}

void capturar(struct producto inventario[], int indice)
{
    fflush(stdin);
	printf("Tipo de prodcuto: ");	gets(inventario[indice].articulo);
    fflush(stdin);
    printf("Marca del producto: "); gets(inventario[indice].marca);
    fflush(stdin);
    printf("Codigo del producto: "); gets(inventario[indice].codigo);
    fflush(stdin);
    printf("Precio del producto: "); scanf("%f",&inventario[indice].precio);
    printf("Disponibilidad del producto en unidades: "); 
    scanf("%i",&inventario[indice].dsponibilidad);
}

void mostrar(struct producto inventario[],int capturado)
{
	int i;
	for(i=0;i<capturado;i++)
    {
		printf("Producto no.%i:\n\n",i+1);
        printf("\tTipo de producto: %s\n",inventario[i].articulo);
        printf("\tMarca del producto: %s\n",inventario[i].marca);
        printf("\tCodigo del producto: %s\n",inventario[i].codigo);
        printf("\tPrecio del producto: %.2f\n",inventario[i].precio);
        printf("\tDisponibilidad del producto: %i unidades\n\n",inventario[i].dsponibilidad);
    }
}

int buscar(struct producto inventario[], char articulo_buscar[20],int capturado, int encontrado)
{	
	int i;
	for(i=0;i<capturado;i++)
		{
		 	if (strcmp(articulo_buscar,inventario[i].articulo)==0)
		 		{
		 			printf("\n[%i]Se encontro %s de la marca %s\n\n",i+1,inventario[i].articulo,inventario[i].marca);
		 			encontrado++;
				}
		}
	return encontrado;	
}

void modificar(struct producto inventario[])
{
	int indice_modificado,modifica,seguir;
	printf("\nCual indice deseas modificar: "); 
    scanf("%i",&indice_modificado);
    do
    {
        system("CLS");
        printf("\nDeseas modificar:\n(1)Articulo\n(2)Marca\n(3)Codigo\n(4)Precio\n(5)Disponibilidad\n---->");
        scanf("%i",&modifica);
        switch(modifica)
            {
                case 1:
                        printf("\nIntroduce el nuevo tipo de producto: ");
                        fflush(stdin);
                    gets(inventario[indice_modificado-1].articulo);
                    break;
                case 2:
                        printf("\nIntroduce la nueva marca: ");
                        fflush(stdin);
                    gets(inventario[indice_modificado-1].marca);
                    break;
                case 3:
                        printf("\nIntroduce el nuevo codigo: ");
                        fflush(stdin);
                    gets(inventario[indice_modificado-1].codigo);
                        break;
                case 4:
                        printf("\nIntroduce el nuevo precio: ");
                    scanf("%f",&inventario[indice_modificado-1].precio);
                        break;
                case 5:
                        printf("\nIntroduce la nueva disponibilidad: ");
                        scanf("%i",&inventario[indice_modificado-1].dsponibilidad);
                        break;
                default:
                    printf("\nOpcion equivocada \n");
            }
        printf("\nDesea hacer otro cambio? (1)Si (0)No ---->"); 
        scanf("%i",&seguir);
    }while(seguir);
}

int eliminar(struct producto inventario[],int capturado)
{
	int indice_modificado,i;
	printf("\nCual indice deseas eliminar: ");
	scanf("%i",&indice_modificado);
	for(i=indice_modificado-1;i<capturado;i++)
		{
            inventario[i]=inventario[i+1];
		}
	return capturado=capturado-1;
}