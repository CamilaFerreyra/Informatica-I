#include <stdio.h>

void cargar(int lista[100]){
    int i,edad, personas;
    i=0;
    printf("Ingrese una edad: ");
    scanf(" %d", &edad);
    for(i=0;edad>0;i++){
        lista[i]=edad;
        printf("Ingrese una edad: ");
        scanf(" %d", &edad);
    }
    personas=i;
    for(i=0;i!=personas;i++){
            printf("\nedad fue: %d",lista[i]);
    }
}
main(){
    int lista[100];
    cargar(lista);
    return 0;
}
