#include<stdio.h>


int main(){
    int lista[10], i, j, aux;
    int mayor, menor, medio, bandera, buscado, posicion_bus;
    bandera=0;   ///no se encontró el numero.
    ///cargo la lista.
    for(i=0; i<10; i++){
        printf("Ingrese un numero: ");
        scanf("%d", &lista[i]);
    }

    ///imprimir un arreglo:
    for(i=0; i<10; i++){
        printf("%d, ", lista[i]);
    }


    ///ordenar. SIEMPRE para una busqueda dicotómica, el arreglo debe estar ordenado de menor a mayor.
    ///ordenamiento de burbuja.
    for(i=1;i<10;i++){
        for(j=0;j<10-i;j++){
            if(lista[j]>lista[j+1]){
                aux=lista[j];
                lista[j]=lista[j+1];
                lista[j+1]=aux;
            }
        }
    }
    printf("\n");
    ///imprimir un arreglo:
    for(i=0; i<10; i++){
        printf("%d, ", lista[i]);
    }

    ///busqueda binaria o dicotomica.
    buscado=7; ///numero por buscar.
    menor=0;
    mayor=9; ///cantidad de elementos de la lista
    while(menor<mayor || menor == mayor){
        medio=(mayor+menor)/2;
        if(buscado==lista[medio]){
            posicion_bus=medio;
            bandera=1; ///el numero fue encontrado.
        }else{
            if(buscado<lista[medio]){
                mayor=medio-1;
            }else{
                menor=medio+1;
            }
        }
    }

    if(bandera==0){
        printf("\nEl numero no fue encontrado.");
    }else{
        printf("\n El numero fue encontrado en la posicion %d del arreglo.", posicion_bus);
    }
    return 0;
}
