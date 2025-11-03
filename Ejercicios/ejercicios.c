/*#include <stdio.h>

  int main() {
      int a = 10, b = 20;
      int *p1, *p2;
      int temp = 0;
      p1 = &a;
      p2 = &b;
      
      // TODO: Hacer que p1 apunte a a y p2 apunte a b
      printf("Antes de la referencia: %p\n", p1);
      printf("Antes de la referencia: %p\n", p2);
      printf("p1 apunta a: %d\n", *p1);
      printf("p2 apunta a: %d\n", *p2);
      
      // TODO: Usando los punteros, intercambiar los valores de a y b
      temp = *p1;
      *p1 = *p2;
      *p2 = temp;
      
      // TODO: Imprimir los valores de a y b después del intercambio
      printf("p1 despues del intercambio: %d\n", *p1);
      printf("p1 despues del intercambio: %d\n", *p2);
            
      return 0;
  } */


/*#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr;
    
    ptr = arr;
    
    // TODO: Hacer que ptr apunte al inicio del array
    printf("ptr apunta al inicio del arreglo %d\n", *ptr);
    
    // TODO: Recorrer el array usando ptr (no usar arr[i])
    for(int i = 0; i < 5; i++){
      printf("ptr apunta a: %d\n", *ptr + i);
    } 
    // TODO: Imprimir cada elemento y su dirección de memoria
    for(int i = 0; i < 5; i++){
      printf("ptr en la posicion [%d]: %d\n y su direccion de memoria: %p\n ",i, *ptr + i, &ptr);
    } 
    
    return 0;
} */

#include <stdio.h>

int main() {
    // TODO: Imprimir el tamaño en bytes de:
    // - int
    int a = 10;
    // - char
    char nombre;
    // - float
    float b = 39.4;
    // - double
    double c = 83.67;
    // - un puntero a int
    int *ptr = &a;
    
    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(char));
    printf("%zu\n", sizeof(float));
    printf("%zu\n", sizeof(double));
    //printf("%zu", sizeof(int *ptr));
    
    int arr[10];
    // TODO: Imprimir el tamaño total de arr y el número de elementos
    
    return 0;
}
