#include<stdio.h>
void sub_cargar_fila(float array[4][3]){
    // (0,0) (0,1) (0,2)
    // (1,0) (1,1) (1,2)
    // (2,0) (2,1) (2,2)
    // (3,0) (3,1) (3,2)
    int f, c;
    for(f=0;f<4;f++){
        for(c=0;c<3;c++){
            printf("Ingrese un numero real: ");
            scanf(" %f", &array[f][c]);
        }
    }
}
void sub_mostrar_matriz(float array[4][3]){
    //apartado a: mostrar elementos por fila. (forma matriz)
    // (0,0) (0,1) (0,2)    //fila 1
    // (1,0) (1,1) (1,2)    //fila 2
    // (2,0) (2,1) (2,2)
    // (3,0) (3,1) (3,2)

    int f, c;
    for(f=0;f<4;f++){
        for(c=0;c<3;c++){
            printf("\t %f",array[f][c]);
        }
        printf("\n");
    }
}

void sub_mostrar_columnas(float array[4][3]){
    //apartado b: muestre el arrelo por columnas.

    //(0,0) (1,0) (2,0) (3,0)
    //(0,1) (1,1) (2,1) (3,1)
    //(0,2) (1,2) (2,2) (3,2)
    int f,c;
    for(c=0;c<3;c++){
        for(f=0;f<4;f++){
            printf("\t %f",array[f][c]);
        }
        printf("\n");
    }
}
void sub_intercambiar(float array[4][3]){
    //apartado c: intercambiar valores de la fila 1 y fila 2.
    // (0,0) (0,1) (0,2)    //fila 1
    // (1,0) (1,1) (1,2)    //fila 2
    int c;
    float aux;
    for(c=0;c<2;c++){
        aux = array[0][c];
        array[0][c] = array[1][c];
        array[1][c] = aux;
    }

}
main(){
//  tipo  nombre[filas][columnas]
    float arreglo[4][3];
    //cargar numeros reales en el arreglo de 4 filas x 3 columnas.
    sub_cargar_fila(arreglo);
    printf("\n");
    //apartado a:
    sub_mostrar_matriz(arreglo);
    printf("\n");
    //apartado b:
    sub_mostrar_columnas(arreglo);
    printf("\n");
    //apartado c: intercambiar elementos de la fila 1 con la fila 2.
    //mostrar como matriz
    sub_intercambiar(arreglo);
    sub_mostrar_matriz(arreglo);
    printf("\n");
    return 0;
}
