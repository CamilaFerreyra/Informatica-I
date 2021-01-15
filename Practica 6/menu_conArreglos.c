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
No pueden ser más de 100 personas.
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
float fun_promedio(int edades[100], int personas){
    float promedio;
    int suma_edades, i;
    suma_edades=0;
    for(i=0;i<personas;i++){
        suma_edades= suma_edades + edades[i];
    }
    promedio= sum_edad/personas;
    return promedio;
}
void sub_promedio(int edades[100],int personas, float *promedio){
    int suma_edades, i;
    suma_edades=0;
    for(i=0;i<personas;i++){
        suma_edades= suma_edades + edades[i];
    }
    *promedio=sum_edad/personas;
}
void sub_porcentaje(int edades[100],int personas, float *porcentaje){
   int mayores, i;
   mayores=0;
   i=0;
   while(i<personas){
    if(edades[i]>18 || edades[i]==18){
        mayores = mayores +1;
    }
    i=i+1;
   }
    // 100 ---------- personas
    //   x ---------- mayores
    *porcentaje= (mayores*100)/personas;
}
main(){
    //declarar
    char opcion;
    int personas, edad, sum_edad, mayores, edades[100], i;
    float promedio, porcentaje;

    //inicializar
    personas = 0;
    sum_edad = 0;
    mayores = 0;
    i = 0;

    menu(&opcion);
    while(opcion != 'S'){
        //segun sea
        switch (opcion){
        case 'C':
            printf("Ingrese una edad (fin de dato <0: ");
            scanf(" %d", &edad);
            while(edad>0 || edad==0){
                edades[i]=edad;
                i= i+1;     //i++;
                printf("Ingrese una edad (fin de dato <0: ");
                scanf(" %d", &edad);
            }
            personas=i+1;
            /*
        SERVIRIA SI CONOZCO EL NUMERO DE PERSONAS
            for(i=0;i<100;i++){
                printf("Ingrese una edad: ");
                scanf(" %d", edades[i]);

                scanf(" %d", &edad);
                edades[i]=edad;
            */
            }
            /*
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
            */
            break;
        case 'M':
            mostrar(personas);
            break;
        case 'P':
            promedio= fun_promedio(edades, personas);
            sub_promedio(edades, personas, &promedio);
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
