#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int acerta_numero(int computador);
int main(){
    int computador;
    srand(time(NULL));
    computador = 1 + rand() % 1000;
    printf("%i\n", computador);
    printf("Eu tenho um numero entre 1 e 1000. :)\n");
    printf("Numero de tentativas: %i", acerta_numero(computador));
    return 0;
}
int acerta_numero(int computador){
    int jogador, acertou = 0,rep = 0;
    while(acertou != 1){
        scanf("%i", &jogador);
        if(jogador == computador){
            printf("Excelente! Voce adivinhou o numero!\n");
            acertou = 1;
        }else{
            if(jogador < computador){
                printf("Muito baixo. Tente novamente.\n");
            }else{
                if(jogador > computador){
                    printf("Muito alto. Tente novamente.\n");
                }
            }
        }
        rep++;
    }
    return rep;
}