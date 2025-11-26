#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Contacto {
    char nombre[25];
    char numero[20];
    char correo[30];
    int edad;
};

void capturaContacto(struct Contacto *lista, int n);
void imprimeContacto(struct Contacto *lista, int n);
void filtrarEdad(struct Contacto *lista, int n);
void buscarContacto(struct Contacto *lista, int n);

int main() {

    int n;

    printf("Cuantos contactos quieres agregar?: ");
    scanf("%d", &n);
    getchar();

    struct Contacto *lista = malloc(n * sizeof(struct Contacto));

    capturaContacto(lista, n);

    printf("\n=== LISTA COMPLETA ===\n");
    imprimeContacto(lista, n);

    printf("\n=== CONTACTOS MAYORES DE 18 ===\n");
    filtrarEdad(lista, n);

    printf("\n=== BUSQUEDA DE CONTACTO ===\n");
    buscarContacto(lista, n);

    free(lista);
    return 0;
}

void capturaContacto(struct Contacto *lista, int n) {

    for (int i = 0; i < n; i++) {

        printf("\nIngresa el Nombre: ");
        fgets(lista[i].nombre, 25, stdin);
        lista[i].nombre[strcspn(lista[i].nombre, "\n")] = '\0';

        printf("Ingresa el numero: ");
        scanf("%s", lista[i].numero);

        printf("Ingresa el correo: ");
        scanf("%s", lista[i].correo);

        printf("Ingresa la edad: ");
        scanf("%d", &lista[i].edad);

        getchar(); 
    }
}

void imprimeContacto(struct Contacto *lista, int n) {

    for (int i = 0; i < n; i++) {

        printf("\nContacto %d:\n", i + 1);
        printf("Nombre: %s\n", (lista + i)->nombre);
        printf("Numero: %s\n", (lista + i)->numero);
        printf("Correo: %s\n", (lista + i)->correo);
        printf("Edad: %d\n", (lista + i)->edad);
    }
}

void filtrarEdad(struct Contacto *lista, int n){
  
    int encontrados = 0;

    for (int i = 0; i < n; i++) {

        if (lista[i].edad > 18) {

            printf("\nContacto %d:\n", i + 1);
            printf("Nombre: %s\n", lista[i].nombre);
            printf("Numero: %s\n", lista[i].numero);
            printf("Correo: %s\n", lista[i].correo);
            printf("Edad: %d\n", lista[i].edad);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("\nNo hay contactos mayores de 18.\n");
    }
}

void buscarContacto(struct Contacto *lista, int n){
  
    char busca[25];
  
    printf("Ingresa el nombre a buscar: ");
    scanf("%s", busca);

    int encontrado = 0;
  
    for(int i = 0; i < n; i++){
        if(strcmp(busca, lista[i].nombre) == 0){

            printf("\nContacto encontrado:\n");
            printf("Nombre: %s\n", lista[i].nombre);
            printf("Número: %s\n", lista[i].numero);
            printf("Correo: %s\n", lista[i].correo);
            printf("Edad: %d\n", lista[i].edad);

            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("\nNo existe un contacto con ese nombre.\n");
    }
}

