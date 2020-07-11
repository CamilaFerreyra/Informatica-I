
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<time.h>

struct alumno{
    int numero;
    char mail[360];
};
struct examinado{
    int numero;
    char mail[360];
    int examen[10];
    float nota_final;
};
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
void cargar(struct alumno planilla[80], int *inscriptos){
/*--- SUBRUTINA abre el archivo estudiantes.dat.
deja disponible la lista de e-mails de los, como máximo, 80 estudiantes
inscriptos en la comisión en una estructura de tipo alumno.
El archivo de organización secuencial estudiantes.dat se compone de
80 registros con dos campos, el primero es el número de estudiante
y el segundo la dirección de correo electrónico. ---*/
    int i=0,id;
    char mail[360];

    FILE *estudiantes;
    estudiantes = fopen("estudiantes.dat","r");
    *inscriptos=0;
    fscanf(estudiantes,"%i%s",&id, &mail);

    while(!feof(estudiantes)){
        printf("\n%i %s", id, mail);

        planilla[i].numero=id;
        strcpy(planilla[i].mail,mail);
        (*inscriptos)++;
///IMPORTANTE parentesis.
        fscanf(estudiantes,"%i%s", &id, &mail);
        i++;
    }
    fclose(estudiantes);
}
/*
void mostrar(struct alumno planilla[80]){
    int i=0;
    while(i<80){
        printf("\n%i %s", planilla[i].numero, planilla[i].mail);
        i++;
    }
}


    Hay un límite de longitud (nombre@dominio).
    Máximo de 64 caracteres en el nombre (antes de” @ “).
    Máximo de 255 caracteres en la parte del dominio
*/
char menu(){
/*--- FUNCION devuelve al algoritmo principal la letra E, C o S,
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
int buscar(char mail[360], struct alumno planilla[80]){
/*--- FUNCION. si encuentra el mail en la planilla,
devuelve la posicion de la planilla donde lo encontro,
sino devuelve -1. --- */
    int posicion=-1, i;
    for(i=0;i<80;i++){
        if(strcmp(mail,planilla[i].mail)==0)
            posicion=i;
    }
    return posicion;
}
void examinar(struct alumno alumnos[80], struct examinado examinados[80], int *total_examenes){
/*--- SUBRUTINA. lee e-mails del archivo evaluados.dat y los busca en la planilla genereada por carga.
Si lo encuentra, genera el examen para el alumno del mail.
si no, muestra "nombre@dominio, no se encuentra inscripto en esta comisión."
Se cuentan la cantidad de examenes generados. ---*/

//VER Se debe mostrar en la pantalla el total de exámenes generados.


    char mail[360];
    int posicion,i=0;
    FILE *evaluados;
    evaluados = fopen("evaluados.dat", "r");
    fscanf(evaluados,"%s",&mail);
    while(!feof(evaluados)){
        posicion=buscar(mail,alumnos);
///si "buscar" encuentra el mail, devuelve la posicion de "alumnos" donde lo encontro, sino devuelve -1.
        if(posicion!=-1){
            (*total_examenes)++;
            printf("\n\nQuiero generar un examen para el mail %s...", mail);
///guardo datos de alumnos con examenes en examinados:
            examinados[i].numero=alumnos[posicion].numero;
            strcpy(examinados[i].mail,mail);
            aleatorio(examinados[i].examen);
            printf("Examen generado.");
            examinados[i].nota_final=0.0;
            i++;
///Inicializo en 0.0 la nota final de cada alumno al que se le asigno un examen.
        }else{
            printf("\n\n%s no se encuentra inscripto en esta comision.", mail);
        }
        fscanf(evaluados,"%s",&mail);
    }
    fclose(evaluados);
}
void mostrar_notas(struct examinado examinados[80], int *examenes_corregidos){
/*--- SUBRUTINA, recibe la lista de alumnos examinados y la cantidad de examenes corregidos.
Muestra lista completa de examenes corregidos junto con la
numero del alumno y nota del alumno. ---*/
    int i,c;
    for(i=0;i<*examenes_corregidos;i++){
        printf("\n\nAlumno numero %i:", examinados[i].numero);
        printf("\n\nExamen:");
        for(c=0;c<10;c++){
            printf(" %i", examinados[i].examen[c]);
            if(c!=9)
            printf(",");
        }
        printf("\n\nNota final: %.2f\n-----------------------\n",examinados[i].nota_final);
    }
}
void corregir(struct examinado examinados[80], int *total_examenes){
/*--- SUBRUTINA, recibe la estructura creada por la opción E).
Recorre los elementos de la estructura y
muestra el nro del estudiante (aún no corregido)
muestra el listado de números de preguntas asignadas.
Permite que el docente ingrese la nota final.

Luego se retorna al menú principal.

observaciones:
Si no se generaron los exámenes se debe advertir con un mensaje de
esta situación y volver a mostrar el menú principal.
La nota final pertenece al rango [1.0; 10:0]
Un examen aún no corregido debe tener 0.0 como nota.

 VER Si se corrigieron todos los exámenes, mostrar la lista completa de
todos los exámenes corregidos indicando el nro de estudiante y la nota, y a continuación
habilitar nuevamente la opción E) EXAMINAR.
*/
///Si el examen fue creado y no fue corregido, nota final == 0.0.
    int i,c, examenes_corregidos;
    if(examinados[0].nota_final!=0.0){
        printf("\n\nNo se han generado los examenes!!");
    }else{
        for(i=0;i<*total_examenes;i++){
            if(examinados[i].nota_final==0.0){
                printf("\n\nAlumno numero %i, aun sin corregir", examinados[i].numero);
                printf("\n\nPreguntas asignadas:");
                for(c=0;c<10;c++){
                    printf(" %i", examinados[i].examen[c]);
                    if(c!=9)
                    printf(",");
                }
                printf("\n\nIngrese la nota final: ");
                scanf("%f", &examinados[i].nota_final);
                examenes_corregidos++;
            }
        }
    }
    printf("\n\nCantidad de examenes corregidos: %i", examenes_corregidos);
    mostrar_notas(examinados, &examenes_corregidos);
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
    struct alumno alumnos[80];
    struct examinado examinados[80];
    int inscriptos, total_examenes;
//esta instrucción sirve de semilla para el aleatorio.
    srand(time(NULL));
    cargar(alumnos, &inscriptos);
    printf("\nCantidad de alumnos inscriptos: %i", inscriptos);
    examinar(alumnos, examinados, &total_examenes);
    printf("\n\nSe acaban de generar %i examenes.", total_examenes);
    corregir(examinados, &total_examenes);
    return 0;
}
