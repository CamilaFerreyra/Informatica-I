/*
Ej.12: Dadas las 31 temperaturas mínimas de cada día del mes de mayo que se ingresan por teclado,
determinar e informar por pantalla en qué día se produjo la menor temperatura y cuál fue ese valor

PSEUDOCÓDIGO:
Algoritmo min_temp_mayo
Variables
    real: Temp, TempMin
    entero: i, dia
Inicio
    i <- 1
    Repetir Para (i<-1, i<=31, 1) hacer
        Escribir('Ingrese la temperatura del dia', i)
        Leer(Temp)
        Si(i=0) entonces
            TempMin= Temp
        Sino
            Si(Temp < TempMin) entonces
                TempMin <- Temp
                dia <- i
            Fin Si
        Fin Si
    Fin Para
   Escribir('La menor temperatura fue registrada el día número', dia)
   Escricir ('Esta temperatura fue de ', TempMin)

Fin

CÓDIGO EN C:
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

main(){

    float Temp,TempMin;
    int dia, i=1;
    ;
    printf("\n\tBienvenido!!\n\tVamos a determinar la temperatura minima del mes de mayo.\n");
    printf("\tPresione una tecla para continuar.\n");
    getch();
    system("cls");

    for(;i<=31;i++){

        printf("\n\tIngrese la temperatura minima del dia %i de mayo en grados centigrados, por favor: ", i);
        scanf("%f",&Temp);
        if(i==1){
            TempMin=Temp;
            }else{
                if(Temp<TempMin){
                TempMin=Temp;
                dia=i;
                }
            }
    }
    system("cls");
    printf("\n\t La menor temperatura fue registrada el dia numero %i de mayo.\n\tEsta temperatura fue de %f grados sentigrados. \n\n", dia, TempMin);
    return 0;
}
