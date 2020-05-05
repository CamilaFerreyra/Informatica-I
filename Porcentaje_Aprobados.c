/*
Ej. 16. Dadas las notas de los alumnos que rindieron un examen final,
calcular e informar el porcentaje de notas superiores a 6.
Con una nota negativa se indica el fin de ingreso de datos.

PSEUDOCODIGO

Algotirmo: Porcentaje_Aprobados
Variables:
    real: nota, porcentaje
    entero: alumnos, aprobados
Inicio
    alumnos=0
    aprobados=0
    Escribir("Ingrese la nota de un alumno: ")
    Leer(nota)
    Repetir Mientras (nota>0 OR nota=0) hacer
        
        Si(nota>6) entonces
            aprobados= aprobados + 1
        Fin Si
        alumnos= alumnos + 1
        Escribir("Ingrese la nota de un alumno: ")
        Leer(nota)
        
    Fin Mientras
    porcentaje= aprobados * 100 / alumnos
    Escribir("El porcentaje de notas superiores a 6 es: ", porcentaje);
FIN

CÓDIGO EN C:
*/

#include<stdio.h>
//#include<stdlib.h>
//#include<conio.h>
main(){

    float nota, porcentaje;
    int alumnos=0, aprobados=0;

    printf("\n\tRecordatorio:\n\tSi ha terminado de ingresar notas, ingrese una nota negativa\n\n");

    printf("\nIngrese la nota de un alumno: ");
    scanf("%f", &nota);

    while (nota>0 || nota==0)
    {
        if(nota>6){
           aprobados ++;
        }

        alumnos++;

        printf("\nIngrese la nota de un alumno: ");
        scanf("%f", &nota);
    }

    porcentaje = (aprobados * 100) / alumnos;
    printf("\n\n El porcentaje de notas superiores a 6 es: %f%%", porcentaje);

    return 0;
}
