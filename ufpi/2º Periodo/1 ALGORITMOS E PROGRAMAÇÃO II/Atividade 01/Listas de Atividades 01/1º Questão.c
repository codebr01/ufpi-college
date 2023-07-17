#include <stdio.h>
int main(){
    float valor;
    scanf("%f", &valor);
    if(valor < 20.00){
        printf("%.2f\n", valor * 1.45);
    }else{
        printf("%.2f\n", valor * 1.30);
    }
    return 0;
}