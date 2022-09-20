//Alumno: Christian Geovany Muñoz Rodríguez
//Fecha: 28 de noviembre del 2021
// Actividad: String.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANO 25

int main()
{
   int menu = 1;
   int opc,i,nomb,ape,coincidencia,len,elemento;
   char nombre[5][TAMANO], apellido[5][TAMANO], nombreCompleto[5][TAMANO*2];
   char busqueda[TAMANO],auxiliar[TAMANO];
   do{
        system("cls");
        printf("Menu de Opciones \n\n");
        printf("1. Captura nombres\n");
        printf("2. Captura apellidos\n");
        printf("3. Concatena y muestra la tercera matriz\n");
        printf("4. Busca coincidencias en la tercera matriz\n");
        printf("5. Cuenta caracteres\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 1://Captura de nombres
                getchar();
                printf("\nNOTA: En caso de tener 2 nombres, ingrese solo UN nombre\n\n");
                for(i=0;i<5;i++){
                    printf("Ingrese el nombre en posicion %d: ",i+1);
                    scanf("%[^\n]*c",nombre[i]);
                    getchar();
                    }
                printf("\nPresione enter para continuar...");
                getchar();
                nomb = 1;
                break;
            case 2: //Captura de apellidos
                getchar();
                printf("\nNOTA: ingrese solo UN apellido\n\n");
                for(i=0;i<5;i++){
                    printf("Ingrese el apellido en posicion %d: ",i+1);
                    scanf("%[^\n]*c",apellido[i]);
                    getchar();
                    }
                printf("\nPresione enter para continuar...");
                getchar();
                ape = 1;
                break;
            case 3://Creacion de 3ra matriz
                if (nomb == 1 && ape == 1){
                    for(i=0;i<5;i++){
                        strcpy(auxiliar,nombre[i]); //copia una cadena 
                        strcat(nombre[i]," "); //concatena un espacio en blanco
                        strcpy(nombreCompleto[i],strcat(nombre[i],apellido[i]));
                        printf("Nombre %d: %s\n",i,nombreCompleto[i]);
                        strcpy(nombre[i],auxiliar);
                    }
                }else
                    printf("ERROR: Ingrese nombre y apellidos primero\n");
                printf("\nPresione enter para continuar...");
                getchar();
                getchar();
                break;
            case 4://Busqueda en la matriz
                coincidencia = 0;
                printf("\nNOTA:Ingrese solo UNA palabra en su busqueda\n\n");
                printf("Ingrese una palabra a buscar: ");
                scanf("%s",busqueda);
                for(i=0;i<5;i++){
                    if (strcmp(nombre[i],busqueda)== 0){ // compara dos cadenas de caracteres
                        printf("Si se encontro la busqueda en: \n");
                        printf("%s\n\n",nombreCompleto[i]);
                        coincidencia++;
                    } else if(strcmp(apellido[i],busqueda)== 0){ // compara dos cadenas de caracteres
                        printf("Si se encontro la busqueda en: \n");
                        printf("%s\n\n",nombreCompleto[i]);
                        coincidencia++;
                    }
                }
                if (coincidencia == 0)
                    printf("No se encontraron coincidencias\n");
                else
                    printf("Se encontraron: %d coincidencias",coincidencia);
                printf("Presione enter para continuar...");
                getchar();
                getchar();
                break;
            case 5://Busqueda de Nombre con mas caracteres
                len = 0;
                elemento = 0;
                for(i=0;i<5;i++){
                    if((int)(strlen(nombreCompleto[i])) > len){ //mide o cuenta la cantidad de caracteres de una cadena de caracteres
                        len = strlen(nombreCompleto[i]);
                        elemento = i;
                    }
                }
                printf("\nNombre con mas caracteres: %s\n",nombreCompleto[elemento]);
                printf("Longitud: %d\n",len);
                printf("\nPresione enter para continuar...");
                getchar();
                getchar();
                break;
            case 6: //Salida del programa
                printf("\nAdios!!!\n");
                menu = 0;
                break;
            default: //Opcion Invalida
                printf("\nERROR: Opcion Invalida\n\n");
                printf("Presione enter para continuar...");
                getchar();
                getchar();
                break;
        }

   }while(menu == 1);

    return 0;
}