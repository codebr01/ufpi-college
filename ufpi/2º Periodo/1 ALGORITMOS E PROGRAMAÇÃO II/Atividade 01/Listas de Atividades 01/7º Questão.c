#include <stdio.h>
int main(){
    int x, y, somaadicao,somamultiplicacao,limitador;
    limitador = somaadicao = 0;
    somamultiplicacao = 1;
    scanf("%i %i", &x, &y);

    if(x < y -2){
        for(x; x <= y; x++){
            if(x % 2 == 0){
                somaadicao += x;
            }else{
                somamultiplicacao *= x;
            }
        }
    }else{
        while(limitador != 1){
            scanf("%i %i", &x, &y);
            if(x < y-2){
                limitador = 1;
            }
        }
        for(x; x <= y; x++){
            if(x % 2 == 0){
                somaadicao += x;
            }else{
                somamultiplicacao *= x;
            }
        }
    }
    printf("%i\n", somaadicao);
    printf("%i\n", somamultiplicacao);
    return 0;
}