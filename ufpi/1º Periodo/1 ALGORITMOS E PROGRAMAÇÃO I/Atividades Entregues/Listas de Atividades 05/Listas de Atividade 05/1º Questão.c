#include <stdio.h>
int num, divisao;
int main(){
    printf("Digite o numero: ");
    scanf("%i", &num);
    while( num >= 1 ){
        divisao = num % 10;
        if(divisao % 2 == 0){
            printf("\n%i numero par.\n", divisao);
        }else{
            printf("\n%i numero impar.\n", divisao);
        }
        num /= 10;
    }
    return 0;
}
