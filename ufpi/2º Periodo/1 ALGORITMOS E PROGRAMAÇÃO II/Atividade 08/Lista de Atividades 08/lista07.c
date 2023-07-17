#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int NUM_COMP, NUM_MOV;

typedef struct{
    int chave;
    char nome[30];
    char endereco[50];
    char telefone[14];

}Alunos;

void gerarDados(Alunos v[], int n, int ordemChave);
void bolha(Alunos v[], int n);
void selecao(Alunos v[], int n);
void insercao(Alunos v[], int n);

void main(){
    srand(time(NULL));
    int n,ordem = 0, algo;
    Alunos turma1[1000];
    Alunos aux;
    scanf("%i", &n);
    while(ordem != 3){
        scanf("%i %i", &ordem, &algo);
        setbuf(stdin,NULL);
        gerarDados(turma1, n, ordem);
        if(algo == 0){
            printf("bolha\n");
            bolha(turma1,n);
        }else{
            if(algo == 1){
            printf("selecao\n");
                selecao(turma1, n);
            }else{
                if(algo == 2){
                    printf("insercao\n");
                    insercao(turma1, n);
                }else{
                    if(algo == 3 || ordem == 3){
                        break;
                    }
                }
            }
        }
    }

}

void gerarDados(Alunos v[], int n, int ordemChave){
    int i;
    for(i = 0; i < n; i++){
        if(ordemChave == 0){
            v[i].chave = i;
        }else{
            if(ordemChave == 1){
                v[i].chave = rand() % n;
            }else{
                if(ordemChave == 2){
                    v[i].chave = n - i - 1;
                }
            }
        }
    }
}

void bolha(Alunos v[], int n){
    int i,j,aux;
    NUM_COMP = NUM_MOV = 0;
    for(i = 0; i < n; i++){
        printf("%i ", v[i].chave);
    }printf("\n");
    for(i = 0; i < n - i; i++){
        for(j = 1; j < n - 1; j++){
            NUM_COMP++;
            if(v[i].chave < v[j - 1].chave){
                NUM_MOV += 3;
                aux = v[i].chave;
                v[i].chave = v[j- 1].chave;
                v[j - 1].chave = aux;
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%i ", v[i].chave);
    }printf("\n");
    printf("%i %i\n", NUM_COMP,NUM_MOV);

}

void selecao(Alunos v[], int n){
    int i, j, min, aux;
    NUM_COMP = NUM_MOV = 0;

    for(i = 0; i < n; i++){
        printf("%i ", v[i].chave);
    }printf("\n");
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
        	NUM_COMP++;
            if(v[j].chave < v[min].chave){
                min = j;
            }
        }
        NUM_MOV += 3;
        aux = v[j].chave;
        v[j].chave = v[min].chave;
        v[min].chave = aux;
    }
    for(i = 0; i < n; i++){
        printf("%i ", v[i].chave);
    }printf("\n");
    printf("%i %i\n", NUM_COMP,NUM_MOV);
}

void insercao(Alunos v[], int n){
    int i,j;
    Alunos aux;
    NUM_COMP = NUM_MOV = 0;

    for(i = 0; i < n; i++){
        printf("%i ", v[i].chave);
    }printf("\n");
    for(i = 1; i < n; i++){
        aux = v[i];
        j = i - 1;
        NUM_MOV++;
        NUM_COMP += 2;
        while((j >= 0) && (aux.chave < v[j].chave)){
            v[j + 1] = v[j];
            j--;
            NUM_MOV++;
            NUM_COMP += 2;
        }
        v[j+ 1] = aux;
        NUM_MOV++;
    }
    for(i = 0; i < n; i++){
        printf("%i ", v[i].chave);
    }printf("\n");
    printf("%i %i\n", NUM_COMP,NUM_MOV);
}
