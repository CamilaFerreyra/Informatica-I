/*
En la fotocopiadora de docentes de la facultad, cada vez que un
profesor retira copias, se registra el código de departamento , la cantidad de copias doble
faz y la cantidad de copias simple faz . La lista se elabora por cada uno de los veinte días
laborables del mes.
Suponer que hay sólo tres departamentos, identificados cada uno con ódigos tipo caracter:
‘M’: Matemática, ‘F’: Física y ‘R’: Representación gráfica.
Cuando termina la actividad de un día, se ingresa un código de departamento igual a @.

Al finalizar cada día , se desea saber:

1) El total de fotocopias realizadas en cada departamento (tener en cuenta que cada
fotocopia doble faz equivale a dos fotocopias).
2) El total de fotocopias realizadas doble faz y simple faz, y la cantidad de hojas utilizadas en
ese día.

Al finalizar los 20 días laborables , se deberá informar:

1) El total de fotocopias realizadas en el mes en cada departamento.
2) La cantidad de hojas utilizadas en el mes.
3) En qué día se realizaron más fotocopias y dicha cantidad. Considerar que no existe más de
un departamento con el mismo valor máximo.
*/

#include<stdio.h>
//#include<stdlib.h>
//#include<conio.h>
main(){

    int M_simples, F_simples, R_simples, M_dobles, F_dobles, R_dobles, simples, dobles, i;
    int M_total_dia, F_total_dia, R_total_dia, total_simples_dia, total_dobles_dia, hojas_dia;
    int  M_total_mes, F_total_mes, R_total_mes, hojas_mes, total_fotocopias_dia, max, dia;
    char depto;
    i=1;
    while(i<=20){

        prinf("Ingrese el departamento que realiza las fotocopias: ");
        scanf("%c", depto);

        while(depto!="@"){

            printf("Ingrese la cantidad de copias simple faz: ");
            scanf("%i", simples);
            printf("Ingrese la cantidad de copias doble faz: ");
            scanf("%i", dobles);

            switch (depto){
            case 'M':
            M_simples+= simples;
            M_dobles+= dobles;
            break;

            case "F":
            F_simples+= simples;
            F_dobles+= dobles;
            break;

            case "R":
            R_simples+= simples;
            R_dobles+= dobles;
            break;

            default:
            printf("ERROR. Por favor ingrese M, F o R.");

            prinf("Ingrese el departamento que realiza copias: ");
            scanf("%c", depto);

        }

        printf("\n\tUsted ha terminado de ingresar las copias del dia %i.\n\n\tEstos son los datos del dia %i:",i);

        M_total_dia= 2*M_dobles+M_simples;
        F_total_dia= 2*F_dobles+F_simples;
        R_total_dia= 2*R_dobles+R_simples;

        printf("\n\tTotal de fotocopias realizadas por el departamento de Matematica: %i",total_M);
        printf("\n\tTotal de fotocopias realizadas por el departamento de Fisica: %i",total_F);
        printf("\n\tTotal de fotocopias realizadas por el departamento de Sist. de Representacion: %i",total_R);

        total_simples_dia= M_simples + F_simples + R_simples;
        total_dobles_dia= M_dobles + F_dobles + R_dobles;
        hojas_dia= total_dobles_dia/2 + total_simples_dia;

        printf("\n\tTotal de fotocopias simple faz realizadas: %i",total_simples_dia);
        printf("\n\tTotal de fotocopias doble faz realizadas: %i",total_dobles_dia);
        printf("\n\tLa cantidad de hojas utilizadas en el día es: %i hojas", hojas_dia);

        // Preparo datos para el mes:

        M_total_mes+= M_total_dia;
        F_total_mes+= F_total_dia;
        R_total_mes+= R_total_dia;

        hojas_mes+= hojas_dia;

        total_fotocopias_dia= 2*total_dobles_dia + total_simples_dia;
        if(i==1){
            max= total_fotocopias_dia;
            dia= i;
        }else{
            if(max<total_fotocopias_dia){
                max= total_fotocopias_dia;
                dia= i;
            }
        }

        // Reinicio contadores para el sig dia:

        M_simples=0;
        F_simples=0;
        R_simples=0;

        M_dobles=0;
        F_dobles=0;
        R_dobles=0;

        M_total_dia=0;
        F_total_dia=0;
        R_total_dia=0;

        total_simples_dia=0;
        total_dobles_dia=0;
        total_fotocopias_dia=0;
        hojas_dia=0;

        i++;
    }

    printf("\n\tHa finalizado el mes. Estos son los datos del mes: ");

    print("\n\tTotal de fotocopias realizadas en el mes por departamento:");
    print("\n\tMatematica: %i", M_total_mes);
    printf("\n\tFisica: %i", F_total_mes);
    prinf("\n\tSistemas de Representacion: %i", R_total_mes);

    printf("\n\tLa cantidad de hojas utilizadas en el mes: %i", hojas_mes);

    printf("\n\tEl dia %i del mes se realizaron %i fotocopias, siendo el dia donde mas fotocopias se realizaron.", dia, max);

    return 0;
}
