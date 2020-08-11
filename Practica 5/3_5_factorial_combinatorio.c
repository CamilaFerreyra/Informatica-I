#include<string.h>
#include<stdio.h>
#include<math.h>

int factorial(int n);
/*---FUNCION retorna n! */
int verificar(int n);
/*---FUNCION, verifica que n>=0 */
int combinatorio(int a, int b);
/*---FUNCION, calcula el numero combinatorio entre a y b.
numero combinatori (ab)= a!/b!*(a-b)!
se supone que existe el combinatorio entre a y b.*/
int main (){
    int n, resultado, a, b;
    printf("Ingrese un numero mayor igual a cero: ");
    scanf("%i", &n);
    n=verificar(n);
    resultado=factorial(n);
    printf("\nEl factorial de %i es %i.", n, resultado);

    printf("\nIngrese el primer numero para calcular el combinatorio: ");
    scanf("%i", &a);
    printf("\nIngrese el segundo numero para calcular el combinatorio: ");
    scanf("%i", &b);
    resultado=combinatorio(a,b);
    printf("\nEl combinatorio (%i/%i) es %i", a,b,resultado);
return 0;
}

int factorial(int n){
    int resultado=1;
    while(n>0){
        resultado*=n;
        n--;
    }
    return resultado;
}
int verificar(int n){
    while(n!=0 || n<0){
    printf("\nERROR.\nPor favor, ingrese un numero mayor o igual a cero: ");
    scanf("%i", &n);
    }
    return n;
}
int combinatorio(int a, int b){
    int resultado;
    resultado=factorial(a)/factorial(b)*factorial(a-b);
    return resultado;
}
