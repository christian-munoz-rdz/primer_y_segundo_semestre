/*
Alumno: Christian Geovany Muñoz Rodríguez
Fecha: 8 de Noviembre del 2021
*/
#include <stdio.h> //Librerías necesarias
#include <stdlib.h>
#include <string.h>
#define MAX 5
//Estructura de los datos del cliente
struct CLIENTE
{
    int codigo_cliente;
    char nombre[50];
    char domicilio[50];
    int telefono[3];
};
//Prototipo de funciones	
void capturar(struct CLIENTE registro_clientes[], int indice,int capturado); //Capturar Datos
void mostrar(struct CLIENTE registro_clientes[],int capturado); //Imprimir datos en pantalla
int buscar(struct CLIENTE registro_clientes[], int codigo_buscar,int capturado, int encontrado); //Mostrar datos que coinsidan con la busqueda
void modificar(struct CLIENTE registro_clientes[]); //Modificar los datos de un cliente
int eliminar(struct CLIENTE registro_clientes[],int capturado); //Eliminar a cliente de la base de datos

void main(int argc, char *argv[]) 
{
	struct CLIENTE registro_clientes[MAX]; //Arreglo de estructuras para registrar clientes
	int opc,capturado=0,indice=0,i,encontrado,modifica,indice_modificado; //Variables locales de control
	int codigo_buscar;
	
	do{
        system("CLS");
		printf("1.Capturar datos de los clientes\n2.Mostrar datos de los clientes\n3.Buscar clientes en la base de datos\n4.Modificar expediente de un cliente\n5.Eliminar clientes de la base de datos\n6.Salir\n"); 
		printf("Selecciona una opcion: "); 
        scanf("%i",&opc); //Menu de opciones
		switch(opc)
		{
		 case 1:
                system("CLS");
                if (capturado==MAX) //Mensaje de alerta sobre base de datos completa
				   		printf("\nYa se lleno la base de datos\n");
				else
					{
						capturar(registro_clientes,indice,capturado); //llamada a la función de capturar
						indice++;
				   		capturado++; //incremento de las variables de control
				   }
                system("PAUSE");
				break;
		 case 2:
                system("CLS");
                if (capturado==0)
		 			{
		 				printf("No se han capturado registros \n"); //Mensaje de alerta por si la base de datos está vacía
                        system("PAUSE");
		 				break;
					 }
		 		mostrar(registro_clientes,capturado); //llamada a la función para imprimir datos en pantalla
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
		 		printf("Ingrese el codigo del cliente que desea buscar: ");
                scanf("%i",&codigo_buscar); //Input del codigo a buscar 
		 		encontrado=0; //Varible de control para definir si hubo coincidencias
		 		encontrado=buscar(registro_clientes,codigo_buscar,capturado,encontrado);
         		if(!encontrado)
				 	printf("\nNo se encontro ninguna coincidencia\n\n"); //Mensaje de alerta en caso de que no haya coincidencias
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
		 		printf("Ingrese el codigo del cliente que desea modificar: "); 
                scanf("%i",&codigo_buscar);
		 		encontrado=0;
		 		encontrado=buscar(registro_clientes,codigo_buscar,capturado,encontrado);
				 if(!encontrado)
				 	printf("\nNo se encontro ninguna coincidencia\n\n");
				else
				{
					modificar(registro_clientes); //llamada a la funcipon que modifica los datos
                    system("CLS");
					printf("Datos actualizados:\n\n"); 
					mostrar(registro_clientes,capturado);//Muestra los datos actualizados
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
		 		printf("Ingrese el codigo del cliente que desea eliminar: "); 
                scanf("%i",&codigo_buscar);
		 		encontrado=0;
		 		encontrado=buscar(registro_clientes,codigo_buscar,capturado,encontrado);
				 if(!encontrado)
				 	printf("No se encontro ninguna coincidencia\n");
				else
				    {
					    capturado=eliminar(registro_clientes,capturado);//Llamada a la funcón para eliminar datos
					    indice=capturado;
                        system("CLS");
					    printf("Datos actualizados:\n\n");
					    mostrar(registro_clientes,capturado);//Muestra los datos actualizados
		 	        }
                system("PAUSE");
		         break;
		 case 6:
                break;
		 default:
                printf("\nOpcion equivocada, selecciona otra vez\n\n");//Eror en caso de opción invalida
                system("PAUSE");
		}
	} while(opc!=6);
	
	system("PAUSE");
}

void capturar(struct CLIENTE registro_clientes[], int indice,int capturado) //Declaracion de la funcion capturar
{
    int i,repetido;//Variables de control
    char agregar;
    do
    { 
        system("CLS");
        repetido=0; //Verifica si existe algun codigo repetido
	    printf("Codigo del cliente: ");	scanf("%i",&registro_clientes[indice].codigo_cliente); //Ingresa el codigo ala base de datos
        for(i=0;i<capturado;i++) //recorre la base de datos para ver si existe algun codigo repetido
        {
            if(indice==i) //omite al codigo que ya fue ingresado
                continue;
            else if(registro_clientes[indice].codigo_cliente==registro_clientes[i].codigo_cliente) //comprara los codigos para ver si estan repetidos
            {
                printf("Ese codigo ya esta registrado... Por favor ingrese otro.\n"); //Mensaje si se da el caso
                repetido = 1; //cambia la variable de control
                system("PAUSE");
                break;
            }
        }
    }while(repetido); //mientras exista algun codigo repetido se repite el proceso

    fflush(stdin);
    printf("Nombre del cliente: "); gets(registro_clientes[indice].nombre); //ingresa nombre
    fflush(stdin);
    printf("Domiciio del cliente: "); gets(registro_clientes[indice].domicilio); //ingresa domicilio
    fflush(stdin);
    for(i=0;i<3;i++) 
    {
        printf("Telefono %i del cliente: ",i+1); scanf("%i",&registro_clientes[indice].telefono[i]); //ciclo para ingresar los tres teefonos del cliente
    }
}

void mostrar(struct CLIENTE registro_clientes[],int capturado) //Imprimir la base de datos
{
	int i,j;
	for(i=0;i<capturado;i++) //ciclo para recorrer la base de datos
    {
		printf("Cliente no.%i:\n\n",i+1); //Imprime numero de cliente
        printf("\tCodigo del cliente: %i\n",registro_clientes[i].codigo_cliente); //Imprime codigo de cliente
        printf("\tNombre del cliente: %s\n",registro_clientes[i].nombre); //Imprime nombre de cliente
        printf("\tDomicilio del cliente: %s\n",registro_clientes[i].domicilio); //Imprime domicilio de cliente
        for(j=0;j<3;j++)
        {
            printf("\tTelefono %i del cliente: %i\n",j+1,registro_clientes[i].telefono[j]); //Imprime telefonos de cliente
        }
    }
    printf("\n");
}

int buscar(struct CLIENTE registro_clientes[], int codigo_buscar,int capturado, int encontrado) //Encontrar coincidencias en la base de datos
{	
	int i;
	for(i=0;i<capturado;i++) //Recorre el arreglo para encontrar coincidencias
	{
		if (codigo_buscar == registro_clientes[i].codigo_cliente) //Si encuentra un codigo que cincida
		{
		 	printf("\n[%i]Se encontro al cliente %i de nombre %s\n\n",i+1,registro_clientes[i].codigo_cliente,registro_clientes[i].nombre); //Imprime este mensaje
		 	encontrado++;
		}
	}
	return encontrado;//Regrresa la variable de control para verificar que hubo coincidencias en el programa principal
}

void modificar(struct CLIENTE registro_clientes[]) //Modificar la base de datos
{
	int indice_modificado,modifica,seguir,i,agregar; //variables de control de la funcion
	printf("\nCual indice deseas modificar: "); 
    scanf("%i",&indice_modificado); 
    do //ciclo para modificar variosdatos de un solo cliente
    {
        system("CLS");
        printf("\nDeseas modificar:\n(1)Codigo\n(2)Nombre\n(3)Domicilio\n(4)Telefonos\n---->"); //Menu de opciones
        scanf("%i",&modifica);
        switch(modifica)
            {
                case 1:
                    printf("\nIntroduce el nuevo codigo del cliente: ");
                    scanf("%i",&registro_clientes[indice_modificado-1].codigo_cliente); //Modificar Codigo
                    break;
                case 2:
                    printf("\nIntroduce el nuevo nombre del cliente: ");
                    fflush(stdin);
                    gets(registro_clientes[indice_modificado-1].nombre); //Modificar Nombre
                    break;
                case 3:
                    printf("\nIntroduce el nuevo domicilio del cliente: ");
                    fflush(stdin);
                    gets(registro_clientes[indice_modificado-1].domicilio); //Modificar Domicilio
                    break;
                case 4:
                    for(i=0;i<3;i++)
                    {
                        printf("Nuevo Telefono %i del cliente: ",i+1); scanf("%i",&registro_clientes[indice_modificado-1].telefono[i]); //Modificar Telefonos
                    }
                    break;
                default:
                    printf("\nOpcion equivocada \n"); //Opcion invalida
            }
        printf("\nDesea hacer otro cambio? (1)Si (0)No ---->"); 
        scanf("%i",&seguir); //Hacer más de un cambio
    }while(seguir);
}

int eliminar(struct CLIENTE registro_clientes[],int capturado)
{
	int indice_modificado,i; //Variables de control de la funcion
	printf("\nCual indice deseas eliminar: ");
	scanf("%i",&indice_modificado); 
	for(i=indice_modificado-1;i<capturado;i++)
		{
            registro_clientes[i]=registro_clientes[i+1]; //Recorre los datos de la base de datos para eliminar al cliente indicado
		}
	return capturado=capturado-1;
}