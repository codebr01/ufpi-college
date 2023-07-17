#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cassino();
int main(){
    cassino();
    return 0;
}
int cassino(){
    int dado1,dado2,rep = 1,ponto = 0, soma = 0, guarda = 0,sair = 1;
    srand(time(NULL));
    while(sair != 0){
        dado1 = 1 + rand() % 6;
        dado2 = 1 + rand() % 6;
        soma = dado1 + dado2;
        printf("Dado 1: %i | Dado 2: %i\n", dado1, dado2);
        if(rep == 1){
            if(soma == 7 || soma == 11){
                sair = 0;
                printf("Soma: %i - O jogador ganhou!", soma);
            }else{
                if(soma == 2 || soma == 3 || soma == 12){
                    sair = 0;
                    printf("Soma: %i\nCRAPS! Jogador Perdeu :( You Lose\n", soma);
                }
            }
            if(soma >= 4 && soma <= 6 || soma >= 8 && soma <= 10){
                ponto++;
                guarda = soma;
                printf("Soma: %i \nJogador pontuou %i\n", soma, soma);
            }
        }
        if(rep >= 2){
            if(soma >= 4 && soma <= 6 || soma >= 8 && soma <= 10){
                printf("Soma: %i\n", soma);
            }
            if(soma == guarda){
                ponto++;
            }
            if(soma == 7){
                sair = 0;
                printf("Soma: %i\nJOGADOR PERDEU!", soma);
            }
            if(ponto == 2){
                sair = 0;
                printf("Soma: %i\nJOGADOR VENCEU POR PONTOS!\n", soma);
            }
        }
        rep++;
        printf("\n");
        system("pause");
    }
    return 0;
}