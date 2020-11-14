#include <stdio.h>
#include <stdlib.h>

/** Hacer usando punteros las siguientes funciones:
a) Devuelva el largo de una cadena.

b) Intercambie el valor de 2 variables.

c) Almacene el contenido de una cadena en otra.

d) Compare 2  cadenas **/

int nuevo_strlen (char  *s){
    int l=0;
    while(*s++) l++;
    return l;
}

void nuevo_swap( int *a, int *b ){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void nuevo_strcpy( char *s1, char *s2 ){
    while( *s1++ = *s2++ );
    }

int nuevo_strcmp( char *s1, char *s2 ){
    // !*s se cumple si --> *s == '\0'
    while( 1 )  ///hasta legar al return
    {
             if( !*s1 && !*s2 ) return 0;
        else if( !*s2 ) return  1;             //termino primero la s2, entonces, es menorcita
        else if( !*s1 ) return -1;

             if( *s1 > *s2 ) return  1;        //comparo importancia de los cartacteres.
        else if( *s2 > *s1 ) return -1;

        s1++;
        s2++;
    }
}





int main(){

    int determinante;
    printf("\n\n\tBienvenido a la tarea numero 9 \n\tQue desea hacer? (Por favor, presione una tecla)\n\n");

    printf("\t1: Determine el largo de una cadena a ingresar.\n");
    printf("\t2: Intercambie el valor entre dos valores enteros a ingresar.\n");
    printf("\t3: Ingrese dos cadena y almacene el contenido de una cadena en otra.\n");
    printf("\t4: Compare dos cadenas.\n");
    printf("\t5: SALIR.\n\t");
    scanf("%i", determinante);

    char s[100],s1[100],s2[100];
    int largo,a,b,cmp;
    switch(determinante)
{
        case 1:
            printf("\n\n\tIngrese la cadena de la cual desea determinr el largo:\n\t");
            scanf("%[^\n]", s);
            largo = nuevo_strlen(s);
            printf("\n\tEl largo de la cadena ingresada es: %i",largo);
            break;

        case 2:
            printf("\n\n\tIgngrese dos valores a intercambiar: ");
            scanf("%i%i", &a, &b);
            printf("\n\t ANTES  %i %i\n", a,b);
            nuevo_swap(&a,&b);
            printf("\n\t DESPUES   %i %i\n", a,b);
            break;

        case 3:
            printf("\n\n\tIngrese la cadena sobre la cual se copiara la siguiente:\n\t");
            scanf("%[^\n]", s1);
            printf("\n\n\tIngrese la cadena que desea copiar en la anteriormente ingresada:\n\t");
            scanf("%[^\n]", s2);
            printf("\n%s %s\n", s1, s2);
            strcpy(s1 ,s2);
            printf("%s %s\n", s1, s2);
            break;

        case 4:
            printf("\n\n\tIngrese una de las cadenas a comparar:\n\t");
            scanf("%[^\n]", s1);
            printf("\n\n\tIngrese la segunda cadena a comparar:\n\t");
            scanf("%[^\n]", s2);
            cmp= nuevo_strcmp(s1,s2);
            if(cmp<0){
                printf("\n\n\tLa segunda cadena ingresada es mayor.");
            }else{
                if(cmp>0){
                    printf("\n\nLa primera cadena ingresda es mayor.");
                }   else{
                        printf("\n\nLas cadenas ingresadas son igules.");
                    }
            }
        case 5:
            break;
}

   return 0;
}
