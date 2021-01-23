#include<stdio.h>
/* EJERCICIO 2
Dado un arreglo V de 20 numeros reales que se cargan desde teclado, generar 2 nuevos
arreglos que contengan el valor y la posicion respectivamente de los elementos no nulos del
arreglo V. Mostrar los 2 nuevos arreglos generados.

Tema: Valor y posicion de elementos de un arreglo.

Aplicacion: Se dispone del total de ventas de 20 vendedores de un negocio.
Los vendedores se identifican con n�meros del 1 al 20. Puede ser que uno o m�s vendedores
no hayan vendido nada, por lo cual su total de ventas ser� 0.
Se debe ingresar la informaci�n ordenada por n�mero de vendedor en un arreglo de nombre
VENTAS, y luego generar 2 arreglos que contengan, por un lado el n�mero del vendedor y
por otro, el total de ventas que le corresponde, pero s�lo para aquellos vendedores que
realizaron ventas.
*/
main(){
    int V[20], vendedores[20], ventas[20], i, c;
    c=0;
    for(i=0;i<20;i++){
        printf("Ingrese la cantidad de ventas del vendedor %d: ", i+1);
        scanf(" %i", &V[i]);
    }
    for(i=0;i<20;i++){
        if(V[i]>0){
            ventas[i]=V[i];
            vendedores[i]=(i+1);
            c = c +1;
        }
    }
    for(i=0;i<c;i++){
        printf("\nVendedor: %d", vendedores[i]);
        printf("\nVentas: %d", ventas[i]);
    }
    return 0;
}
