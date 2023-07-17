#include <stdio.h>

float u, t;

int main(){

    printf("Venda de Macasz\n");
    printf("|  Menos de uma duzia: un. R$1,30   |\n");
    printf("| A partir de uma duzia: un. R$1,00 |\n");
    printf("\nQuantas unidades de maca voce quer comprar: ");
    scanf("%f", &u);
    if(u < 12){
        t = u * 1.3;
        printf("O total foi R$%.2f\n", t);
    }else{
        if(u >= 12){
            t = u;
            printf("O total foi R$%.2f\n", t);
        }
    }
    return 0;
}
