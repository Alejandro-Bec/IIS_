/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTO 5

struct Contacto {
  char nombre[50];
  char numero[15];
  char correo[30];
  int edad;
}; 

void capturarContacto(struct Contacto lista[], int n);
void imprimeContacto(struct Contacto lista[], int n);

int main(){

  struct Contacto lista[MAX_CONTACTO];
  int n;
  
  printf("Cuantos contactos quieres registrar?: ");
  scanf("%d", &n);
  getchar();
  
  capturarContacto(lista, n);
  imprimeContacto(lista, n);
}

void capturarContacto(struct Contacto lista[], int n){
    
    for(int i = 0; i < n; i++){
      
      printf("=====Contacto %d=====\n", i + 1);
      
      printf("Ingresa el nombre: \n");
      fgets(lista[i].nombre, sizeof(lista[i].nombre), stdin);
      lista[i].nombre[strlen(lista[i].nombre) -1] = '\0';
      
      printf("Ingresa el numero: \n");
      fgets(lista[i].numero, sizeof(lista[i].numero), stdin);
      
      printf("Ingresa el correo: \n");
      fgets(lista[i].correo, sizeof(lista[i].correo), stdin);
      
      printf("Ingresa la edad: \n");
      scanf("%d", &lista[i].edad);
      getchar();
    }
  
}

void imprimeContacto(struct Contacto lista[], int n){
  
  for(int i = 0; i < n; i++){
    
    printf("=====Contacto %d=====\n", i +1);
    printf("Nombre: %s\n", lista[i].nombre);
    printf("Numero: %s\n", lista[i].numero);
    printf("Correo: %s\n", lista[i].correo);
    printf("Edad: %d\n", lista[i].edad);
  }

}

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_CALIF 10

struct Calificacion {
  char materia[30];
  float puntuacion;
  int semestre;
};

struct Estudiante {
  char nombre[50];
  int edad;
  struct Calificacion calificaciones[MAX_CALIF];
  float promedio_general;
};

// Prototipos
struct Estudiante captura_estudiante_calif(int num_calif);
void imprime_estudiante_calif(struct Estudiante est, int num_calif);

int main(){
  struct Estudiante est1;
  int num_calif = 2;
  est1 = captura_estudiante_calif(num_calif);
  imprime_estudiante_calif(est1, num_calif);
}

// Captura los datos de un estudiante y sus calificaciones
struct Estudiante captura_estudiante_calif(int num_calif) {
  
  float total = 0;
  struct Estudiante e;
  printf("nombre del estudiante: ");
  fgets(e.nombre, sizeof(e.nombre), stdin);
  e.nombre[strlen(e.nombre) -1] = '\0'; // quitar salto de línea
  printf("edad: ");
  scanf("%d", &e.edad);
  
  // Capturar calificaciones
  for (int i = 0; i < num_calif; i++) {
  
    printf("\nCalificación #%d\n", i + 1);
    printf("Materia: ");
    // limpiar buffer debido al salto de línea introducido por el último scanf
    getchar();
    fgets(e.calificaciones[i].materia, sizeof(e.calificaciones[i].materia), stdin);
    e.calificaciones[i].materia[strlen(e.calificaciones[i].materia)-1] = '\0';
    
    printf("Puntuación: ");
    scanf("%f", &e.calificaciones[i].puntuacion);
    printf("Semestre: ");
    scanf("%d", &e.calificaciones[i].semestre);
    
    total += e.calificaciones[i].puntuacion; 
  }
  
 total = total / num_calif;
 e.promedio_general =  total;
 
return e;
}

// Imprime los datos de un estudiante y sus calificaciones
void imprime_estudiante_calif(struct Estudiante e, int num_calif) {
  printf("\n===== Datos del Estudiante =====\n");
  printf("Nombre: %s\n", e.nombre);
  printf("Edad: %d\n", e.edad);
  printf("\n--- Calificaciones ---\n");
  for (int i = 0; i < num_calif; i++) {
    printf("\tMateria: %s\n", e.calificaciones[i].materia);
    printf("\t\tPuntuación: %.2f\n", e.calificaciones[i].puntuacion);
    printf("\t\tsemestre: %d\n", e.calificaciones[i].semestre);
    printf("\t\tPromedio general: %.2f\n", e.promedio_general);
  }
}
