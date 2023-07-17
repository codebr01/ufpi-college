#include <stdio.h>
int num1, num2, soma_num2, i;
int main(){
    soma_num2 = 0;
    printf("Infome o primeiro numero: ");
    scanf("%i", &num1);
    printf("Informe o segundo numero: ");
    scanf("%i", &num2);
    i = 0;
    while(num1 > 0){
        soma_num2 += num2;
        num1 -= 1;
        i += 1;
    }
    printf("%i x %i = %i",i, num2, soma_num2);
    return 0;
}
