#include <stdio.h>
int main(){
    float salario;
    scanf("%f", &salario);
    if(salario <= 600.00){
        printf("0.00\n");
        printf("%.2f\n", salario);
    }
    if(salario > 600.00 && salario <= 1200.00){
        printf("%.2f\n", salario * 0.2);
        printf("%.2f\n", salario - (salario * 0.2));
    }
    if(salario > 1200.00 && salario <= 2000.00){
        printf("%.2f\n", salario * 0.25);
        printf("%.2f\n", salario - (salario * 0.25));
    }
    if(salario > 2000.00){
        printf("%.2f\n", salario * 0.3);
        printf("%.2f\n", salario - (salario * 0.3));
    }
    return 0;
}