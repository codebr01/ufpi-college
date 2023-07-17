#include <stdio.h>

int mdc(int a, int b, int c);

int main(){
    int a,b,c;
    printf("Digite um numero: ");
    scanf("%i", &a);
    printf("Digite um numero: ");
    scanf("%i", &b);
    printf("Digite um numero: ");
    scanf("%i", &c);
    mdc(a,b,c);
    return 0;
}
int mdc(int a, int b, int c){
    int aux,i;
        aux = a;
        a = b;
        b = c;
        c = aux;
    for(i = a; (i > 1) && !((a % i == 0) && (b % i == 0) && (c % i == 0)); i--){

    }
    printf("MDC = %i", i);

    return 0;
}

