#include <stdio.h>
int main(){
    int a, b, tmp, cont;
    cont = 0;
    scanf("%i %i", &a, &b);
    if(a > b){
        tmp = a;
        a = b;
        b = tmp;
    }
    while(b % a){
        b -= a;
        if(a > b){
            tmp = a;
            a = b;
            b = tmp;
        }
        cont++;
    }
    printf("MDC = %i\n", a);
    printf("Repeticoes = %i", cont);
    return 0;
}