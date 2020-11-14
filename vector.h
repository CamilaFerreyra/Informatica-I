#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned tamanio;   /* cantidad de elementos */
    unsigned capacidad; /* capacidad máxima (memoria reservada) */
    void** datos;  /* datos */
} vector;

void vector_init(vector* v, int tamanio){
    /* tamaño inválido */
    if(tamanio < 1){
        fprintf(stderr, "ERROR FATAL EN \"vector.h\":\n" );
        fprintf(stderr, "   valor demasiado chico (%d) para vector_init().\n", tamanio);
        exit(0);
    }

    v->datos = malloc( sizeof(void*) * tamanio );
    if(v->datos == NULL){
        fprintf(stderr, "ERROR FATAL EN \"vector.h\":\n" );
        fprintf(stderr, "   error en el alojamiento de memoria en vector_init().\n");
        exit(0);
    }
    v->tamanio = 0;
    v->capacidad = tamanio;
}

int vector_resize(vector* v, int tamanio){
    /* el valor de retorno indica si la acción se completó exitósamente o no */

    void **datos = realloc( v->datos, sizeof(void*) * tamanio );

    if(datos == NULL) return -1;

    v->datos = datos;
    v->capacidad = tamanio;
    if(v->tamanio >= v->capacidad){
        v->tamanio = v->capacidad;
    }

    return 0;
}

void vector_insert(vector* v, void* dato){
    /* asegurarse de que haya memoria */
    if(v->tamanio >= v->capacidad){
        v->capacidad *= 2;
        /* asegurarse de que la acción se haya completado exitósamente */
        int q = vector_resize(v, v->capacidad * 2);

        if(q == -1){
            fprintf(stderr, "ERROR FATAL EN \"vector.h\":\n" );
            fprintf(stderr, "   error en el re-alojamiento de memoria en vector_insert().\n");
            exit(0);
        }
    }
    v->datos[v->tamanio++] = dato;
}

void vector_delete(vector* v, int indice){
    /* indice inválido */
    if(indice < 0 || indice > v->tamanio - 1){
        fprintf(stderr, "ERROR FATAL EN \"vector.h\":\n" );
        fprintf(stderr, "   indice invalido (%d) para vector de tamanio (%d) en vector_delete().\n", indice, v->tamanio);
        exit(0);
    }
    v->datos[indice] = NULL;

    int i;
    for( i = indice; i < v->tamanio - 1; i++ ){
        v->datos[i] = v->datos[i+1];
        v->datos[i+1] = NULL;
    }
    v->tamanio--;

    /* asegurarse de que haya memoria */
    if(v->tamanio > 0 && v->tamanio == v->capacidad / 4){
        vector_resize(v, v->capacidad * 2);
    }
}

void *vector_get(vector* v, int indice){
    /* indice inválido */
    if(indice < 0 || indice > v->tamanio - 1){
        fprintf(stderr, "ERROR FATAL EN \"vector.h\":\n" );
        fprintf(stderr, "   indice invalido (%d) para vector de tamanio (%d) en vector_get().\n", indice, v->tamanio);
        exit(0);
    }
    return v->datos[indice];
}

void vector_set(vector* v, int indice, void* valor){
    /* indice inválido */
    if(indice < 0 || indice > v->tamanio - 1){
        fprintf(stderr, "ERROR FATAL EN \"vector.h\":\n" );
        fprintf(stderr, "   indice invalido (%d) para vector de tamanio (%d) en vector_set().\n", indice, v->tamanio);
        exit(0);
    }
    free(v->datos[indice]);
    v->datos[indice] = valor;
}

void vector_free(vector* v){
    int i;
    for( i = 0; i < v->tamanio; i++ ){
        free(v->datos[i]);
    }
    free(v->datos);
}
