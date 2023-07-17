#include <stdio.h>
long long fibonacciVetor(int nEsimoTermo);
int t,n,i;
int main(){
    scanf("%i", &t);
    fibonacciVetor(t);
    return 0;
}
long long fibonacciVetor(int nEsimoTermo){
    unsigned long long int fib[61];
    fib[0] = 0;
    fib[1] = 1;
    for(i = 2; i <= 60; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for(i = 1;i <= t; i++){
        scanf("%i", &n);
        printf("Fib(%i) = %llu\n", n,fib[n]);
    }
    return 0;
}
