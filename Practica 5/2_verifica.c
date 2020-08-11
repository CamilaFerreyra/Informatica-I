#include<string.h>
#include<stdio.h>
#include<math.h>

int verificar_pertenencia(int num, int a, int b);
/*---FUNCION, recibe como parametros 3 numeros enteros cualesquiera
devuelve 1 si el primer parametro pertenece al intervalo cerrado
definido por los otros dos o 0 si no pertenece.
Se desconoce cual es el lımite inferior del
intervalo y cual es el limite superior---*/
void intercambiar(int *a, int *b);
/*---SUBRUTINA, intercambia los valores de a y b.*/
int main (){
    int num, a, b, bandera;
    printf("Ingrese un numero: ");
    scanf("%i", &num);
    printf("\nIngrese una cota del intervalo cerrado: ");
    scanf("%i", &a);
    printf("\nIngrese la otra cota del intervalo cerrado: ");
    scanf("%i", &b);
    bandera=verificar_pertenencia(num, a, b);
    if(bandera==1){
        printf("\nEl numero pertenece al intervalo.");
    }else{
        printf("\nEl numero no pertence al intervalo.");
    }

return 0;
}

int verificar_pertenencia(int num, int a, int b){
    int bandera=0;
    if(a>b)
        intercambiar(&a,&b);
    if((num>a && num<b) || num==a || num==b)
        bandera=1;
    return bandera;
}
void intercambiar(int *a, int *b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}
