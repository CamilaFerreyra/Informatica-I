#include<stdio.h>
#include<stdlib.h>

void sub_promedio(int numeros[20], int cant_numeros){
    int suma, i;
    float promedio;
    suma=0;
    for(i=0;i<cant_numeros;i++){
        suma=suma+numeros[i];
    }
    promedio=suma/cant_numeros;

    FILE *archivo;
    archivo=fopen("promedio.txt", "w");
    fprintf(archivo, "El promedio de numeros ingresados es: %f", promedio);
    fclose(archivo);

}

main(){
    int numerito, numeros[20], i, cant_numeros;
    i=0;
    FILE* archivo;
    archivo= fopen("numeros.txt","r");
    fscanf(archivo,"%i",&numerito);
    for(i=0;(!feof(archivo)); i++){
        numeros[i]=numerito;
        printf("\n %d", numerito);
        fscanf(archivo, "%i", &numerito);
    }

    fclose(archivo);
    cant_numeros= i + 1;
    sub_promedio(numeros, cant_numeros);
    return 0;
}
