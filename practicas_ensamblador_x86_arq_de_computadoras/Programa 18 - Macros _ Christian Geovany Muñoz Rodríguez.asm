;PROGRAMA 18 - MACROS
;CHRISTIAN GEOVANY MUNOZ RODRIGUEZ
;26 DE OCTUBRE DEL 2021

ORG 0100H

MOV AH, 0               ;CONFIGURACION DE VIDEO
MOV AL, 00H             ;40X25 COLORES
INT 10H

;MACROS

;IMPRIMIR CADENA
IMPRIMIR MACRO MENSAJE
    MOV AH, 09H
    LEA DX, MENSAJE
    INT 21H
ENDM

;INGRESAR CARACTER POR TECLADO
INGRESO MACRO
    MOV AH, 1
    INT 21H
ENDM

;SALTO DE LINEA Y RETORNO DE CARRO
SALTO_LINEA MACRO 
    MOV AH, 0EH
    MOV AL, 10          
    INT 10H
    MOV AH, 0EH         
    MOV AL, 13          
    INT 10H
ENDM

;PROGRAMA PRINCIPAL
IMPRIMIR msje
INGRESO
SUB AL,30H              ;CONVIERTE ASCII A DEC 
MOV BL, AL              ;GUARDA EL DATO EN OTRO REGISTRO
SALTO_LINEA
IMPRIMIR msje2
INGRESO
SUB AL, 30H
MOV CL, AL
SALTO_LINEA
ADD CL,BL               ;SUMA LOS DATOS INGRESADOS
ADD CL, 30H
IMPRIMIR msje3
MOV AH, 0EH             ;IMPRESION DE LA SUMA
MOV AL,CL
INT 10H


RET

msje db "Dame un numero: $"
msje2 db "Dame otro numero: $"
msje3 db "La suma de los numeros es: $"