#include <stdio.h>
int main(){
    int qtd;
    scanf("%i", &qtd);
    if(qtd < 12){
        printf("R$ %.2f\n", qtd * 1.3);
    }else{
        printf("R$ %.2f\n", qtd * 1.0);
    }
    return 0;
}