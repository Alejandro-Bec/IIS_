#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

    FILE *fp;

    char nombre[35];
    char direccion[100];
    char email[25];
    int n;

    fp = fopen("estudiantes.txt", "w");

    if(fp == NULL){
        printf("Error: no se pudo abrir el archivo");
        return 1;
    }

    printf("Cuantos estudiantes agregaras?: ");
    scanf("%d", &n);

    fflush(stdin); // Limpia el buffer para fgets (válido en Windows)

    for(int i = 0; i < n; i++){

        printf("\n--- Estudiante %d ---\n", i+1);

        printf("Nombre: ");
        fgets(nombre, sizeof(nombre), stdin);

        printf("Direccion: ");
        fgets(direccion, sizeof(direccion), stdin);

        printf("Correo: ");
        fgets(email, sizeof(email), stdin);

        fprintf(fp, "Nombre: %s", nombre);
        fprintf(fp, "Direccion: %s", direccion);
        fprintf(fp, "Correo: %s\n", email);
        fprintf(fp, "---------------------------\n");
    }

    fclose(fp);

    printf("\nDatos guardados en estudiantes.txt\n");
    return 0;

}
