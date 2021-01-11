#include<stdio.h>
/*
Se ingresan las notas de un examen.
No sé cuantas notas se van a ingresar.
Calcular:
Porcentaje de las notas mayores a 6 (aprobados) -> cant alumnos / cant de aprobados
Promedio de todas las notas -> cant alumnos = cant notas / suma de notas
NO se cuantos alumnos son -> fin de dato = -1
*/
int main() {
    
    //declaracion
    float nota, promedio, porcentaje, notas_total;
    int alumnos, aprobadas;
    
    //inicializar
    alumnos = 0;
    notas_total=0;
    aprobadas=0;
    
    printf("Ingresar la primer nota (fin de dato = -1): ");
    scanf ("%f", &nota); // f: real, i: entero
   
    
    while(nota=!-1){
        alumnos= alumnos +1;  // alumnos++
        notas_total= notas_total + nota;
        if(nota>6){
            aprobadas= aprobadas + 1;
        }
    }
    /*
    100% -------------- alumnos
    x= porcentaje ----- aprobadas
    */
    porcentaje = (aprobadas*100)/alumnos;
    
    promedio = notas_total/alumnos;
    
    printf("Porcentaje de alumnos que aprobnaron: %f",porcentaje);
    
    printf("Promedio total de notas: %f", promedio);
    
    return 0;
}