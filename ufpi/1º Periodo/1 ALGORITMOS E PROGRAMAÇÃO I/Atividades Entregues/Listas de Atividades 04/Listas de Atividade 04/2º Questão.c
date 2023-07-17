#include <stdio.h>

float c, i, rendimento, total;

int main(){

    printf("Informe o valor do deposito: ");
    scanf("%f", &c);
    printf("Informe a taxa de juros\(%%): ");
    scanf("%f", &i);
    i = i / 100;
    rendimento = c * i;

    total = c + rendimento;

    printf("O rendimento sera de: R$%.2f\n", rendimento);
    printf("E o total apos o rendimento sera um valor de R$%.2f", total);
    return 0;
}
