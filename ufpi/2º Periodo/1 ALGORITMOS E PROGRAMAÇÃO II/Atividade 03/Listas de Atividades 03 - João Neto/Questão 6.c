#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char frase[100];
char artigo[5][9] = {'o','\0',' ',' ',' ',' ',' ',' ',' ','u','m','\0',' ',' ',' ',' ',' ',' ','a','l','g','u','m','\0',' ',' ',' ','t','o','d','o','\0',' ',' ',' ',' ','q','u','a','l','q','u','e','r','\0',};
char substantivo[5][9] = {'m','e','n','i','n','o','\0',' ',' ','h','o','m','e','m','\0',' ',' ',' ','c','a','c','h','o','r','r','o','\0','c','a','r','r','o','\0',' ',' ',' ','g','a','t','o','\0',' ',' ',' ',' ',};
char verbo[5][9] = {'p','a','s','s','o','u','\0',' ',' ','p','u','l','o','u','\0',' ',' ',' ','c','o','r','r','e','u','\0',' ',' ','s','a','l','t','o','s','\0',' ',' ','a','n','d','o','u','\0',' ',' ',' ',};
char preposicao[5][9] = {'s','o','b','r','e','\0',' ',' ',' ','s','o','b','\0',' ',' ',' ',' ',' ','a','n','t','e','\0',' ',' ',' ',' ','a','t','e','\0',' ',' ',' ',' ',' ','c','o','m','\0',' ',' ',' ',' ',' ',};

int concatena();
int artigo_concatena(int posicao);
int substantivo_concatena(int posicao);
int verbo_concatena(int posicao);
int preposicao_concatena(int posicao);
int sortear();

int concatena(){
    int posicao = 0;
    posicao = artigo_concatena(posicao);
    posicao = substantivo_concatena(posicao);
    posicao = verbo_concatena(posicao);
    posicao = preposicao_concatena(posicao);
    frase[0] -= 32;
    frase[posicao] = '.';
    frase[posicao + 1] = '\0';
    posicao = 0;
}

int artigo_concatena(int posicao){
    int k = 0,a;
    a = sortear();
    while(artigo[a][k] != '\0'){
        frase[posicao] = artigo[a][k];
        posicao++;
        k++;
    }
    frase[posicao] = ' ';
    posicao++;
    return posicao;
}

int substantivo_concatena(int posicao){
    int k = 0,q;
    q = sortear();
    while(substantivo[q][k] != '\0'){
        frase[posicao] = substantivo[q][k];
        posicao++;
        k++;
    }
    frase[posicao] = ' ';
    posicao++;
    return posicao;
}

int verbo_concatena(int posicao){
    int k = 0,w;
    w = sortear();
    while(verbo[w][k] != '\0'){
        frase[posicao] = verbo[w][k];
        posicao++;
        k++;
    }
    frase[posicao] = ' ';
    posicao++;
    return posicao;
}

int preposicao_concatena(int posicao){
    int k = 0,e;
    e = sortear();
    while(preposicao[e][k] != '\0'){
        frase[posicao] = preposicao[e][k];
        posicao++;
        k++;
    }
    return posicao;
}

int sortear(){
    srand(time(NULL));
    int i = rand() % 5;
    return i;
}

int main(){
    int u;
    for(u = 0; u < 20; u++){
        concatena();
        printf("%s\n", frase);
    }
    return 0;
}
