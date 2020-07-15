#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<time.h>

struct alumno{
    int numero;
    char mail[320];
};
struct examinado{
    int numero;
    char mail[320];
    int examen[10];
    float nota_final;
};
void aleatorio(int exam[10]){
    /*--- SUBRUTINA, carga en un arreglo de tipo int,
    10 numeros aleatorios entre 1 y 100 ---*/

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
    char mail[320];

    FILE *estudiantes;
    estudiantes = fopen("estudiantes.dat","r");
    *inscriptos=0;
    fscanf(estudiantes,"%i%s",&id, mail);

    while(!feof(estudiantes)){
        //printf("\n%i %s", id, mail);
        planilla[i].numero=id;
        strcpy(planilla[i].mail,mail);
        (*inscriptos)++;
///IMPORTANTE parentesis.
        fscanf(estudiantes,"%i%s", &id, mail);
        i++;
    }
    fclose(estudiantes);
}
/*
    Hay un límite de longitud (nombre@dominio).
    Máximo de 64 caracteres en el nombre (antes de” @ “).
    Máximo de 255 caracteres en la parte del dominio
*/
char menu(){
    /*--- FUNCION devuelve al algoritmo principal la letra E, C o S,
    con previa validación. ---*/
    char opcion;
    printf ("\n\n\tMENU");
    printf ("\nE) Examinar");
    printf ("\nC) Corregir");
    printf ("\nS) Salir");
    printf ("\nOpci%cn elegida: " ,162);
    scanf (" %c", &opcion);
    opcion=toupper(opcion);
    while (opcion!='E' && opcion!='C' && opcion!='S'){
        printf ("\nLa opci%cn elegida no es correcta. Ingrese una opci%cn valida (E/C/S): ", 162, 162);
        scanf (" %c", &opcion);
        opcion=toupper(opcion);
    }
    return opcion;
}
int buscar(char mail[320], struct alumno planilla[80]){
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
void examinar(struct alumno alumnos[80], struct examinado examinados[80], int *total_examenes, int *bandera_examinar){
    /*--- SUBRUTINA. lee e-mails del archivo evaluados.dat y los busca en la planilla genereada por carga.
    Si lo encuentra, genera el examen para el alumno del mail.
    si no, muestra "nombre@dominio, no se encuentra inscripto en esta comisión."
    Se cuentan la cantidad de examenes generados. ---*/

    //VER Se debe mostrar en la pantalla el total de exámenes generados.

    if(*bandera_examinar==1){
        char mail[320];
    int posicion,i=0;
    *total_examenes=0;
    FILE *evaluados;
    evaluados = fopen("evaluados.dat", "r");
    fscanf(evaluados,"%s",mail);
    while(!feof(evaluados)){
        posicion=buscar(mail,alumnos);
    ///si "buscar" encuentra el mail, devuelve la posicion de "alumnos" donde lo encontro, sino devuelve -1.
        if(posicion!=-1){
            (*total_examenes)++;
            //printf("\n\nSe esta generando un examen para el mail %s...", mail);
    ///guardo datos de alumnos con examenes en examinados:
            examinados[i].numero=alumnos[posicion].numero;
            strcpy(examinados[i].mail,mail);
            aleatorio(examinados[i].examen);
            //printf("Examen generado.");
            examinados[i].nota_final=0.0;
    /// si nota_final == 0.0, fue creado el examen para ese alumno.
            *bandera_examinar=0;
    /// hay examenes pendientes de correccion, inhabilito la opcion de volver a examinar.
            i++;

        }else{
            printf("\n\nEl propietario de: %s, no se encuentra inscripto en esta comision.", mail);
        }
        fscanf(evaluados,"%s",mail);
    }
    fclose(evaluados);
    }else{
        printf("\nNo es posible crear examenes para los alumnos. \nVerifique que no existan examenes sin corregir");
    }

}
void mostrar_notas(struct examinado examinados[80], int corregidos){
    /*--- SUBRUTINA, recibe la lista de alumnos examinados y la cantidad de examenes corregidos.
    Muestra la lista completa de examenes corregidos junto con el
    numero de alumno y la nota final del mismo. ---*/
    int i,c;
    printf("\nListado alumnos corregidos:\n--------------------------");
    for(i=0;i<corregidos;i++){
        printf("\nAlumno numero %i:", examinados[i].numero);
        printf("\nExamen:");
        for(c=0;c<10;c++){
            printf(" %i", examinados[i].examen[c]);
            if(c!=9)
            printf(",");
        }
        printf("\nNota final: %.2f\n--------------------------",examinados[i].nota_final);
    }
}
int verificar_correccion(struct examinado examinados[80], int total_examenes){
    /*--- FUNCION, si todos los examenes fueron corregidos,
    devuelve 1, sino devuelve 0.  ---*/
    int contador=0,respuesta, i;
    for(i=0;i<total_examenes;i++){
        if(examinados[i].nota_final!=0.0)
            contador++;
        if(contador==total_examenes)
            respuesta=1;
        else
            respuesta=0;
    }
    return respuesta;
}
void corregir(struct examinado examinados[80], int *total_examenes, int *corregidos){
    /*--- SUBRUTINA, recibe la estructura creada por la opción E).
    Recorre los elementos de la estructura y
    muestra el nro del estudiante (aún no corregido)
    muestra el listado de números de preguntas asignadas.
    Permite que el docente ingrese la nota final. ---*/

    int i,c;
    *corregidos=0;
    ///Si el examen fue creado y no fue corregido, nota final == 0.0
    if(examinados[0].nota_final==0.0){
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
                *corregidos= *corregidos +1;
            }else{
                printf("El alumno numero %i, ya ha sido corregido", examinados[i].numero);
            }
        }
    }
    if(*corregidos==0){
        printf("\n\nADVERTENCIA: no se han generado los examenes!!");
    }
}
void intercambiar(struct examinado examinados[80], int a, int b){
    /*--- SUBRUTINA, dada una estructura del tipo examinado,
    intercmbia el elemento ubicado en la posicion "a"
    por el elemento ubicado en la posicion "b" ---*/
    struct examinado aux;
    int i;
    ///aux<-a
    aux.numero=examinados[a].numero;
    strcpy(aux.mail,examinados[a].mail);
    for(i=0;i<10;i++){
        aux.examen[i]=examinados[a].examen[i];
    }
    aux.nota_final=examinados[a].nota_final;
    ///a<-b
    examinados[a].numero=examinados[b].numero;
    strcpy(examinados[a].mail,examinados[b].mail);
    for(i=0;i<10;i++){
        examinados[a].examen[i]=examinados[b].examen[i];
    }
    examinados[a].nota_final=examinados[b].nota_final;
    ///b<-aux
    examinados[b].numero=aux.numero;
    strcpy(examinados[b].mail,aux.mail);
    for(i=0;i<10;i++){
        examinados[b].examen[i]=aux.examen[i];
    }
    examinados[b].nota_final=aux.nota_final;
}
void ordenar_creciente(struct examinado examinados[80], int examenes_corregidos){
    /* --- SUBRUTINA, ordena a los alumnos examinados, segun su calificacion,
    de menor a mayor. Algoritmo: bubble sort ---*/

    int i,c;
    for(c=0;c<examenes_corregidos;c++){
        for(i=0;i<examenes_corregidos-1-c;i++){
            if(examinados[i].nota_final>examinados[i+1].nota_final)
                intercambiar(examinados,i,i+1);
        }
    }
}
void salir(struct examinado examinados[80], int *examenes_corregidos){
    /*--- SUBRUTINA, guarda en un archivo de nombre “correcciones.txt”
    un listado que con los siguientes campos:
    nro de estudiante, los 10 números de las preguntas y nota final,
    en orden creciente de notas de todos los estudiantes evaluados.
    ---*/

    int i,c;
    printf("\n\nUsted ha finalizado el programa.");
    ordenar_creciente(examinados,*examenes_corregidos);
    FILE *correcciones;
    correcciones= fopen("correcciones.txt", "w");
    printf("\n\nGrenerando archivo con correcciones...");
    for(i=0;i<*examenes_corregidos;i++){
        fprintf(correcciones,"%i", examinados[i].numero);
        for(c=0;c<10;c++){
            fprintf(correcciones," %i", examinados[i].examen[c]);
            if(c!=9)
            fprintf(correcciones,",");
        }
        fprintf(correcciones," %.2f\n", examinados[i].nota_final);
    }
    fclose(correcciones);
    printf("Archivo generado.\n\n");
}

main(){
    struct alumno alumnos[80];
    struct examinado examinados[80];
    char opcion;
    int bandera_examinar=1,inscriptos, total_examenes, alumnos_examinados;
    ///si bandera_examinar == 1, puedo crear examenes.
    ///esta instrucción sirve para plantar la semilla para el rand().
    srand(time(NULL));
    cargar(alumnos, &inscriptos);
    //printf("\nCantidad de alumnos inscriptos en la comision: %i", inscriptos);
    while(opcion!='S'){
        opcion=menu();
        switch(opcion){
            case 'E':
                examinar(alumnos, examinados, &total_examenes, &bandera_examinar);
                //printf("\nSe acaban de generar %i examenes.", total_examenes);
                break;
            case 'C':
                corregir(examinados, &total_examenes, &alumnos_examinados);
                //printf("\nCantidad de examenes corregidos: %i", alumnos_examinados);
                ///Si todos los examenes fueron corregidos, se enlista el examen, nro de alumno y nota.
                if(verificar_correccion(examinados, total_examenes)==1){
                    mostrar_notas(examinados, alumnos_examinados);
                    bandera_examinar=1;
                ///habilito la posibilidad de examinar nuevamente.
                }

                break;
            case 'S':
                salir(examinados, &alumnos_examinados);
        }
    }
    return 0;
}
