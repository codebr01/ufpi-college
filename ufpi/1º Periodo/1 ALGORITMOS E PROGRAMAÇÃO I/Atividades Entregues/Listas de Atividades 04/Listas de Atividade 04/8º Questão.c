#include <stdio.h>

int h1, h2, m1, m2, mais_velho, mais_novo, mais_velha, mais_nova, soma, produto;

int main(){

    printf("Informe a idade do primeiro homem: ");
    scanf("%i", &h1);
    printf("Informe a idade do segundo  homem: ");
    scanf("%i", &h2);
    printf("Informe a idade da primeira mulher: ");
    scanf("%i", &m1);
    printf("Informe a idade da segunda  mulher:");
    scanf("%i", &m2);
    if((h1 != h2) && (m1 != m2)){
            if(h1 > h2){
                mais_velho = h1;
                mais_novo = h2;
            }else{
                mais_velho = h2;
                mais_novo = h1;
            }
            if(m1 > m2){
                mais_velha = m1;
                mais_nova = m2;
            }else{
                mais_velha = m2;
                mais_nova = m1;
            }
            soma = mais_velho + mais_nova;
            produto = mais_novo * mais_velha;
            printf("\nO homem mais velho e %i e o mais novo e %i\n", mais_velho, mais_novo);
            printf("A mulher mais velha e %i e a mais nova e %i\n", mais_velha, mais_nova);
            printf("\nA soma do homem mais velho e da mulher mais nova: %i\n",soma);
            printf("O produto do homem mais nova e da mulher mais velha: %i\n", produto);
    }else{
        printf("As idades nao podem iguais!\nInforme APENAS idades diferentes\n");
    }
    return 0;
}
