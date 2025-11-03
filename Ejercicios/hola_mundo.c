#include <stdio.h>

int main (){

printf("Hola mundo");

}

#include <stdio.h>
void suma(int, int, int *);
int main()
{
int a=10, b=30, c=0;
suma(a, b, &c);
printf("la suma es %d", c);
}
void suma(int x, int y, int *z){
*z=x+y;
}
