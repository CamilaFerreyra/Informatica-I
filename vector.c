#include <stdio.h>
#include "vector.h"

int main(){
    freopen("input", "r", stdin);

    /* declaro el vector */
    vector mi_vector;
    /* lo construyo con un tamaño inicial */
    vector_init(&mi_vector, 1);

    char q, c, *cp;
    int i;
    /*
        Vamos a tomar algunas consultas:

        "A x"   -> insertar 'x' en el fondo
        "B i"   -> borrar el elemento del índice 'i'
        "P i"   -> mostrar el elemento en el índice 'i'
        "S i x" -> cambiar el elemento del índice 'i' a 'x'
        "M"   -> mostrar el contenido del vector
    */

    /*
        Cosa Interesate:

            A las funciones que toman como parámetro un (void*) les paso un (char*) sin problemas,
        porque se castea (se traduce) implícitamente de (char*) a (void*).

            (La función toma sólo la referencia del puntero que yo le doy.)
     */
    while( scanf(" %c", &q) == 1 ){
        if( q == 'A' | q == 'a' ){
            scanf(" %c", &c);

            /* aloco memoria */
            cp = malloc( sizeof(char) );
            if( cp == NULL ) continue;

            /* guardo el dato en el lugar al que apunta cp */
            *cp = c;
            /* meto la referencia de ese dato en el vector */
            vector_insert(&mi_vector, cp);
        }

        if( q == 'B' || q == 'b' ){
            scanf("%d", &i);
            vector_delete(&mi_vector, i);
        }

        if( q == 'P' || q == 'p' ){
            scanf("%d", &i);
            printf("V[ %d ] == '%c'\n", i, *(char*)vector_get(&mi_vector, i));
        }

        if( q == 'S' || q == 's' ){
            scanf("%d %c", &i, &c);

            cp = malloc( sizeof(char) );
            if(cp == NULL) continue;

            *cp = c;
            vector_set(&mi_vector, i, cp);
        }

        if( q == 'M' | q == 'm' ){
            printf("V : ");
            for( i = 0; i < mi_vector.tamanio; i++ ){
                printf("%c", *(char*)vector_get(&mi_vector, i));
            }
            putchar('\n');
        }
    }

    /* destruyo el vector */
    vector_free(&mi_vector);

    return 0;
}
