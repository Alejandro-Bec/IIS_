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
  
}Cliente;

void agregarCliente(Cliente lista[], int *total);
void buscarCliente(Cliente lista[], int total);
void eliminarCliente(Cliente lista[], int *total);


int main(){

  long int cuenta = 112400040414;
  int op;
  int totalClientes = 0;
  Cliente lista[MAX_VENTAS];
  
  printf("\t\t\t----- SISTEMA DE VENTAS -----\n\n");
  
  printf("Ingresa tu numero de cuenta o numero de socio: \n");
  scanf("%ld", &cuenta);
  getchar();
  
  if(cuenta != 112400040414){
    printf("Error: cuenta no encontada.");
    return 0;
  }
  
  printf("\t\t\t BIENVENIDA PATY\n\n");
  printf("Que deseas hacer el dia de hoy?: \n");
  printf("1. Buscar Cliente.\n");
  printf("2. Agregar Cliente.\n");
  printf("3. Eliminar Cliente.\n");
  scanf("%d", &op);
  getchar();
  
 switch(op){
        case 1:
            buscarCliente(lista, totalClientes);
            break;
        case 2:
            agregarCliente(lista, &totalClientes);
            break;
        case 3:
            eliminarCliente(lista, &totalClientes);
            break;
        default:
            printf("Opcion invalida");
    }
}

void agregarCliente(Cliente lista[], int *total){

  int n, abo; 
  Cliente c;
  
  if(*total >= 100){
    printf("Error: no puedes agregar mas de 100 clientes.");
  }
  
  printf("Cuantos clientes deseas agregar?: \n");
  scanf("%d", &n);
  getchar();
  
  for(int i = 0; i < n; i++){
  
    printf("Ingresa el nombre: \n");
    fgets(c.nombre, sizeof(c.nombre), stdin);
    c.nombre[strcspn(c.nombre, "\n")] = '\0';
    
    printf("Ingresa el producto: \n");
    fgets(c.producto, sizeof(c.producto), stdin);
    c.producto[strcspn(c.producto, "\n")] = '\0';
    
    printf("Ingresa la categoria (perfumes o zapatos): \n");
    scanf("%s", &c.categoria);
    getchar();
    printf("Ingresa el costo del producto (costo en que lo compraste): \n");
    scanf("%f", &c.costo);
    printf("Ingresa el precio de venta \n");
    scanf("%f", &c.venta);
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
  return c;
}

void buscarCliente(Cliente lista[], int total) {
    
    int busca = 0;
    
    printf("Nombre de cliente: \n");
    fgets(c.nombre, sizeof(c.nombre), stdin);
    c.nombre[strcspn(c.nombre, "\n")] = '\0';
    
    for(int i = 0; i < lista; i++){
      for(int j = 0; j < total; i -1)
      
    }
}

void eliminarCliente(Cliente lista[], int *total) {
    printf("Funcion eliminar (aún no implementada)\n");
}

