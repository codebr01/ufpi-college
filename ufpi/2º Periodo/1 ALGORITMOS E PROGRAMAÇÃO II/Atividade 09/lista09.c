#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 1000

typedef struct{
    int codigo;
    char nome[20];
}Registro;

typedef struct{
    Registro carro[MAX + 1];
    int tamanho;
}Tabela;

void ordena(Tabela *t, int n);
int pesquisa_sequencial(int chave, Tabela *t);
int binaria(int chave, Tabela *t);

float contador_global = 0;

int main(){
    Tabela t;
    t.tamanho = 0;
    int i,aleatorio;
    srand(time(NULL));
    for(i = 0; i < 1000; i++){
        if(t.tamanho == MAX){
            printf("Erro: Tabela cheia\n");
        }else{
            t.tamanho++;
            t.carro[t.tamanho].codigo = rand() % 1000;
            strcpy(t.carro[t.tamanho].nome, "Gol");
        }
    }
    for(i = 1; i < 1000; i++){
        printf("%s : %i\n", t.carro[i].nome, t.carro[i].codigo);
    }
    for(i = 0; i < 100; i++){
        aleatorio = rand() % 1000;
        pesquisa_sequencial(aleatorio, &t);
    }

    printf("Pesquisa sequencial: a media de registros percorridos por pesquisa eh %.2f\n", contador_global / 100);
    contador_global = 0;
    t.tamanho = 0;
    ordena(&t, 1000);
    for(i = 1; i < 1000; i++){
        printf("%s : %i\n", t.carro[i].nome, t.carro[i].codigo);
    }
    for(i = 0; i < 100; i++){
        aleatorio = rand() % 1000;
        binaria(aleatorio, &t);
    }


    return 0;
}

void ordena(Tabela *t, int n){
    int i,j,aux;  

    for(i = 0; i < n - 1; i++){
        for(j = 1; j < n - i; j++){
            if(t->carro[j].codigo < t->carro[j - 1].codigo){
                aux = t->carro[j].codigo;
                t->carro[j].codigo = t->carro[j - 1].codigo;
                t->carro[j - 1].codigo = aux;
            }
        }
    }

}

int pesquisa_sequencial(int chave, Tabela *t){
    int i;
    t->carro[0].codigo = chave;
    for(i = t->tamanho; t->carro[i].codigo != chave; i--){
        contador_global++;
    }
    return i;
}
int binaria(int chave, Tabela *t){
    int i, left, right;
    if(t->tamanho == 0){
    	return 0;
	}
	left = 1;
	right = t->tamanho;
	do{
		i = (left + right) / 2;
		if(chave > t->carro[i].codigo){
			left = i + 1;
		}else{
			right = i - 1;
		}
	}while(chave != t->carro[i].codigo && left <= right);
	if(chave == t->carro[i].codigo){
		return i;
	}else{
		return 0;
	}
	
}
