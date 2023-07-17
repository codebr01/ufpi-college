#include <stdio.h>
int num,i,n_divisor,primo,qtd_primo;
int main(){
    printf("Digite -1 para sair do programa.....\n");
    printf("Digite um numero: ");
    scanf("%i", &num);
    n_divisor = 0;
    qtd_primo = 0;
    while(num != -1){
        for(i = 1; i <= num; i += 1){
            if(num % i == 0){
                n_divisor += 1;
            }
        }
        if(n_divisor == 2){
            primo += 1;
            qtd_primo = primo;
        }
        printf("\nO numero %i tem %i divisores.\n",num, n_divisor);
        printf("\nDigite -1 para sair ou digite outro numero: ");
        scanf("%i",&num);
        n_divisor = 0;
    }
    printf("%i numeros primos digitados.\n", qtd_primo);
    printf("\nVoce saiu do programa....\n");
    return 0;
}
