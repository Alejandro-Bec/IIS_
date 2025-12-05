#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_VENTAS 100

typedef struct {
    char nombre[50];
    char producto[50];
    char categoria[15];
    float costo;
    float venta;
    float ganancia;
    float abonos[15];
    int numAbonos;
} Cliente;

void agregar_registroCliente(Cliente *lista[], int *total);
void buscarCliente(Cliente *lista[], int total);
void agregarAbono(Cliente *lista[], int total);


void cargarArchivo(Cliente *lista[], int *total) {
    FILE *fp = fopen("clientes.txt", "r");
    if (fp == NULL) return;

    while (!feof(fp)) {

        Cliente *c = malloc(sizeof(Cliente));

        if (fgets(c->nombre, sizeof(c->nombre), fp) == NULL) {
            free(c);
            break;
        }

        c->nombre[strcspn(c->nombre, "\n")] = '\0';

        fgets(c->producto, sizeof(c->producto), fp);
        c->producto[strcspn(c->producto, "\n")] = '\0';

        fgets(c->categoria, sizeof(c->categoria), fp);
        c->categoria[strcspn(c->categoria, "\n")] = '\0';

        fscanf(fp, "%f\n", &c->costo);
        fscanf(fp, "%f\n", &c->venta);
        fscanf(fp, "%f\n", &c->ganancia);
        fscanf(fp, "%d\n", &c->numAbonos);

        for (int i = 0; i < c->numAbonos; i++)
            fscanf(fp, "%f\n", &c->abonos[i]);

        lista[*total] = c;
        (*total)++;
    }

    fclose(fp);
}


void guardarArchivo(Cliente *lista[], int total) {
    FILE *fp = fopen("clientes.txt", "w");
    if (fp == NULL) {
        printf("Error al guardar archivo.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        Cliente *c = lista[i];
        fprintf(fp, "%s\n", c->nombre);
        fprintf(fp, "%s\n", c->producto);
        fprintf(fp, "%s\n", c->categoria);
        fprintf(fp, "%.2f\n", c->costo);
        fprintf(fp, "%.2f\n", c->venta);
        fprintf(fp, "%.2f\n", c->ganancia);
        fprintf(fp, "%d\n", c->numAbonos);
        for (int j = 0; j < c->numAbonos; j++)
            fprintf(fp, "%.2f\n", c->abonos[j]);
    }

    fclose(fp);
}


int main() {

    long int cuenta = 112400040414;
    int op;
    int totalClientes = 0;

    Cliente **lista = malloc(MAX_VENTAS * sizeof(Cliente*));

    cargarArchivo(lista, &totalClientes);

    printf("\t\t\t----- SISTEMA DE VENTAS -----\n\n");

    printf("Ingresa tu numero de cuenta o numero de socio: ");
    scanf("%ld", &cuenta);
    getchar();

    if (cuenta != 112400040414) {
        printf("Error: cuenta no encontada.\n");
        return 0;
    }

    printf("\n\t\t\t\t BIENVENIDA PATY\n");

    while (1) {

        printf("\n¿Qué deseas hacer el día de hoy?\n");
        printf("-----------------------------------\n");
        printf("1. Buscar Cliente\n");
        printf("2. Agregar Cliente\n");
        printf("3. Agregar ABono\n");
        printf("4. Salir\n");
        printf("-----------------------------------\n");
        printf("Opción: ");
        scanf("%d", &op);
        getchar();

        printf("\n");

        switch (op) {
            case 1:
                buscarCliente(lista, totalClientes);
                break;

            case 2:
                agregar_registroCliente(lista, &totalClientes);
                guardarArchivo(lista, totalClientes);
                break;

            case 3:
                agregarAbono(lista, totalClientes);
                guardarArchivo(lista, totalClientes);
                break;

            case 4:
                printf("Saliendo del sistema...\n");
                guardarArchivo(lista, totalClientes);
                return 0;

            default:
                printf("Opción inválida.\n");
        }
    }
}


void agregar_registroCliente(Cliente *lista[], int *total) {

    int n, abo;
    float g1, g2, g3;
    int resp, op;

    if (*total >= MAX_VENTAS) {
        printf("Error: no puedes agregar mas de 100 clientes.\n");
        return;
    }

    printf("\nCuantos clientes deseas agregar?: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {

        Cliente *c = malloc(sizeof(Cliente));

        printf("\nIngresa el nombre: ");
        fgets(c->nombre, sizeof(c->nombre), stdin);
        c->nombre[strcspn(c->nombre, "\n")] = '\0';

        printf("Ingresa el producto: ");
        fgets(c->producto, sizeof(c->producto), stdin);
        c->producto[strcspn(c->producto, "\n")] = '\0';

        printf("Ingresa la categoria (perfumes o zapatos): ");
        scanf("%s", c->categoria);
        getchar();

        printf("Ingresa el costo del producto (costo en que lo compraste): ");
        scanf("%f", &c->costo);
        printf("\n");

        g1 = (c->costo * 30) / 100;
        g2 = (c->costo * 40) / 100;
        g3 = (c->costo * 50) / 100;

        printf("\t\t\t===== SUGERENCIA DE VENTA =====\n\n");
        printf("Tu producto te costo %.2f, si quisieras ganarle el 30%%, tu ganancia seria de %.2f.\n", c->costo, g1);
        printf("Tu producto te costo %.2f, si quisieras ganarle el 40%%, tu ganancia seria de %.2f.\n", c->costo, g2);
        printf("Tu producto te costo %.2f, si quisieras ganarle el 50%%, tu ganancia seria de %.2f.\n", c->costo, g3);

        printf("\nSi deseas conservar alguna de las opciones digita 1, si deseas ingresar tu precio de venta digita 2: ");
        scanf("%d", &resp);

        if (resp == 1) {

            printf("\nIngresa la opcion que deseas de ganancia:\n");
            printf("1: Ganancia del 30 porciento.\n");
            printf("2: Ganancia del 40 porciento.\n");
            printf("3: Ganancia del 50 porciento.\n");
            scanf("%d", &op);

            if (op == 1) c->venta = c->costo + g1;
            else if (op == 2) c->venta = c->costo + g2;
            else if (op == 3) c->venta = c->costo + g3;

        } else {
            printf("Ingresa el precio de venta: ");
            scanf("%f", &c->venta);
        }

        c->ganancia = c->venta - c->costo;

        printf("\nCuantos abonos has recibido?: ");
        scanf("%d", &abo);

        c->numAbonos = 0;

        for (int j = 0; j < abo && j < 15; j++) {
            printf("Monto de abono %d: ", j + 1);
            scanf("%f", &c->abonos[j]);
            c->numAbonos++;
        }

        lista[*total] = c;
        (*total)++;
        getchar();
    }
}

void buscarCliente(Cliente *lista[], int total) {

    char busca[25];
    float restante;

    printf("\nIngresa el nombre a buscar: ");
    scanf("%s", busca);

    int encontrado = 0;

    for (int i = 0; i < total; i++) {

        if (strstr(lista[i]->nombre, busca) != NULL) {   

            printf("\nContacto encontrado:\n");
            printf("------------------------------\n");
            printf("Nombre: %s\n", lista[i]->nombre);
            printf("Producto: %s\n", lista[i]->producto);
            printf("Categoria: %s\n", lista[i]->categoria);
            printf("Costo: %.2f\n", lista[i]->costo);
            printf("Venta: %.2f\n", lista[i]->venta);
            printf("Ganancia: %.2f\n", lista[i]->ganancia);

            float sumaAbonos = 0;

            if (lista[i]->numAbonos == 0) {
                printf("No tiene abonos.\n");
            } else {
                for (int j = 0; j < lista[i]->numAbonos; j++) {
                    printf("Abono %d: %.2f\n", j + 1, lista[i]->abonos[j]);
                    sumaAbonos += lista[i]->abonos[j];
                }
            }

            restante = lista[i]->venta - sumaAbonos;

            printf("\nRestante de la cuenta total: %.2f\n", restante);
            printf("------------------------------\n");

            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nNo existe un contacto con ese nombre.\n");
    }
}



void agregarAbono(Cliente *lista[], int total) {

    int opcion;
    float monto;

    printf("\n¿A quién deseas agregarle abono?\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < total; i++) {
        printf("%d. %s\n", i + 1, lista[i]->nombre);
    }

    printf("--------------------------------------\n");
    printf("Elige una opción: ");
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > total) {
        printf("Error: opción inválida.\n");
        return;
    }

    Cliente *c = lista[opcion - 1];

    printf("\nMonto del abono: ");
    scanf("%f", &monto);

    c->abonos[c->numAbonos] = monto;
    c->numAbonos++;

    printf("\nAbono agregado correctamente a %s\n", c->nombre);
}

