#include <stdio.h>

float produto, valor_de_venda;

int main(){

    printf("Informe o valor do produto: R$ ");
    scanf("%f", &produto);
    if(produto < 20){
        valor_de_venda = produto * 1.45;
    }else{
        if(produto >= 20){
            valor_de_venda = produto * 1.30;
        }
    }
    printf("\nO valor do produto sera R$%.2f\n", valor_de_venda);
    return 0;
}
