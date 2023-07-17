#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char *naipe;
    char *face;

} Carta;

void preenche(Carta *deck, char *face[], char *naipe[]);
void embaralha(Carta *deck);
void imprime(Carta *deck);

int main(){
    srand(time(NULL));

    Carta d[52];

    char *naipe[] = {"Paus", "Ouros", "Copas", "Espadas"};
    char *face[] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};

    preenche(d, face, naipe);
    embaralha(d);
    imprime(d);

    return 0;
}

void preenche(Carta *deck, char *face[], char *naipe[]){

    int i, j, k = 0;

    for (i = 0; i < 4; i++)
    {
        deck[k].naipe = naipe[i];
        for (j = 0; j < 13; j++)
        {
            deck[k].face = face[j];
            k++;
        }
    }
}

void embaralha(Carta *deck){
    int i, j = 0;
    i = rand() % 52;
    for (i; j < 52; j++)
    {
        printf("%s de %s\n", deck[i].face, deck[i].naipe);
    }
}

void imprime(Carta *deck){
    int i;
    for (i = 0; i < 52; i++)
    {
        printf("%s de %s\n", deck[i].naipe, deck[i].face);
    }
}