#include <stdio.h>
int main(){
    int t,n,i;
    unsigned long long int fib[61];
    fib[0] = 0;
    fib[1] = 1;
    for(i = 2; i <= 60; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    scanf("%i", &t);
    for(i = 1;i <= t; i++){
        scanf("%i", &n);
        printf("Fib(%i) = %llu\n", n,fib[n]);
    }
    return 0;
}

