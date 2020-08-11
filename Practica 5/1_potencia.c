#include<string.h>
#include<stdio.h>
#include<math.h>

float potencia_funcion(int base, int exponente);
/* ---FUNCION recibe como parametros la base y el exponente de la operacion.
operacion: potencia.
*/
void potencia_subrutina(int base, int exponente, float *resultado);
/* ---SUBRUTINA recibe como parametros la base y el exponente de la operacion,
junto con la dirección de memoria donde debe guardar el resultado.
operacion: potencia.
*/
int main (){
    int base, exponente;
    float resultado;
    printf("Ingrese una base: ");
    scanf("%i",&base);
    printf("Ingrese un exponente: ");
    scanf("%i",&exponente);

    resultado=potencia_funcion(base, exponente);
    printf("\nEl resultado de la operacion es: %.2f", resultado);
    potencia_subrutina(base, exponente, &resultado);
    printf("\nEl resultado de la operacion es: %.2f", resultado);

return 0;
}
float potencia_funcion(int base, int exponente){
    int bandera=0;
    float resultado=1;
    if(exponente<0){
        bandera=1;
        exponente=(-1)*exponente;
    }
    for(;exponente>0; exponente--){
        resultado=resultado*base;
    }
    if(bandera==1)
        resultado=1/resultado;

    return resultado;
}
void potencia_subrutina(int base, int exponente, float *resultado){
    int bandera;
    *resultado=1;
    if(exponente<0){
        bandera=1;
        exponente=(-1)*exponente;
    }
    while(exponente>0){
        *resultado=(*resultado)*base;
        exponente--;
    }
    if(bandera==1)
        *resultado=1/(*resultado);
}

