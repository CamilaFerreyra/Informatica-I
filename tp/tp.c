#include<stdio.h>
#include<string.h>
#define cantidad 10
struct diccionario{
    char espaniol[20];
    char ingles[20];
    int busqueda;
};

void CARGA (struct diccionario DICCIONARIO[cantidad], int *cant_traducciones){
//Variables
    char p_espaniol[20];
    char p_ingles[20];
    int p_buscada, i;
//Inicio

   FILE *archivo;
   archivo= fopen("espaingl.dat", "r");
   fscanf(archivo,"%s%s%d", p_espaniol, p_ingles, &p_buscada);
    for(i=0;!(feof(archivo)); i++) {
        strcpy(DICCIONARIO[i].espaniol, p_espaniol);
        strcpy(DICCIONARIO[i].ingles, p_ingles);
        DICCIONARIO[i].busqueda = p_buscada;
        printf("%s %s %d \n", DICCIONARIO[i].espaniol, DICCIONARIO[i].ingles, DICCIONARIO[i].busqueda);
        fscanf(archivo,"%s%s%d", p_espaniol, p_ingles, &p_buscada);
    }
    fclose(archivo);
    *cant_traducciones= i;
}
int VALIDACION_MENU_PRINCIPAL(int opcion){
//Variables
//Inicio
                    ///AND = && ; or = ||
	while ((opcion != 0) && (opcion != 1) && (opcion !=2)){
		printf("\nLa opcion ingresada es incorrecta.\n Reingrese por favor. (1-Ingles a Espaniol. 2-Espaniol a Ingles. 0-Cerrar): ");
		scanf("%d", &opcion);
	}
	return opcion;
}

char VALIDACION_LETRA(char letra){
//Variables
//Inicio

	while ((letra != 'T') && (letra !='A') && (letra !='M') && (letra != 'V')){
		printf("\nLa opcion ingresada es incorrecta.\n Reingrese por favor. (T - Traducir al Espaniol, A - Agregar palabra, M - Mas buscadas, V - Volver): ");
		scanf(" %c", letra);
    }
    return letra;
}
int MENU_PRINCIPAL (){
//variables
    int opcion;
//inicio
    printf("Bienvenido al diccionario espaniol-ingles\n");
    printf("MENU PRINCIPAL\n");
    printf("1 - Ingles a Espaniol\n");
    printf("2 - Espaniol a Ingles\n");
    printf("0 - Cerrar\n");
    printf("Ingrese opcion: ");
    scanf(" %d", &opcion);
    opcion=VALIDACION_MENU_PRINCIPAL(opcion);
    return opcion;

}

char ingles_a_espaniol (){
//variables
    char letra;
//inicio
    printf("\nUsted ingreso la opcion 1; \n");
    printf("T - Traducir al Espaniol\n");
    printf("A - Agregar palabra\n");
    printf("M - Mas buscadas\n");
    printf("V - Volver\n");
    printf("Ingrese opcion deseada: ");
    scanf(" %c", &letra);
    letra= VALIDACION_LETRA(letra);
    return letra;

}

char espaniol_a_ingles (){
//variables
    char letra;
//inicio
    printf("\nUsted ingreso la opcion 2; \n");
    printf("T - Traducir al Ingles\n");
    printf("A - Agregar palabra\n");
    printf("M - Mas buscadas\n");
    printf("V - Volver\n");
    printf("Ingrese opcion deseada: ");
    scanf(" %c", &letra);
    letra=VALIDACION_LETRA(letra);
    return letra;

}

void agregar_ingles_a_espaniol(struct diccionario DICCIONARIO[cantidad], int *cant_traducciones){
//Variables
	char palabra_ingles[20], p_espaniol[20];

//Inicio
	printf("Ingrese o reingrese palabra en Ingles que quiere cargar");
	scanf(" %s", palabra_ingles);
	printf("Ingrese su traduccion");
	scanf(" %s", p_espaniol);
	strcpy(DICCIONARIO[(*cant_traducciones)].ingles,palabra_ingles);
	strcpy(DICCIONARIO[(*cant_traducciones)].espaniol,p_espaniol);
	DICCIONARIO[(*cant_traducciones)].busqueda=0;
	*cant_traducciones= *cant_traducciones +1;
}

void traducir_ingles_a_espaniol (struct diccionario DICCIONARIO[cantidad], int *cant_traducciones){
//Variables
    char p_ingles[20];
    int i, rta, bandera;
//Inicio
    bandera=0;
    printf("\nInglese palabra en ingles: ");
    scanf(" %s", p_ingles);
    for (i=0; i< *cant_traducciones; i++){
        if (strcmp(DICCIONARIO[i].ingles, p_ingles) == 0){
            printf("Su traduccion es: %s\n", DICCIONARIO[i].espaniol);
            DICCIONARIO[i].busqueda= DICCIONARIO[i].busqueda +1;
            bandera=1; //si encontro la palabra y mostro su traduccion
	  }
        if (bandera ==0){  //no enocntro la palabra
           printf("La palabra buscada no existe. Desea cargarla? (1=si/ 0=no): ");
           scanf(" %d", &rta);
           if (rta ==1){
            //agregar_ingles_a_espaniol(DICCIONARIO, &cant_traducciones);
           }
        }
    }



}

void agregar_espaniol_a_ingles(struct diccionario DICCIONARIO[cantidad], int *cant_traducciones){
//Variables
	char palabra_espaniol[20], p_ingles[20];

//Inicio
	printf("\nIngrese o reingrese palabra en Espaniol que quiere cargar: ");
	scanf(" %s", palabra_espaniol);
	printf("\nIngrese su traduccion: ");
	scanf(" %s", p_ingles);
	strcpy(DICCIONARIO[(*cant_traducciones)].espaniol,palabra_espaniol);
	strcpy(DICCIONARIO[(*cant_traducciones)].ingles,p_ingles);
	DICCIONARIO[(*cant_traducciones)].busqueda=0;
	*cant_traducciones= *cant_traducciones +1;


}

void traducir_espaniol_a_ingles (struct diccionario DICCIONARIO[cantidad], int *cant_traducciones){
//variables
    char p_espaniol[20];
    int i, rta,bandera;
//inicio
    bandera=0;
    printf("\n Ingrese palabra en Espaniol: ");
    scanf(" %s", p_espaniol);
    for (i=0; i< *cant_traducciones; i++){
            /*
///Busqueda dicotomica
            int mayor, menor, medio, posicion_buscada;
            menor=0;
            mayor= *canta_traducciones - 1;
            while(menor<mayor) || (menor == mayor)){
                medio= (mayor+menor)/2;
                if(strcmp(DICCIONARIO[medio].espaniol,p_espaniol)==0){
                    bandera=1; ///se encontro la palabra.
                    posicion_buscada=medio;
                }else{
                    if(strcmp(DICCIONARIO[medio].espaniol,p_espaniol)<0){
                        menor=medio+1;
                    }else{
                        mayor=medio-1;
                    }
                }
            }
            /// a------m-------b
///busqueda secuencial:
       if(strcmp(DICCIONARIO[i].espaniol,p_espaniol) ==0){
            printf("\nSu traduccion es: %s\n", DICCIONARIO[i].ingles);
            DICCIONARIO[i].busqueda= DICCIONARIO[i].busqueda +1;
            bandera=1; //encontro la palabra ingresada y mostro su traduccion
       }
       */
        if (bandera==0){ //no encontro la palabra ingresada
            printf("La palabra buscada no existe. Desea ingresarla? (1=si/ 0=no): ");
            scanf(" %d", &rta);
            if (rta ==1){
                //agregar_espaniol_a_ingles(DICCIONARIO, &cant_traducciones);
            }
        }
    }

}

void mas_buscadas (struct diccionario DICCIONARIO[cantidad], int cant_traducciones){
//variables
    int i;
//inicio

}

void imprimir(struct diccionario DICCIONARIO[cantidad], int cant_traducciones){
//variable
    int i;
//inicio
    FILE *archivo2;
    archivo2=fopen("salida.txt", "w");
    for (i=0; i<cant_traducciones; i++){
        fprintf(archivo2,"%s\t%s\t%d\n", DICCIONARIO[i].espaniol, DICCIONARIO[i].ingles, DICCIONARIO[i].busqueda);

    }
    fclose(archivo2);

}

int main(){
struct diccionario DICCIONARIO[cantidad];
//variables
    int opcion, cant_traducciones;
    char letra;
//Inicio
    CARGA(DICCIONARIO, &cant_traducciones);
    opcion= MENU_PRINCIPAL();
    //VALIDACION_MENU_PRINCIPAL()
    while (opcion != 0){
        if(opcion ==1) {
           letra= ingles_a_espaniol();
           //VALIDACION_LETRA(letra)
           switch(letra){
            case 'T':
                traducir_espaniol_a_ingles(DICCIONARIO, &cant_traducciones);
                break;
            case 'A':
                agregar_espaniol_a_ingles(DICCIONARIO, &cant_traducciones);
                break;
            case 'M':
                //...
                break;
            }

        }
         else{
            letra=espaniol_a_ingles();
            //VALIDACION_LETRA(letra)
            switch(letra){
                case 'T':
                    traducir_ingles_a_espaniol(DICCIONARIO, &cant_traducciones);
                    break;
                case 'A':
                    agregar_ingles_a_espaniol(DICCIONARIO, &cant_traducciones);
                    break;
                case 'M':
                    //...
                    break;
                }

         }

        opcion= MENU_PRINCIPAL();
    }

    imprimir(DICCIONARIO, cant_traducciones);
    return 0;
}



