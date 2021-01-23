#include<stdio.h>
void sub_cargar(float numeros[100]){
    int i;
    for(i=0;i<100;i++){
        printf("Ingrese un numero: ");
        scanf(" %f", &numeros[i]);
    }
}
void sub_promedio(float num[100], float *promedio){
    int i, mayores;
    float sum;
    mayores=0;
    sum=0;
    for(i=0;i<100;i++){
        if(num[i]>0){
            sum=sum+num[i];
            mayores=mayores+1;
        }
    }
    *promedio=sum/mayores;
}
float fun_promedio(float numeros[100]){
    float promedio, sum;
    int i, mayores;
    mayores=0;
    sum=0;
    for(i=0;i<100;i++){
        if(numeros[i]>0){
            sum=sum+numeros[i];
            mayores=mayores+1;
        }
    }
    promedio=sum/mayores;
    return promedio;
}
int fun_contar(float numeros[100]){
    int i, mayores_promedio;
    float promedio;
    mayores_promedio=0;
    promedio = fun_promedio(numeros);
    for(i=0;i<100;i++){
        if(numeros[i]>promedio){
            mayores_promedio=mayores_promedio+1;
        }
    }
    return mayores_promedio;
}
void sub_porcentaje_negativos(float numeros[100], float *porcentaje){
    int i, negativos;
    negativos=0;
    for(i=0;i<100;i++){
        if(numeros[i]<0){
            negativos=negativos+1;
        }
    }
/// total numeros (100) ----- 100%
/// negativos (negativos) --- x% (porcentaje)
    *porcentaje= (negativos*100) / 100;
}
main(){

    float numeros[100], promedio, porcentaje;
    int may_promedio;

    sub_cargar(numeros);

    //sub_promedio(numeros,&promedio);
    promedio = fun_promedio(numeros);
    printf("\n El promedio de los numeros mayores a cero es: %f", promedio);

    may_promedio = fun_contar(numeros);
    printf("\n La cantidad de numeros que superan el promedio de numeros \nmayores a cero es: %d", may_promedio);

    sub_porcentaje_negativos(numeros, &porcentaje);
    printf("\n El porcentaje de numeros negativos es: %f%%", porcentaje);
    return 0;
}
