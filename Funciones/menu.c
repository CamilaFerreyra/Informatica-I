#include<stdio.h>
/*
Consigna:
Mostrar un menú que permita ingresar una letra para elegir cada opción.
Ejemplo:


-------------------------------
(C)argar
(M)ostrar
(P)romedio
(X)porcentaje
(S)alir
Ingrese una opción:
--------------------------------


"Cargar" nos permite ingresar la edad de un grupo de personas. Se desconoce la cantidad de personas que serán registradas.
"Mostrar" nos muestra por pantalla la cantidad de personas que se han ingresado.
"Promedio" muestra el promedio de edad del grupo de personas registradas.

*/
void menu (char *opcion){
    //mostrar un menu
    printf("\n\tIngrese una opcion: ");
    scanf(" %c", &*opcion);
}
void mostrar(int personas){
    printf("\nSe ingresaron las edades de %d personas\n", personas);
}
float fun_promedio(int personas, int sum_edad){
    float promedio;
    promedio= sum_edad/personas;
    return promedio;
}
void sub_promedio(int personas, int sum_edad, float *promedio){
    *promedio=sum_edad/personas;
    sum_edad=0;
}
void sub_porcentaje(int personas, int mayores, float *porcentaje){
    // 100 ---------- personas
    //   x ---------- mayores
    *porcentaje= (mayores*100)/personas;
}
main(){
    //declarar
    char opcion;
    int personas, edad, sum_edad, mayores;
    float promedio, porcentaje;

    //inicializar
    personas = 0;
    sum_edad = 0;
    mayores = 0;

    menu(&opcion);
    while(opcion != 'S'){
        //segun sea
        switch (opcion){
        case 'C':
            printf("\nIngrese la primer edad (fin de dato numero menos a cero): ");
            scanf(" %d", &edad);
            while(edad>0 || edad==0){
                personas= personas + 1;
                sum_edad= sum_edad + edad;
                if(edad>18 || edad==18){
                    mayores= mayores + 1;
                }
                printf("\nIngrese la siguiente edad (fin de dato numero menos a cero): ");
                scanf(" %d", &edad);
            }
            break;
        case 'M':
            mostrar(personas);
            break;
        case 'P':
            promedio= fun_promedio(personas, sum_edad);
            sub_promedio(personas,sum_edad, &promedio);
            printf("\nEl promedio es: %f", promedio);
            break;
        case 'X':
            sub_porcentaje(personas, mayores, &porcentaje);
            printf("\nEl porcentaje de personas mayores de edad es: %f%%", porcentaje);
            break;
        }
        menu(&opcion);
    }
    return 0;
}
