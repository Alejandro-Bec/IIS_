/*#include <stdlib.h>
#include <stdio.h>

void mayor(int a, int b);

int main(){

    int a, b;

    printf("Ingresa el numero A: ");
    scanf("%d", &a);

    printf("Ingresa el numero B: ");
    scanf("%d", &b);

    mayor(a, b);

}

void mayor(int a, int b){

    if(a > b){
        printf("El numero %d es el mayor", a);
    }else if(a < b){
        printf("El numero %d es el mayor", b);
    }

}
*/

/*#include <stdlib.h>
#include <stdio.h>

void parImpar(int a);

int main(){

    int a;

    printf("Ingresa el numero A: ");
    scanf("%d", &a);

    parImpar(a);

    return 0;
}

void parImpar(int a){

    if(a %2 == 1){
       printf("%d es impar");
    }else{
        printf("%d es par");
    }

}*/

/*#include <stdlib.h>
#include <stdio.h>

void mult(int a);

int main(){

    int a;

    printf("Ingresa un numero: ");
    scanf("%d", &a);

    mult(a);

}

void mult(int a){

    int resultado = a * 2;
    printf("%d x 2 = %d.", a, resultado);
}*/

/*#include <stdlib.h>
#include <stdio.h>

void pares(int a[], int n);

int main(){

    int arr[5] = {2, 3, 7, 9, 8};

    pares(arr, 5);
    

}

void pares(int arr[], int n){

    for(int i = 0; i < n; i++){
        if(arr[i] %2 == 0){
            printf("%d,", arr[i]);
        }
    }
    
}*/

/*#include <stdlib.h>
#include <stdio.h>

void rever(int a[], int n);

int main(){

    int arr[5] = {2, 3, 7, 9, 8};

    rever(arr, 5);
    
    return 0;
}

void rever(int arr[], int n){

    for(int i = 0; i < n; i++){
        int temp = arr[0];
        int fin = n -1;
        int inicio = 0;

        inicio = arr[0];

    }
    
}*/

/*#include <stdlib.h>
#include <stdio.h>


int main(){

    int x = 204;
    int *p = &x;

    printf("%d", *p);


    return 0;
}*/

/*#include <stdlib.h>
#include <stdio.h>

void inter(int *x, int *y);

int main(){

    int x = 204;
    int y = 85;

    printf("%d", *p);

    printf("Valores antes del intercambio: %d, %d", x, y);

    inter(&x, &y);


    return 0;
}

void inter(int *x, int *y){
    int temp = 0;

    temp = *x ;
    *x = *y;
    *y = *x;

    printf("Valores despues del intercambio: %d, %d", x, y);

}*/

#include <stdlib.h>
#include <stdio.h>

void rec(int )
 
int main(){

    int *arr[] = {4,7,98,25,9,124};



    return 0;
}
