#include <stdio.h>
#include <stdlib.h>

float llenarCalificaciones(int n);
void mostrarCalificaciones(float *arr, int n);
float calcularPromedio(float *arr, int n);

int main(){

  int tam;
  float *calificaciones;
  
  printf("Cuantos calificaciones deseas registrar?: ");
  scanf("%d", &tam);
  
  calificaciones = llenarCalificaciones(tam);
  
  free(calificaciones);
  return 0;

}

float llenarCalificaciones(int n){

 float arr = (float *) malloc(n * sizeof(float));
  if(arr == NULL){
    printf("Error: no se pudo reservar memoria.");
    return(1);
  }
  
  for(int i = 0; i < n; i++){
    printf("Ingresa la calificacion del alumno %d:  \n", i + 1);
    scanf("%f", &arr[i]);
  }
} 

