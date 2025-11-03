#include <stdio.h>
#include <stdlib.h>
void imprime(int *, int );
int main() {
int *arr;
arr[0] = 10;
arr[1] = 20;
// Reserva 5 enteros (sin inicializar)
arr = (int *) realloc(arr[0], 50 * sizeof(int));
if (arr==NULL){
printf ("Error no se pudo reservar la memoria\n");
return -1;
}
imprime(arr, 50);
free(arr); // Libera la memoria
return 0;
}
void imprime(int *datos, int n)
{
for(int i = 0; i < n; i++) {
printf("Valor %d: %d \n", i + 1, *datos);
datos++;
}
}
