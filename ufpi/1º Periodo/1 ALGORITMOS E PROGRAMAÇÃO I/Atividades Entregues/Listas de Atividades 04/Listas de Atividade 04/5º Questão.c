#include <stdio.h>

float salario, desconto, novo_salario;

int main(){
    printf("Informe seu salario:R$");
    scanf("%f", &salario);
    if(salario <= 600){
        printf("Voce nao recebera desconto no salario.\n");
        printf("Seu salario sera R$%.2f", salario);
    }else{
        if((salario > 600) && (salario <= 1200)){
            novo_salario = salario * 0.80;
            desconto = salario - novo_salario;
            printf("Seu desconto sera de R$%.2f\n", desconto);
            printf("Seu sera apos o desconto sera de R$%.2f", novo_salario);
        }else{
            if((salario > 1200) && (salario <= 2000)){
                novo_salario = salario * 0.75;
                desconto = salario - novo_salario;
                printf("Seu desconto sera de R$%.2f\n", desconto);
                printf("Seu salario apos o desconto sera de R$%.2f", novo_salario);
            }else{
                if(salario > 2000){
                    novo_salario = salario * 0.70;
                    desconto = salario - novo_salario;
                    printf("Seu desconto sera de R$%.2f\n", desconto);
                    printf("Seu salario apos o desconto sera de R$%.2f", novo_salario);
                }
            }
        }
    }

    return 0;
}
