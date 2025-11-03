 
 #include <stdio.h>
#include <string.h>

void capturar_cadena(char cadena[], int max);
void invertir_cadena(char cadena[]);

int main() {
// Definimos el tamaño máximo del arreglo
int MAX = 100;

// Declaramos el arreglo (cadena de caracteres)
char cadena[MAX];


// Llamamos a la función para capturar la cadena
capturar_cadena(cadena, MAX);

// Llamamos a la función para invertir la cadena
invertir_cadena(cadena);

// Mostramos la cadena invertida
printf("\nCadena invertida: %s\n", cadena);

return 0;
}

void capturar_cadena(char cadena[], int max) {
printf("Ingresa una palabra o frase (max %d caracteres): ",
max - 1);
fgets(cadena, max, stdin); // Lee hasta max-1 caracteres
cadena[strcspn(cadena, "\n")] = '\0'; // Elimina el salto de
línea si existe
}

void invertir_cadena(char cadena[]) {
int inicio = 0;


int fin = strlen(cadena) - 1; // Última posición válida
char temp;

// Intercambia los caracteres desde los extremos hacia el
centro
while (inicio < fin) {
temp = cadena[inicio];
cadena[inicio] = cadena[fin];
cadena[fin] = temp;

inicio++;
fin--;
}
}
