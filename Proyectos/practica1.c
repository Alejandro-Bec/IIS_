 
#include <stdio.h>
#include <stdlib.h>

void imprimir_Piramide( int alto);
void repetir_Espacios(int cantidad);
void repetir_Simbolo(int cantidad);

int main() {

Introducción a la Ingeniería de Software

10

19 de septiembre de 2025

int a;

printf("Ingresa el alto: ");
scanf("%i", &a);

imprimir_Piramide(a);

return 0;
}
void repetir_Espacios(int cantidad){
for(int i=0; i < cantidad; i++){
printf(" ");
}
}

void repetir_Simbolo(int cantidad){
for(int i = 0; i < cantidad; i++){
printf("*");
}
}

void imprimir_Piramide( int alto ){

Introducción a la Ingeniería de Software

11

19 de septiembre de 2025

int espacios = alto -1;
int ancho = (alto * 2) - 1;

// Para validar que el alto sea mayor que 0
if( alto <= 0 ){
printf("ERROR, ingresa un numero mayor a 0.");
return;
}else if( alto %2 == 0){
alto = alto + 1;
}

//bucle para imprimir el alto de la piramide
for(int i = 1; i <= alto; i++ ) {

//realiza la impresion del lado izquierdo dependiendo de i
repetir_Espacios(alto - i);
//realiza la impresion en el centro de los astersicos
dependiendo del impar

repetir_Simbolo((2 * i)- 1);

//realiza la impresion del lado derecho dependiendo de i
repetir_Espacios(alto - i);
printf("\n");
}
}
