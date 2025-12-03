#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    long int codigo;
    char nombre[50];
    float precio;
    int existencias;
} Productos;

void agregarProd(Productos **lista, int *totalProd);
void buscarProd(Productos *lista, int totalProd);
void actualizarExist(Productos *lista, int totalProd);
void bajaExist(Productos *lista, int totalProd);

int main() {

    Productos *lista = NULL;  
    int totalProd = 0;
    int opc;

    do {
        printf("\t\t-------SISTEMA DE VENTAS-------\n");
        printf("Que deseas hacer el dia de hoy?: \n");
        printf("1. Agregar producto.\n");
        printf("2. Buscar Producto.\n");
        printf("3. Actualizar existencias.\n");
        printf("4. Mostrar productos con baja existencia.\n");
        printf("5. Salir.\n");
        printf("\t\t---------------------------------------\n");
        printf("Opcion: ");
        scanf("%d", &opc);
        getchar(); // limpia buffer

        switch(opc){

            case 1:
                agregarProd(&lista, &totalProd);
                break;

            case 2:
                buscarProd(lista, totalProd);
                break;

            case 3:
                actualizarExist(lista, totalProd);
                break;

            case 4:
                bajaExist(lista, totalProd);
                break;

            case 5:
                printf("\nSaliendo del sistema...\n");
                break;

            default:
                printf("Opcion no valida.\n");
                break;
        }

    } while(opc != 5);

    free(lista);
    return 0;
}



void agregarProd(Productos **lista, int *totalProd) {

    int n;

    printf("Cuantos productos deseas agregar?: ");
    scanf("%d", &n);
    getchar();

    // Ampliamos la lista
    *lista = realloc(*lista, (*totalProd + n) * sizeof(Productos));

    for(int i = 0; i < n; i++){

        int idx = *totalProd + i;

        printf("\n--- Producto %d ---\n", idx + 1);

        printf("Codigo del producto: ");
        scanf("%li", &(*lista)[idx].codigo);
        getchar();

        printf("Nombre: ");
        fgets((*lista)[idx].nombre, 50, stdin);
        (*lista)[idx].nombre[strcspn((*lista)[idx].nombre, "\n")] = '\0';

        printf("Precio: ");
        scanf("%f", &(*lista)[idx].precio);

        printf("Numero de existencias: ");
        scanf("%d", &(*lista)[idx].existencias);
        getchar();
    }

    *totalProd += n;
}


void buscarProd(Productos *lista, int totalProd){

    long int busca;

    printf("Ingresa el codigo del producto a buscar: ");
    scanf("%li", &busca);

    int encontrado = 0;

    for(int i = 0; i < totalProd; i++){
        if(busca == lista[i].codigo){

            printf("\nContacto encontrado:\n");
            printf("Nombre: %s\n", lista[i].nombre);
            printf("Precio: %.2f\n", lista[i].precio);
            printf("Existencias: %d\n", lista[i].existencias);

            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("\nProducto no encontrado.\n");
    }
}


void actualizarExist(Productos *lista, int totalProd){

    long int busca;
    int nuevas;

    printf("Ingresa el codigo del producto: ");
    scanf("%li", &busca);

    for(int i = 0; i < totalProd; i++){
        if(busca == lista[i].codigo){

            printf("Existencias actuales: %d\n", lista[i].existencias);
            printf("Ingresa la nueva cantidad: ");
            scanf("%d", &nuevas);

            lista[i].existencias = nuevas;

            printf("Actualizado correctamente.\n");
            return;
        }
    }

    printf("\nProducto no encontrado.\n");
}


void bajaExist(Productos lista[], int totalProd) {

    int encontrado = 0;

    printf("\nProductos con baja existencia (menos de 5):\n");

    for(int i = 0; i < totalProd; i++){

        if(lista[i].existencias < 5){

            printf("\nProducto encontrado:\n");
            printf("Nombre: %s\n", lista[i].nombre);
            printf("Existencias: %d\n", lista[i].existencias);

            encontrado = 1;
        }
    }

    if(!encontrado){
        printf("\nNo hay productos con baja existencia.\n");
    }
}
