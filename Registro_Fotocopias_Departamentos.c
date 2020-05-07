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


/*
    PSEUDOCODIGO

    Algoritmo: Registro_Fotocopias_Departamentos
    Variables
        Enteros: M_simples, F_simples, R_simples, M_dobles, F_dobles, R_dobles, simples, dobles, i,
                M_total_dia, F_total_dia, R_total_dia, total_simples_dia, total_dobles_dia, hojas_dia,
                M_total_mes, F_total_mes, R_total_mes, hojas_mes, total_fotocopias_dia, max, dia
        Caracter: depto
    Inicio
        i <- 1

        M_total_mes <- 0
        F_total_mes <- 0
        R_total_mes <- 0

        hojas_mes <- 0
        
        Repetir Mientras (i<=20) hacer

            M_simples <-0
            F_simples <- 0
            R_simples <- 0

            M_dobles <- 0
            F_dobles <- 0
            R_dobles <- 0

            M_total_dia <- 0
            F_total_dia <- 0
            R_total_dia <- 0

            total_simples_dia <- 0
            total_dobles_dia <- 0
            total_fotocopias_dia <- 0
            hojas_dia <- 0

            Escribir("Dia ", i)
            Escribir("Ingrese el departamento que realiza las fotocopias: ")
            Leer (depto)
            Repetir Mientras (depto <> "@") hacer
                Escribir("Ingrese la cantidad de copias doble faz")
                Leer(dobles)
                Escribir("Ingrese la cantidad de copias simple faz")
                Leer(simples)

                Segun Sea (depto)
                    'M': M_simples <- M_simples + simples 
                         M_dobles <- M_dobles + dobles
                    'F': F_simples <- F_simples + simples 
                         F_dobles <- F_dobles + dobles
                    'R': R_simples <- R_simples + simples 
                         R_dobles <- R_dobles + dobles
                Sino
                    Escribir("ERROR. Por favor ingrese M, F o R.")
                Fin Segun

                Escribir("Ingrese el departamento que realiza copias: ")
                Leer(depto)
            Fin Mientras
            Escribir("Usted ha terminado de ingresar las copias del dia",i)
            Escribir("Estos son los datos del dia",i)

            M_total_dia <- 2*M_dobles + M_simples
            F_total_dia <- 2*F_dobles + F_simples
            R_total_dia <- 2*R_dobles + R_simples

            Escribir("Total de fotocopias realizadas por el departamento de Matematica: ",M_total_dia)
            Escribir("Total de fotocopias realizadas por el departamento de Fisica: ",F_total_dia)
            Escribir("Total de fotocopias realizadas por el departamento de Sist. de Representacion: ",R_total_dia)

            total_simples_dia <- M_simples + F_simples + R_simples
            total_dobles_dia <- M_dobles + F_dobles + R_dobles
            hojas_dia <- total_dobles_dia + total_simples_dia

            Escribir("Total de fotocopias simple faz realizadas: ",total_simples_dia)
            Escribir("Total de fotocopias doble faz realizadas: ",2*total_dobles_dia)
            Escribir("La cantidad de hojas utilizadas en el dia es: ", hojas_dia, "hojas")

            M_total_mes <- M_total_mes + M_total_dia
            F_total_mes <- F_total_mes + F_total_dia
            R_total_mes <- R_total_mes + R_total_dia

            hojas_mes <- hojas_mes + hojas_dia

           total_fotocopias_dia <- 2*total_dobles_dia + total_simples_dia

            Si(i=1) Entonces
                max <- total_fotocopias_dia
                dia <- i
            Sino
                Si(max<total_fotocopias_dia) Entonces
                max <- total_fotocopias_dia
                dia <- i
                Fin Si
            Fin Si
            
            i++;

        Fin Mientras

        Escribir("Ha finalizado el mes. Estos son los datos del mes:")

        Escribir("Total de fotocopias realizadas en el mes por departamento:")
        Escribir("Matematica: ", M_total_mes)
        Escribir("Fisica: ", F_total_mes)
        Escribir("Sistemas de Representacion: ", R_total_mes)

        Escribir("La cantidad de hojas utilizadas en el mes: ", hojas_mes)

        Escribir("El dia", dia, "del mes se realizaron", max,"fotocopias, siendo el dia donde mas fotocopias se realizaron.")

    Fin

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
    /// Reinicio contadores para el mes:
    M_total_mes=0;
    F_total_mes=0;
    R_total_mes=0;

    hojas_mes=0;

    while(i<=20){

        /// Reinicio contadores para el dia:
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

        printf("\n\tDia %i:",i);

        printf("\n\tIngrese el departamento que realiza las fotocopias: ");
        scanf(" %c", &depto);

        while(depto!='@'){

            printf("\n\tIngrese la cantidad de copias doble faz (depto %c): ",depto);
            scanf("%i", &dobles);
            printf("\n\tIngrese la cantidad de copias simple faz (depto %c): ",depto);
            scanf("%i", &simples);
            printf("\n\tPresione cualquier tecla para continuar...");
            getch();                ///Cosas amigables al usuario (:
            system("cls");

            switch (depto){
            case 'M':
            M_simples+= simples;
            M_dobles+= dobles;
            break;

            case 'F':
            F_simples+= simples;
            F_dobles+= dobles;
            break;

            case 'R':
            R_simples+= simples;
            R_dobles+= dobles;
            break;

            default:
            printf("\n\tERROR. Por favor ingrese M, F o R.");
            }

            printf("\n\tIngrese el departamento que realiza copias: ");
            scanf(" %c", &depto);
        }

        printf("\n\tUsted ha terminado de ingresar las copias del dia %i.\n\n\tEstos son los datos del dia %i:",i,i);

        M_total_dia= 2*M_dobles+M_simples;
        F_total_dia= 2*F_dobles+F_simples;
        R_total_dia= 2*R_dobles+R_simples;

        printf("\n\tTotal de fotocopias realizadas por el departamento de Matematica: %i",M_total_dia);
        printf("\n\tTotal de fotocopias realizadas por el departamento de Fisica: %i",F_total_dia);
        printf("\n\tTotal de fotocopias realizadas por el departamento de Sist. de Representacion: %i",R_total_dia);

        total_simples_dia= M_simples + F_simples + R_simples;
        total_dobles_dia= M_dobles + F_dobles + R_dobles;
        hojas_dia= total_dobles_dia + total_simples_dia;

        printf("\n\tTotal de fotocopias simple faz realizadas: %i",total_simples_dia);
        printf("\n\tTotal de fotocopias doble faz realizadas: %i",2*total_dobles_dia);
        printf("\n\tLa cantidad de hojas utilizadas en el dia es: %i hojas", hojas_dia);

        printf("\n\tPresione cualquier tecla para continuar...");
        getch();                                                 ///Cosas amigables al usuario (:
        system("cls");

        /// Preparo datos para el mes:

        M_total_mes+= M_total_dia;
        F_total_mes+= F_total_dia;
        R_total_mes+= R_total_dia;

        hojas_mes+= hojas_dia;

        ///DIA CON MAXIMA CANTIDAD DE FOTOCOPIAS
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

        i++;

    }

    printf("\n\tHa finalizado el mes. Estos son los datos del mes: ");

    printf("\n\tTotal de fotocopias realizadas en el mes por departamento:");
    printf("\n\tMatematica: %i", M_total_mes);
    printf("\n\tFisica: %i", F_total_mes);
    printf("\n\tSistemas de Representacion: %i", R_total_mes);

    printf("\n\tLa cantidad de hojas utilizadas en el mes: %i", hojas_mes);

    printf("\n\tEl dia %i del mes se realizaron %i fotocopias, siendo el dia donde mas fotocopias se realizaron.", dia, max);


    return 0;
}
