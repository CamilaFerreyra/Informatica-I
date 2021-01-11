
#include<stdio.h>
/*
Se ingresan las notas de un examen.
No sé cuantas notas se van a ingresar.
Calcular utilizando funciones:
Porcentaje de las notas mayores a 6 (aprobados) -> cant alumnos / cant de aprobados
Promedio de todas las notas -> cant alumnos = cant notas / suma de notas
Promedio de notas de alumnos que aprobaron.
NO se cuantos alumnos son -> fin de dato = -1
*/
float fun_porcentaje (int total, int partecita){
    float porcentaje;
    /*
    total ------ 100%
    partecita --- porcentaje = x %
    */
    porcentaje= (partecita*100)/total;
    return porcentaje;
}
float fun_promedio (float notas_total, int cantidad){
    float promedio;
    promedio = notas_total/cantidad;
    return promedio;
}
/*
ver si fue facil o estuvo complicado.
promedio de notas de los chicos que aprobaron
 -> cant notas aprobadas, sumatoria de notas aprobadas. 
*/
float fun_estadistica( int aprobados, float sum_aprobadas){
    float promedio_aprobados;
    promedio_aprobados= fun_promedio(sum_aprobadas, aprobados)
    return promedio_aprobados;
}
int main() {
    
    //declaracion
    float nota, promedio, porcentaje, notas_total, suma_aprobadas, promedio_aprobados;
    int alumnos, aprobadas;
    
    //inicializar
    alumnos = 0;
    notas_total=0;
    aprobadas=0;
    suma_aprobadas=0;
    
    printf("Ingresar la primer nota (fin de dato = -1): ");
    scanf ("%f", &nota); // f: real, i: entero
   
    
    while(nota=!-1){
        alumnos= alumnos +1;  // alumnos++
        notas_total= notas_total + nota;
        if(nota>6){
            aprobadas= aprobadas + 1;               //cuenta la cantidad de notas 
            suma_aprobadas= suma_aprobadas + nota;  //suma todas las notas aprobadas
        }
    }
    /*
    100% -------------- alumnos
    x= porcentaje ----- aprobadas
    */
    
    //porcentaje = (aprobadas*100)/alumnos;
    
    porcentaje= fun_porcentaje(alumnos, aprobadas);
    
    promedio = fun_promedio(notas_total, alumnos);
    
    promedio_aprobados= fun_estadistica(aprobadas, sum_aprobadas);
    
    printf("Porcentaje de alumnos que aprobnaron: %f",porcentaje);
    
    printf("Promedio total de notas: %f", promedio);
    
    return 0;
}