#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
    int naipe;
    int valor;
}Carta;
int main(){
    Carta c;
    char carta_valor[13][7] = {"As","Dois","Tres","Quatro","Cinco","Seis","Sete","Oito","Nove","Dez","Valete","Dama","Rei"};
    char carta_naipe[4][8] = {"Paus","Ouros","Copas","Espadas"};
    int resp,i;
    scanf("%i", &resp);
    if(resp == 1){
        c.naipe = c.valor = 0;
        for(i = 0; i < 1;i++){
            for(c.naipe;c.naipe < 4;c.naipe++){
                for(c.valor = 0;c.valor < 13;c.valor++){
                    printf("%s de %s\n", carta_valor[c.valor],carta_naipe[c.naipe]);
                }
                c.valor = 0;
            }
        }
    }else{
        if(resp == 0){
            srand(time(NULL));
            for(i = 0; i < 52; i++){
                c.valor = rand() % 13;
                c.naipe = rand() % 4;
                printf("%s de %s\n", carta_valor[c.valor], carta_naipe[c.naipe]);
            }
        }
    }

    return 0;
}