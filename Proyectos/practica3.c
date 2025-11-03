  #include <stdio.h>
  #include <stdlib.h>

  int *capturar_conjunto(int n);
  void imprimir_conjunto(int *conjunto, int n);
  int existe(int *conjunto, int n, int valor);
  int *interseccion(int *A, int *B, int nA, int nB, int *n_inter);

  int main() {
  int n1, n2;
  int *c1, *c2;

  int *c_inter;
  int n_inter = 0;

  printf("Cuantos numeros deseas ingresar para el primer conjunto: ");
  scanf("%d", &n1);
  c1 = capturar_conjunto(n1);

  printf("Cuantos numeros deseas ingresar para el segundo conjunto:
  ");
  scanf("%d", &n2);
  c2 = capturar_conjunto(n2);

  // Calculamos intersección
  c_inter = interseccion(c1, c2, n1, n2, &n_inter);

  // Imprimimos resultados
  printf("\nConjunto A: ");
  imprimir_conjunto(c1, n1);

  printf("\nConjunto B: ");
  imprimir_conjunto(c2, n2);

  printf("\nInterseccion A ∩ B: ");
  imprimir_conjunto(c_inter, n_inter);

  // Liberar memoria
  free(c1);
  free(c2);
  free(c_inter);

  return 0;
  }

  // Captura los elementos de un conjunto
  int *capturar_conjunto(int n) {
  int *conjunto = (int *) malloc(n * sizeof(int));
  if (conjunto == NULL) {
  printf("Error: no se pudo reservar memoria.\n");
  exit(1);
  }

  for (int i = 0; i < n; i++) {
  printf("Ingresa el elemento %d: ", i + 1);
  scanf("%d", &conjunto[i]);
  }

  return conjunto;
  }

  // Imprime un conjunto
  void imprimir_conjunto(int *conjunto, int n) {
  printf("{ ");
  for (int i = 0; i < n; i++) {
  printf("%d ", conjunto[i]);
  }
  printf("}");
  }

  // Verifica si un valor existe dentro de un conjunto
  int existe(int *conjunto, int n, int valor) {
  for (int i = 0; i < n; i++) {
  if (conjunto[i] == valor)
  return 1; // sí existe
  }
  return 0; // no existe
  }

  // Calcula la intersección de dos conjuntos
  int *interseccion(int *A, int *B, int nA, int nB, int *n_inter) {
  int *inter = (int *) malloc((nA + nB) * sizeof(int));
  if (inter == NULL) {
  printf("Error al reservar memoria para la interseccion.\n");
  exit(1);
  }

  *n_inter = 0;

  for (int i = 0; i < nA; i++) {
  if (existe(B, nB, A[i])) { // si A[i] también está en B
  if (!existe(inter, *n_inter, A[i])) { // y no está repetido en inter
  inter[*n_inter] = A[i];
  (*n_inter)++;
  }
  }
  }

  return inter; 
  }
