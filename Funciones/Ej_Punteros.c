#include<stdio.h>
void modificar(int c2,int *a2, int *b2){
    /*int aux;
    aux2=*a2;
    *a2=*b2;
    *b2=aux2;
    */
    *a2=*a2+c2;
    *b2=*b2+c2;
}
main(){
    int a,b,c, aux;
    a=0;
    b=2;
    c=3;
    printf("a=%d, b=%d, c=%d", a,b,c);
    //a=0, b=2, c=3
    modificar(c,&a,&b);
    printf("\na=%d, b=%d, c=%d", a,b,c);
    //a=2, b=0, c=3
return 0;
}
