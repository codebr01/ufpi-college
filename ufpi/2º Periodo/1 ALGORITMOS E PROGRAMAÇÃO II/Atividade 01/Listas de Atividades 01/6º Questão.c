#include <stdio.h>
int main(){
    int limitador = 0;
    int num, soma;
    soma = 0;
    while(limitador >= 0){
        scanf("%i", &num);
        if(num < 0){
            num = 0;
            limitador = -1;
        }
        if(num > 0){
            soma += num;
        }
    }
    printf("%i\n", soma);
    return 0;
}