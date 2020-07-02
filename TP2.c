
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<time.h>

void aleatorio(int exam[10]){
    int i, j, alea, bandera;
    
    exam[0] = rand()%100+1;
    for(i=1; i<10; i++){
        bandera=0;
        while(bandera==0){
        j=0;
        alea = rand()%100+1;
        while((alea != exam[j]) && (j < i)) j++;
        if (exam[j]!=alea) bandera=1;
        }
        exam[i] = alea;
    }
}
void carga(){
/* 
    Abrir el archivo estudiantes.dat y dejar disponible en sus parámetros
    la lista de e-mails de los, como máximo, 80 estudiantes
    inscriptos en la comisión en una estructura de datos adecuada.

    El archivo de organización secuencial estudiantes.dat se compone de 
    80 registros con dos campos, el primero es el número de estudiante 
    (un entero correlativo entre 1 y 80) y el
    segundo la dirección de correo electrónico.
*/
}
/*
    Hay un límite de longitud (nombre@dominio). 
    Máximo de 64 caracteres en el nombre (antes de” @ “).
    Máximo de 255 caracteres en la parte del dominio
*/
void validar(){
/*
Validar el ingreso de "E, C o S".
*/
}
char menu(){
/*
    (Funcion)
Debe devolver al algoritmo principal la letra E, C o S, 
con previa validación. 
El algoritmo principal
mostrará este menú hasta que se seleccione la opción S.
    Mostrar:
MENU
E) Examinar
C) Corregir
S) Salir
OPCIÓN ELEGIDA:__

*/
}

void examinar(){
/*
leer de a uno todos los e-mails del archivo evaluados.dat y 
buscarlo en la lista generada por CARGA.
Si lo encuentra se debe generar el examen,
si no, se debe mostrar el mensaje... "nombre@dominio, no se encuentra inscripto en esta comisión."

Al terminar de procesar evaluados.dat debe mostrarse en la pantalla el total de exámenes
generados.

Para generar el examen: invocar al subalgortimo aleatorio(), 
se creará un arreglo con 10 números enteros aleatorios entre 1 y 100,
corresponden a los números de las 10 preguntas asignadas a ese examen. 

Luego, en el algoritmo principal se deberán guardar esos números de preguntas asociándolos con el
número de estudiante en estructura/s adecuada/s, quedando ese examen disponible para su
corrección.
*/
}

void corregir(){
/* 
Crear un subalgoritmo que recibiendo la estructura creada por la
opción E), realice lo siguiente
Recorra los elementos de la estructura y muestre el nro del estudiante (aún no corregido)
a continuación, muestre el listado de números de preguntas asignadas,
y permita que el docente ingrese la nota final. 

Luego se retornar al menú principal.

observaciones:
Si no se generaron los exámenes se debe advertir con un mensaje de
esta situación y volver a mostrar el menú principal.
La nota final pertenece al rango [1.0; 10:0]
Un examen aún no corregido debe tener 0.0 como nota.

Si se corrigieron todos los exámenes, mostrar la lista completa de
todos los exámenes corregidos indicando el nro de estudiante y la nota, y a continuación
habilitar nuevamente la opción E) EXAMINAR.
*/    
}

void finalizacion(){
/*
Finaliza el programa. 
Antes de salir:guardar en un archivo de nombre “correcciones.txt” 
un listado que contenga los siguientes campos:
nro de estudiante, los 10 números de las preguntas y nota final, 
en orden creciente de notas de todos los estudiantes evaluados.
*/
}


main(){
    char respuesta;
//esta instrucción sirve de semilla para el aleatorio.
    srand(time(NULL)); 
    carga();
    respuesta= menu();  //debe repetirse hasta que devuelva "S". 

    return 0;
}