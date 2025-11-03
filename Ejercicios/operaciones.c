
#include <stdio.h>
void suma(int x, int y, int *z);
void multiplicacion(int x, int y, int *z);
void division( int x, int y, int *f);

int main()
{
int a=10, b=30, c=0, d=0;

suma(a, b, &c);
multiplicacion(a,b,&c);
division(a,b,&d);

printf("la suma es %d", c);
printf("la multiplicacion es %d", c);
printf("la division es %.1f", d);
}

void suma(int x, int y, int *z){
*z=x+y;
}

void multiplicacion(int x, int y, int *z){
*z = x * y;
}

void division( int x, int y, int *f){
*f = (float) x / y;
}

