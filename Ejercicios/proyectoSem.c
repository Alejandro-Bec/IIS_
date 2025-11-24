#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_VENTAS 100

typedef struct {
  
  char nombre[50];
  char producto[50];
  char categoria;
  float costo;
  float venta;
  float ganancia;
  float abonos[15];
  int numAbonos;
  
}Cliente;

void agregar_registroCliente(Cliente lista[], int *total); //cambiarle nombre a Agregar registro de cliente
void buscarCliente(Cliente lista[], int total);
void agregarAbono(Cliente lista[], int *total);


int main(){

  long int cuenta = 112400040414;
  int op;
  int totalClientes = 0;
  Cliente lista[MAX_VENTAS];
  
  printf("\t\t----- SISTEMA DE VENTAS -----\n\n");
  
  printf("Ingresa tu numero de cuenta o numero de socio: \n");
  scanf("%ld", &cuenta);
  getchar();
  
  if(cuenta != 112400040414){
    printf("Error: cuenta no encontada.");
    return 0;
  }
  
  printf("\t\t\t\t BIENVENIDA PATY\n\n");
   while (1) {

        printf("\n¿Qué deseas hacer el día de hoy?\n");
        printf("1. Buscar Cliente\n");
        printf("2. Agregar Cliente\n");
        printf("3. Eliminar Cliente\n");
        printf("4. Salir\n");
        printf("Opción: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
                buscarCliente(lista, totalClientes);
                break;

            case 2:
                agregar_registroCliente(lista, &totalClientes);
                break;

            case 3:
                agregarAbono(lista, &totalClientes); 
                break;

            case 4:
                printf("Saliendo del sistema...\n");
                return 0;   

            default:
                printf("Opción inválida.\n");
        }
    }
}

void agregar_registroCliente(Cliente lista[], int *total){

  int n, abo; 
  float g1,g2,g3;
  int resp, op;
  Cliente c;
  
  if(*total >= 100){
    printf("Error: no puedes agregar mas de 100 clientes.");
  }
  
  printf("Cuantos clientes deseas agregar?: ");
  scanf("%d", &n);
  getchar();
  
  for(int i = 0; i < n; i++){
  
    printf("Ingresa el nombre: ");
    fgets(c.nombre, sizeof(c.nombre), stdin);
    c.nombre[strcspn(c.nombre, "\n")] = '\0';
    
    printf("Ingresa el producto: ");
    fgets(c.producto, sizeof(c.producto), stdin);
    c.producto[strcspn(c.producto, "\n")] = '\0';
    
    printf("Ingresa la categoria (perfumes o zapatos): ");
    scanf("%s", &c.categoria);
    getchar();
    printf("Ingresa el costo del producto (costo en que lo compraste): ");
    scanf("%f", &c.costo);
    printf("\n");
    g1 = (c.costo * 30) / 100;
    g2 = (c.costo * 40) / 100;
    g3 = (c.costo * 50) / 100;
    
    printf("\t\t\t===== SUGERENCIA DE VENTA =====\n");
    
    printf("Tu producto te costo %.2f, si quisieras ganarle el 30 porciento, tu ganancia seria de %.2f.\n", c.costo, g1);
    printf("Tu producto te costo %.2f, si quisieras ganarle el 40 porciento, tu ganancia seria de %.2f.\n", c.costo, g2);
    printf("Tu producto te costo %.2f, si quisieras ganarle el 50 porciento, tu ganancia seria de %.2f.\n", c.costo, g3);
    printf("Si deseas conservar alguna de las opciones digita 1, si deseas ingresar tu precio de venta digita 2: \n");
    scanf("%d", &resp);
    
    if(resp == 1){
      printf("Ingresa la opcion que deseas de ganancia: \n");
      printf("1: Ganancia del 30 porciento.\n");
      printf("2: Ganancia del 40 porciento.\n");
      printf("3: Ganancia del 50 porciento.\n");
      scanf("%d", &op);
      if(op == 1){
          c.venta = c.costo + g1;
          printf("El precio de venta sera de: %.2f.\n", c.venta);
        }else if(op == 2){
          c.venta = c.costo + g2;
          printf("El precio de venta sera de: %.2f.\n", c.venta);
        }else if(op == 3){
          c.venta = c.costo + g3;
          printf("El precio de venta sera de: %.2f.\n", c.venta);
        }
      }else if(resp == 2){
        printf("Ingresa el precio de venta \n");
        scanf("%f", &c.venta);
    }
    printf("Cuantos abonos has recibido?: \n");
    scanf("%d", &abo);
    for(int j = 0; j < abo; j++){
        printf("Cantidad del abono %d: \n", j + 1);
        scanf("%f", &c.abonos[j]);
    }
    lista[*total] = c;
    (*total)++;
    getchar();
  }

}

void buscarCliente(Cliente lista[], int total) {
    
    char busca[25];
  
    printf("Ingresa el nombre a buscar: ");
    scanf("%s", busca);
    
    int encontrado = 0;
  
    for(int i = 0; i < total; i++){
        if(strcmp(busca, lista[i].nombre) == 0){

            printf("\nContacto encontrado:\n");
            printf("Nombre: %s\n", lista[i].nombre);
            printf("Producto: %s\n", lista[i].producto);
            printf("Categoria: %c\n", lista[i].categoria);
            printf("Costo: %.2f\n", lista[i].costo);
            printf("Venta: %.2f\n", lista[i].venta);
            printf("Ganancia: %.2f\n", lista[i].ganancia);
            
            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("\nNo existe un contacto con ese nombre.\n");
    }
 }

void agregarAbono(Cliente lista[], int *total) {
    printf("Funcion eliminar (aún no implementada)\n");
}

