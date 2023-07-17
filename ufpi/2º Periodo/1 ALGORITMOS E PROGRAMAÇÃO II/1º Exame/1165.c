#include <stdio.h>
int x;
int ehPrimo(int n);

int main()
{

    int n,i;
    scanf("%i", &n);
    if(n <= 1 || n > 100){
        while(n <= 1 || n > 100){
            scanf("%i", &n);
        }
    }
    for(i = 0; i < n; i++){
        if(ehPrimo(n) == 1){
            printf("%i eh primo\n", x);
        }else{
            printf("%i nao eh primo\n", x);
        }

    }

    return 0;
}
int ehPrimo(int n){
    int i,divisor;
    divisor = 0;
    scanf("%i", &x);
    if(x <= 1 || x > 10000000){
        while(x <= 1 || x > 10000000){
            scanf("%i", &x);
        }
    }
    for(i = 1; i <= x; i++){
        if(x % i == 0){
            divisor++;
        }
    }
    if(divisor == 2){
        return 1;
    }else{
        return 0;
    }

}